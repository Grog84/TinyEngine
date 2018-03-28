#pragma once
#include <string>

typedef void(*CommandFunction)();

struct CommandDefinition
{
	std::string Command = "";
	std::string Description = "";
	CommandFunction Function = nullptr;

};

typedef std::map<std::string, CommandDefinition>					_CmdMap;
typedef std::map<std::string, CommandDefinition>::const_iterator	_CmdMapIter;

class idConsole
{
public:
	
	virtual void	Init(void) = 0;
	virtual void	Shutdown(void) = 0;

	virtual bool	ProcessEvent(const std::string & Cmd) const = 0;
	virtual bool	AddCommand(const std::string & Cmd, void(*Function)(), const std::string & Description);
	virtual bool	RemoveCommand(const std::string & Cmd);
};

