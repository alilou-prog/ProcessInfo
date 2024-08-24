// ProcessInfo class header file
// This class displays the running processes in the machine
#ifndef PROCESS_INFO
#define PROCESS_INFO

#include "SystemAnalyser.h"
#include <string>

class ProcessInfo {

    public:
    void display(const std::string& arguments) noexcept(false);
    
    // print the possible HEADERS SPECIFIERS as arguments to display
    std::string help() const;

    private:
    SystemAnalyser m_systemAnalyser;
    
    // evaluate the argument given to display()
    bool evaluateArguments(const std::string&) const;
};
#endif