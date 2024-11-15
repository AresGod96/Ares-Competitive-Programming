/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: GCJ 2019 Round 1C - Power Arrangers
	- Problem link: https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134e91
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

//#define LOCAL
const int MAXN = 5e5 + 100;
const int MOD = 1e9 + 7;
const ll MAXV = 1e9;
const double eps = 1e-12;
const int INF = 2e9 + 100;
const ll INF_LL = 1e16;

int p[6][123];
set<int> pos[6][123];
string ANS;
int fact[6] = {1, 1, 2, 6, 24, 120};
int query = 0;

char ask(int pos) 
{
	#ifdef LOCAL
		++query;
		return ANS[pos - 1];
	#else
		printf("%d\n", pos);
		fflush(stdout);
		char res;
		cin >> res;
		return res;
	#endif
}

int Ares_KN() // main
{
	int nTest, maxF;
	cin >> nTest >> maxF;
	if (maxF == 475)
	{
		while (nTest--)
		{
			#ifdef LOCAL
				cin >> ANS;
			#endif
			FOR(i, 1, 5)
				FOR(c, 'A', 'E') pos[i][c].clear();
			string res = "";
			FOR(i, 1, 5) memset(p[i], 0, sizeof(p[i]));
			FOR(k, 1, 3)
				FOR(i, 1, 119)
				{
					char tmp = ask((i - 1) * 5 + k);
					++p[k][tmp];
					pos[k][tmp].insert(i);
				}

			// find for first three letters
			FOR(k, 1, 3)
				FOR(c, 'A', 'E') if (p[k][c] == 23)
				{
					res += c;
					break;
				}
		
			int good_set; // good set is the only set with same 3 first letters as the missing permutation
			FOR(i, 1, 119)
			{
				bool ok = true;
				ok &= pos[1][res[0]].count(i);
				ok &= pos[2][res[1]].count(i);
				ok &= pos[3][res[2]].count(i);
				if (ok)
				{
					good_set = i;
					break;
				}
			}
			char tmp = ask((good_set - 1) * 5  + 5);
			res += tmp;
			tmp = ask((good_set - 1) * 5 + 4);
			res += tmp;
			printf("%s\n", res.c_str());
			fflush(stdout);

			char answer;
			cin >> answer;
			if (answer == 'N') return 0;
		}
	}
	
	if (maxF == 150)
	{
		while (nTest--)
		{
			#ifdef LOCAL
				cin >> ANS;
			#endif
			FOR(i, 1, 5)
				FOR(c, 'A', 'E') pos[i][c].clear();
			string res = "";
			FOR(i, 1, 5) memset(p[i], 0, sizeof(p[i]));
			set<int> good_set;
			FOR(i, 1, 119) good_set.insert(i);

			int cur = 1;
			int query = 0;
			while (res.size() < 3)
			{
				for (auto i: good_set)
				{
					// check set i
					char tmp = ask((i - 1) * 5 + cur);
					++p[cur][tmp];
					pos[cur][tmp].insert(i);
				}
				
				// find cur letter
				FOR(c, 'A', 'E') if (p[cur][c] == (fact[6 - cur] / (6 - cur) - 1) )
				{
					res += c;
					vector<int> del;
					for (auto x: good_set) if (!pos[cur][c].count(x)) del.push_back(x);
					for (auto x: del) good_set.erase(x);
					break;
				}
				++cur;
			}
			char tmp = ask((*good_set.begin() - 1) * 5  + 5);
			res += tmp;
			tmp = ask((*good_set.begin() - 1) * 5 + 4);
			res += tmp;
			printf("%s\n", res.c_str());
			fflush(stdout);

			char answer;
			cin >> answer;
			if (answer == 'N') return 0;
		}
	}
	#ifdef LOCAL
		printf("%d\n", query);
	#endif
	return 0;
}

int main()
{
	//freopen(".inp", "r", stdin);	freopen(".out", "w", stdout);
	IOS
	Ares_KN();
	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}