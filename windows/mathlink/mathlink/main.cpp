#include "wstp.h"

extern int WSMain(int, char **);
#ifdef WINDOWS_WSTP
extern HWND WSInitializeIcon( HINSTANCE hinstCurrent, int nCmdShow);
#endif


#if WINDOWS_WSTP

int PASCAL WinMain( HINSTANCE hinstCurrent, HINSTANCE hinstPrevious, LPSTR lpszCmdLine, int nCmdShow)
{
	char  buff[512];
	char FAR * buff_start = buff;
	char FAR * argv[32];
	char FAR * FAR * argv_end = argv + 32;

	hinstPrevious = hinstPrevious; /* suppress warning */

	if( !WSInitializeIcon( hinstCurrent, nCmdShow)) return 1;
	WSScanString( argv, &argv_end, &lpszCmdLine, &buff_start);
	return WSMain( (int)(argv_end - argv), argv);
}

#else

int main(int argc, char* argv[])
{
	return WSMain(argc, argv);
}

#endif
