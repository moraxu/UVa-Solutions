#include <vector>

//Fenwick Tree supports both RSQ and update operations in just O(n) space
//and O(lg n) time given a set of m integers keys that ranges from [1..n],
//this makes Fenwick Tree an ideal data structure for solving dynamic
//RSQ problems on arrays (the static RSQ problem can be solved with simple
//O(n) pre-processing and O(1) per query)
///////////////////////////////////////////////////////////////////////
class Fenwick_Tree  //space - O(n)
{
    std::vector<int> ft;

    int LSOne(int i) const
    {
        return (i & (-i));  //value of the least significant bit that is on (first from the right)
    }

public:
    Fenwick_Tree(int max_range) : ft(max_range+1)
    {   }

    int rsq(int b) const    //O(lg n), returns RSQ(1, b)
    {
        int sum = 0;
        for( ; b ; b -= LSOne(b))
        {
            sum += ft[b];
        }

        return sum;
    }

    int rsq(int a, int b) const //O(lg n), returns RSQ(a, b)
    {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v)   //O(lg n), adjusts value of the k-th element by v (v can be positive/negative)
    {
        for( ; k < ft.size() ; k += LSOne(k))
        {
            ft[k] += v;
        }
    }
};
///////////////////////////////////////////////////////////////////////

#include <cstdio>

using namespace std;

int main()
{
    int n;

    for(int case_no = 1 ; (scanf("%d", &n), n) ; ++case_no)
    {
        if(case_no != 1)
            putchar('\n');

        printf("Case %d:\n", case_no);

        Fenwick_Tree ft(200000);

        for(int i = 0 ; i < n ; ++i)
        {
            int value;
            scanf("%d", &value);
            ft.adjust(i+1, value);
        }

        char c;
        while(scanf(" %c", &c), c != 'E')
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);

            if(c == 'S')
            {
                ft.adjust(v1, v2-ft.rsq(v1, v1));
            }
            else
            {
                printf("%d\n", ft.rsq(v1, v2));
            }
        }
        scanf("%*[^\n]%*c");
    }

    return 0;
}
