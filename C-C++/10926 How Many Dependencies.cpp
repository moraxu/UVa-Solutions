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

#include <climits>

///////////////////////////////////////////////////////////////////////
template <class DAG>
class DAG_RTS   //reverse topological sort on DAGs
{
    const DAG& D;
    int pre_cnt, post_cnt;
    std::vector<int> pre, relabeling, rearrangement;

    void tsR(int v)
    {
        pre[v] = pre_cnt++;

        typename DAG::adjIterator A(D, v);
        for(int t = A.beg() ; !A.end() ; t = A.nxt())
        {
            if(pre[t] == -1)
                tsR(t);
        }

        relabeling[v] = post_cnt;
        rearrangement[post_cnt++] = v;   //rearrangement[relabeling[v]] = v
    }

public:
    DAG_RTS(const DAG& D) : D(D), pre_cnt(0), post_cnt(0), pre(D.V(), -1), relabeling(D.V()), rearrangement(D.V())
    {
        for(int v = 0 ; v < D.V() ; ++v)
        {
            if(pre[v] == -1)
                tsR(v);
        }
    }

    int operator[](int v) const //rearrangement
    {
        return rearrangement[v];    //topological sort: rearrangement[D.V()-1 - v]
    }

    int relabel(int v) const    //relabeling
    {
        return relabeling[v];   //a graph where every edge points from a higher-numbered vertex to a lower-numbered vertex
    }
};
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
template <class DAG>
class DAG_longest_paths
{
    const DAG& D;

    struct vertex
    {
        int length, end_vertex;

        vertex(int len, int end_v) : length(len), end_vertex(end_v) { }
    };

    std::vector<vertex> longest_paths;

    void compute_paths()
    {
        DAG_RTS<DAG> ts(D);

        for(int i = 0 ; i < D.V() ; ++i)
        {
            typename DAG::adjIterator A(D, ts[i]);

            int max_length = 0;
            int end_v = INT_MAX;

            for(int t = A.beg() ; !A.end() ; t = A.nxt())
            {
                if(longest_paths[t].length+1 == max_length)
                {
                    if(longest_paths[t].end_vertex < end_v)
                        end_v = longest_paths[t].end_vertex;
                }
                else if(longest_paths[t].length+1 > max_length)
                {
                    max_length = longest_paths[t].length+1;
                    end_v = longest_paths[t].end_vertex;
                }
            }

            if(end_v != INT_MAX)
                longest_paths[ts[i]].end_vertex = end_v;

            longest_paths[ts[i]].length = max_length;
        }
    }

public:
    DAG_longest_paths(const DAG& D) : D(D)
    {
        for(int v = 0 ; v < D.V() ; ++v)
        {
            longest_paths.push_back(vertex(0, v));
        }

        compute_paths();
    }

    vertex operator[](int v) const
    {
        return longest_paths[v];
    }
};
///////////////////////////////////////////////////////////////////////

#include <cstdio>
using namespace std;

int main()
{
    int scenarios;

    while(scanf("%d", &scenarios), scenarios)
    {
        SparseMultiGRAPH_vectors dag(scenarios, true);

        for(int i = 0 ; i < scenarios ; ++i)
        {
            int on_how_many_depends;
            scanf("%d", &on_how_many_depends);
            for(int x = 0 ; x < on_how_many_depends ; ++x)
            {
                int depends_on;
                scanf("%d", &depends_on);
                dag.insert(Edge(depends_on-1, i));
            }
        }

        DAG_longest_paths<SparseMultiGRAPH_vectors> paths(dag);

        int longest = 0;
        int min_vertex = INT_MAX;

        for(int v = 0 ; v < dag.V() ; ++v)
        {
            if(paths[v].length == longest)
            {
                if(paths[v].end_vertex < min_vertex)
                    min_vertex = paths[v].end_vertex;
            }
            else if(paths[v].length > longest)
            {
                longest = paths[v].length;
                min_vertex = paths[v].end_vertex;
            }
        }

        printf("%d\n", min_vertex+1);
    }
}
