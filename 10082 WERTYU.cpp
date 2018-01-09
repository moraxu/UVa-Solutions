#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char tablica[] = { "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./" };

    char linia[300];
    while(fgets(linia, 300, stdin))
    {
        for(char* p = linia ; *p ; ++p)
        {
            if(*p != '\n' && *p != ' ')
            {
                putchar(*(strchr(tablica, *p)-1));
            }
            else
            {
                putchar(*p);
            }
        }
    }

    return 0;
}
