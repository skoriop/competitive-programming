#include <bits/stdc++.h>
#include "../common.h"
using namespace std;

template <class T>
struct matrix
{
    int n;
    vector<vector<T>> raw;

    matrix(int _n)
    {
        n = _n;
        raw.assign(n, vector<T>(n, 0));
    }

    matrix(vector<vector<T>> _raw)
    {
        raw = _raw;
        n = raw.size();
    }

    static matrix<T> identity(int _n)
    {
        vector<vector<T>> res(_n, vector<T>(_n, 0));
        for (int i = 0; i < _n; i++)
            res[i][i] = 1;
        return matrix<T>(res);
    }

    matrix<T> transpose() const
    {
        vector<vector<T>> res = raw;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                swap(res[i][j], res[j][i]);
        }
        return matrix<T>(res);
    }

    matrix<T> operator+(matrix<T> &r) const
    {
        assert(n == r.n);
        matrix<T> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.raw[i][j] = raw[i][j] + r.raw[i][j];
            }
        }
        return res;
    }

    matrix<T> operator-(matrix<T> &r) const
    {
        assert(n == r.n);
        matrix<T> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.raw[i][j] = raw[i][j] - r.raw[i][j];
            }
        }
        return res;
    }

    matrix<T> operator*(matrix<T> &r) const
    {
        assert(n == r.n);
        matrix<T> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                    res.raw[i][j] += raw[i][k] * r.raw[k][j];
            }
        }
        return res;
    }

    vector<T> operator*(vector<T> &v) const
    {
        assert(n == (int)v.size());
        vector<T> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i] += v[j] * raw[i][j];
            }
        }
        return res;
    }

    matrix<T> &operator+=(matrix<T> &r)
    {
        *this = *this + r;
        return *this;
    }
    matrix<T> &operator-=(matrix<T> &r)
    {
        *this = *this - r;
        return *this;
    }
    matrix<T> &operator*=(matrix<T> &r)
    {
        *this = *this * r;
        return *this;
    }

    matrix<T> pow(ll k) const
    {
        matrix<T> x = *this;
        matrix<T> y = matrix<T>::identity(n);
        for (; k; k >>= 1)
        {
            if (k & 1)
                y *= x;
            x *= x;
        }
        return y;
    }
};