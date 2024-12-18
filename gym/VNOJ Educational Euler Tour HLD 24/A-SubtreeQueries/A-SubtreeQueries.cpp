/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: Educational Euler Tour and HLD Contest - A - Subtree Queries
	- Problem link: https://oj.vnoi.info/problem/euler_A
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
const int MAXN = 2e5 + 10;
const int MOD = 1e6;
const int MAX_VALUE = 2e5;
const double eps = 1e-12;
const int INF = 2e9 + 100;
const ll INF_LL = 1e16;

const int MAX_NODE = 2e5 + 10;
struct SegmentTree {
	struct Node {
		ll value;

		Node() {
			(*this).value = 0;
		}
		
		Node(ll value) {
			(*this).value = value;
		}
	};

	int size;
	vector<int> a;
	vector<Node> st;

	Node combine(Node le, Node ri) {
		return Node(le.value + ri.value);
	}

	void build(int id, int l, int r) {
		if (l == r) {
			st[id] = Node(a[l - 1]);
			return;
		}
		int mid = (l + r) >> 1;
		build(id << 1, l, mid);
		build(id << 1 | 1, mid + 1, r);

		st[id] = combine(st[id << 1], st[id << 1 | 1]);
	}

	void update(int id, int l, int r, int u, ll value) {
		if (l > u || r < u) return;
		if (l == r) {
			st[id] = Node(value);
			return;
		}
		int mid = (l + r) >> 1;
		update(id << 1, l, mid, u, value);
		update(id << 1 | 1, mid + 1, r, u, value);

		st[id] = combine(st[id << 1], st[id << 1 | 1]);
	}

	void update(int u, ll value) {
		update(1, 1, size, u, value);
	}

	// get sum of value in [u..v]
	Node query(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return Node(0);
		if (u <= l && r <= v) return st[id];
		int mid = (l + r) >> 1;

		return combine(query(id << 1, l, mid, u, v), query(id << 1 | 1, mid + 1, r, u, v));
	}

	ll query(int l, int r) {
		Node res = query(1, 1, size, l, r);
		return res.value;
	}

	SegmentTree(vector<int> a) {
		(*this).a = a;
		size = a.size();
		st.resize(size << 2 | 1);
		build(1, 1, size);
	}

	SegmentTree(int sz) {
		size = sz;
	}
};

vector<int> value;
vector<vector<int>> g;

class EulerTour {
	public:
		int root;
		int n_vertices;
		vector<int> par;
		vector<int> tour;
		vector<int> tin, tout;

		EulerTour(vector<vector<int>> g, int root) {
			int n_vertices = g.size();
			par.resize(n_vertices + 1, -1);
			(*this).root = root;
			par[root] = 0;
			tin.resize(n_vertices + 1, -1);
			tout.resize(n_vertices + 1);

			dfs(root);
		}

		void print() {
			for (auto v: tour) printf("%d ", v);
			puts("");
		}

		void add(int u) {
			// tour.emplace_back(u);
			tour.emplace_back(value[u]);
			if (tin[u] == -1) tin[u] = int(tour.size() - 1);
			tout[u] = int(tour.size() - 1);
		}

		void dfs(int u) {
			// begin of subtree rooted at u
			add(u);
			for (auto v: g[u])
				if (par[v] == -1) {
					par[v] = u;
					dfs(v);
				}

			// end of subtree rooted at u
			add(u);
		}
};


int Ares_KN() // main
{
	int n, q;
	cin >> n >> q;
	value.resize(n + 1);
	g.resize(n + 1);
	FOR(u, 1, n) cin >> value[u];

	REP(i, n - 1) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	int root = 1;
	EulerTour et(g, root);
	// et.print();

	SegmentTree st(et.tour);
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			// update
			int u, value;
			cin >> u >> value;
			auto update = [&](int u, ll value) {
				st.update(et.tin[u] + 1, value);
				st.update(et.tout[u] + 1, value);
			};

			update(u, value);
		}
		else {
			// query
			int u;
			cin >> u;
			auto query = [&](int u) {
				int l = et.tin[u] + 1;
				int r = et.tout[u] + 1;
				return st.query(l, r) / 2;
			};

			printf("%lld\n", query(u));
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