/* 
	- author: Ares
	- "Let's make it to ORANGE!"
	- Problem: Malaysian Computing Olympiad MCO 2014 - E - Fish
	- Problem link: https://www.acmicpc.net/problem/13215
	- Solution: Treap
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

// Treap
class Treap {
	public:
		struct Node {
			ll key;
			int priority, size;
			Node* left;
			Node* right;

			Node(ll key) : key(key), priority(rand()), size(1), left(nullptr), right(nullptr) {}
		};

		Treap() : root(nullptr) {
			srand(time(0));  // Seed for random priorities
		}

		void insert(ll key) {
			root = insert(root, key);
		}

		int count_less_than(ll K) const {
			return count_less_than(root, K);
		}

	private:
		Node* root;

		int get_size(Node* node) const {
			return node ? node->size : 0;
		}

		void update_size(Node* node) {
			if (node) {
				node->size = get_size(node->left) + get_size(node->right) + 1;
			}
		}

		Node* rotate_right(Node* y) {
			Node* x = y->left;
			Node* T2 = x->right;

			// Perform rotation
			x->right = y;
			y->left = T2;

			// Update sizes
			update_size(y);
			update_size(x);

			// Return new root
			return x;
		}

		Node* rotate_left(Node* x) {
			Node* y = x->right;
			Node* T2 = y->left;

			// Perform rotation
			y->left = x;
			x->right = T2;

			// Update sizes
			update_size(x);
			update_size(y);

			// Return new root
			return y;
		}

		Node* insert(Node* root, ll key) {
			if (!root) return new Node(key);

			if (key < root->key) {
				root->left = insert(root->left, key);
				if (root->left->priority > root->priority) {
					root = rotate_right(root);
				}
			} else {
				root->right = insert(root->right, key);
				if (root->right->priority > root->priority) {
					root = rotate_left(root);
				}
			}

			update_size(root);
			return root;
		}

		int count_less_than(Node* root, ll K) const {
			if (!root) return 0;

			if (root->key < K) {
				return 1 + get_size(root->left) + count_less_than(root->right, K);
			} else {
				return count_less_than(root->left, K);
			}
		}
};
// end of Treap


ll count_subarray(const vector<int>& a, int value) {
	int n = a.size();
	vector<ll> prefix(n + 1, 0);
	REP(i, n) prefix[i] = a[i] + (i ? prefix[i - 1] : 0);

	Treap treap;
	treap.insert(prefix[0]);
	ll res = a[0] >= value;
	FOR(i, 1, n - 1) {
		// count number of keys less than or equal to (prefix[i]-value)
		res += treap.count_less_than(prefix[i] - value + 1);
		treap.insert(prefix[i]);

		res += prefix[i] >= value;
	}

	return res;
}

int Ares_KN() // main
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	printf("%lld\n", count_subarray(a, k));

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
