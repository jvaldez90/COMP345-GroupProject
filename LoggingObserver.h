// LoggingObserver.h
#pragma once

#include <string>
#include <vector>

class Subject;

class Observer
{
public:
    virtual void update(Subject *subject) = 0;
};

class Subject
{
public:
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify();

private:
    std::vector<Observer *> observers;
};

class ILoggable
{
public:
    virtual std::string stringToLog() const = 0;
};

class LogObserver : public Observer
{
public:
    LogObserver();
    void update(Subject *subject) override;
    void writeToLogFile(const std::string &logText);

private:
    std::string logFileName;
};
