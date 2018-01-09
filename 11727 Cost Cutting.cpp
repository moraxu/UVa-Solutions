#include <cstdio>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 1 ; T-- ; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        if((a>b&&a<c)||(a>c&&a<b))
            printf("Case %d: %d\n", i, a);
        if((b>a&&b<c)||(b>c&&b<a))
            printf("Case %d: %d\n", i, b);
        if((c>a&&c<b)||(c>b&&c<a))
            printf("Case %d: %d\n", i, c);
    }

    return 0;
}
