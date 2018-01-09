#include <cstdio>
using namespace std;

int main()
{
    int K;

    while(scanf("%d", &K), K)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        while(K--)
        {
            int x, y;
            scanf("%d%d", &x, &y);

            if(x == n || m == y)
            {
                puts("divisa");
            }
            else if(x < n && y > m)
            {
                puts("NO");
            }
            else if(x > n && y > m)
            {
                puts("NE");
            }
            else if(x > n && y < m)
            {
                puts("SE");
            }
            else
            {
                puts("SO");
            }
        }
    }

    return 0;
}
