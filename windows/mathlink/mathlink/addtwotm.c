/*
 * This file automatically produced by c:\Users\T-000\source\repos\mathlink\mathlink\Resources\wsprep.exe from:
 *	addtwo.tm
 * wsprep Revision 19 Copyright (c) Wolfram Research, Inc. 1990-2019
 */

#define WSPREP_REVISION 19


#include "wstp.h"

int WSAbort = 0;
int WSDone  = 0;
long WSSpecialCharacter = '\0';
HANDLE WSInstance = (HANDLE)0;
HWND WSIconWindow = (HWND)0;

WSLINK stdlink = 0;
WSEnvironment stdenv = 0;
WSYieldFunctionObject stdyielder = (WSYieldFunctionObject)0;
WSMessageHandlerObject stdhandler = (WSMessageHandlerObject)0;

extern int WSDoCallPacket(WSLINK);
extern int WSEvaluate( WSLINK, char *);
extern int WSEvaluateString P(( WSLINK, char *));

#include <windows.h>

#if defined(__GNUC__)

#	ifdef TCHAR
#		undef TCHAR
#	endif
#	define TCHAR char

#	ifdef PTCHAR
#		undef PTCHAR
#	endif
#	define PTCHAR char *

#	ifdef __TEXT
#		undef __TEXT
#	endif
#	define __TEXT(arg) arg

#	ifdef _tcsrchr
#		undef _tcsrchr
#	endif
#	define _tcsrchr strrchr

#	ifdef _tcscat
#		undef _tcscat
#	endif
#	define _tcscat strcat

#	ifdef _tcsncpy
#		undef _tcsncpy
#	endif
#	define _tcsncpy _fstrncpy
#else
#	include <tchar.h>
#endif

#include <stdlib.h>
#include <string.h>
#if (WIN32_MATHLINK || WIN64_MATHLINK || __GNUC__) && !defined(_fstrncpy)
#       define _fstrncpy strncpy
#endif

#ifndef CALLBACK
#define CALLBACK FAR PASCAL
typedef LONG LRESULT;
typedef unsigned int UINT;
typedef WORD WPARAM;
typedef DWORD LPARAM;
#endif


LRESULT CALLBACK WSEXPORT
IconProcedure( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WSEXPORT
IconProcedure( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg){
	case WM_CLOSE:
		WSDone = 1;
		WSAbort = 1;
		break;
	case WM_QUERYOPEN:
		return 0;
	}
	return DefWindowProc( hWnd, msg, wParam, lParam);
}


#ifdef _UNICODE
#define _APISTR(i) L ## #i
#else
#define _APISTR(i) #i
#endif

#define APISTR(i) _APISTR(i)

HWND WSInitializeIcon( HINSTANCE hInstance, int nCmdShow)
{
	TCHAR path_name[260];
	PTCHAR icon_name;

	WNDCLASS  wc;
	HMODULE hdll;

	WSInstance = hInstance;
	if( ! nCmdShow) return (HWND)0;

	hdll = GetModuleHandle( __TEXT("wstp32i" APISTR(WSINTERFACE)));

	(void)GetModuleFileName( hInstance, path_name, 260);

	icon_name = _tcsrchr( path_name, '\\') + 1;
	*_tcsrchr( icon_name, '.') = '\0';


	wc.style = 0;
	wc.lpfnWndProc = IconProcedure;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;

	if( hdll)
		wc.hIcon = LoadIcon( hdll, __TEXT("WSIcon"));
	else
		wc.hIcon = LoadIcon( NULL, IDI_APPLICATION);

	wc.hCursor = LoadCursor( NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)( COLOR_WINDOW + 1);
	wc.lpszMenuName =  NULL;
	wc.lpszClassName = __TEXT("mprepIcon");
	(void)RegisterClass( &wc);

	WSIconWindow = CreateWindow( __TEXT("mprepIcon"), icon_name,
			WS_OVERLAPPEDWINDOW | WS_MINIMIZE, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			(HWND)0, (HMENU)0, hInstance, (void FAR*)0);

	if( WSIconWindow){
		ShowWindow( WSIconWindow, SW_MINIMIZE);
		UpdateWindow( WSIconWindow);
	}
	return WSIconWindow;
}

