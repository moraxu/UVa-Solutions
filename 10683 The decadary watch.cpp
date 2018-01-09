#include <cstdio>
using namespace std;

int main()
{
    int HH, MM, SS, CC;

    while(scanf("%2d%2d%2d%2d", &HH, &MM, &SS, &CC) != EOF)
    {
        printf("%07d\n", 125 * ((HH*60*60 + MM*60 + SS)*100 + CC) / 108);
    }

    return 0;
}
