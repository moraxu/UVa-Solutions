#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int no_requir, no_proposals;

    for(int rfp = 1 ; (scanf("%d%d", &no_requir, &no_proposals), no_requir) ; ++rfp)
    {
        char temp[100];

        getchar();
        for(int i = 0 ; i < no_requir ; ++i)    fgets(temp, 100, stdin);

        char name_proposal[100];

        --no_proposals;
        double price;
        int met_requir;
        fgets(name_proposal, 100, stdin);
        scanf("%lf%d", &price, &met_requir);

        getchar();
        for(int i = 0 ; i < met_requir ; ++i)   fgets(temp, 100, stdin);

        while(no_proposals--)
        {
            double present_price;
            int present_met_requir;
            fgets(temp, 100, stdin);
            scanf("%lf%d", &present_price, &present_met_requir);

            if((present_met_requir > met_requir) || (present_met_requir == met_requir && present_price < price))
            {
                met_requir = present_met_requir;
                price = present_price;
                strcpy(name_proposal, temp);
            }

            getchar();
            for(int i = 0 ; i < present_met_requir ; ++i) fgets(temp, 100, stdin);
        }

        if(rfp > 1) putchar('\n');
        printf("RFP #%d\n%s", rfp, name_proposal);
    }

    return 0;
}
