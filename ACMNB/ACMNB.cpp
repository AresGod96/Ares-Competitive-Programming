#include <bits/stdc++.h>
#define ii pair<long,long>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
vector<pair<long,ii> > a;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	long n,nA=0,nB=0,res=0;
	scanf("%ld",&n);
	for (long i=1; i<=n<<1; ++i)
	{
		long x,y;
		scanf("%ld%ld",&x,&y);
		a.pb(mp(abs(x-y),mp(x,y)));
	}
	sort(a.begin(),a.end());
	for (long i=(n<<1)-1; i>=0; --i)
	{
		if (nA==n) res+=a[i].se.se;
		if (nB==n) res+=a[i].se.fi;
		if (nA<n && nB<n)
		{
			if (a[i].se.fi>a[i].se.se) res+=a[i].se.se,++nB;
			else res+=a[i].se.fi,++nA;
		}
	}
	printf("%ld",res);
	return 0;
}
