#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct kosz
{
    unsigned brown, green, clear;
};

int main()
{
    kosz kosze[3];
    string tab[6] = {"BCG", "CBG", "BGC", "CGB", "GBC", "GCB"};

    while(scanf("%u%u%u%u%u%u%u%u%u", &(kosze[0].brown), &(kosze[0].green), &(kosze[0].clear),
                                        &(kosze[1].brown), &(kosze[1].green), &(kosze[1].clear),
                                        &(kosze[2].brown), &(kosze[2].green), &(kosze[2].clear)) != EOF)
    {
        int indeks = 0;
        unsigned max_suma;
        for(int i = 0 ; i < 6 ; ++i)
        {

            unsigned suma = 0;
            for(int j = 0 ; j < 3 ; ++j)
            {
                if(tab[i][j] == 'B')
                {
                    suma += (kosze[j].clear + kosze[j].green);
                }
                else if(tab[i][j] == 'C')
                {
                    suma += (kosze[j].green + kosze[j].brown);
                }
                else
                {
                    suma += (kosze[j].clear + kosze[j].brown);
                }
            }

            if(!i || suma < max_suma)
            {
                max_suma=suma;
                indeks = i;
            }
        }

        printf("%s %u\n", tab[indeks].c_str(), max_suma);
    }

    return EXIT_SUCCESS;
}
