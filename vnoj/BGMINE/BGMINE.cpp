#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int MAXN = 111111;;
struct mine {
	ll x, amount, l;
};
int Min[MAXN];
ll sum[MAXN], L[MAXN];
pair<ll, int> c[MAXN];
mine a[MAXN];

bool cmp(mine i, mine j) {return i.x < j.x;}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i) scanf("%lld%lld%lld", &a[i].x, &a[i].amount, &a[i].l);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i].amount;
		L[i] = L[i - 1] + a[i].l;
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i)
	{
		ll tmp = a[i].x - L[i - 1];
		c[i] = mp(tmp, i);
	}
	sort(c + 1, c + n + 1);
	Min[n] = c[n].se;
	for (int i = n - 1; i >= 1; --i) Min[i] = min(Min[i+1], c[i].se);
	for (int i = 1; i <= n; ++i)
	{
		ll tmp=a[i].x - L[i];
		pair<ll,int> *it = lower_bound(c + 1, c + n + 1, mp(tmp, 0));
		if (it != c + n + 1)
		{
			int pos = it - c, j = Min[pos];
			if (j <= i) res = max(res, sum[i] - sum[j - 1]);
		}
	}
	printf("%lld", res);
	return 0;
}
