#include <bits/stdc++.h>
#include "../common.h"
using namespace std;

template <const ll mod = MOD>
struct modint {
    ll value;
    modint () = default;
    modint (ll value_) : value(value_) {}
    explicit operator ll () const { return value; }
    modint<mod> norm () { if (value < -mod || value >= mod) value %= mod; if (value < 0) value += mod;}
    modint<mod> pow (ll k) const { modint<mod> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
    modint<mod> pow (modint<mod> k) const { return pow(ll(k)); }
    modint<mod> inv () const { return pow(mod - 2); } 
    inline modint<mod> & operator += (modint<mod> other) { this->value += other.value; if (this->value >= mod) this->value -= mod; return *this; }
    inline modint<mod> & operator -= (modint<mod> other) { this->value -= other.value; if (this->value < 0) this->value += mod; return *this; }
    inline modint<mod> & operator *= (modint<mod> other) { this->value = (ll)this->value * other.value % mod; if (this->value < 0) this->value += mod; return *this; }
    inline modint<mod> & operator /= (modint<mod> other) { return *this *= other.inv(); }
    inline modint<mod> operator + (modint<mod> other) const { modint temp = *this; temp += other; return temp; }
    inline modint<mod> operator - (modint<mod> other) const { modint temp = *this; temp -= other; return temp; }
    inline modint<mod> operator * (modint<mod> other) const { modint temp = *this; temp *= other; return temp; }
    inline modint<mod> operator / (modint<mod> other) const { return *this * other.inv(); }
    inline modint<mod> operator - () const { return modint<mod>(this->value ? mod - this->value : 0); }
    inline modint<mod> & operator ++ () { value = (value == MOD - 1) ? 0 : value + 1; return *this; }
    inline modint<mod> & operator -- () { value = (value == 0) ? MOD - 1 : value - 1; return *this; }
    inline modint<mod> operator ++ (int) { modint<mod> before = *this; ++*this; return before; }
    inline modint<mod> operator -- (int) { modint<mod> before = *this; --*this; return before; }
    inline bool operator == (modint<mod> other) const { return value == other.value; }
    inline bool operator != (modint<mod> other) const { return value != other.value; }
};
template <ll mod> istream & operator >> (istream & in, modint<mod> &n) { return in >> n.value; }
template <ll mod> ostream & operator << (ostream & out, modint<mod> n) { return out << n.value; }
using mint = modint<MOD>;
typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;