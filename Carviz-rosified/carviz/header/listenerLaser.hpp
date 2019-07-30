#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <boost/thread/thread.hpp>
#include </opt/jderobot/include/jderobot/types/laserData.h>
#include "../interfaces/laserClient.hpp"
#include "../header/translators.hpp"

namespace Comm {
	class ListenerLaser: public Comm::LaserClient {
		
	public:
		ListenerLaser(Communicator* jdrc);
		~ListenerLaser();

		void start();
		void stop();
		virtual JdeRobotTypes::LaserData  getLaserData();
		

	private:
		pthread_mutex_t mutex;
		ros::Subscriber sub;
		std::string topic;
		std::string nodeName;

		ros::AsyncSpinner* spinner;
		
		void lasercallback (const sensor_msgs::LaserScanConstPtr& laser_msg);

	};//class

} 

