#include <cstdio>
using namespace std;

int main()
{
    int H, D, F;
    double U;
    while(scanf("%d%lf%d%d", &H, &U, &D, &F), H)
    {
        if(U > H)
        {
            printf("success on day 1\n");
            continue;
        }
        double initial_height = U-D;
        if(initial_height < 0)
        {
            printf("failure on day 1\n");
            continue;
        }

        double factor = F/100.0 * U;

        for(int day = 2 ; ; ++day)
        {
            U-=factor;
            if(U < 0)
                U = 0;
            initial_height += U;
            if(initial_height > H)
            {
                printf("success on day %d\n", day);
                break;
            }
            initial_height -= D;
            if(initial_height < 0)
            {
                printf("failure on day %d\n", day);
                break;
            }
        }
    }
    return 0;
}
