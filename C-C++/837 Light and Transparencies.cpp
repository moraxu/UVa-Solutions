#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct segment
{
    double pocz, koniec, wspolcz;

    bool czy_nalezy(double punkt)
    {
        return punkt > pocz && punkt <= koniec;
    }
};

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        int np;
        scanf("%d", &np);

        double temp;
        vector<segment> wekt(np);
        vector<double> punkty;
        for(int i = 0 ; i < np ; ++i)
        {
            scanf("%lf%lf%lf%lf%lf", &wekt[i].pocz, &temp, &wekt[i].koniec, &temp, &wekt[i].wspolcz);
            if(wekt[i].pocz > wekt[i].koniec)
                swap(wekt[i].pocz, wekt[i].koniec);
            punkty.push_back(wekt[i].pocz);
            punkty.push_back(wekt[i].koniec);
        }

        sort(punkty.begin(), punkty.end());

        printf("%d\n-inf %.3lf 1.000\n", (np<<1)+1, punkty[0]);

        for(int i = 1 ; i < punkty.size() ; ++i)
        {
            double akt_wspolcz = 1.0;
            for(int x = 0 ; x < wekt.size() ; ++x)
            {
                if(wekt[x].czy_nalezy(punkty[i]))
                {
                    akt_wspolcz*=wekt[x].wspolcz;
                }
            }
            printf("%.3lf %.3lf %.3lf\n", punkty[i-1], punkty[i], akt_wspolcz);
        }

        printf("%.3lf +inf 1.000\n", punkty[punkty.size()-1]);

        if(n)   putchar('\n');
    }

    return 0;
}
