#pragma once
#include <string>
#include <vector>

class CmdArgs
{
public:
	CmdArgs();
	CmdArgs( const std::string & );

	void operator=(const CmdArgs & other);

	// Returns the number of arguments
	int Argc() const;

	void AppendArg( const std::string & );
	void Clear();

	const std::string & GetArg(int idx);


private:
	static const int MAX_COMMAND_ARGS = 16;
	
	int ArgCount = 0;
	std::vector<std::string> Args;

};

