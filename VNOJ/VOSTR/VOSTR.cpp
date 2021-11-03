/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: VNSPOJ - VOSTR
	- Problem link: https://vn.spoj.com/problems/VOSTR/
*/
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

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

mt19937 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() { return abs((int) RNG()); }
int randint(int lb, int ub) {
	return uniform_int_distribution<int>(lb, ub)(RNG);
}

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

// template ends here
const int MAXN = 5e5 + 100;
const int MOD = 1e9 + 7;
const ll MAXV = 1e9;
const double eps = 1e-12;
const int INF = 2e9 + 100;
const ll INF_LL = 1e16;

// Hash function template
// base and list of modulos, NMOD = number of mods to be used
const int NMOD = 2;
const int MOD_LIST[4] = {(int)1e9 + 5277, (int)1e9 + 9277, (int)1e9 + 7, (int)1e9 + 9999};
const int base = 311;
const bool mod64 = false; // allow overflow mod
struct Hash {
	vector<ll> p[NMOD + mod64], value[NMOD + mod64];
	Hash() {
		REP(i, NMOD + mod64) p[i].clear(), value[i].clear();
	}
	Hash(const string s) {
		int len = s.size();
		REP(i, NMOD + mod64) p[i].resize(len), value[i].resize(len), p[i][0] = 1;
		FOR(i, 1, len - 1)
		{
			REP(j, NMOD)
				p[j][i] = (p[j][i - 1] * base) % MOD_LIST[j];
			if (mod64) p[NMOD][i] = p[NMOD][i - 1] * base;
		}
		REP(i, len)
		{
			REP(j, NMOD)
			{
				if (!i) value[j][i] = (s[i] - 'a' + 1) % MOD_LIST[j];
				else value[j][i] = (value[j][i - 1] * base + s[i] - 'a' + 1) % MOD_LIST[j];
			}
			if (mod64)
			{
				if (!i) value[NMOD][i] = s[i] - 'a' + 1;
				else value[NMOD][i] = value[NMOD][i - 1] * base + s[i] - 'a' + 1;
			}
		}

	}
	void init(string s) {
		(*this) = Hash(s);
	}

	ull getHash(int l, int r) {
		ull res = 0;
		REP(j, NMOD)
		{
			ll tmp = 0;
			if (!l) tmp = (value[j][r] + 1LL * MOD_LIST[j] * MOD_LIST[j]) % MOD_LIST[j];
			else tmp = (value[j][r] - value[j][l - 1] * p[j][r - l + 1] + 1LL * MOD_LIST[j] * MOD_LIST[j]) % MOD_LIST[j];
			while (tmp < 0) tmp += MOD_LIST[j];
			res += tmp;
		}
		if (mod64)
		{
			ll tmp = 0;
			if (!l) tmp = value[NMOD][r];
			else tmp = value[NMOD][r] - value[NMOD][l - 1] * p[NMOD][r - l + 1];
			res += tmp;
		}
		return res;
	}
};
//
Hash hash_s, hash_t;

bool equal(int ls, int rs, int lt, int rt)
{
	if (rs - ls != rt - lt) return false;
	ull value_s = hash_s.getHash(ls, rs);
	ull value_t = hash_t.getHash(lt, rt);
	return value_s == value_t;
}

int Ares_KN() // main
{
	int len_s, len_t;
	string s, t;
	cin >> len_s >> len_t;
	cin >> s >> t;

	hash_s = Hash(s), hash_t = Hash(t);
	int q;
	cin >> q;
	while (q--)
	{
		int sx, sy, tx, ty;
		cin >> sx >> sy >> tx >> ty;
		--sx, --sy, --tx, --ty;
		if (equal(sx, sy, tx, ty))
		{
			printf("=");
			continue;
		}
		int min_len = min(sy - sx, ty - tx);
		if (equal(sx, sx + min_len, tx, tx + min_len))
		{
			printf(sy - sx < ty - tx ? "<" : ">");
			continue;
		}
		
		int l = 0, r = min_len;
		do
		{
			int mid = (l + r) >> 1;
			if (equal(sx, sx + mid, tx, tx + mid))
				l = mid;
			else
				r = mid - 1;
		} while (l + 1 < r);
		if (s[sx + l] != t[tx + l])
		{
			printf(s[sx + l] < t[tx + l] ? "<" : ">");
			continue;
		}
		while (s[sx + l] == t[tx + l]) ++l;
		if (s[sx + l] < t[tx + l]) printf("<");
		else if (s[sx + l] > t[tx + l]) printf(">");
	}
	return 0;
}

int main()
{
	//freopen(".inp", "r", stdin);	freopen(".out", "w", stdout);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	IOS
	Ares_KN();
	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}