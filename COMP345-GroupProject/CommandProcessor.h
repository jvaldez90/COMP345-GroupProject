#include "GameEngine.h"
#include "LoggingObserver.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

class Command : public Subject, public ILoggable
{
private:
    string commandString;
    string name;

public:
    Command();
    string effectString;
    bool hasArgument(string arg) const;
    void outputCommand(const Command &cmd);
    string getName(Command cmd);
    Command(const string name);
    void saveEffect(const std::string &effStr);
    string getEffectString(Command &cmd) const;
    void Notify(ILoggable *) override;
    string stringToLog() override;
};

class CommandProcessor : public Command
{
private:
    vector<Command> commands;
    string readCommand();
    void saveCommand(const std::string &cmdStr);

public:
    // std::vector<std::string> getEffects(const Command& cmd);
    // void outputCommand(const Command& cmd);
    CommandProcessor();
    void validate(Command cmd);
    Command getCommand();
    bool CommandProcessor::isValidTournamentCommand(Command cmd);
    void Notify(ILoggable *) override;
    string stringToLog() override;
};

class FileCommandProcessorAdapter : public CommandProcessor
{
public:
    FileCommandProcessorAdapter(const string &fileName);
    void processCommands();
    void Notify(ILoggable *) override;
    string stringToLog() override;

private:
    ifstream fileStream;
};

#endif
