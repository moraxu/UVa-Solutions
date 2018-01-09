#include <cstdio>
#include <cstring>
#include <stack>
#include <utility>
#include <cstdlib>
using namespace std;

char znaki[1001][1001];
int liczby[1001][1001];
int max_z_kazdej[1001];
int X, Y;
char czy_taki;
int rodzina;

int main()
{
    bool nie_ma_eof = true;

    while(nie_ma_eof)
    {
        char zn1, zn2;
        for(X = 0 ; ; ++X)
        {
            for(Y = 0 ; ; ++Y)
            {
                zn1 = getchar();
                zn2 = getchar();
                znaki[X][Y] = zn1;
                if(zn2 == '\n')
                    break;
            }

            zn1 = getchar();
            if(zn1 == EOF)
            {
                nie_ma_eof = false;
                break;
            }
            if(zn1 == '%')
            {
                getchar();
                break;
            }
            else
            {
                ungetc(zn1, stdin);
            }
        }

        ++X, ++Y;

        memset(liczby, 0, sizeof(liczby));
        rodzina = 1;
        stack<pair<int,int> > stos;

        for(int i = 0 ; i < X ; ++i)
        {
            for(int j = 0 ; j < Y ; ++j)
            {
                if(liczby[i][j] == 0)
                {
                    czy_taki = znaki[i][j];
                    pair<int,int> para;

                    stos.push(pair<int,int>(i,j));

                    while(!stos.empty())
                    {
                        para = stos.top();
                        int i = para.first, j = para.second;
                        stos.pop();

                        liczby[i][j] = rodzina;
                        if(liczby[i][j] > max_z_kazdej[j])
                            max_z_kazdej[j] = liczby[i][j];

                        if(i > 0 && znaki[i-1][j] == czy_taki && !liczby[i-1][j])       //gora
                            stos.push(pair<int,int>(i-1,j));
                        if(i < X-1 && znaki[i+1][j] == czy_taki && !liczby[i+1][j])     //dol
                            stos.push(pair<int,int>(i+1,j));
                        if(j > 0 && znaki[i][j-1] == czy_taki && !liczby[i][j-1])       //lewo
                            stos.push(pair<int,int>(i,j-1));
                        if(j < Y-1 && znaki[i][j+1] == czy_taki && !liczby[i][j+1])     //prawo
                            stos.push(pair<int,int>(i,j+1));

                        if(i > 0 && j < Y-1 && znaki[i-1][j+1] == czy_taki && !liczby[i-1][j+1])      //prawy gorny
                            stos.push(pair<int,int>(i-1,j+1));
                        if(i > 0 && j > 0 && znaki[i-1][j-1] == czy_taki && !liczby[i-1][j-1])        //lewy gorny
                            stos.push(pair<int,int>(i-1,j-1));
                        if(i < X-1 && j < Y-1 && znaki[i+1][j+1] == czy_taki && !liczby[i+1][j+1])    //prawy dolny
                            stos.push(pair<int,int>(i+1,j+1));
                        if(i < X-1 && j > 0 && znaki[i+1][j-1] == czy_taki && !liczby[i+1][j-1])      //lewy dolny
                            stos.push(pair<int,int>(i+1,j-1));
                    }
                    ++rodzina;
                }
            }
        }

        for(int kol = 0 ; kol < Y ; ++kol)
        {
            int digits = 0;
            while(max_z_kazdej[kol])
            {
                max_z_kazdej[kol] /= 10;
                digits++;
            }
            max_z_kazdej[kol] = digits;
        }

        for(int i = 0 ; i < X ; ++i)
        {
            for(int j = 0 ; j < Y ; ++j)
            {
                printf("%*d", max_z_kazdej[j], liczby[i][j]);
                if(j+1<Y)   putchar(' ');
            }
            putchar('\n');
        }
        putchar('%');
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
