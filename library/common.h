#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vst;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef multiset<int> msi;
typedef multiset<ll> msll;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
#define ln "\n"
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(), (x).rend()

int lg2(int i) {return 31 - __builtin_clz(i);}
int lg2(ll i) {return 63 - __builtin_clzll(i);}

const ll MOD = 1000000007;

template<class T, class U> T firstTrue(T l, T r, U f) {
	assert(l <= r);
	T ans = r + 1;
	while (l <= r) {
		T mid = l + (r - l) / 2;
		if (!f(mid)) {
			l = mid + 1;
		} else {
			ans = mid;
			r = mid - 1;
		}
	}
	return ans;
}

template<class T, class U> T lastTrue(T l, T r, U f) {
	assert(l <= r);
	T ans = firstTrue(l, r, [&] (T x) {
		return !f(x); 
	});
	return ans - 1;
}