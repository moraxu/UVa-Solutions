#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    char znak;
    int licznik = 0;
    while((znak = getchar()) != EOF)
    {
        if(znak == '"')
            if(++licznik&1)
                printf("``");
            else
                printf("''");
        else
            putchar(znak);
    }

    return EXIT_SUCCESS;
}
