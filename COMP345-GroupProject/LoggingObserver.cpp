#include "LoggingObserver.h"

LogObserver::LogObserver() {}

LogObserver::LogObserver(LogObserver &logObserver)
{
}

std::ostream &operator<<(std::ostream &out, const LogObserver *logObserver)
{
    out << "This is the assignment operator for LogObserver.\n";
    return out;
}

LogObserver &LogObserver::operator=(const LogObserver &logObserver)
{
    return *this;
}

void LogObserver::Update(ILoggable *logObserver)
{
    std::string s = logObserver->stringToLog();
    std::ofstream file("gamelog.txt", std::fstream::app);
    if (file.is_open())
    {
        file << s;
        std::cout << "Welcome!" << std::endl;
    }
    else
    {
        std::cout << "Cannot access file gamelog.txt" << std::endl;
    }
    file.close();
}
