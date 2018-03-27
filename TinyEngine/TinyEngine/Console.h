#pragma once
#include <string>

class idConsole
{
public:
	
	virtual void	Init(void) = 0;
	virtual void	Shutdown(void) = 0;

	virtual bool	ProcessEvent(const std::string & Cmd) const = 0;

};

