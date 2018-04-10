#include "stdafx.h"
#include "CmdSystem.h"

#include <iostream>
#include <cassert>

typedef void(*CommandFunction)(const CmdArgs &args);

struct CommandDefinition
{
	std::string Command = "";
	CommandFunction Function = nullptr;
	std::string Description = "";
};


typedef std::map<std::string, CommandDefinition>					_CmdMap;
typedef std::map<std::string, CommandDefinition>::const_iterator	_CmdMapIter;


class CmdSystemLocal : public CmdSystem
{
public:

	virtual void		Init();
	virtual void		Shutdown();

	virtual	bool		ProcessCommand(const std::string & Cmd) const;

	// FullCmd stands for command plus args
	virtual bool		AddCommand(const std::string & Cmd, CommandFunction, const std::string & Description);
	virtual bool		RemoveCommand(const std::string & Cmd);

	_CmdMapIter			GetCommandsIterBegin() const;
	_CmdMapIter			GetCommandsIterEnd() const;

private:

	// Tokenize creates a Vector with the command name as the first element and the args as the remaining
	virtual std::vector<std::string>	Tokenize(const std::string & Cmd) const;

	// Functions connected to Console commands
	static void				ListCmds_f(const CmdArgs &args);

	static void				CommandNotFound_f();

	

	_CmdMap				Commands;
};

CmdSystemLocal			cmdSystemLocal;
CmdSystem *				cmdSystem = &cmdSystemLocal;

//======= INTERFACE =======//

void CmdSystemLocal::Init()
{	
	AddCommand("listCmds", ListCmds_f, "Lists commands");

}

void CmdSystemLocal::Shutdown()
{
	Commands.clear();
}

bool CmdSystemLocal::ProcessCommand(const std::string & Cmd) const
{
	std::vector<std::string> TokenizedCmd = Tokenize(Cmd);

	_CmdMapIter CmdIter = Commands.find(TokenizedCmd[0]);

	if (CmdIter != Commands.end())
	{

		CmdArgs Args;

		// Iterator parsing the Args
		auto ArgsIter = TokenizedCmd.begin();
		ArgsIter++;

		// Fills the Args
		for (auto iter = ArgsIter; iter != TokenizedCmd.end(); iter++)
		{
			Args.AppendArg(*iter);
		}
		
		CmdIter->second.Function(Args);
	}
	else
	{
		CommandNotFound_f();
	}

	return false;
}

bool CmdSystemLocal::AddCommand(const std::string & CmdName, CommandFunction Func, const std::string & Description)
{
	
	CommandDefinition Cmd{CmdName, Func, Description};
	std::pair<_CmdMapIter, bool> ret = Commands.insert({ CmdName, Cmd });

	return ret.second;
}

bool CmdSystemLocal::RemoveCommand(const std::string & Cmd)
{
	return Commands.erase(Cmd);
}

_CmdMapIter CmdSystemLocal::GetCommandsIterBegin() const
{
	return Commands.begin();
}

_CmdMapIter CmdSystemLocal::GetCommandsIterEnd() const
{
	return Commands.end();
}

//======= UTILITY FUNCTIONS =======//

std::vector<std::string> CmdSystemLocal::Tokenize(const std::string & Cmd) const
{
	std::vector<std::string> TokenizedCmd;
	char Delimeter = ' ';

	unsigned int PrevDelPos = 0;
	unsigned int DelPos = 0;

	std::string::const_iterator CmdIter = Cmd.begin();

	while (CmdIter != Cmd.end())
	{
		if (*CmdIter == Delimeter)
		{
			TokenizedCmd.push_back(Cmd.substr(PrevDelPos, DelPos - PrevDelPos));
			PrevDelPos = DelPos;

			// DEBUG
			std::cout << "CMD TOKENIZED AS: " << Cmd.substr(PrevDelPos, DelPos - PrevDelPos) << std::endl;			
		}

		++CmdIter;
		++DelPos;
	}

	return TokenizedCmd;
}

//======= COMMANDS FUNCTIONS =======//

void CmdSystemLocal::ListCmds_f(const CmdArgs & args)
{
}

void CmdSystemLocal::CommandNotFound_f()
{
}


