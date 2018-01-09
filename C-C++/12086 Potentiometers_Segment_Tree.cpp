#include <cmath>
#include <vector>

//Range Sum Query (RSQ) problem - finding the sum of the
//elements in an array within range [i..j]
///////////////////////////////////////////////////////////////////////
class Segment_Tree_RSQ  //preprocessing time - O(n), space - O(n)
{
    std::vector<int> st;    //st[p] - RSQ value (sum value) of the segment associated with an element range
    int size;

    int left_child(int p) const  { return p << 1; }
    int right_child(int p) const { return (p << 1) + 1; }

    void build(int p, int L, int R, const std::vector<int>& data) //O(n)
    {
        if(L == R)  //as L == R, either one is fine
        {
            st[p] = data[L];
        }
        else    //recursively compute the sums
        {
            build(left_child(p),    L,              (L+R)>>1, data);
            build(right_child(p),  ((L+R)>>1) + 1,  R       , data);

            st[p] = st[left_child(p)] + st[right_child(p)];
        }
    }

    int rsq(int p, int L, int R, int i, int j) const  //O(lg n); L, R - concerning array; i, j - concerning actual range
    {
        if(i > R || j < L)      return -1;      //current segment outside query range
        if(L >= i && R <= j)    return st[p];   //current segment inside query range

        //compute the sum from the left and right part of the interval
        int s1 = rsq(left_child(p),    L,              (L+R)>>1,    i, j),
            s2 = rsq(right_child(p),  ((L+R)>>1) + 1,  R,           i, j);

        //if we try to access segment outside query:
        if(s1 == -1)    return s2;
        if(s2 == -1)    return s1;

        return s1 + s2;
    }

public:
    Segment_Tree_RSQ(const std::vector<int>& data) : size(data.size())
    {
        int tree_height = std::ceil(std::log2(size));   //hight of the tree: ceil of lg size
        st.resize((1 << (tree_height+1)) - 1);          //right child of the last segment L: 2*L+1,
                                                        //L = 2^tree_height - 1,
                                                        //so 2*L+1 = 2*L - 2 + 1 = 2*L - 1

        build(1, 0, size-1, data);
    }

    int rsq(int i, int j) const { return rsq(1, 0, size-1, i, j); }

    void update(int index, int new_element) //O(lg n)
    {
        int p = 1;
        for(int L = 0, R = size-1 ; L != R ; )  //finding index of the segment [index, index]
        {
            if(index <= (L+R)>>1)
            {
                R = (L+R)>>1;
                p = left_child(p);
            }
            else
            {
                L = ((L+R)>>1) + 1;
                p = right_child(p);
            }
        }

        st[p] = new_element;

        while(p != 1)   //updating the tree from the leaf towards the root
        {
            p >>= 1;

            st[p] = st[left_child(p)] + st[right_child(p)];    //as in build function
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

        vector<int> data;

        for(int i = 0 ; i < n ; ++i)
        {
            int value;
            scanf("%d", &value);
            data.push_back(value);
        }

        Segment_Tree_RSQ st(data);

        char c;
        while(scanf(" %c", &c), c != 'E')
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);

            if(c == 'S')
                st.update(v1-1, v2);
            else
                printf("%d\n", st.rsq(v1-1, v2-1));

        }
        scanf("%*[^\n]%*c");
    }

    return 0;
}
