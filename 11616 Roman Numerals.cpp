#include <cstdio>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

int wartosc_znaku(char znak)
{
    switch(znak)
    {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default:  return 0;
    }
}

int rzymski_na_dziesietny(string S)
{
    int dziesiatkowa = 0;
    S += "0";

    for(int i = 0; i+1 < S.size(); ++i)
    {
        int obecny = wartosc_znaku(S[i]);
        int nastepny = wartosc_znaku(S[i+1]);
        if(obecny >= nastepny) dziesiatkowa += obecny;
        else dziesiatkowa -= obecny;
    }
    return dziesiatkowa;
}

string dziesietny_na_rzymski(int wartosc)
{
    string rzymski[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int dziesietny[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    string rzymska_wartosc = "";

    for(int i = 0; i < 13; ++i)
    {
        while(wartosc >= dziesietny[i])
        {
            wartosc -= dziesietny[i];
            rzymska_wartosc += rzymski[i];
        }
    }
    return rzymska_wartosc;
}

int main()
{
    char tab[100];

    while(scanf("%s", tab) != EOF)
    {
        if(isdigit(tab[0]))
        {
            printf("%s\n", dziesietny_na_rzymski(atoi(tab)).c_str());
        }
        else
        {
            printf("%d\n", rzymski_na_dziesietny(tab));
        }
    }

    return 0;
}
