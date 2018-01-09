#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        int suma, roznica;
        scanf("%d %d", &suma, &roznica);

        int wynik = (suma+roznica)>>1;

        if(wynik-roznica >= 0 && (wynik<<1)-roznica == suma)
            printf("%d %d\n", wynik, wynik-roznica);
        else
            printf("impossible\n");
    }

    return 0;
}
