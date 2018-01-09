#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    unsigned i, j;

    while(scanf("%u%u", &i, &j) != EOF)
    {
        unsigned temp_i = i,
                 temp_j = j;
        unsigned max = 0;

        if(i > j) swap(i, j);

        for( ; i <= j ; ++i)
        {
            unsigned licznik = 1;
            unsigned n = i;
            while(n != 1)
            {
                ++licznik;
                if(n%2) n = 3*n+1;
                else    n = n/2;
            }
            if(licznik > max)
                max = licznik;
        }

        printf("%u %u %u\n", temp_i, temp_j, max);
    }

    return EXIT_SUCCESS;
}
