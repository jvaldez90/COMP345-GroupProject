#include "CommandProcessing.h"

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

std::string CommandProcessor::readCommand() {
    string input;
    cout << "Enter a command: ";
    cin >> input;
    saveCommand(input);
    return input;
}

void CommandProcessor::saveCommand(string name) {
    Command cmd;
    cmd.command = name;
    commands.push_back(cmd);
}

//void CommandProcessor::executeCommand() {
//    Command cmd = getCommand();
//    // Execute command
//    cmd.effect = "Command executed successfully.";
//}

// TODO: Implement the actual validate method following the valid commands list
void CommandProcessor::validate() {
    Command cmd = getCommand();
    // Validate command


    cmd.effect = "Command is valid.";
}

Command CommandProcessor::getCommand() {
    if (commands.empty()) {
        Command cmd;
        cmd.command = "";
        cmd.effect = "";
        cout << "Commands list is empty" << endl;
        return cmd;
    }
    Command cmd = commands.front();
    commands.erase(commands.begin());
    return cmd;
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(string filename) {
    file.open(filename);
    eof = false;
}

std::string FileCommandProcessorAdapter::readCommand() {
    if (!eof && commands.empty()) {
        readNextCommand();
    }
    return CommandProcessor::readCommand();
}

void FileCommandProcessorAdapter::readNextCommand() {
    std::string input;
    if (std::getline(file, input)) {
        saveCommand(input);
    } else {
        eof = true;
    }
}
