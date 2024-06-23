/**============================================================================
Name        : main.cpp
Created on  : 04.06.2024
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description : FlatBuffers expeiments
============================================================================**/

#include <iostream>
#include <vector>
#include <string_view>

#include "all_headers.h"

int main([[maybe_unused]] int argc,
         [[maybe_unused]] char** argv)
{
    const std::vector<std::string_view> args(argv + 1, argv + argc);

    const LoggingSystem::LogCommand cmd = LoggingSystem::LogCommand::LogCommand_Start;
    std::cout << LoggingSystem::EnumNameLogCommand(cmd) << std::endl;

    const LoggingSystem::LogStatus status = LoggingSystem::LogStatus::LogStatus_Paused;
    std::cout << LoggingSystem::EnumNameLogStatus(status) << std::endl;

    const LoggingSystem::LogMessage message = LoggingSystem::LogMessage::LogMessage_MAX;
    std::cout << LoggingSystem::EnumNameLogMessage(message) << std::endl;

    return EXIT_SUCCESS;
}

