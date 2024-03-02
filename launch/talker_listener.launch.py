import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='ros-test',
            executable='listener',
            name='listener'
        ),
        launch_ros.actions.Node(
            package='ros-test',
            executable='talker',
            name='talker'
        ),
    ])
