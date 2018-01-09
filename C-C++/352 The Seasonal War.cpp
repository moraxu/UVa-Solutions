#include <cstdio>
#include <cstring>
#include <utility>
#include <stack>
#include <cstdlib>
using namespace std;

char tab[25][25];
char czy_byl[25][25];

int main()
{
    int n; int licznik = 1;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                scanf(" %c ", &tab[i][j]);

        memset(czy_byl, 0, sizeof(czy_byl));

        int ilosc_orlow = 0;

        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
            {
                if(czy_byl[i][j] || tab[i][j] == '0')
                    continue;

                ++ilosc_orlow;

                czy_byl[i][j] = 1;

                stack<pair<int,int> > stos;
                stos.push(make_pair(i, j));

                while(!stos.empty())
                {
                    pair<int,int> para = stos.top();
                    stos.pop();

                    if((para.first-1 >= 0) && (para.second+1 < n) && (!czy_byl[para.first-1][para.second+1]) && (tab[para.first-1][para.second+1] == '1'))
                    {
                        stos.push(make_pair(para.first-1, para.second+1));
                        czy_byl[para.first-1][para.second+1] = 1;
                    }
                    if((para.first+1 < n) && (para.second-1 >= 0) && (!czy_byl[para.first+1][para.second-1]) && (tab[para.first+1][para.second-1] == '1'))
                    {
                        stos.push(make_pair(para.first+1, para.second-1));
                        czy_byl[para.first+1][para.second-1] = 1;
                    }
                    if((para.first-1 >= 0) && (para.second-1 >= 0) && (!czy_byl[para.first-1][para.second-1]) && (tab[para.first-1][para.second-1] == '1'))
                    {
                        stos.push(make_pair(para.first-1, para.second-1));
                        czy_byl[para.first-1][para.second-1] = 1;
                    }
                    if((para.first-1 >= 0) && (!czy_byl[para.first-1][para.second]) && (tab[para.first-1][para.second] == '1'))
                    {
                        stos.push(make_pair(para.first-1, para.second));
                        czy_byl[para.first-1][para.second] = 1;
                    }
                    if((para.second-1 >= 0) && (!czy_byl[para.first][para.second-1]) && (tab[para.first][para.second-1] == '1'))
                    {
                        stos.push(make_pair(para.first, para.second-1));
                        czy_byl[para.first][para.second-1] = 1;
                    }
                    if((para.second+1 < n) && (!czy_byl[para.first][para.second+1]) && (tab[para.first][para.second+1] == '1'))
                    {
                        stos.push(make_pair(para.first, para.second+1));
                        czy_byl[para.first][para.second+1] = 1;
                    }
                    if((para.first+1 < n) && (!czy_byl[para.first+1][para.second]) && (tab[para.first+1][para.second] == '1'))
                    {
                        stos.push(make_pair(para.first+1, para.second));
                        czy_byl[para.first+1][para.second] = 1;
                    }
                    if((para.first+1 < n) && (para.second+1 < n) && (!czy_byl[para.first+1][para.second+1]) && (tab[para.first+1][para.second+1] == '1'))
                    {
                        stos.push(make_pair(para.first+1, para.second+1));
                        czy_byl[para.first+1][para.second+1] = 1;
                    }
                }
            }

        printf("Image number %d contains %d war eagles.\n", licznik++, ilosc_orlow);
    }

    return EXIT_SUCCESS;
}
