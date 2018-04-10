#include "stdafx.h"
#include "Console.h"
#include <map>
#include <SDL_ttf.h>
#include <SDL_image.h>

class ConsoleLocal : public Console
{
public:
	virtual void		Init(void);
	virtual void		Shutdown(void);

	virtual void		Draw(bool forceFullScreen);
	virtual void		Print(const char *text);

};

static ConsoleLocal localConsole;
Console	*console = &localConsole;