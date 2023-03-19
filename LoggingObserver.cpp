// LoggingObserver.cpp
#include "LoggingObserver.h"
#include <fstream>
#include <iostream>

void Subject::attach(Observer *observer)
{
    observers.push_back(observer);
}

void Subject::detach(Observer *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify()
{
    for (Observer *observer : observers)
    {
        observer->update(this);
    }
}

LogObserver::LogObserver() : logFileName("gamelog.txt") {}

void LogObserver::update(Subject *subject)
{
    ILoggable *loggable = dynamic_cast<ILoggable *>(subject);
    if (loggable)
    {
        writeToLogFile(loggable->stringToLog());
    }
}

void LogObserver::writeToLogFile(const std::string &logText)
{
    std::ofstream logFile;
    logFile.open(logFileName, std::ios_base::app);
    logFile << logText << std::endl;
    logFile.close();
}
