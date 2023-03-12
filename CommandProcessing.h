#pragma once


#include <string>
#include <vector>
#include <fstream>
using namespace std;


class Command {
public:
    string command;
    string effect;
};

class CommandProcessor {

public:
    Command getCommand();
    void saveEffect(string name);
    void validate();
    vector<Command> commands;

private:
    string readCommand();
    void saveCommand(string name);
};

class FileCommandProcessorAdapter : public CommandProcessor {
private:
    ifstream file;
    bool eof;

    void readNextCommand();
public:
    FileCommandProcessorAdapter(string filename);
    string readCommand();
};

