#include <iostream>
#include <array>
#include <memory>
#include "SystemAnalyser.h"

SystemAnalyser::SystemAnalyser()
{
}

void SystemAnalyser::RunCommand(const char * command)
{
	std::array<char, 128> buffer;
	std::string result;
	
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}

	StoreOutput(result);
}

void SystemAnalyser::StoreOutput(std::string result)
{
	outputStore = result;
}

void SystemAnalyser::DisplayOutput() const
{
	std::cout << outputStore << std::endl;
}

SystemAnalyser::~SystemAnalyser()
{
}
