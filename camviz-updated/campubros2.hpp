#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "common.hpp"
#include <yaml-cpp/yaml.h>

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class CameraServer : public rclcpp::Node
{
public:
  CameraServer(std::string topic, std::string cameraNum, int fps, std::string name)
  : Node(name), count_(0)
  {
    publisher_ = this->create_publisher<sensor_msgs::msg::Image>(topic, 10);
    timer_ = this->create_wall_timer(
      10ms, std::bind(&CameraServer::timer_callback, this));
    cap = cv::VideoCapture(-1);
  }

private:
  void timer_callback()
  {

      cap >> frame;

      std::cout << frame.rows << " " << frame.cols << std::endl;

    auto message = sensor_msgs::msg::Image();
    //sensor_msgs::msg::Image::UniquePtr message(new sensor_msgs::msg::Image());

    // Pack the OpenCV image into the ROS image.
    set_now(message.header.stamp);
    message.header.frame_id = "camera_frame";
    message.height = frame.rows;
    message.width = frame.cols;
    message.encoding = mat_type2encoding(frame.type());
    message.is_bigendian = false;
    message.step = static_cast<sensor_msgs::msg::Image::_step_type>(frame.step);

    cv::imencode(".png", frame, message.data); // Encode the read frame, so as to reduce it's size

    RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", this->count_);
    publisher_->publish(message);  // Publish.

    this->count_++;

  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
  cv::VideoCapture cap;
  cv::Mat frame;
  size_t count_;
};
