#include "./File.hh"
#include "./Log.hh"

int main()
{
    /*
     *puti::File file = puti::File("test.log");
     *puti::Log::setLogFile(file);
     */
    puti::Log::log(puti::Log::LT_DEBUG, "Hello World");
    return 0;
}
