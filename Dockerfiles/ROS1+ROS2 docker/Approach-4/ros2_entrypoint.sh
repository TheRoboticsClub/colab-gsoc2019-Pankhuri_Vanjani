#!/bin/bash
set -e

# setup ros2 environment
source "/opt/ros/dashing/setup.bash"
exec "$@"
