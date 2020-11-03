#include "stdint.h"
#include "stdio.h"

//Here u can see an exaple used for future compilation and elf analysis

char str[] = "hello world";

int main(int argc, char** argv)
{
    fprintf(stdout, "%s", str);
    return 0;
}