#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <stack>
#include <cstdlib>
using namespace std;

char tab[105][105];

int X, Y;
int ile;
int xmark[] = {-1, 0, 1, 0 };
int ymark[] = {0, 1, 0, -1};

void dfs1(int x, int y) //TU NIE LICZYMY "ILE"
{
    if(x < 0 || x == X || y < 0 || y == Y || tab[x][y] != 'X')
        return;

    tab[x][y] = '*';

    for(int i = 0; i < 4; ++i)
    {
        dfs1(x + xmark[i], y + ymark[i]);
    }
}

void dfs (int x, int y)
{
    if(x < 0 || x == X || y < 0 || y == Y || tab[x][y] == '.')
        return;

    if(tab[x][y] == 'X')
    {
        ile++;
        dfs1(x, y);
    }

    tab[x][y] = '.';

    for ( int i = 0; i < 4; i++ )
    {
        dfs(x + xmark[i], y + ymark[i]);
    }

}

int main()
{
    int n, m, licznik = 1;
    while((scanf("%d%d", &m, &n), m))
    {
        X = n, Y = m;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < m ; ++j)
                scanf(" %c ", &tab[i][j]);

        vector<int> zbior_dot;

        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < m ; ++j)
            {
                if(tab[i][j] != '.' )
                {
                    ile = 0;
                    dfs(i, j);
                    zbior_dot.push_back(ile);
                }
            }
        }
        printf("Throw %d\n", licznik++);
        sort(zbior_dot.begin(), zbior_dot.end());
        for(int i = 0 ; i < zbior_dot.size() ; ++i)
        {
            printf("%d", zbior_dot[i]);
            if((i+1)<zbior_dot.size()) printf(" ");
        }
        printf("\n\n");
    }

    return EXIT_SUCCESS;
}
