#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

struct tablica
{
    char nazwa[11];
    int B, D, CD;
    int* Ld, *Ud;
    int C0;
};

int main()
{
    int ile_tablic, ile_ref;
    scanf("%d%d", &ile_tablic, &ile_ref);
    tablica* nasze_tablice = new tablica[ile_tablic];
    for(int i = 0 ; i < ile_tablic ; ++i)
    {
        scanf("%s%d%d%d", nasze_tablice[i].nazwa, &nasze_tablice[i].B,
              &nasze_tablice[i].CD, &nasze_tablice[i].D);
        nasze_tablice[i].Ld = new int[nasze_tablice[i].D];
        nasze_tablice[i].Ud = new int[nasze_tablice[i].D];
        for(int j = 0 ; j < nasze_tablice[i].D ; ++j)
            scanf("%d%d", &nasze_tablice[i].Ld[j],
                  &nasze_tablice[i].Ud[j]);
        nasze_tablice[i].C0 = nasze_tablice[i].B;
        for(int j = 0 ; j < nasze_tablice[i].D-1 ; ++j)
        {
            int wynik_Cd = nasze_tablice[i].CD;
            for(int x = nasze_tablice[i].D-1 ; x > j ; --x)
                wynik_Cd *= (nasze_tablice[i].Ud[x] - nasze_tablice[i].Ld[x] + 1);
            nasze_tablice[i].C0 -= (wynik_Cd*nasze_tablice[i].Ld[j]);
        }

        nasze_tablice[i].C0 -= nasze_tablice[i].CD*nasze_tablice[i].Ld[nasze_tablice[i].D-1];
    }
    while(ile_ref--)
    {
        char nazwa[11];
        scanf("%s", nazwa);
        int ktora_tablica;
        for(int i = 0 ; i < ile_tablic ; ++i)
            if(!strcmp(nasze_tablice[i].nazwa, nazwa))
                ktora_tablica = i;
        int indeks, wynik = nasze_tablice[ktora_tablica].C0;
        printf("%s[", nazwa);
        for(int i = 0 ; i < nasze_tablice[ktora_tablica].D ; ++i)
        {
            scanf("%d", &indeks);
            printf("%d", indeks);
            if(i+1 < nasze_tablice[ktora_tablica].D)
            {
                int wynik_Cd = nasze_tablice[ktora_tablica].CD;
                for(int x = nasze_tablice[ktora_tablica].D-1 ; x > i ; --x)
                    wynik_Cd *= (nasze_tablice[ktora_tablica].Ud[x] - nasze_tablice[ktora_tablica].Ld[x] + 1);
                printf(", ");
                wynik += (wynik_Cd*indeks);
            }
            else
            {
                wynik += nasze_tablice[ktora_tablica].CD*indeks;
            }
        }
        printf("] = %d\n", wynik);
    }

    for(int i = 0 ; i < ile_tablic ; ++i)
    {
        delete [] nasze_tablice[i].Ld;
        delete [] nasze_tablice[i].Ud;
    }

    delete [] nasze_tablice;

    return EXIT_SUCCESS;
}
