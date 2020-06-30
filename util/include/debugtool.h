#include<config.h>
#include<iostream>
#ifdef ASSERTIONS_ENABLED
#define reportAssertionFailure(expr,file,line) \
do \
{\
    std::cerr<<"ASSERT:"<<expr<<" in "<<file<<":"<<line<<std::endl;\
} while(0);

#define ASSERT(expr) \
    if (expr) {} \
    else \
    { \
        reportAssertionFailure(#expr, __FILE__, __LINE__); \
        abort(); \
    }
#else
#define ASSERT(expr)
#endif