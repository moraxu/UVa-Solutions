#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    char tab[30];

    map<char, int> mapa;
    mapa['B'] = mapa['P'] = mapa['F'] = mapa['V'] = 1;
    mapa['C'] = mapa['S'] = mapa['K'] = mapa['G'] = mapa['J'] = mapa['Q'] = mapa['X'] = mapa['Z'] = 2;
    mapa['D'] = mapa['T'] = 3;
    mapa['L'] = 4;
    mapa['M'] = mapa['N'] = 5;
    mapa['R'] = 6;

    printf("%13s%33s\n", "NAME", "SOUNDEX CODE");

    while(scanf("%s", tab) != EOF)
    {
        getchar();

        char code[5];
        code[0] = tab[0];
        code[4] = '\0';
        int rozmiar = strlen(tab);
        int poprz = mapa[tab[0]];
        int i2 = 1;
        for(int i = 1 ; i < rozmiar && i2 < 4 ; ++i)
        {
            if(mapa[tab[i]] && mapa[tab[i]] != poprz)
                code[i2++] = mapa[tab[i]]+48;
            poprz = mapa[tab[i]];
        }
        while(i2 < 4)
            code[i2++] = '0';

        printf("%*s%*s\n", 10+rozmiar-1, tab, 25-rozmiar+4, code);
    }

    printf("%32s\n", "END OF OUTPUT");

    return 0;
}
