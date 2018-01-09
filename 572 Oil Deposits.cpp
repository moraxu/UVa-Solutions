#include <cstdio>
#include <cstring>
#include <utility>
#include <stack>
#include <cstdlib>
using namespace std;

char tab[105][105];
char czy_byl[105][105];

int X, Y;

int main()
{
    int n, m;
    while((scanf("%d%d", &n, &m), n))
    {
        X = n, Y = m;
        int ile = 0;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < m ; ++j)
                scanf(" %c ", &tab[i][j]);

        memset(czy_byl, 0, sizeof(czy_byl));

        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < m ; ++j)
        {
            if(czy_byl[i][j] || tab[i][j] == '*')
                continue;

            ++ile;
            czy_byl[i][j] = 1;

            stack<pair<int,int> > stos;
            stos.push(make_pair(i, j));

            while(!stos.empty())
            {
                pair<int,int> para = stos.top();
                stos.pop();

                if((para.first-1 >= 0) && (para.second+1 < Y) && (!czy_byl[para.first-1][para.second+1]) && (tab[para.first-1][para.second+1] == '@'))
                {
                    stos.push(make_pair(para.first-1, para.second+1));
                    czy_byl[para.first-1][para.second+1] = 1;
                }
                if((para.first+1 < X) && (para.second-1 >= 0) && (!czy_byl[para.first+1][para.second-1]) && (tab[para.first+1][para.second-1] == '@'))
                {
                    stos.push(make_pair(para.first+1, para.second-1));
                    czy_byl[para.first+1][para.second-1] = 1;
                }
                if((para.first-1 >= 0) && (para.second-1 >= 0) && (!czy_byl[para.first-1][para.second-1]) && (tab[para.first-1][para.second-1] == '@'))
                {
                    stos.push(make_pair(para.first-1, para.second-1));
                    czy_byl[para.first-1][para.second-1] = 1;
                }
                if((para.first-1 >= 0) && (!czy_byl[para.first-1][para.second]) && (tab[para.first-1][para.second] == '@'))
                {
                    stos.push(make_pair(para.first-1, para.second));
                    czy_byl[para.first-1][para.second] = 1;
                }
                if((para.second-1 >= 0) && (!czy_byl[para.first][para.second-1]) && (tab[para.first][para.second-1] == '@'))
                {
                    stos.push(make_pair(para.first, para.second-1));
                    czy_byl[para.first][para.second-1] = 1;
                }
                if((para.second+1 < Y) && (!czy_byl[para.first][para.second+1]) && (tab[para.first][para.second+1] == '@'))
                {
                    stos.push(make_pair(para.first, para.second+1));
                    czy_byl[para.first][para.second+1] = 1;
                }
                if((para.first+1 < X) && (!czy_byl[para.first+1][para.second]) && (tab[para.first+1][para.second] == '@'))
                {
                    stos.push(make_pair(para.first+1, para.second));
                    czy_byl[para.first+1][para.second] = 1;
                }
                if((para.first+1 < X) && (para.second+1 < Y) && (!czy_byl[para.first+1][para.second+1]) && (tab[para.first+1][para.second+1] == '@'))
                {
                    stos.push(make_pair(para.first+1, para.second+1));
                    czy_byl[para.first+1][para.second+1] = 1;
                }
            }
        }
        printf("%d\n", ile);
    }

    return EXIT_SUCCESS;
}
