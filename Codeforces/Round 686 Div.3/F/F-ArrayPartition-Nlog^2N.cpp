/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: CF ROUND 1454 F - Array Partition
	- Problem link: https://codeforces.com/contest/1454/problem/F
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
const int MAXN = 2e5 + 100;
const int MOD = 1e9 + 7;
const ll MAXV = 1e9;
const double eps = 1e-12;
const int INF = 2e9 + 100;
const ll INF_LL = 1e16;

// Range Min/Max Query
struct RangeQuery {
	// 0-indexed and int type
	vector<vector<int> > rmin, rmax;
	int Log[MAXN];
	int sz;

	void initRMQ(vector<int> a) {
		int n = a.size();
		sz = n;
		rmin.resize(n + 1), rmax.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			rmin[i].resize(25), rmax[i].resize(25);
		}
		for (int i = 1; i <= a.size(); ++i) {
			rmax[i][0] = rmin[i][0] = a[i - 1];
			int e = 1, j = 1;
			while ((1 << j) <= i) {
				rmin[i][j] = min(rmin[i][j - 1], rmin[i - e][j - 1]);
				rmax[i][j] = max(rmax[i][j - 1], rmax[i - e][j - 1]);
				Log[i] = j++, e <<= 1;
			}
		}
	}
	RangeQuery(vector<int> a) { initRMQ(a);};

	int get_min(int u, int v) {
		++u, ++v;
		int k = Log[v - u + 1];
		return min(rmin[v][k], rmin[u + (1 << k) - 1][k]);
	}

	int get_max(int u, int v) {
		++u, ++v;
		int k = Log[v - u + 1];
		return max(rmax[v][k], rmax[u + (1 << k) - 1][k]);
	}
};


int Ares_KN() // main
{
	int nTest;
	cin >> nTest;
	while (nTest--) {
		int n;
		int max_val = 0;
		cin >> n;
		vector<int> a(n);
		map<int, int> cnt;
		map<int, set<int> > pos;
		REP(i, n) {
			cin >> a[i];
			++cnt[a[i]];
			max_val = max(max_val, a[i]);
			pos[a[i]].insert(i);
		}

		if (cnt[max_val] >= 3) {
			puts("YES");
			vector<int> pos;
			REP(i, n)
				if (a[i] == max_val)
					pos.emplace_back(i);

			int p = pos[1];
			printf("%d %d %d\n", p, 1, n - p - 1);
		}
		else {
			RangeQuery rmq(a);
			stack<int> st;
			vector<int> L(n), R(n);

			REP(i, n) {
				while (!st.empty() && a[st.top()] <= a[i])
					st.pop();
				L[i] = st.empty() ? 0 : st.top() + 1;
				st.push(i);
			}
			while (!st.empty()) st.pop();
			FORD(i, n - 1, 0) {
				while (!st.empty() && a[st.top()] <= a[i])
					st.pop();
				R[i] = st.empty() ? n - 1 : st.top() - 1;
				st.push(i);
			}

			bool gotans = false;
			REP(i, n) {
				int val = a[i];
				if (val == max_val) {
					break;
				}
				if (cnt[val] < 3 || L[i] > 0) continue;
				int l = R[i] + 1;
				int p_last = *pos[val].rbegin();
				if (R[p_last] < n - 1) continue;
				int r = L[p_last] - 1;

				if (rmq.get_min(l, r) == val) {
					gotans = true;
					printf("YES\n%d %d %d\n", l, r - l + 1, n - r - 1);
					break;
				}
				bool good = false;
				auto it = pos[val].lower_bound(l);
				--it;
				int p = *it;
				if (p > i) {
					int mmin = rmq.get_min(p, r);
					if (mmin == val) good = true;
				}
				if (good) {
					gotans = true;
					printf("YES\n%d %d %d\n", p, r - p + 1, n - r - 1);
					break;
				}

				it = pos[val].lower_bound(r);
				p = *it;
				if (p < p_last) {
					int mmin = rmq.get_min(l, p);
					if (mmin == val) good = true;
				}
				if (good) {
					gotans = true;
					printf("YES\n%d %d %d\n", l, p - l + 1, n - p - 1);
					break;
				}
			}

			if (!gotans)
				puts("NO");
		}
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