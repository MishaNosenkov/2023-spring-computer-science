#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() 
{
    const char* cmd = "git status";

    FILE* fp = popen(cmd, "r");

    if (!fp) 
    {
        std::cerr << "Failed to run command: " << std::strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, fp)) 
    {
        std::cout << buf;
    }

    pclose(fp);
    return EXIT_SUCCESS;
}