#include "GameEngine.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

class Command {
private:
    string commandString;
    string name;

public:
    Command();
    string effectString;
    void outputCommand(const Command& cmd);
    string getName(Command cmd);
    Command(const string name);
    void saveEffect(const std::string& effStr);
};



class CommandProcessor : public Command {
private:
    vector<Command> commands;
    string readCommand();
    void saveCommand(const std::string& cmdStr);

public:
    //std::vector<std::string> getEffects(const Command& cmd);
    void outputCommand(const Command& cmd);
    CommandProcessor();
    void validate(Command cmd);
    Command getCommand();
    string getEffectString(Command& cmd) const;
};



class FileCommandProcessorAdapter : public CommandProcessor {
public:
    FileCommandProcessorAdapter(const string& fileName);
    void processCommands();

private:
    ifstream fileStream;
};

#endif