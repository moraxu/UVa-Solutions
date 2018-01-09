#include <cstdio>
using namespace std;

int main()
{
    int butelki;

    while(scanf("%d", &butelki) != EOF)
    {
        int w_sumie = butelki;
        while(butelki >= 3)
        {
            int temp = butelki/3;
            w_sumie += temp;
            butelki = temp + butelki%3;
        }

        if(butelki == 2) w_sumie++;
        printf("%d\n", w_sumie);
    }

    return 0;
}
