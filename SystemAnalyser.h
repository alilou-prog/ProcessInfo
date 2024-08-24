#ifndef __SYSTEM_ANALYSER_H__
#define __SYSTEM_ANALYSER_H__
#include <string>
class SystemAnalyser 
{
	public: 
		SystemAnalyser();
		virtual void RunCommand(const char * command);
		virtual void DisplayOutput() const;
		virtual ~SystemAnalyser();
	private:
		std::string outputStore;
		void StoreOutput(std::string result);
};
#endif
