#include "WSTPLink.h"
#include <iostream>
#include <boost/timer/timer.hpp>

void example(WSLINK link)
{
    int packet;
    WSPutFunction(link, "EvaluatePacket", 1);
    WSPutFunction(link, "Total", 1);
    double *temp = new double[1000];
    for(int i=0;i<1000;++i)
        temp[i]=i;
    WSPutReal64List(link, temp, 1000);
    WSEndPacket(link);
    WSFlush(link);

    while ((packet = WSNextPacket(link)) && packet != RETURNPKT)
    {
        WSNewPacket(link);
    }

    double i;
    WSGetReal64(link, &i);
    std::cout << i << std::endl;
}

int main(int argc, char **argv)
{
    WSTPLink wstp_link{"/usr/local/bin/WolframKernel"};

    boost::timer::auto_cpu_timer timer;
    example(wstp_link.link);
}