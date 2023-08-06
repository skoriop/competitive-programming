#include <bits/stdc++.h>
#include "../common.h"
using namespace std;

template <class T>
class SegmentTree
{
public:
    ll n;
    vector<T> st;
    T(*merge)
    (T, T);
    T identity;

    SegmentTree(ll _n, vector<T> arr, T identity, T (*merge)(T, T)) : identity(identity), merge(merge)
    {
        n = 1 << (lg2(_n) + !!(_n & (_n - 1)));
        st.resize(2 * n, identity);
        for (int i = 0; i < n; i++)
        {
            st[n + i] = arr[i];
            update(i, arr[i]);
        }
    }

    T query(ll l, ll r)
    {
        T ra = identity, rb = identity;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ra = merge(ra, st[l++]);
            if (!(r & 1))
                rb = merge(st[r--], rb);
        }
        return merge(ra, rb);
    }

    void update(ll pos, T val)
    {
        st[pos += n] = val;
        for (pos >>= 1; pos; pos >>= 1)
            st[pos] = merge(st[2 * pos], st[2 * pos + 1]);
    }
};
