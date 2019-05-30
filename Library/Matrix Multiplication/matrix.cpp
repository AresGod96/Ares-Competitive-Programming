#include <cstdio> 
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define REPD(i, a) for (int i = (a) - 1; i >= 0; --i)
#define fi first
#define se second
typedef long long ll;
const int MOD = 1e9 + 7;

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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	int nTest;
	scanf("%d", &nTest);
	while (nTest--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
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
