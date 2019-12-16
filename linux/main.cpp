#include "wstp.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

static WSENV env;
static WSLINK link;
static int error, packet;

void initialize_mathlink()
{
    env = WSInitialize((WSEnvironmentParameter)0);
    if (env == (WSENV)0)
    { /* unable to initialize environment */
        std::cout << "unable to initialize environment\n";
        exit(EXIT_FAILURE);
    }

    std::string WSArgv[4] = {"-linkmode", "launch", "-linkname", "/usr/bin/math -wstp"};
    char *WSArgv_ptr[4];
    for (int i = 0; i < 4; ++i)
        WSArgv_ptr[i] = (char *)WSArgv[i].c_str();
    link = WSOpenArgv(env,
                      WSArgv_ptr, WSArgv_ptr + 4,
                      &error);

    if (link == (WSLINK)0 || error != WSEOK)
    { /* unable to create link */
        std::cout << "unable to create link\n";
        exit(EXIT_FAILURE);
    }

    WSFlush(link);
}

void deinitialize_mathlink()
{
    WSPutFunction(link, "Exit", 0);
    WSClose(link);
    WSDeinitialize(env);
}

int main(int argc, char **argv)
{
    initialize_mathlink();

    WSPutFunction(link, "EvaluatePacket", 1L);
    WSPutFunction(link, "Total", 1);
    double *temp = new double[1000];
    for(int i=0;i<1000;++i)
        temp[i]=i;
    WSPutReal64List(link, temp, 1000);
    WSEndPacket(link);
    WSFlush(link);

    while ((packet = WSNextPacket(link), packet) && packet != RETURNPKT)
    {
        WSNewPacket(link);
    }

    double i;
    WSGetReal64(link, &i);
    std::cout << i << std::endl;

    deinitialize_mathlink();
}