#include <bits/stdc++.h>
#include "../common.h"
using namespace std;

template <class T>
class Matrix
{
public:
    int n;
    vector<vector<T>> raw;

    Matrix(int n) : n(n) { raw.assign(n, vector<T>(n, 0)); }

    Matrix(vector<vector<T>> raw) : raw(raw), n(raw.size()) {}

    static Matrix<T> identity(int _n)
    {
        vector<vector<T>> res(_n, vector<T>(_n, 0));
        for (int i = 0; i < _n; i++)
            res[i][i] = 1;
        return Matrix<T>(res);
    }

    Matrix<T> transpose() const
    {
        vector<vector<T>> res = raw;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                swap(res[i][j], res[j][i]);
        }
        return Matrix<T>(res);
    }

    Matrix<T> operator+(Matrix<T> &r) const
    {
        assert(n == r.n);
        Matrix<T> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.raw[i][j] = raw[i][j] + r.raw[i][j];
            }
        }
        return res;
    }

    Matrix<T> operator-(Matrix<T> &r) const
    {
        assert(n == r.n);
        Matrix<T> res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.raw[i][j] = raw[i][j] - r.raw[i][j];
            }
        }
        return res;
    }

    Matrix<T> operator*(Matrix<T> &r) const
    {
        assert(n == r.n);
        Matrix<T> res(n);
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
                res[i] += raw[i][j] * v[j];
            }
        }
        return res;
    }

    Matrix<T> &operator+=(Matrix<T> &r)
    {
        *this = *this + r;
        return *this;
    }
    Matrix<T> &operator-=(Matrix<T> &r)
    {
        *this = *this - r;
        return *this;
    }
    Matrix<T> &operator*=(Matrix<T> &r)
    {
        *this = *this * r;
        return *this;
    }

    Matrix<T> pow(ll k) const
    {
        Matrix<T> x = *this;
        Matrix<T> y = Matrix<T>::identity(n);
        for (; k; k >>= 1)
        {
            if (k & 1)
                y *= x;
            x *= x;
        }
        return y;
    }
};