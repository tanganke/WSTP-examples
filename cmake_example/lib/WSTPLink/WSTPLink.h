#pragma once
//* Reference: https://reference.wolfram.com/language/tutorial/WSTPInterface4.html
#include "wstp.h"
#include <memory>
#include <string>
#include <vector>

struct WSIntegerList
{
    int* data;
    long count;
};
struct WSRealList
{
    double* data;
    long count;
};
class WSTPLink
{
public:
    WSENV env;
    WSLINK link;
    int error, packet;
    // use a default kernel path: /usr/local/bin/math
    WSTPLink();
    WSTPLink(std::string kernelPath);
    ~WSTPLink();

    // inline member functions
    inline int PutFunction(const char* s, int argc)
    {
        return WSPutFunction(link, s, argc);
    }
    inline int PutInteger(int i)
    {
        return WSPutInteger(link, i);
    }
    inline int PutIntegerList(const int* data,long count)
    {
        return WSPutIntegerList(link,data,count);
    }
    inline int PutIntegerList(WSIntegerList* list)
    {
        return WSPutIntegerList(link,list->data,list->count);
    }
    inline int PutReal(double d)
    {
        return WSPutReal(link, d);
    }
    inline int PutReal32(float f)
    {
        return WSPutReal32(link, static_cast<double>(f));
    }
    inline int PutReal64(double d)
    {
        return WSPutReal64(link, d);
    }
    inline int PutRealList(WSRealList* list)
    {
        return WSPutRealList(link,list->data,list->count);
    }
    inline int PutReal32List(const float* data, int count)
    {
        return WSPutReal32List(link, data, count);
    }
    inline int PutReal64List(const double* data, int count)
    {
        return WSPutReal64List(link, data, count);
    }
    inline int PutIntegerArray(const int* data, const long* dims, const char** heads, long depth)
    {
        return WSPutIntegerArray(link, data, dims, heads, depth);
    }
    /*
    * The array 'data' must be laid out in memory like a C array declared explicitly as double[m][n].
    * If heads is given as NULL, the array will be assumed to have head List at every level.
    * The length of the array at level i is taken to be dim[i].
    * WSPutRealArray() is equivalent to WSPutReal64Array().
    */
    inline int PutRealArray(const double* data, const long* dims, const char** heads, long depth)
    {
        return WSPutRealArray(link, data, dims, heads, depth);
    }
    inline int Flush()
    {
        return WSFlush(link);
    }
    inline std::shared_ptr<const char> GetString()
    {
        const char* s;
        WSGetString(link, &s);
        return std::shared_ptr<const char>(s, [&](const char* s) { WSReleaseString(link, s); });
    }
    /*
    * Example Code
    * const char *string;
    *
    * if(! WSGetString(lp, &string))
    *    {
    *        //! unable to read the string from lp 
    *        return;
    *    }
    * 
    * WSReleaseString(lp, string); //! 需要手动释放内存
    */
    inline int GetString(const char** s)
    {
        return WSGetString(link, s);
    }
    inline int GetInteger(int* ip)
    {
        return WSGetInteger(link, ip);
    }
    inline int GetInteger()
    {
        int i;
        WSGetInteger(link, &i);
        return i;
    }
    inline int GetReal(double* dp)
    {
        return WSGetReal(link, dp);
    }
    inline double GetReal()
    {
        double d;
        WSGetReal(link, &d);
        return d;
    }
    /*
    *  int *data;
    *  long length;
    *
    *  if(! WSGetIntegerList(lp, &data, &length))
    *      {
    *           //! unable to read the integer list from lp
    *          return;
    *      }
    *   
    *  WSReleaseIntegerList(lp, data, length); //!需要手动释放内存
    */
    inline int GetIntegerList(int** datap, long* countp)
    {
        return WSGetIntegerList(link, datap, countp);
    }
    inline std::shared_ptr<WSIntegerList> GetIntegerList()
    {
        WSIntegerList* ret = new WSIntegerList;
        WSGetIntegerList(link, &(ret->data), &(ret->count));
        return std::shared_ptr<WSIntegerList>(ret, [&](WSIntegerList* list) {
            WSReleaseIntegerList(link, list->data, list->count);
            delete list;
        });
    }
    inline std::shared_ptr<WSRealList> GetRealList()
    {
        WSRealList* ret = new WSRealList;
        WSGetRealList(link,&(ret->data),&(ret->count));
        return std::shared_ptr<WSRealList>(ret,[&](WSRealList*list){
            WSReleaseRealList(link,list->data,list->count);
            delete list;
        });
    }
    inline int NextPacket()
    {
        return WSNextPacket(link);
    }
    inline int NewPacket()
    {
        return WSNewPacket(link);
    }
};