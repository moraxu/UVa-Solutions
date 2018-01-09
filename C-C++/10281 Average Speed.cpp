#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char tab[30];
    double dystans = 0;
    int prev_speed = 0, prev_seconds = 0;

    for(bool czy_pierwszy = true ; gets(tab) ; )
    {
        int godz, min, sek;
        double in_hour;
        if(strchr(tab, ' '))
        {
            int speed;
            sscanf(tab, "%d:%d:%d%d", &godz, &min, &sek, &speed);
            in_hour = godz*3600 + min*60 + sek;
            if(czy_pierwszy)
            {
                czy_pierwszy = false;
            }
            else
            {
                dystans += prev_speed/3600.0 * (in_hour-prev_seconds);
            }
            prev_seconds = in_hour;
            prev_speed = speed;
        }
        else
        {
            sscanf(tab, "%d:%d:%d", &godz, &min, &sek);
            in_hour = godz*3600 + min*60 + sek;
            printf("%s %.2lf km\n", tab, dystans + prev_speed/3600.0 * (in_hour-prev_seconds));
        }
    }

    return 0;
}
