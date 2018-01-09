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
    int n;
    scanf("%d", &n);
    while(n--)
    {
        Y = 0;
        X = 1;
        char temp[105];
        scanf("%s", temp);
        Y = strlen(temp);
        strcpy(tab[X-1], temp);

        while(true)
        {
            char pierwszyy = getchar();
            char znak = getchar();
            ungetc(znak, stdin);
            if(znak != 'L' && znak != 'W')
            {
                break;
            }

            ++X;

            scanf("%s", temp);
            strcpy(tab[X-1], temp);
        }

        while(true)
        {
            memset(czy_byl, 0, sizeof(czy_byl));
            int znak = getchar();
            if(znak == EOF)
                break;
            ungetc(znak, stdin);
            if(znak == '\n')
                break;
            int powierzchnia = 1;

            int i, j;
            scanf("%d%d", &i, &j);
            --i;--j;
            getchar();

            czy_byl[i][j] = 1;

            stack<pair<int,int> > stos;
            stos.push(make_pair(i, j));

            while(!stos.empty())
            {
                pair<int,int> para = stos.top();
                stos.pop();

                if((para.first-1 >= 0) && (para.second+1 < Y) && (!czy_byl[para.first-1][para.second+1]) && (tab[para.first-1][para.second+1] == 'W'))
                {
                    stos.push(make_pair(para.first-1, para.second+1));
                    czy_byl[para.first-1][para.second+1] = 1;
                    ++powierzchnia;
                }
                if((para.first+1 < X) && (para.second-1 >= 0) && (!czy_byl[para.first+1][para.second-1]) && (tab[para.first+1][para.second-1] == 'W'))
                {
                    stos.push(make_pair(para.first+1, para.second-1));
                    czy_byl[para.first+1][para.second-1] = 1;
                    ++powierzchnia;
                }
                if((para.first-1 >= 0) && (para.second-1 >= 0) && (!czy_byl[para.first-1][para.second-1]) && (tab[para.first-1][para.second-1] == 'W'))
                {
                    stos.push(make_pair(para.first-1, para.second-1));
                    czy_byl[para.first-1][para.second-1] = 1;
                    ++powierzchnia;
                }
                if((para.first-1 >= 0) && (!czy_byl[para.first-1][para.second]) && (tab[para.first-1][para.second] == 'W'))
                {
                    stos.push(make_pair(para.first-1, para.second));
                    czy_byl[para.first-1][para.second] = 1;
                    ++powierzchnia;
                }
                if((para.second-1 >= 0) && (!czy_byl[para.first][para.second-1]) && (tab[para.first][para.second-1] == 'W'))
                {
                    stos.push(make_pair(para.first, para.second-1));
                    czy_byl[para.first][para.second-1] = 1;
                    ++powierzchnia;
                }
                if((para.second+1 < Y) && (!czy_byl[para.first][para.second+1]) && (tab[para.first][para.second+1] == 'W'))
                {
                    stos.push(make_pair(para.first, para.second+1));
                    czy_byl[para.first][para.second+1] = 1;
                    ++powierzchnia;
                }
                if((para.first+1 < X) && (!czy_byl[para.first+1][para.second]) && (tab[para.first+1][para.second] == 'W'))
                {
                    stos.push(make_pair(para.first+1, para.second));
                    czy_byl[para.first+1][para.second] = 1;
                    ++powierzchnia;
                }
                if((para.first+1 < X) && (para.second+1 < Y) && (!czy_byl[para.first+1][para.second+1]) && (tab[para.first+1][para.second+1] == 'W'))
                {
                    stos.push(make_pair(para.first+1, para.second+1));
                    czy_byl[para.first+1][para.second+1] = 1;
                    ++powierzchnia;
                }
            }

            printf("%d\n",powierzchnia);
        }
        if(n) printf("\n");
    }

    return EXIT_SUCCESS;
}
