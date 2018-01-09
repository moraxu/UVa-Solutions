#include <cstdio>
#include <map>
using namespace std;

int main()
{
    map<char, int> mapa;
    mapa['A'] = mapa['B'] = mapa['C'] = 2;
    mapa['D'] = mapa['E'] = mapa['F'] = 3;
    mapa['G'] = mapa['H'] = mapa['I'] = 4;
    mapa['J'] = mapa['K'] = mapa['L'] = 5;
    mapa['M'] = mapa['N'] = mapa['O'] = 6;
    mapa['P'] = mapa['Q'] = mapa['R'] = mapa['S'] = 7;
    mapa['T'] = mapa['U'] = mapa['V'] = 8;
    mapa['W'] = mapa['X'] = mapa['Y'] = mapa['Z'] = 9;

    char temp[40];

    while(fgets(temp, 40, stdin))
    {
        for(char* wsk = temp ; *wsk ; ++wsk)
        {
            printf("%c", (mapa[*wsk] ? mapa[*wsk]+48 : *wsk));
        }
    }

    return 0;
}
