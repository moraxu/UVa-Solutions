#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char tab[500][500];

int main()
{
    int i, j, n;

    while(scanf("%d%d%d", &j, &i, &n), j)
    {
        memset(tab, 1, sizeof(tab));

        int licznik = 0;

        while(n--)
        {
            int X1, Y1, X2, Y2;

            scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);

            if(X1 > X2)
                swap(X1, X2);
            if(Y1 > Y2)
                swap(Y1, Y2);

            --X1, --Y1;

            for(int poz = Y1 ; poz < Y2 ; ++poz)
                for(int pion = X1 ; pion < X2 ; ++pion)
                    tab[poz][pion] = 0;
        }

        for(int poz = 0 ; poz < i ; ++poz)
            for(int pion = 0 ; pion < j ; ++pion)
                if(tab[poz][pion])
                    ++licznik;

        if(licznik == 0)
            printf("There is no empty spots.\n");
        else if(licznik == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", licznik);
    }

    return 0;
}
