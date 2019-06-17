#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "common.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber(std::string topic)
  : Node("CameraViewer")
  {
    RCLCPP_INFO(this->get_logger(), "constructor Called");
    subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
      topic, std::bind(&MinimalSubscriber::topic_callback, this, _1), 10);
    printf("hi");  
  }

private:
  void topic_callback(const sensor_msgs::msg::Image::SharedPtr message)
  {
    printf("hello");
    RCLCPP_INFO(this->get_logger(), "In callback");

    cv::Mat cv_mat = cv::imdecode(cv::Mat(message->data), cv::IMREAD_UNCHANGED);

    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", "Image");

    cv::Mat c_mat = cv_mat;

    std::cout << c_mat.rows << " " << c_mat.cols << std::endl;

    cv::imshow("CameraViewer", c_mat);

    char key = cv::waitKey(1);

    if (key == 27 /* ESC */ || key == 'q') {
      rclcpp::shutdown();
    }

  }
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
};


