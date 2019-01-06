#include "pch.h"

void selfprint(){char*p="void selfprint(){char*p=%c%s%c;(void)printf(p,34,p,34,10);}%c";(void)printf(p,34,p,34,10);}

int main()
{
    selfprint();
    return 0;
}