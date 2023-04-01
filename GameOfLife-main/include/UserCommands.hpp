#pragma once
#include "CommandSource.hpp"

class UserCommands : public CommandSource
{
    public:
    std::string next_command() override;
};