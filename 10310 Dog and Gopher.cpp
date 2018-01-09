#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

const double EPS = 10e-9;

struct POINT
{
    int x, y;
    POINT(int x = 0, int y = 0) : x(x), y(y) { }
    bool operator==(POINT& a)
    {
        return a.x == x && a.y == y;
    }
};

struct POINTD
{
    double x, y;
    POINTD(double x = 0, double y = 0) : x(x), y(y) {}
    POINTD(const POINT& p) : x(p.x), y(p.y) {}
    bool operator==(POINTD& a)
    {
         return fabs(a.x - x) <= EPS && fabs(a.y - y) <= EPS;
    }
};

double PointLineDist(POINTD p1, POINTD p2, POINTD p)
{
    double A = p2.y - p1.y,
           B = p2.x - p1.x;
    return abs(A * (p1.x - p.x) + B * (p.y - p1.y)) / sqrt(A*A + B*B);
}

int main()
{
    int ile_dziur;
    POINTD susel, pies;
    while(scanf("%d%lf%lf%lf%lf", &ile_dziur, &susel.x, &susel.y, &pies.x, &pies.y) != EOF)
    {
        bool sprawdzac_dalej = true;
        POINTD odpowiedz;
        while(ile_dziur--)
        {
            POINTD dziura;
            scanf("%lf%lf", &dziura.x, &dziura.y);
            if(sprawdzac_dalej)
            {
                if(dziura == susel
                   ||
                   4*((susel.x - dziura.x)*(susel.x - dziura.x) + (susel.y-dziura.y)*(susel.y-dziura.y))    //dystant susla
                    <=
                   ((pies.x - dziura.x)*(pies.x - dziura.x) + (pies.y-dziura.y)*(pies.y-dziura.y)))         //dystant psa / 2
                {
                    sprawdzac_dalej = false;
                    odpowiedz = dziura;
                }
            }
        }
        if(sprawdzac_dalej)
            printf("The gopher cannot escape.\n");
        else
            printf("The gopher can escape through the hole at (%.3f,%.3f).\n", odpowiedz.x, odpowiedz.y);
    }

    return EXIT_SUCCESS;
}
