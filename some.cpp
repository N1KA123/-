#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class LogLevel
{
    INFO,
    WARNING,
    ERROR
};

class Logger
{
public:
    static void Log(const string &message, LogLevel level = LogLevel::INFO)
    {
        validate(message);
        cout << "[" << levelToString(level) << "] " << message << endl;
    }

    static void LogToFile(const string &message, LogLevel level = LogLevel::INFO)
    {
        ofstream MyFile("filename.txt", ios_base::app);
        MyFile << "[" << levelToString(level) << "] " << message << endl;
    }

private:
    static void validate(const string &message)
    {
        if (message.empty())
            throw invalid_argument("Message is empty.");

        for (char i : message)
        {
            if (!((i >= 'a' && i <= 'z') || i == ' '))
                throw invalid_argument("Message contains invalid symbols.");
        }
    }

    static string levelToString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
        }
    }
};

int main()
{
    Logger::Log("Something good happened.", LogLevel::INFO);
    Logger::LogToFile("Something good happened.", LogLevel::INFO);
    Logger::Log("Something suspicious happened.", LogLevel::WARNING);
    Logger::LogToFile("Something suspicious happened.", LogLevel::WARNING);
    Logger::Log("An error occurred.", LogLevel::ERROR);
    Logger::LogToFile("An error occurred.", LogLevel::ERROR);
}
