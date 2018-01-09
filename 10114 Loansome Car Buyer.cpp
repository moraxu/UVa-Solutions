#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdlib>
using namespace std;

bool definitelyGreaterThan(double x, double y)
{
    double maxXYOne = max( {1.0, fabs(x), fabs(y)} );

    return (x - y) > numeric_limits<double>::epsilon() * maxXYOne;
}

int main()
{
    for(int months ; scanf("%d", &months), months > 0 ; )
    {
        double downpayment, loan;
        int depreciation_no;

        scanf("%lf%lf%d", &downpayment, &loan, &depreciation_no);

        vector<pair<int,double>> depreciations(depreciation_no);

        for(int i = 0 ; i < depreciation_no ; ++i)
        {
            int month_no;
            double depreciation_perc;

            scanf("%d%lf", &month_no, &depreciation_perc);

            depreciations[i] = make_pair(month_no, depreciation_perc);
        }

        double car_value{(downpayment + loan)*(1-depreciations[0].second)},
               money_owed{loan},
               previous_depr{depreciations[0].second},
               rate{loan / months};

        int month = 0, index = 1;
        while(definitelyGreaterThan(money_owed, car_value))
        {
            ++month;

            if(index < depreciations.size() && month == depreciations[index].first)
            {
                previous_depr = depreciations[index++].second;
            }

            car_value *= (1-previous_depr);

            money_owed -= rate;
        }

        if(month == 1)
            printf("1 month\n");
        else
            printf("%d months\n", month);
    }

    return EXIT_SUCCESS;
}
