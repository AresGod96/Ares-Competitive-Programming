/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: Croatian Highschool Competitions in Informatics 2006 - Final Exam #2 - LUBENICA
	- Problem link: https://www.acmicpc.net/problem/3176

	- Tags: lca
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
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll MAXV = 1e9;
const double eps = 1e-12;
const int INF = 2e9 + 100;
const ll INF_LL = 1e16;

vector<vector<pii>> g;

int dist[MAXN];	// distance from root
int up[MAXN][19];
int max_path[MAXN][19];
int min_path[MAXN][19];
int depth[MAXN];

class LCA {
	/*
		This LCA finds the lowest common ancestor of two nodes (u, v) using binary lifting method
		Pre-process: O(NlogN)
		Query: O(logN)
	*/
	public:
		int n, LOG;
		int root;
	
		LCA(vector<vector<pii>> g, int root) {
			n = g.size();
			LOG = log2(n) + 1;
			this->root = root;
			depth[root] = 0;
			dfs(root, root, 0);
		}

		void dfs(int u, int p, int w) {
			up[u][0] = p;
			if (u == p) {
				max_path[u][0] = 0;
				min_path[u][0] = INF;
			}
			else {
				max_path[u][0] = min_path[u][0] = w;
			}

			for (int i = 1; i < LOG; ++i) {
				int prev = up[u][i - 1];
				up[u][i] = up[prev][i - 1];
				max_path[u][i] = max(max_path[prev][i - 1], max_path[u][i - 1]);
				min_path[u][i] = min(min_path[prev][i - 1], min_path[u][i - 1]);
			}

			for (auto [v, w]: g[u]) {
				if (v != p) {
					depth[v] = depth[u] + 1;
					dist[v] = dist[u] + w;
					dfs(v, u, w);
				}
			}
		}

		int get_lca(int u, int v) {
			/*
				Returns the lowest common ancestor of node u and node v using binary lifting
				Complexity: O(logN)
			*/
			if (depth[u] < depth[v]) swap(u, v);
			for (int i = LOG - 1; i >= 0; i--)
				if (depth[u] - (1 << i) >= depth[v]) {
					u = up[u][i];
				}
			if (u == v) return u;

			for (int i = LOG - 1; i >= 0; --i) {
				if (up[u][i] != up[v][i]) {
					u = up[u][i];
					v = up[v][i];
				}
			}
			return up[u][0];
		}

		int get_dist(int u, int v) {
			/*
				Returns the distance of the path between node u and node v
				Complexity: O(logN) due to get_lca(u, v)
			*/
			return dist[u] + dist[v] - 2 * dist[get_lca(u, v)];
		}
		
		int get_kth_parent(int u, int k) {
			/*
				Returns the k-th parent of node u on the way to root using binary lifting
				Complexity: O(logN)
			*/
			while (u != root) {
				if (k == 0) return u;
				if (k == 1) return up[u][0];
				int e = log2(k);
				k -= 1 << e;
				u = up[u][e];
			}
			return u;
		}

		int get_kth_child(int u, int k) {
			/*
				Returns the k-th child of root on the way from root to node u
				Complexity: O(logN)
			*/
			int d = depth[u];
			if (k > d) return -1; // no child exists
			return get_kth_parent(u, d - k);
		}

		pii get_max_min(int u, int v) {
			// since v is u's ancestor, depth[u] >= depth[v]
			if (u == v) return {0, INF};
			if (depth[u] == depth[v] + 1) return {max_path[u][0], min_path[u][0]};

			pii res = {0, INF};
			int k = depth[u] - depth[v];
			while (u != v) {
				if (k == 0) break;
				if (k == 1) {
					if (res.fi < max_path[u][0]) res.fi = max_path[u][0];
					if (res.se > min_path[u][0]) res.se = min_path[u][0];
					break;
				}
				int e = log2(k);
				res.fi = max(res.fi, max_path[u][e]);
				res.se = min(res.se, min_path[u][e]);
				k -= 1 << e;
				u = up[u][e];
			}
			return res;
		}

		pii query(int u, int v) {
			/*
				Returns the max and min length on the path between node u and node v
			*/
			int ancestor = get_lca(u, v);
			if (u == v) return {0, 0};
			
			pii u_anc = get_max_min(u, ancestor);
			pii v_anc = get_max_min(v, ancestor);
			pii res = {max(u_anc.fi, v_anc.fi), min(u_anc.se, v_anc.se)};
			return res;
		}
};


int Ares_KN() // main
{
	int n;
	cin >> n;
	g.resize(n + 1);

	REP(i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	int root = 1;
	LCA lca(g, root);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		pii res = lca.query(u, v);
		printf("%d %d\n", res.se, res.fi);
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