#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char tab[2000];
    while(fgets(tab, 2000, stdin))
    {
        int rozmiar = strlen(tab);
        for(int i = 0 ; i < rozmiar ; ++i)
        {
            int nowe_i;
            if(isspace(tab[i]))
            {
                putchar(tab[i]);
            }
            else
            {
                int i2;
                for(i2 = i ; isgraph(tab[i2]) ; ++i2);
                --i2;
                nowe_i = i2;
                while(i2 >= i) putchar(tab[i2--]);
                i = nowe_i;
            }
        }
    }
    return 0;
}