WSYDEFN( int, WSDefaultYielder, ( WSLINK wslp, WSYieldParameters yp))
{
	MSG msg;
	wslp = wslp; /* suppress unused warning */
	yp = yp; /* suppress unused warning */

	if( PeekMessage( &msg, (HWND)0, 0, 0, PM_REMOVE)){
		TranslateMessage( &msg);
		DispatchMessage( &msg);
	}
	return WSDone;
}


/********************************* end header *********************************/


int addtwo P(( int _tp1, int _tp2));

static int _tr0( WSLINK wslp)
{
	int	res = 0;
	int _tp1;
	int _tp2;
	int _rp0;
	if ( ! WSGetInteger( wslp, &_tp1) ) goto L0;
	if ( ! WSGetInteger( wslp, &_tp2) ) goto L1;
	if ( ! WSNewPacket(wslp) ) goto L2;

	_rp0 = addtwo(_tp1, _tp2);

	res = WSAbort ?
		WSPutFunction( wslp, "Abort", 0) : WSPutInteger( wslp, _rp0);
L2: L1: 
L0:	return res;
} /* _tr0 */


int addList P(( int * _tp1, long _tpl1, int _tp2, int _tp3));

static int _tr1( WSLINK wslp)
{
	int	res = 0;
	int * _tp1;
	long _tpl1;
	int _tp2;
	int _tp3;
	int _rp0;
	if ( ! WSGetIntegerList( wslp, &_tp1, &_tpl1) ) goto L0;
	if ( ! WSGetInteger( wslp, &_tp2) ) goto L1;
	if ( ! WSGetInteger( wslp, &_tp3) ) goto L2;
	if ( ! WSNewPacket(wslp) ) goto L3;

	_rp0 = addList(_tp1, _tpl1, _tp2, _tp3);

	res = WSAbort ?
		WSPutFunction( wslp, "Abort", 0) : WSPutInteger( wslp, _rp0);
L3: L2: L1:	WSReleaseInteger32List( wslp, _tp1, _tpl1);

L0:	return res;
} /* _tr1 */


static struct func {
	int   f_nargs;
	int   manual;
	int   (*f_func)P((WSLINK));
	const char  *f_name;
	} _tramps[2] = {
		{ 2, 0, _tr0, "addtwo" },
		{ 3, 0, _tr1, "addList" }
		};

static const char* evalstrs[] = {
	"AddTwo::usage = \"AddTwo[x, y] gives the sum of two machine integ",
	"ers x and y.\"",
	(const char*)0,
	(const char*)0
};
#define CARDOF_EVALSTRS 1

static int _definepattern P(( WSLINK, char*, char*, int));

static int _doevalstr P(( WSLINK, int));

int  _WSDoCallPacket P(( WSLINK, struct func[], int));


int WSInstall( WSLINK wslp)
{
	int _res;
	_res = WSConnect(wslp);
	if (_res) _res = _definepattern(wslp, (char *)"AddTwo[i_Integer, j_Integer]", (char *)"{ i, j }", 0);
	if (_res) _res = _doevalstr( wslp, 0);
	if (_res) _res = _definepattern(wslp, (char *)"AddList[i_List,j_Integer,k_Integer]", (char *)"{i,j,k}", 1);
	if (_res) _res = WSPutSymbol( wslp, "End");
	if (_res) _res = WSFlush( wslp);
	return _res;
} /* WSInstall */


int WSDoCallPacket( WSLINK wslp)
{
	return _WSDoCallPacket( wslp, _tramps, 2);
} /* WSDoCallPacket */

/******************************* begin trailer ********************************/

#ifndef EVALSTRS_AS_BYTESTRINGS
#	define EVALSTRS_AS_BYTESTRINGS 1
#endif

#if CARDOF_EVALSTRS
static int  _doevalstr( WSLINK wslp, int n)
{
	long bytesleft, charsleft, bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
	long charsnow;
#endif
	char **s, **p;
	char *t;

	s = (char **)evalstrs;
	while( n-- > 0){
		if( *s == 0) break;
		while( *s++ != 0){}
	}
	if( *s == 0) return 0;
	bytesleft = 0;
	charsleft = 0;
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = (long)(t - *p);
		bytesleft += bytesnow;
		charsleft += bytesnow;
#if !EVALSTRS_AS_BYTESTRINGS
		t = *p;
		charsleft -= WSCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
#endif
		++p;
	}


	WSPutNext( wslp, WSTKSTR);
