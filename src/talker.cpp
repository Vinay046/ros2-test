#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("talker");
    auto publisher = node->create_publisher<std_msgs::msg::String>("chatter", 10);
    rclcpp::Rate loop_rate(1);

    while (rclcpp::ok()) {
        auto msg = std_msgs::msg::String();
        msg.data = "Hello, world!";
        publisher->publish(msg);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
