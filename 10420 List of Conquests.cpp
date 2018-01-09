#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    char temp[80];
    map<string, int> mapa;

    while(n--)
    {
        scanf("%s", temp);
        ++mapa[temp];
        fgets(temp, 80, stdin);
    }

    for(map<string, int>::const_iterator it = mapa.begin() ; it != mapa.end() ; ++it)
    {
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    return 0;
}
