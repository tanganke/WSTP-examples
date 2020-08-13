#include "WSTPLink.h"
#include <iostream>
#include <pthread.h>



void example(WSLINK link);
void* parallel_example(void* link);

int main(int argc, char **argv)
{
    WSTPLink wstp_link;
    example(wstp_link.link);

    WSTPLink links[4];
    pthread_t threads[4];
    for(int i=0;i<4;i++)
    {
        pthread_create(threads+i,NULL,parallel_example,links[i].link);
    }
    for(int i=0;i<4;i++)
    {
        pthread_join(threads[i],nullptr);
    }
}


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

void* parallel_example(void* link)
{
    example((WSLINK)link);
    return nullptr;
}