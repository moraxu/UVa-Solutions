#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    double n, p;

    while(scanf("%lf%lf", &n, &p) != EOF)
        printf("%.lf\n", pow(p, 1/n));

    return EXIT_SUCCESS;
}
