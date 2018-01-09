#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char tab[105][105];
char czy_byl[105][105];
int dlugosc_linii[105];
int X, Y;

int xmark[] = {-1, 0, 1, 0 };
int ymark[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    czy_byl[x][y] = 1;

    for(int i = 0; i < 4; ++i)
    {
        int x2 = x + xmark[i], y2 = y + ymark[i];

        if((x2 >= 0) && (x2 < X) && (y2 >= 0) && (y2 < Y) && (!czy_byl[x2][y2]))
        {
            if(tab[x2][y2] == ' ' || tab[x2][y2] == '\0')
            {
                tab[x2][y2] = ' ';
                dfs(x2, y2);
            }
            else
                tab[x][y] = '#';
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        memset(czy_byl, 0, sizeof(czy_byl));
        memset(tab, 0, sizeof(tab));
        X = Y = 0;

        for(char pierwszy = '\0' ; pierwszy != '_' ; ++X)
        {
            pierwszy = *gets(tab[X]);
            dlugosc_linii[X] = strlen(tab[X]);

            if(Y < dlugosc_linii[X]+1)
                Y = dlugosc_linii[X]+1;
        }
        --X;

        bool przerywamy = false;
        for(int i = 0 ; i < X && !przerywamy ; ++i)
        {
            for(int j = 0 ; j < dlugosc_linii[i] && !przerywamy ; ++j)
            {
                if(tab[i][j] == '*')
                {
                    tab[i][j] = ' ';
                    dfs(i, j);
                    przerywamy = true;
                }
            }
        }

        for(int i = 0 ; i <= X ; ++i)
        {
            int j;
            for(j = Y ; j >= 0 && (tab[i][j] == ' ' || tab[i][j] == '\0') ; --j);
            tab[i][j+1]='\n';
            tab[i][j+2]='\0';
            printf("%s", tab[i]);
        }
    }

    return EXIT_SUCCESS;
}
