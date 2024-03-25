#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Logger
{
public:
    static void Log(const string &massage)
    {
        validate(massage);
        cout << massage << endl;
    }
    static void LogToFile(const string &massage)
    {
        ofstream MyFile("filename.txt");
        MyFile<<massage;
    }

private:
    static void validate(const string &massage)
    {
        if (massage.length() == 0)
            throw invalid_argument("massage is empty.");

        for (char i : massage)
        {
            if ((i < 'a' && i > 'z') && i != ' ')
                throw invalid_argument("massage contains invalid symbols.");
        }
    }
};



int main()
{
    Logger::Log("something is good thing");
    Logger::LogToFile("something is good thing");
}