#if EVALSTRS_AS_BYTESTRINGS
	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = (long)(t - *p);
		bytesleft -= bytesnow;
		WSPut8BitCharacters( wslp, bytesleft, (unsigned char*)*p, bytesnow);
		++p;
	}
#else
	WSPut7BitCount( wslp, (long_st)charsleft, (long_st)bytesleft);

	p = s;
	while( *p){
		t = *p; while( *t) ++t;
		bytesnow = t - *p;
		bytesleft -= bytesnow;
		t = *p;
		charsnow = bytesnow - WSCharacterOffset( &t, t + bytesnow, bytesnow);
		/* assert( t == *p + bytesnow); */
		charsleft -= charsnow;
		WSPut7BitCharacters(  wslp, charsleft, *p, bytesnow, charsnow);
		++p;
	}
#endif
	return WSError( wslp) == WSEOK;
}
#endif /* CARDOF_EVALSTRS */


static int  _definepattern( WSLINK wslp, char *patt, char *args, int func_n)
{
	WSPutFunction( wslp, "DefineExternal", (long)3);
	  WSPutString( wslp, patt);
	  WSPutString( wslp, args);
	  WSPutInteger( wslp, func_n);
	return !WSError(wslp);
} /* _definepattern */


int _WSDoCallPacket( WSLINK wslp, struct func functable[], int nfuncs)
{
	int len;
	int n, res = 0;
	struct func* funcp;

	if( ! WSGetInteger( wslp, &n) ||  n < 0 ||  n >= nfuncs) goto L0;
	funcp = &functable[n];

	if( funcp->f_nargs >= 0
	&& ( ! WSTestHead(wslp, "List", &len)
	     || ( !funcp->manual && (len != funcp->f_nargs))
	     || (  funcp->manual && (len <  funcp->f_nargs))
	   )
	) goto L0;

	stdlink = wslp;
	res = (*funcp->f_func)( wslp);

L0:	if( res == 0)
		res = WSClearError( wslp) && WSPutSymbol( wslp, "$Failed");
	return res && WSEndPacket( wslp) && WSNewPacket( wslp);
} /* _WSDoCallPacket */


wsapi_packet WSAnswer( WSLINK wslp)
{
	wsapi_packet pkt = 0;
	int waitResult;

	while( ! WSDone && ! WSError(wslp)
		&& (waitResult = WSWaitForLinkActivity(wslp),waitResult) &&
		waitResult == WSWAITSUCCESS && (pkt = WSNextPacket(wslp), pkt) &&
		pkt == CALLPKT)
	{
		WSAbort = 0;
		if(! WSDoCallPacket(wslp))
			pkt = 0;
	}
	WSAbort = 0;
	return pkt;
}



/*
	Module[ { me = $ParentLink},
		$ParentLink = contents of RESUMEPKT;
		Message[ MessageName[$ParentLink, "notfe"], me];
		me]
*/

static int refuse_to_be_a_frontend( WSLINK wslp)
{
	int pkt;

	WSPutFunction( wslp, "EvaluatePacket", 1);
	  WSPutFunction( wslp, "Module", 2);
	    WSPutFunction( wslp, "List", 1);
		  WSPutFunction( wslp, "Set", 2);
		    WSPutSymbol( wslp, "me");
	        WSPutSymbol( wslp, "$ParentLink");
	  WSPutFunction( wslp, "CompoundExpression", 3);
	    WSPutFunction( wslp, "Set", 2);
	      WSPutSymbol( wslp, "$ParentLink");
	      WSTransferExpression( wslp, wslp);
	    WSPutFunction( wslp, "Message", 2);
	      WSPutFunction( wslp, "MessageName", 2);
	        WSPutSymbol( wslp, "$ParentLink");
	        WSPutString( wslp, "notfe");
	      WSPutSymbol( wslp, "me");
	    WSPutSymbol( wslp, "me");
	WSEndPacket( wslp);

	while( (pkt = WSNextPacket( wslp), pkt) && pkt != SUSPENDPKT)
		WSNewPacket( wslp);
	WSNewPacket( wslp);
	return WSError( wslp) == WSEOK;
}


int WSEvaluate( WSLINK wslp, char *s)
{
	if( WSAbort) return 0;
	return WSPutFunction( wslp, "EvaluatePacket", 1L)
		&& WSPutFunction( wslp, "ToExpression", 1L)
		&& WSPutString( wslp, s)
		&& WSEndPacket( wslp);
}


