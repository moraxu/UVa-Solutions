#include <cstdio>
//#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        //printf("%d\n", static_cast<int>(ceil((n-2)/3.0) * ceil((m-2)/3.0)));
        //or (much shorter ^^):
        printf("%d\n", (n/3)*(m/3));
    }

    return 0;
}
