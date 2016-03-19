#include "../File.h"

int main()
{
    puti::File fout("file_test.txt");
    fout.write("Hello World!\n");
    fout.close();
    return 0;
}
