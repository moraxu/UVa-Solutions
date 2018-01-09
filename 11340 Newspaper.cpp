#include <cstdio>
#include <cstring>
using namespace std;

unsigned char tab[10100];

int main()
{
    int N;
    scanf("%d", &N);

    while(N--)
    {
        int K;
        scanf("%d", &K);

        int mapa[257];
        memset(mapa, 0, sizeof(mapa));

        while(K--)
        {
            unsigned char znak;
            int wartosc;
            scanf(" %c%d", &znak, &wartosc);
            mapa[znak] = wartosc;
        }

        int M;
        scanf("%d", &M);
        getchar();

        int suma = 0;

        while(M--)
        {
            fgets((char*)tab, 10100, stdin);
            for(unsigned char* p = tab ; *p ; ++p) suma += mapa[*p];
        }

        printf("%d.%.2d$\n", suma/100, suma%100);
    }

    return 0;
}
