#include "WSTPLink.h"
#include <cstdio>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

void
example(WSLINK link);
void*
parallel_example(void* link);

int
main(int argc, char** argv)
{
    WSTPLink wstp_link;
    wstp_link.SetHistoryLength(0);
    wstp_link.LogStreamToFile("/dev/stdout");

    // Total[Range[0,999]]
    example(wstp_link.link);

    // Graphics Plot Example
    wstp_link.PutFunction("EvaluatePacket", 1);
    wstp_link.PutFunction("Needs", 1);
    wstp_link.PutString("JavaGraphics`");
    wstp_link.EndPacket();
    wstp_link.Flush();
    wstp_link.WaitAndDiscardAnswer();

    wstp_link.Evaluate("Show[Plot[x,{x,-10,10}]]");
    wstp_link.WaitAndDiscardAnswer();

    // Total[Range[0,999]] 
    // parallel (4 Kernels)
    WSTPLink links[4];
    pthread_t threads[4];
    for (int i = 0; i < 4; i++)
    {
        pthread_create(threads + i, NULL, parallel_example, links[i].link);
    }
    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], nullptr);
    }

    std::cout<<"Enter to exit\n";
    getchar();

    return 0;
}

// Total[Range[0,999]]
void
example(WSLINK link)
{
    int packet;
    WSPutFunction(link, "EvaluatePacket", 1);
    WSPutFunction(link, "Total", 1);
    double* temp = new double[1000];
    for (int i = 0; i < 1000; ++i)
        temp[i] = i;
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
    array_meterp x;
}

void*
parallel_example(void* link)
{
    example((WSLINK)link);
    return nullptr;
}