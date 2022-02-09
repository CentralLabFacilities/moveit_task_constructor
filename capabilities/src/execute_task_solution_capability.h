/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2018, Hamburg University.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Hamburg University nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/*
 * Capability to execute trajectories through a ROS action
 * that were generated by the MoveIt Task Constructor.
 *
 * Author: Michael 'v4hn' Goerner
 * */

#pragma once

#include <moveit/move_group/move_group_capability.h>
#include <actionlib/server/simple_action_server.h>

#include <moveit_task_constructor_msgs/ExecuteTaskSolutionAction.h>

#include <memory>

namespace move_group {

class ExecuteTaskSolutionCapability : public MoveGroupCapability
{
public:
	ExecuteTaskSolutionCapability();

	void initialize() override;

private:
	bool constructMotionPlan(const moveit_task_constructor_msgs::Solution& solution,
	                         plan_execution::ExecutableMotionPlan& plan);

	void goalCallback(const moveit_task_constructor_msgs::ExecuteTaskSolutionGoalConstPtr& goal);
	void preemptCallback();

	std::vector<std::string> msgToString(std::vector<std_msgs::String> sv);

	std::unique_ptr<actionlib::SimpleActionServer<moveit_task_constructor_msgs::ExecuteTaskSolutionAction>> as_;
};

}  // namespace move_group
