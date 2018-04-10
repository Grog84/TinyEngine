#pragma once

class Console
{
public:
	
	virtual void	Init(void) = 0;
	virtual void	Shutdown(void) = 0;

	virtual void	Draw(bool forceFullScreen) = 0;
	virtual void	Print(const char *text) = 0;

};

extern Console * console;  // statically initialized as an idConsoleLocal
