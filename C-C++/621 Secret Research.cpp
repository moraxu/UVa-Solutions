#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int test_cases;
    scanf("%d", &test_cases);

    while(test_cases--)
    {
        char s[1000];
        scanf("%s", s);

        string mess{s};

        if(mess.size() == 1 || mess.size() == 2)
        {
            puts("+");
        }
        else if(mess.substr(mess.size()-2) == "35")
        {
            puts("-");
        }
        else if(mess[0] == '9')
        {
            puts("*");
        }
        else
        {
            puts("?");
        }
    }

    return EXIT_SUCCESS;
}
