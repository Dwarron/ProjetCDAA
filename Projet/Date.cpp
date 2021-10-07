#include "Date.h"
#include <time.h>

Date::Date()
{
 time_t n = time(0);
 d = localtime(&n);
 //...
}
