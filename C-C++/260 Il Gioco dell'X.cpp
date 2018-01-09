#include <cstdio>
#include <cstring>
#include <utility>
#include <stack>
#include <cstdlib>
using namespace std;

char tab[200][200];
char czy_byl[200][200];

int main()
{
    int n; int licznik = 1;
    while(scanf("%d", &n), n)
    {
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                scanf(" %c ", &tab[i][j]);

        memset(czy_byl, 0, sizeof(czy_byl));

        bool czy_czarne = false;
        for(int i = 0 ; i < n && !czy_czarne ; ++i)
        {
            stack<pair<int,int> > stos;
            if((!czy_byl[0][i]) && (tab[0][i] == 'b'))
            {
                stos.push(make_pair(0, i));
                czy_byl[0][i] = 1;
            }

            while(!stos.empty())
            {
                pair<int,int> para = stos.top();
                if(para.first == n-1)
                {
                    czy_czarne=true;
                    break;
                }
                stos.pop();

                if((para.first-1 >= 0) && (para.second-1 >= 0) && (!czy_byl[para.first-1][para.second-1]) && (tab[para.first-1][para.second-1] == 'b'))
                {
                    stos.push(make_pair(para.first-1, para.second-1));
                    czy_byl[para.first-1][para.second-1] = 1;
                }
                if((para.first-1 >= 0) && (!czy_byl[para.first-1][para.second]) && (tab[para.first-1][para.second] == 'b'))
                {
                    stos.push(make_pair(para.first-1, para.second));
                    czy_byl[para.first-1][para.second] = 1;
                }
                if((para.second-1 >= 0) && (!czy_byl[para.first][para.second-1]) && (tab[para.first][para.second-1] == 'b'))
                {
                    stos.push(make_pair(para.first, para.second-1));
                    czy_byl[para.first][para.second-1] = 1;
                }
                if((para.second+1 < n) && (!czy_byl[para.first][para.second+1]) && (tab[para.first][para.second+1] == 'b'))
                {
                    stos.push(make_pair(para.first, para.second+1));
                    czy_byl[para.first][para.second+1] = 1;
                }
                if((para.first+1 < n) && (!czy_byl[para.first+1][para.second]) && (tab[para.first+1][para.second] == 'b'))
                {
                    stos.push(make_pair(para.first+1, para.second));
                    czy_byl[para.first+1][para.second] = 1;
                }
                if((para.first+1 < n) && (para.second+1 < n) && (!czy_byl[para.first+1][para.second+1]) && (tab[para.first+1][para.second+1] == 'b'))
                {
                    stos.push(make_pair(para.first+1, para.second+1));
                    czy_byl[para.first+1][para.second+1] = 1;
                }
            }
        }
        if(czy_czarne)
            printf("%d B\n", licznik++);
        else
            printf("%d W\n", licznik++);
    }

    return EXIT_SUCCESS;
}
