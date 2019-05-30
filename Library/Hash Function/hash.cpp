// Hash function
// submitted on problem K ACM ICPC Mid-central USA Regional 2018
// https://open.kattis.com/contests/d7yx3a/problems/repeatedsubstrings
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,a) for (int i = 0, _a = (a); i < _a; ++i)
#define REPD(i,a) for (int i = (a) - 1; i >= 0; --i)
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e5 + 100;

// Hash function template
// base and list of modulos, NMOD = number of mods to be used
const int NMOD = 2;
const int MOD_LIST[4] = {(int)1e9 + 5277, (int)1e9 + 9277, (int)1e9 + 7, (int)1e9 + 9999};
const int base = 311;
const bool mod64 = true; // allow overflow mod
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
string s;
Hash H;

bool good(int x) {
	map<ull, int> M;
	REP(i, s.size())
	{
		int j = i + x - 1;
		if (j >= s.size()) break;
		ull tmp = H.getHash(i, j);
		++M[tmp];
		if (M[tmp] > 1) return true;
	}
	return false;
}

bool better(string x, string y) {
	REP(i, x.size())
		if (x[i] > y[i]) return true;
		else if (x[i] < y[i]) return false;
	return false;
}

int main()
{
	//freopen(".inp", "r", stdin);	freopen(".out", "w", stdout);
	cin >> s;
	int l = 1, r = s.size();
	// build hash array
	H = Hash(s);
	do
	{
		int mid = (l + r) >> 1;
		if (!good(mid)) r = mid - 1; else l = mid;
	} while (l + 1 < r);

	// test with l
	int len = good(r) ? r : l;
	map<ull, int> M;
	string res = "";
	REP(i, s.size())
	{
		int j = i + len - 1;
		if (j >= s.size()) break;
		ull tmp = H.getHash(i, j);
		++M[tmp];
		if (M[tmp] > 1)
		{
			string tmp = s.substr(i, len);
			if (res == "") res = tmp;
			else if (better(res, tmp)) res = tmp;
		}
	}
	cout << res;
}
