#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
vector<pair<int, ii>> a;

int main()
{
	int n, nA = 0, nB = 0, res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n << 1; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a.pb(mp(abs(x - y), mp(x, y)));
	}
	sort(a.begin(),a.end());
	for (int i = (n << 1) - 1; i >= 0; --i)
	{
		if (nA == n) res += a[i].se.se;
		if (nB == n) res += a[i].se.fi;
		if (nA < n && nB < n)
		{
			if (a[i].se.fi > a[i].se.se) res += a[i].se.se, ++nB;
			else res += a[i].se.fi, ++nA;
		}
	}
	printf("%d\n", res);
	return 0;
}
