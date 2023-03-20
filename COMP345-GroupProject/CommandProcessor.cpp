#include "CommandProcessor.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string GameEngine::currentState;

Command::Command(string name)
{
    this->name = name;
}

Command::Command() {}

CommandProcessor::CommandProcessor() {}

string CommandProcessor::readCommand()
{
    string cmdStr;
    cout << "Enter command: ";
    getline(cin, cmdStr);
    return cmdStr;
}

string Command::getName(Command cmd)
{
    return cmd.name;
}

void Command::saveEffect(const string &effect)
{
    this->effectString = effect;
}

void CommandProcessor::saveCommand(const string &cmdStr)
{
    Command cmd(cmdStr);
    commands.push_back(cmd);
}

string CommandProcessor::getEffectString(Command &cmd) const
{
    return cmd.effectString;
}

Command CommandProcessor::getCommand()
{
    string cmdStr = readCommand();
    saveCommand(cmdStr);
    return commands.back();
}

void CommandProcessor::validate(Command cmd)
{
    // Call the appropriate game state function to check if the command is valid
    // and save any error message in the Command object's effect.
    if (getName(cmd) == "validatemap")
    {
        if (GameEngine::currentState == "maploaded")
        {
            cmd.saveEffect("Command executed successfully.");
            cout << "Effect: " << getEffectString(cmd) << std::endl;
        } else {
            cout << "Wrong state" << endl;
        }
    }
    else if (getName(cmd) == "gamestart")
    {
        if (GameEngine::currentState == "playersadded")
        {
            cmd.saveEffect("Command executed successfully.");
            std::cout << "Effect: " << getEffectString(cmd) << std::endl;
        } else {
            cout << "Wrong state" << endl;
        }
    }
    else if (getName(cmd) == "replay")
    {
        if (GameEngine::currentState == "win")
        {
            cmd.saveEffect("Command executed successfully.");
            std::cout << "Effect: " << getEffectString(cmd) << std::endl;
        } else {
            cout << "Wrong state" << endl;
        }
    }
    else if (getName(cmd) == "quit")
    {
        if (GameEngine::currentState == "win")
        {
            cmd.saveEffect("Command executed successfully.");
            std::cout << "Effect: " << getEffectString(cmd) << std::endl;
        } else {
            cout << "Wrong state" << endl;
        }
    }
    else if (getName(cmd) == "addplayer")
    {
        if (GameEngine::currentState == "mapvalidated" || GameEngine::currentState == "playersadded")
        {
            cmd.saveEffect("Command executed successfully.");
            std::cout << "Effect: " << getEffectString(cmd) << std::endl;
        } else {
            cout << "Wrong state" << endl;
        }
    }
    else if (getName(cmd) == "loadmap")
    {
        if (GameEngine::currentState == "start" || GameEngine::currentState == "maploaded")
        {
            cmd.saveEffect("Command executed successfully.");
            std::cout << "Effect: " << getEffectString(cmd) << std::endl;
        } else {
            cout << "Wrong state" << endl;
        }
    }
}

ifstream fileStream;

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const string &fileName)
{
    fileStream.open(fileName);
    if (!fileStream.is_open())
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }
}

void FileCommandProcessorAdapter::processCommands()
{
    std::string line;
    while (std::getline(fileStream, line))
    {
        Command cmd(line);
        validate(cmd);
        std::cout << "Command: " << getName(cmd) << std::endl;
        std::cout << "Effect: " << getEffectString(cmd) << std::endl;
    }
    fileStream.close();
}