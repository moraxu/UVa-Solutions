#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    getchar();

    map<string, char> mapa;
    mapa[".-"] = 'A';
    mapa["-..."] = 'B';
    mapa["-.-."] = 'C';
    mapa["-.."] = 'D';
    mapa["."] = 'E';
    mapa["..-."] = 'F';
    mapa["--."] = 'G';
    mapa["...."] = 'H';
    mapa[".."] = 'I';
    mapa[".---"] = 'J';
    mapa["-.-"] = 'K';
    mapa[".-.."] = 'L';
    mapa["--"] = 'M';
    mapa["-."] = 'N';
    mapa["---"] = 'O';
    mapa[".--."] = 'P';
    mapa["--.-"] = 'Q';
    mapa[".-."] = 'R';
    mapa["..."] = 'S';
    mapa["-"] = 'T';
    mapa["..-"] = 'U';
    mapa["...-"] = 'V';
    mapa[".--"] = 'W';
    mapa["-..-"] = 'X';
    mapa["-.--"] = 'Y';
    mapa["--.."] = 'Z';
    mapa["-----"] = '0';
    mapa[".----"] = '1';
    mapa["..---"] = '2';
    mapa["...--"] = '3';
    mapa["....-"] = '4';
    mapa["....."] = '5';
    mapa["-...."] = '6';
    mapa["--..."] = '7';
    mapa["---.."] = '8';
    mapa["----."] = '9';
    mapa[".-.-.-"] = '.';
    mapa["--..--"] = ',';
    mapa["..--.."] = '?';
    mapa[".----."] = '\'';
    mapa["-.-.--"] = '!';
    mapa["-..-."] = '/';
    mapa["-.--."] = '(';
    mapa["-.--.-"] = ')';
    mapa[".-..."] = '&';
    mapa["---..."] = ':';
    mapa["-.-.-."] = ';';
    mapa["-...-"] = '=';
    mapa[".-.-."] = '+';
    mapa["-....-"] = '-';
    mapa["..--.-"] = '_';
    mapa[".-..-."] = '"';
    mapa[".--.-."] = '@';


    for(int i = 1 ; t-- ; ++i)
    {
        bool czy_bylo = false, czy_znak = false;
        char znak;
        string symbol;

        printf("Message #%d\n", i);

        while(scanf("%c", &znak) != EOF && (znak != '\n'))
        {
            if(znak == ' ')
            {
                if(czy_bylo)
                {
                    putchar(' ');
                    czy_bylo = false;
                }
                else
                {
                    if(czy_znak)
                    {
                        putchar(mapa[symbol]);
                        symbol.clear();
                        czy_znak = false;
                    }
                    czy_bylo = true;
                }
            }
            else
            {
                symbol += znak;
                czy_znak = true;
                czy_bylo = false;
            }
        }

        if(czy_znak)
            putchar(mapa[symbol]);

        putchar('\n');
        if(t)
            putchar('\n');
    }

    return 0;
}
