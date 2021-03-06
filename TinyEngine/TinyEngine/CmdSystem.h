#pragma once
#include <string>
#include <map>
#include "CmdArgs.h"

typedef void(*CommandFunction)(const CmdArgs &args);

class CmdSystem
{
public:

	virtual void	Init() = 0;
	virtual void	Shutdown() = 0;

	virtual bool	ProcessCommand(const std::string & Cmd) const = 0;

	virtual bool	AddCommand(const std::string & Cmd, CommandFunction CmdFunction, const std::string & Description) = 0;
	virtual bool	RemoveCommand(const std::string & Cmd) = 0;	
	
};

extern CmdSystem *	cmdSystem; // statically initialized as an CmdSystemLocal
