#include "stdafx.h"
#include "Console.h"
#include <map>

class idConsoleLocal : public idConsole
{
public:
	virtual	void		Init(void);
	virtual void		Shutdown(void);


	virtual	bool		ProcessCommand(const std::string & Cmd) const;
	virtual bool		AddCommand(const std::string & Cmd, void(*Function)(), const std::string & Description);

	_CmdMapIter			GetCommandsIterBegin() const;
	_CmdMapIter			GetCommandsIterEnd() const;

private:
	void				ListCommands();

	//============================

	_CmdMap				Commands;
};