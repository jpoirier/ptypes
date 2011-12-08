
#include "ptypes.h"


PTYPES_BEGIN


exception::exception(const char* imsg)
    : message(imsg) 
{
}


exception::exception(const string& imsg) 
    : message(imsg) 
{
}


exception::~exception() 
{
}


PTYPES_END
