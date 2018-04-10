#include "stdafx.h"
#include "CmdArgs.h"


CmdArgs::CmdArgs(){}

CmdArgs::CmdArgs(const std::string & arg)
{
	AppendArg(arg);
}

void CmdArgs::operator=(const CmdArgs & other)
{
	Clear();
	ArgCount = other.Argc();
	auto argIter = Args.begin();

	int i = 0;
	while (argIter != Args.end())
	{
		AppendArg(*argIter);
		i++;
	}

}

int CmdArgs::Argc() const
{
	return ArgCount;
}

void CmdArgs::AppendArg(const std::string & arg)
{
	ArgCount++;
	Args.push_back(arg);
}

void CmdArgs::Clear()
{
	ArgCount = 0;
	Args.clear();
}

const std::string & CmdArgs::GetArg(int idx)
{
	return Args[idx];
}




