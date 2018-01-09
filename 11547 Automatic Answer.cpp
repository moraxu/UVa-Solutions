#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        int odp = (((n*567/9+7492)*235/47-498)/10)%10;

        printf("%d\n", (odp < 0 ? -odp : odp));
    }

    return 0;
}
