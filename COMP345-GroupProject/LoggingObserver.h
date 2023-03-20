#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class ILoggable;

class ILoggable
{
public:
    virtual std::string stringToLog() = 0;
};

class Subject
{
public:
    virtual void Notify(ILoggable *) = 0;
};

class Observer
{
public:
    virtual void Update(ILoggable *) = 0;
};

class LogObserver : public Observer
{
public:
    LogObserver();
    LogObserver(LogObserver &);
    void Update(ILoggable *) override;
    friend std::ostream &operator<<(std::ostream &, const LogObserver *);
    LogObserver &operator=(const LogObserver &);
};
