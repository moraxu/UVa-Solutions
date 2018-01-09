#include <vector>

///////////////////////////////////////////////////////////////////////
struct Edge
{
    int v, w;

    Edge(int v = -1, int w = -1) : v(v), w(w) { }

    bool operator!=(const Edge& e2) const
    {
        return (v != e2.v) || (w != e2.w);
    }

};
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
class SparseMultiGRAPH_vectors   //adjacency-list (vector of vectors), fixed number of vertices
{
    int Vcnt, Ecnt;
    bool digraph;

    std::vector<std::vector<int> > adj; //no extra information about edges, except for their existence

public:
    SparseMultiGRAPH_vectors(int V, bool digraph = false)
                : Vcnt(V), Ecnt(0), digraph(digraph), adj(V)
    {   }

    int V() const { return Vcnt; }
    int E() const { return Ecnt; }

    bool directed() const { return digraph; }

    void insert(Edge e);    //allows multiple edges and self-loops
    void remove(Edge e);    //checks for edge existence before removal (although removal isn't recommended in case of vectors)
                            //MIGHT TAKE TIME O(V)

    bool edge(int v, int w) const;   //MIGHT TAKE TIME O(V)

    friend class adjIterator;   //unnecessary in C++11

    class adjIterator
    {
        const SparseMultiGRAPH_vectors& G;
        int v;
        std::vector<int>::size_type it;

    public:
        adjIterator(const SparseMultiGRAPH_vectors& G, int v) : G(G), v(v), it(0) { }

        int beg()
        {
            return (G.adj[v].empty() ? -1 : G.adj[v][it=0]);
        }

        int nxt()
        {
            return (++it != G.adj[v].size() ? G.adj[v][it] : -1);
        }

        bool end()
        {
            return it == G.adj[v].size();
        }
    };
};
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
void SparseMultiGRAPH_vectors::insert(Edge e)    //allows multiple edges and self-loops
{
    int v = e.v, w = e.w;
    adj[v].push_back(w);
    if(!digraph)    adj[w].push_back(v);
    ++Ecnt;
}
///////////////////////////////////////////////////////////////////////
void SparseMultiGRAPH_vectors::remove(Edge e)    //checks for edge existence before removal (although removal isn't recommended in case of vectors)
{                                               //MIGHT TAKE TIME O(V)
    int v = e.v, w = e.w;
    std::vector<int>::size_type it;
    for(it = 0 ; (it < adj[v].size()) && (adj[v][it] != w) ; ++it);
    if(it != adj[v].size())
    {
        adj[v].erase(adj[v].begin()+it);
        if(!digraph)
        {
            for(it = 0 ; adj[w][it] != v ; ++it);
            adj[w].erase(adj[w].begin()+it);
        }
    }
}
///////////////////////////////////////////////////////////////////////
bool SparseMultiGRAPH_vectors::edge(int v, int w) const  //MIGHT TAKE TIME O(V)
{
    std::vector<int>::size_type it;
    for(it = 0 ; (it < adj[v].size()) && (adj[v][it] != w) ; ++it);
    return it != adj[v].size();
}
///////////////////////////////////////////////////////////////////////

#include <stack>

///////////////////////////////////////////////////////////////////////
template <class Graph>
class VC
{
    const Graph& G;
    int cnt;
    std::vector<int> ord, low;
    std::vector<bool> marked;
    std::vector<std::vector<bool> > processed_edges;
    std::stack<Edge> edges;

    std::vector<std::vector<Edge> > biconnected_components;
    std::vector<int> articulation_points;

    void dfsR(const int root, Edge e)
    {
        int w = e.w;
        ord[w] = low[w] = cnt++;

        int children_of_root = 0;

        typename Graph::adjIterator A(G, w);
        for(int t = A.beg() ; !A.end() ; t = A.nxt())
        {
            if(!processed_edges[w][t])
            {
                edges.push(Edge(w, t));
                processed_edges[w][t] = processed_edges[t][w] = true;
            }

            if(ord[t] == -1)
            {
                dfsR(root, Edge(w, t));

                if(low[t] >= ord[w])    //is there a child "t" of "w" that cannot reach a vertex visited before "w"?
                                        //if yes, then removing "w" will disconnect "t" (and "w" is an articulation point)
                {
                    Edge top;
                    std::vector<Edge> biconn_comp;
                    do
                    {
                        top = edges.top();
                        edges.pop();

                        biconn_comp.push_back(top);

                    } while(top != Edge(w, t));

                    biconnected_components.push_back(biconn_comp);

                    if(w != root)
                    {
                        if(!marked[w])
                        {
                            articulation_points.push_back(w);   //if "w" isn't root, then it is an articulation point
                            marked[w] = true;
                        }
                    }
                    else
                    {
                        ++children_of_root;
                    }
                }
                else if(low[w] > low[t])    //low[w] is always <= ord[w] !!!
                {
                    low[w] = low[t];
                }
            }
            else if(t != e.v)   //detects back links
            {
                if(low[w] > ord[t])
                    low[w] = ord[t];
            }
        }

        if(w == root && children_of_root >= 2)  //if root has at least 2 children ->in a DFS tree<- then it is an articulation point
            articulation_points.push_back(w);
    }

public:
    VC(const Graph& G) : G(G), cnt(0), ord(G.V(), -1), low(G.V(), -1), marked(G.V(), false), processed_edges(G.V())
    {
        for(int i = 0 ; i < G.V() ; ++i)
            processed_edges[i].assign(G.V(), false);

        for(int v = 0 ; v < G.V() ; ++v)
        {
            if(ord[v] == -1)
                dfsR(v, Edge(v, v));
        }
    }

    int number_of_articulation_points() const
    {
        return articulation_points.size();  //number of articulation points
    }
    std::vector<int> vector_of_articulation_points() const
    {
        return articulation_points;
    }

    int number_of_biconn_components() const
    {
        return biconnected_components.size();   //number of biconnected components
    }
    std::vector<std::vector<Edge> > vector_of_biconn_components() const
    {
        return biconnected_components;
    }
};
///////////////////////////////////////////////////////////////////////

#include <cstdio>
using namespace std;

int main()
{
    int places;

    while(scanf("%d", &places), places)
    {
        SparseMultiGRAPH_vectors network(places);

        Edge ed;

        while(scanf("%d", &ed.v), ed.v)
        {
            --ed.v;

            char sep;
            do
            {
                scanf("%d%c", &ed.w, &sep);

                --ed.w;

                network.insert(ed);
            }while(sep != '\n');
        }

        VC<SparseMultiGRAPH_vectors> vec_connectivity(network);
        printf("%d\n", vec_connectivity.number_of_articulation_points());
    }
}
