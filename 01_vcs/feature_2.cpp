#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() 
{
    const char* cmd1 = "git ls-tree -r HEAD";
    const char* cmd2 = "git ls-tree -r HEAD~1";

    FILE* fp1 = popen(cmd1, "r");
    FILE* fp2 = popen(cmd2, "r");

    if (!fp1 || !fp2) 
    {
        std::cerr << "Failed to run command: " << std::strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    std::string result1, result2;
    char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, fp1)) 
    {
        result1 += buf;
    }
    while (fgets(buf, BUFSIZ, fp2)) 
    {
        result2 += buf;
    }

    pclose(fp1);
    pclose(fp2);

    if (result1 == result2) {
        std::cout << "The repositories are identical" << std::endl;
    }
    else {
        std::cout << "Repositories are different" << std::endl;
    }

    return EXIT_SUCCESS;
}