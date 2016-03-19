#include "Time.hh"

namespace puti
{

std::string Time::current()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64] = { 0 };
    strftime(s, sizeof(s), "[%Y-%m-%d %H:%M:%S]", tm);
    return std::string(s);
}


}/* namespace puti */
