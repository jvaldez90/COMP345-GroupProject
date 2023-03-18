#include "CommandProcessing.h"
#include "GameEngine.h"

#include <iostream>
#include <sstream>
#include <regex>
#include <vector>
#include <fstream>
using namespace std;

CommandProcessor::CommandProcessor() {}


std::string CommandProcessor::readCommand() {
    std::string cmdStr;
    std::cout << "Enter command: ";
    std::getline(std::cin, cmdStr);
    return cmdStr;
}

string outputCommand(Command cmd) {
    //cout << "Command: " << cmd.getName() << endl;
    return cmd.getName();
}

void Command::saveEffect(const std::string& effect) {
    effectString.push_back(effect);
}

void CommandProcessor::saveCommand(const std::string& cmdStr) {
    Command cmd(cmdStr);
    commands.push_back(cmd);
}

void CommandProcessor::validate(Command cmd) {
    // Call the appropriate game state function to check if the command is valid
    // and save any error message in the Command object's effect.

    if (cmd.getName().compare(GameEngine::command)) {
        if (cmd.getName() == "validatemap") {
            if (GameEngine::command == "maploaded") {
                cmd.saveEffect("Command executed successfully.");
                std::cout << "Effect: " << cmd.getEffectString() << std::endl;
            }
        } else if (cmd.getName() == "gamestart") {
            if (GameEngine::command == "playersadded") {
                cmd.saveEffect("Command executed successfully.");
                std::cout << "Effect: " << cmd.getEffectString() << std::endl;
            }
        } else if (cmd.getName() == "replay") {
            if (GameEngine::command == "win") {
                cmd.saveEffect("Command executed successfully.");
                std::cout << "Effect: " << cmd.getEffectString() << std::endl;
            }
        } else if (cmd.getName() == "quit") {
            if (GameEngine::command == "win") {
                cmd.saveEffect("Command executed successfully.");
                std::cout << "Effect: " << cmd.getEffectString() << std::endl;
            }
        } else if (cmd.getName() == "addplayer") {
            if (GameEngine::command == "mapvalidated" || GameEngine::command == "playersadded") {
                cmd.saveEffect("Command executed successfully.");
                std::cout << "Effect: " << cmd.getEffectString() << std::endl;
            }
        } else if (cmd.getName() == "loadmap") {
            if (GameEngine::command == "start" || GameEngine::command == "maploaded") {
                cmd.saveEffect("Command executed successfully.");
                std::cout << "Effect: " << cmd.getEffectString() << std::endl;
            }
        }

    }


}


Command CommandProcessor::getCommand() {
    std::string cmdStr = readCommand();
    saveCommand(cmdStr);
    return commands.back();
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const std::string& filename) :
        filename(filename), inputFileStream(filename) {
    if (!inputFileStream.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
    }
}

std::string FileCommandProcessorAdapter::readCommandFromFile() {
    std::string cmdStr;
    std::getline(inputFileStream, cmdStr);
    return cmdStr;
}

void FileCommandProcessorAdapter::saveCommand(const std::string& cmdStr) {
    Command cmd(cmdStr);
    commands.push_back(cmd);
}

void FileCommandProcessorAdapter::validate() {
    // Call the appropriate game state function to check if the command is valid
    // and save any error message in the Command object's effect.
}

Command FileCommandProcessorAdapter::getCommand() {
    std::string cmdStr = readCommandFromFile();
    saveCommand(cmdStr);
    return commands.back();
}

Command::Command(const std::string& cmdStr) : commandString(cmdStr) {}

std::string Command::getCommandString() const {
    return commandString;
}

