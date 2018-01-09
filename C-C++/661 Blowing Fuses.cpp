#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int tab[30];
    char toggle[30];
    int n, m, c;

    for(int seq = 1 ; (scanf("%d%d%d", &n, &m, &c), n) ; ++seq)
    {
        for(int i = 1 ; i <= n ; ++i)
            scanf("%d", tab+i);
        int max = 0, suma = 0, nr;
        memset(toggle, 0, sizeof(toggle));
        bool blowed = false;
        while(m--)
        {
            scanf("%d", &nr);
            if(!blowed)
            {
                toggle[nr] = ~toggle[nr];
                if(toggle[nr])
                {
                    suma += tab[nr];
                    if(suma > max)
                        max = suma;
                    if(suma > c)
                        blowed = true;
                }
                else
                {
                    suma -= tab[nr];
                }
            }
        }
        if(blowed)
        {
            printf("Sequence %d\nFuse was blown.\n\n", seq);
        }
        else
        {
            printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n", seq, max);
        }
    }
    return 0;
}