int WSEvaluateString( WSLINK wslp, char *s)
{
	int pkt;
	if( WSAbort) return 0;
	if( WSEvaluate( wslp, s)){
		while( (pkt = WSAnswer( wslp), pkt) && pkt != RETURNPKT)
			WSNewPacket( wslp);
		WSNewPacket( wslp);
	}
	return WSError( wslp) == WSEOK;
} /* WSEvaluateString */


WSMDEFN( void, WSDefaultHandler, ( WSLINK wslp, int message, int n))
{
	wslp = (WSLINK)0; /* suppress unused warning */
	n = 0;          /* suppress unused warning */

	switch (message){
	case WSTerminateMessage:
		WSDone = 1;
	case WSInterruptMessage:
	case WSAbortMessage:
		WSAbort = 1;
	default:
		return;
	}
}



static int _WSMain( char **argv, char **argv_end, char *commandline)
{
	WSLINK wslp;
	int err;

	if( !stdenv)
		stdenv = WSInitialize( (WSEnvironmentParameter)0);

	if( stdenv == (WSEnvironment)0) goto R0;

	if( !stdyielder)
		stdyielder = (WSYieldFunctionObject)WSDefaultYielder;

	if( !stdhandler)
		stdhandler = (WSMessageHandlerObject)WSDefaultHandler;

	wslp = commandline
		? WSOpenString( stdenv, commandline, &err)
		: WSOpenArgcArgv( stdenv, (int)(argv_end - argv), argv, &err);
	if( wslp == (WSLINK)0){
		WSAlert( stdenv, WSErrorString( stdenv, err));
		goto R1;
	}

	if( WSIconWindow){
#define TEXTBUFLEN 64
		TCHAR textbuf[TEXTBUFLEN];
		PTCHAR twsname;
		const char *wsname;
		size_t namelen, i;
		int len;
		len = GetWindowText(WSIconWindow, textbuf, 62 );
		wsname = WSName(wslp);
		namelen = strlen(wsname);
		twsname = (PTCHAR)malloc((namelen + 1)*sizeof(TCHAR));
		if(twsname == NULL) goto R2;

		for(i = 0; i < namelen; i++){
			twsname[i] = wsname[i];
		}
		twsname[namelen] = '\0';
		
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
		_tcscat_s( textbuf + len, TEXTBUFLEN - len, __TEXT("("));
		_tcsncpy_s(textbuf + len + 1, TEXTBUFLEN - len - 1, twsname, TEXTBUFLEN - len - 3);
		textbuf[TEXTBUFLEN - 2] = '\0';
		_tcscat_s(textbuf, TEXTBUFLEN, __TEXT(")"));
#else
		_tcscat( textbuf + len, __TEXT("("));
		_tcsncpy( textbuf + len + 1, twsname, TEXTBUFLEN - len - 3);
		textbuf[TEXTBUFLEN - 2] = '\0';
		_tcscat( textbuf, __TEXT(")"));
#endif
		textbuf[len + namelen + 2] = '\0';
		free(twsname);
		SetWindowText( WSIconWindow, textbuf);
	}

	if( WSInstance){
		if( stdyielder) WSSetYieldFunction( wslp, stdyielder);
		if( stdhandler) WSSetMessageHandler( wslp, stdhandler);
	}

	if( WSInstall( wslp))
		while( WSAnswer( wslp) == RESUMEPKT){
			if( ! refuse_to_be_a_frontend( wslp)) break;
		}

R2:	WSClose( wslp);
R1:	WSDeinitialize( stdenv);
	stdenv = (WSEnvironment)0;
R0:	return !WSDone;
} /* _WSMain */


int WSMainString( char *commandline)
{
	return _WSMain( (char **)0, (char **)0, commandline);
}

int WSMainArgv( char** argv, char** argv_end) /* note not FAR pointers */
{   
	static char FAR * far_argv[128];
	int count = 0;
	
	while(argv < argv_end)
		far_argv[count++] = *argv++;
		 
	return _WSMain( far_argv, far_argv + count, (char *)0);
}

int WSMain( int argc, char **argv)
{
 	return _WSMain( argv, argv + argc, (char *)0);
}
 
