/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: CF ROUND 1873 - H - Mad City
	- Problem link: https://codeforces.com/contest/1873/problem/H
*/
#define LOCAL
#undef LOCAL

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

// DEBUG template - many thanks to tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
	return '"' + s + '"';
}
 
string to_string(const char* s) {
	return to_string((string) s);
}
 
string to_string(bool b) {
	return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first)
			res += ", ";
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++)
		res += static_cast<char>('0' + v[i]);
	return res;
}
 
template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first)
			res += ", ";
		first = false;
		res += to_string(x);
  	}
	res += "}";
	return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__);
#else
	#define debug(...) 42;
#endif

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

int n;
vector<int> g[MAXN];
vector<int> tin, low, cycle;
vector<pii> edges;
set<pii> bridges;
vector<bool> visited, in_cycle;
int timer;

void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to: g[v]) {
	 	if (to == p) continue;
	 	if (visited[to]) {
	 		low[v] = min(low[v], tin[to]);
	 	} else {
	 		dfs(to, v);
	 		low[v] = min(low[v], low[to]);
	 		if (low[to] > tin[v]) {
				if (v > to) {
					bridges.emplace(to, v);
				}
				else  {
					bridges.emplace(v, to);
				}
			}
	 	}
	}
}

// for Dijkstra
vector<int> dist;

void dijkstra(int src) {
	dist.resize(n + 1);
	FOR(u, 1, n) dist[u] = INF;
	dist[src] = 0;
	priority_queue<pii> heap;
	heap.emplace(0, src);
	while (!heap.empty()) {
		int u = heap.top().se;
		heap.pop();
		for (auto v: g[u]) {
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				heap.emplace(-dist[v], v);
			}
		}
	}
}

pair<int, int> dist_to_cycle(int src) {

	dijkstra(src);

	pair<int, int> res = {INF, -1};
	FOR(u, 1, n)
		if (u != src && in_cycle[u] && res.fi > dist[u]) {
			res = {dist[u], u};
		}
	return res;
}

int dist_to_vertex(int src, int u) {

	dijkstra(src);
	return dist[u];
}

int Ares_KN() // main
{
	int testInd = 0;
	int nTest;
	cin >> nTest;
	while (nTest--) {
		testInd++;
		int st, en;
		cin >> n >> st >> en;
		/*
			Input:
				N vertices with (N-1) edges -> exists 1 cycle
			
			Alogirhtm:
				Find vertices belong to that cycle, and if Valeriu enters the cycle first
				then he can escape forever
		*/

		// initialization

		timer = 0;
		visited.assign(n + 1, false);
		tin.assign(n + 1, -1);
		low.assign(n + 1, -1);
		edges.clear();
		bridges.clear();
		cycle.clear();
		in_cycle.assign(n + 1, false);
		FOR(u, 1, n) g[u].clear();

		REP(i, n) {
			int u, v;
			cin >> u >> v;
			g[u].emplace_back(v), g[v].emplace_back(u);
			if (u > v) swap(u, v);
			edges.emplace_back(u, v);
		}
		if (st == en) {
			puts("NO");
			continue;
		}
		FOR(u, 1, n)
			if (!visited[u]) dfs(u);
		
		auto is_bridge = [&](int u, int v) {
			if (u > v) swap(u, v);
			return bridges.count({u, v});
		};

		for (auto [u, v]: edges) {
			if (!is_bridge(u, v)) {
				if (!in_cycle[u]) {
					in_cycle[u] = true;
				}
				if (!in_cycle[v]) {
					in_cycle[v] = true;
				}
			}
		}
		
		// case 1: escaper already in cycle -> YES
		if (in_cycle[en]) {
			puts("YES");
		}
		// case 2: escaper hasn't been to cycle, check if catcher can get into the cycle first
		else {
			pair<int, int> meta = dist_to_cycle(en);
			int escaper = meta.fi;

			// the first vertex in cycle which escapers reach
			int node = meta.se;
			int catcher = dist_to_vertex(st, node);
			puts(escaper < catcher ? "YES" : "NO");
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
	return 0;
}