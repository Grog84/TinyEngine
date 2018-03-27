#include "stdafx.h"
#include "Console.h"
#include <map>

typedef void(*CommandFunction)();

struct CommandDefinition
{
	std::string Command			= "";
	std::string Description		= "";
	CommandFunction Function    = nullptr;

};

typedef std::map<std::string, CommandDefinition>					_CmdMap;
typedef std::map<std::string, CommandDefinition>::const_iterator	_CmdMapIter;

class idConsoleLocal : public idConsole
{
public:
	virtual	void		Init(void);
	virtual void		Shutdown(void);
	virtual	bool		ProcessEvent(const std::string & Cmd) const;

	_CmdMapIter			GetCommandsIterBegin() const;
	_CmdMapIter			GetCommandsIterEnd() const;

private:
	bool				AddCommand(const std::string & Cmd, void(*Function)(), const std::string & Description);
	
	// Commands Definition
	void				ListCommands();


	_CmdMap				Commands;
};