#pragma once
#include "wstp.h"
#include <string>

struct WSTPLink
{
    WSENV env;
    WSLINK link;
    int error, packet;
    WSTPLink();
    WSTPLink(std::string kernelPath);
    ~WSTPLink();
};