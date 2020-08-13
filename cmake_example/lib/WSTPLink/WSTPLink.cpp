#include "WSTPLink.h"
#include <cstdlib>
#include <iostream>

WSTPLink::WSTPLink()
  : WSTPLink{ "/usr/local/bin/math" }
{
}

WSTPLink::WSTPLink(std::string path)
{
    env = WSInitialize((WSEnvironmentParameter)0);
    if (env == (WSENV)0)
    { /* unable to initialize environment */
        std::cout << "unable to initialize environment\n";
        exit(EXIT_FAILURE);
    }

    std::string WSArgv[4] = { "-linkmode", "launch", "-linkname", (path + " -wstp").c_str() };
    char* WSArgv_ptr[4];
    for (int i = 0; i < 4; ++i)
        WSArgv_ptr[i] = (char*)WSArgv[i].c_str();
    link = WSOpenArgv(env,
                      WSArgv_ptr,
                      WSArgv_ptr + 4,
                      &error);

    if (link == (WSLINK)0 || error != WSEOK)
    { /* unable to create link */
        std::cout << "unable to create link\n";
        std::cout << WSErrorMessage(link) << '\n';
        exit(EXIT_FAILURE);
    }

    WSFlush(link);
}

WSTPLink::~WSTPLink()
{
    WSPutFunction(link, "Exit", 0);
    WSClose(link);
    WSDeinitialize(env);
}
