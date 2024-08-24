
#include "ProcessInfo.h"
#include <iostream>
#include <sstream>

#include <stdexcept>
#include <regex>
using namespace std;

void ProcessInfo::display(const string& arguments)
{
    if(evaluateArguments(arguments))
    {
        const string command = "ps -eo " + arguments; 
        m_systemAnalyser.RunCommand(command.data());
        m_systemAnalyser.DisplayOutput();
    }
    else
    {
        throw invalid_argument("ProcessInfo::display() :"
        "invalid arguments given to ps");
    }
}

string ProcessInfo::help() const 
{
    ostringstream out;
    out << "Usage: ProcessInfo::diplay(arguments)\n"
        << "arguments= PATTERN, PATTERN, ....\n"
        << "PATTERN = (args|cmd|comm|pid|ppid|tty),\n"
        << endl;

    return out.str();
}

// use regulat expression to validate arguments
bool ProcessInfo::evaluateArguments(const string& arguments) const
{
    // each group contains three letter and a comma, except the last one
    regex re("((args|cmd|comm|pid|ppid|tty),)*"
        "((args|cmd|comm|pid|ppid|tty))",
        std::regex_constants::extended); 

    if (regex_match(arguments, re))
        return true;
    else
        return false;
}