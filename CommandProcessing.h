#pragma once

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Command {
private:
    std::string commandString;
    vector<string> effectString;
    string name;

public:
    void outputCommand(const Command& cmd);
    string getName();
    Command(const std::string& name);
    std::string getCommandString() const;
    void saveEffect(const std::string& effStr);
    std::string getEffectString() const;
};

class CommandProcessor {
private:
    std::vector<Command> commands;

    std::string readCommand();
    void saveCommand(const std::string& cmdStr);

public:
    std::string getName(const Command& cmd);
    std::vector<std::string> getEffects(const Command& cmd);
    void outputCommand(const Command& cmd);
    CommandProcessor();
    void validate(Command cmd);
    Command getCommand();
};

class FileCommandProcessorAdapter {
private:
    std::vector<Command> commands;
    std::string filename;
    std::ifstream inputFileStream;

    std::string readCommandFromFile();
    void saveCommand(const std::string& cmdStr);

public:
    FileCommandProcessorAdapter(const std::string& filename);
    void validate();
    Command getCommand();
};
