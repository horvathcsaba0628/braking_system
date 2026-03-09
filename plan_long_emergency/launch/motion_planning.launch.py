from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    motion_planning = Node(
        package="plan_long_emergency",
        executable="motion_handler",
        name="motion_handler",
        output="screen"
    )

    return LaunchDescription([
        motion_planning
    ])

    return ld