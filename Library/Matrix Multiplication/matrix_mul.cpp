/*
	Algorithm: Matrix multiplication

	Usage: calculate an exponentation of a square matrix
	Complexity:
		- multiplication: O(sz^3) 
		- exponentiation: O(log(k) * (sz^3)) 
	
	Submitted to SPOJ FIBOSUM at https://www.spoj.com/problems/FIBOSUM/
*/
#include <cstdio> 
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

// Matrix template
struct Matrix {
	int n;
	vector<vector<long long> > M;

	Matrix(int size) {
		n = size;
		M.resize(n, vector<long long>(n));
	}

	friend ostream& operator<<(ostream& os, const Matrix& mat) {
		int n = mat.n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) os << mat.M[i][j] << ' ';
			os << '\n';
		}
		return os;
	}
	
	Matrix operator%(int mod) {
		Matrix tmp = *this;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				tmp.M[i][j] %= mod;
			}
		return tmp;
	}

	Matrix operator*(Matrix b) {
		Matrix c(n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				c.M[i][j] = 0;
				for (int k = 0; k < n; ++k) {
					c.M[i][j] += (*this).M[i][k] * b.M[k][j];
					c.M[i][j] %= MOD;
				}
			}
		return c;
	}

	Matrix operator^(long long k) {
		if (k == 1) return *this;
		Matrix tmp = (*this)^(k >> 1);
		tmp = tmp * tmp;
		return k & 1 ? ((*this) * tmp) : tmp;
	}
};


ll sum_fib(int n) {
	if (!n) return 0;
	if (n == 1) return 1;
	Matrix a(3);
	a.M[0][0] = 0;
	a.M[1][0] = 1;
	a.M[2][0] = 1;
	Matrix b(3);
	b.M[0][1] = 1;
	b.M[1][0] = b.M[1][1] = 1;
	b.M[2][0] = b.M[2][1] = b.M[2][2] = 1;
	b = b^(n - 1);
	a = b * a;

	return a.M[2][0];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	cin.tie(0), ios::sync_with_stdio(0);
	int nTest;
	cin >> nTest;
	while (nTest--) {
		int l, r;
		cin >> l >> r;
		if (!l) {
			printf("%lld\n", sum_fib(r));
			continue;
		}
		ll tmp = sum_fib(r) - sum_fib(l - 1);
		while (tmp < 0) tmp += MOD;
		printf("%lld\n", tmp);
	}
	
	return 0;
}