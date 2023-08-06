#include <bits/stdc++.h>
#include "../common.h"
using namespace std;

template <const ll mod = MOD>
class Modint
{
public:
    ll value;
    Modint() = default;
    Modint(ll value) : value(value) {}
    explicit operator ll() const { return value; }
    Modint<mod> norm()
    {
        if (value < -mod || value >= mod)
            value %= mod;
        if (value < 0)
            value += mod;
    }
    Modint<mod> pow(ll k) const
    {
        Modint<mod> x = *this, y = 1;
        for (; k; k >>= 1)
        {
            if (k & 1)
                y *= x;
            x *= x;
        }
        return y;
    }
    Modint<mod> pow(Modint<mod> k) const { return pow(ll(k)); }
    Modint<mod> inv() const { return pow(mod - 2); }
    Modint<mod> &operator+=(Modint<mod> other)
    {
        this->value += other.value;
        if (this->value >= mod)
            this->value -= mod;
        return *this;
    }
    Modint<mod> &operator-=(Modint<mod> other)
    {
        this->value -= other.value;
        if (this->value < 0)
            this->value += mod;
        return *this;
    }
    Modint<mod> &operator*=(Modint<mod> other)
    {
        this->value = (ll)this->value * other.value % mod;
        if (this->value < 0)
            this->value += mod;
        return *this;
    }
    Modint<mod> &operator/=(Modint<mod> other) { return *this *= other.inv(); }
    Modint<mod> operator+(Modint<mod> other) const
    {
        Modint temp = *this;
        temp += other;
        return temp;
    }
    Modint<mod> operator-(Modint<mod> other) const
    {
        Modint temp = *this;
        temp -= other;
        return temp;
    }
    Modint<mod> operator*(Modint<mod> other) const
    {
        Modint temp = *this;
        temp *= other;
        return temp;
    }
    Modint<mod> operator/(Modint<mod> other) const { return *this * other.inv(); }
    Modint<mod> operator-() const { return Modint<mod>(this->value ? mod - this->value : 0); }
    Modint<mod> &operator++()
    {
        value = (value == MOD - 1) ? 0 : value + 1;
        return *this;
    }
    Modint<mod> &operator--()
    {
        value = (value == 0) ? MOD - 1 : value - 1;
        return *this;
    }
    Modint<mod> operator++(int)
    {
        Modint<mod> before = *this;
        ++*this;
        return before;
    }
    Modint<mod> operator--(int)
    {
        Modint<mod> before = *this;
        --*this;
        return before;
    }
    bool operator==(Modint<mod> other) const { return value == other.value; }
    bool operator!=(Modint<mod> other) const { return value != other.value; }
};
template <ll mod>
istream &operator>>(istream &in, Modint<mod> &n) { return in >> n.value; }
template <ll mod>
ostream &operator<<(ostream &out, Modint<mod> n) { return out << n.value; }
using mint = Modint<MOD>;
typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;