// - Author: Ares
// - Compatible with C++11 
// CAN YOU GET AC IN ONE HIT? :D
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <cassert>
#include <iomanip>
#include <iostream>
#include <cstdio> 
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>
#include <bitset>
#include <random>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag,
//tree_order_statistics_node_update> ordered_set;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define REPD(i, a) for (int i = (a) - 1; i >= 0; --i)
#define fi first
#define se second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define prev KhanhNgan
#define next MinhTu
#define y0 chuquachula
#define y1 tacadada
#define left uzumakinaruto
#define right uchihasasuke
#define PI (2 * acos((double)0))
#define sec(x) 1.0 / cos((x))
#define asec(x) acos(1.0 / (x))
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline int minimize(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int maximize(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define ARR(X, L, R) { cerr << #X << " = {"; FOR(_, L, R) cerr << ' ' << X[_]; cerr << " }\n"; }
#define SET(X) { cerr << "set " << #X << " = "; for (auto _:X) cerr << _ << ' '; cerr << '\n'; }
#define MAP(X) { cerr << "map " << #X << " = "; for (auto _:X) cerr << '(' << _.first << ' ' << _.second << ')' << '\n'; }
#define debugfunc(f, x) printf("%s(%g) = %g\n", #f, (x), (f(x)));
#define debugfunc2(f, x, y) printf("%s(%g,%g) = %g\n", #f, (x), (y), (f((x), (y))));

#define sqr(x) ((x) * (x))
#define unify(x) x.erase(unique(x.begin(), x.end()), x.end())
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
mt19937 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() { return abs((int) RNG()); }
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
const int MAXN = 5e5 + 100;
const int MOD = 1e9 + 7;
const ll MAXV = 1e9;
const double eps = 1e-12;
const ll INF = 1e16;

inline string toStr(ll x) {
	string tmp = "";
	do tmp = char(x % 10 + '0') + tmp; while (x /= 10);
	return tmp;
}
inline ll toInt(string s) {
	ll res = 0;
	for (auto x: s) res = res * 10 + x - '0';
	return res;
}
inline string toBinStr(ll x) {
	string res = "";
	do res = (x % 2 ? "1" : "0") + res; while (x >>= 1LL);
	return res;
}
ll rnd(int k) {
	if (!k) return myrand() % MAXV + 1;
	ll t = myrand() % MAXV + 1;
	return (myrand() % t) + (MAXV - t);
}
ll random_gen(int sign) {
	ll x = rnd(myrand() % 2);
	ll s = myrand() % 2; s = !s ? 1 : -1;
	return sign == 1 ? x : sign == -1 ? -x : s * x;
}
// template ends here
const int sz = 3; // size of matrix
struct matrix {
	ll M[sz][sz];

	matrix()
	{
		REP(i, sz)
			REP(j, sz) M[i][j] = 0;
	}

	void show()
	{
		REP(i, sz)
		{
			REP(j, sz) printf("%lld ", M[i][j]);
			puts("");
		}
	}
	
	matrix operator*(matrix b)
	{
		matrix c;
		REP(i, sz)
			REP(j, sz)
			{
				c.M[i][j] = 0;
				REP(k, sz)
				{
					c.M[i][j] += (*this).M[i][k] * b.M[k][j];
					c.M[i][j] %= MOD;
				}
			}
		return c;
	}

	matrix Exp(ll k)
	{
		if (k == 1) return (*this);
		matrix tmp = Exp(k >> 1);
		tmp = tmp * tmp;
		return k & 1 ? ((*this) * tmp) : tmp;
	}
};

ll Sum_fib(int n)
{
	if (!n) return 0;
	if (n == 1) return 1;
	matrix a = matrix();
	a.M[0][0] = 0;
	a.M[1][0] = 1;
	a.M[2][0] = 1;
	matrix b;
	b.M[0][1] = 1;
	b.M[1][0] = b.M[1][1] = 1;
	b.M[2][0] = b.M[2][1] = b.M[2][2] = 1;
	b = b.Exp(n - 1);
	a = b * a;
	return a.M[2][0];
}

int Ares_KN() // main
{
	int nTest;
	cin >> nTest;
	while (nTest--)
	{
		int l, r;
		cin >> l >> r;
		if (!l)
		{
			printf("%lld\n", Sum_fib(r));
			continue;
		}
		ll tmp = Sum_fib(r) - Sum_fib(l - 1);
		while (tmp < 0) tmp += MOD;
		printf("%lld\n", tmp);
	}
	
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	IOS
	Ares_KN();
	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
