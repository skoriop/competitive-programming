#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
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
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
#define ln "\n"
#define pb push_back
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define rev(x) (x).rbegin(), (x).rend()

string dbg_function;
int dbg_line;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
	os << '{';
	string sep;
	for (const T &x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << "\033[0;31m" << dbg_function << ":" << dbg_line << " -> \033[0;33m" << *it << " = " << a << "\033[0m" << ln;
	err(++it, args...);
}
#ifdef LOCAL
#define dbg(args...)                             \
	{                                            \
		dbg_function = __func__;                 \
		dbg_line = __LINE__;                     \
		string _s = #args;                       \
		replace(_s.begin(), _s.end(), ',', ' '); \
		stringstream _ss(_s);                    \
		istream_iterator<string> _it(_ss);       \
		err(_it, args);                          \
	}
#else
#define dbg(...) 42
#endif

int lg2(int i)
{
	return 31 - __builtin_clz(i);
}
int lg2(ll i) { return 63 - __builtin_clzll(i); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());

template <class T, class U>
T firstTrue(T l, T r, U f)
{
	assert(l <= r);
	T ans = r + 1;
	while (l <= r)
	{
		T mid = l + (r - l) / 2;
		if (!f(mid))
		{
			l = mid + 1;
		}
		else
		{
			ans = mid;
			r = mid - 1;
		}
	}
	return ans;
}

template <class T, class U>
T lastTrue(T l, T r, U f)
{
	assert(l <= r);
	T ans = firstTrue(l, r, [&](T x)
					  { return !f(x); });
	return ans - 1;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;

void solve()
{
}

int main()
{
	fastio;
	// cout << fixed << setprecision(10);
	ll t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	cerr << ln;
	return 0;
}