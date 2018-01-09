#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <string>
using namespace std;

/// --------------------------------------------------
typedef vector<int> VI;
typedef long long LL;

#define FOR(x,b,e) for(int x = b ; x <= (e) ; ++x)
#define FORD(x,b,e) for(int x = b ; x >= (e) ; --x)
#define REP(x,n) for(int x = 0 ; x < (n) ; ++x)
#define VAR(v,n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i,c) for(VAR(i, (c).begin()) ; i != (c).end() ; ++i)
#define PB push_back
#define ST first
#define ND second
/// --------------------------------------------------

const int INF = 1000000001;

template <class V, class E>
struct Graph
{
    struct Ed : E
    {
        int v;  //do jakiego wierzcholka
        Ed(E p, int w) : E(p), v(w) { }
    };

    struct Ve : V, vector<Ed> { };

    vector<Ve> g;

    Graph(int n = 0) : g(n) { }

    void EdgeD(int b, int e, E d = E())
    {
        g[b].PB(Ed(d, e));
    }

    void EdgeU(int b, int e, E d = E())
    {
        Ed eg(d, e);
        eg.rev = SIZE(g[e]) + (b == e);
        g[b].PB(eg);
        eg.v = b;
        eg.rev = SIZE(g[b]) - 1;
        g[e].PB(eg);
    }
    void BFS(int s)
    {
        g[s].t = 0;

        queue<int> qu;
        qu.push(s);
        while(!qu.empty())
        {
            s = qu.front();
            qu.pop();

            FOREACH(it, g[s])
            {
                if(g[it->v].t == -1)
                {
                    qu.push(it->v);
                    g[it->v].t = g[s].t+1;
                    g[it->v].s = s;
                }
            }
        }
    }

    void Write()
    {
        REP(x, SIZE(g))
        {
            printf("%d, krawedzie: ", x+1);

            FOREACH(it, g[x]) printf(" %d", it->v+1);
            puts("");
        }
        puts("");
    }

};
/// --------------------------------------------------

struct Ve   //krawędzie
{
    int rev, kolor;
};

struct Vs   //wierzchołki
{
    int t, s;
    Vs() : t(-1), s(-1) {}
};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        char max;
        scanf(" %c", &max);

        Graph<Vs,Ve> graph(max-64);

        while(true)
        {
            getchar();
            int a = getchar();
            if(a!='\n' && a!=' ' && a!=EOF)
            {
                int b = getchar();
                graph.EdgeU(a-65,b-65);
            }
            else
            {
                break;
            }
        }

        int ile = 0;
        for(int i = 0; i < max-64 ; ++i)
        {
            if(graph.g[i].t == -1)
            {
                graph.BFS(i);
                ++ile;
            }
        }

        printf("%d\n", ile);
        if(t) printf("\n");
    }
    return EXIT_SUCCESS;
}
