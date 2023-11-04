#include "philosophers.h"

u_int64_t get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        return (0);
    return ((u_int64_t)(tv.tv_sec * 1000) + (u_int64_t)(tv.tv_usec / 1000));
}