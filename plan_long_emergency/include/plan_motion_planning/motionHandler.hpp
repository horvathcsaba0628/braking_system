#ifndef MOTION_HANDLER_HPP
#define MOTION_HANDLER_HPP

#include <rclcpp/rclcpp.hpp>
#include <crp_msgs/msg>

namespace brakingSystem
{

    class MotionHandler : public rclcpp::Node
    {
    public:
        MotionHandler();

    private:
        void scenarioCallback(const crp_msgs::msg::scenario::SharedPtr msg);
        void egoCallback(const crp_msgs::msg::ego::SharedPtr msg);
        void targetSpaceCallback(const crp_msgs::msg::TargetSpace::SharedPtr msg);

        rclcpp::Subscription<crp_msgs::msg::scenario>::SharedPtr m_subScenario_;
        rclcpp::Subscription<crp_msgs::msg::ego>::SharedPtr m_subEgo_;
        rclcpp::Subscription<crp_msgs::msg::TargetSpace>::SharedPtr m_subTargetSpace_;

        rclcpp::Publisher<autoware_planning_msgs::msg::Trajectory>::SharedPtr m_pubTrajectory_;
    };

} // namespace brakingSystem

#endif // MOTION_HANDLER_HPP