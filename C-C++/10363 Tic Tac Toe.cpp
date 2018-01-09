#include <cstdio>
using namespace std;

char tab[3][3];

bool czy_win(char znak)
{
    bool win_przek = true, win_poziom = true, win_pion = true,
         sum_przek = false, sum_poziom = false, sum_pion = false;

    for(int i = 0 ; i < 3 ; ++i)
    {
        win_przek = win_przek && (tab[i][i] == znak);

        for(int j = 0 ; j < 3 ; ++j)
        {
            win_poziom = win_poziom && (tab[i][j] == znak);
            win_pion = win_pion && (tab[j][i] == znak);
        }
        sum_poziom = sum_poziom || win_poziom;
        sum_pion = sum_pion || win_pion;
        win_poziom = win_pion = true;
    }

    sum_przek = sum_przek || win_przek;
    win_przek = true;

    for(int i = 2 ; i >= 0 ; --i)
    {
        win_przek = win_przek && (tab[i][i] == znak);
    }

    sum_przek = sum_przek || win_przek;

    return sum_przek || sum_poziom || sum_pion;
}

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        int X = 0, O = 0;

        for(int i = 0 ; i < 3 ; ++i)
        {
            for(int j = 0 ; j < 3; ++j)
            {
                scanf(" %c", &tab[i][j]);
                if(tab[i][j] == 'X')
                    ++X;
                else if(tab[i][j] == 'O')
                    ++O;
            }
        }

        bool Xwin = czy_win('X'),
             Owin = czy_win('O');

        if((Xwin && Owin) || (X-O == 0 && Xwin) || (X-O == 1 && Owin) || ((X-O) != 1 && (X-O) != 0))
        {
            puts("no");
        }
        else
        {
            puts("yes");
        }
    }

    return 0;
}
