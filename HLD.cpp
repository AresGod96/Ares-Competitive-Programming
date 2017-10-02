#include <bits/stdc++.h>
#define maxN long(1e5+100)
#define maxP 31
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int nChain,chainInd[maxN],chainHead[maxN],nBase,posInBase[maxN];
int par[maxN],nChild[maxN];
int n,k,c[maxN],P[maxN][maxP],L[maxN],f[maxN];
vector<int> g[maxN];

void dfs(int u,int h)
{
	c[u]=1,L[u]=h;
	nChild[u]=1;
	for (auto v:g[u]) if (!c[v])
	{
		dfs(v,h+1);
		par[v]=u,nChild[u]+=nChild[v];
	}
}
void HLD(int u)
{
	if (!chainHead[nChain]) chainHead[nChain]=u;
	chainInd[u]=nChain;
	posInBase[u]=++nBase;
	int choose=-1;
	for (auto v:g[u])
	{
		if (v!=par[u])
		{
			if (choose==-1 || nChild[v]>nChild[choose]) choose=v;
		}
	}
	if (choose>-1) HLD(choose);
	for (auto v:g[u])
		if (v!=par[u] && v!=choose) ++nChain,HLD(v);
}

void BuildLCA()
{
	for (int i=0; i<=n; ++i)
		for (int j=1; j<=trunc(log2(n)); ++j) P[i][j]=-1;
	for (int i=1; i<=n; ++i) P[i][0]=par[i];
	
	for (int j=1; j<=trunc(log2(n)); ++j)
		for (int i=0; i<=n; ++i) if (P[i][j-1]!=-1) P[i][j]=P[P[i][j-1]][j-1];
}

int lca(int u,int v)
{
	if (L[u]<L[v]) swap(u,v);
	int x=1;
	while (x<=log2(L[u])) ++x;--x;
	
	for (int i=x; i>=0; --i)
		if (L[u]-(1<<i) >= L[v]) u=P[u][i];
	if (u==v) return u;
	for (int i=x; i>=0; --i)
		if (P[u][i]!=-1 && P[u][i]!=P[v][i]) u=P[u][i],v=P[v][i];
	return par[u];
}

void update(int u,int v) //u is a child of v
{
	int uchain;
	while (u)
	{
		if (chainInd[u]==chainInd[v])
		{
			int L=min(posInBase[u],posInBase[v]);
			int R=max(posInBase[u],posInBase[v]);
			++f[L],--f[R+1];
			break;
		}
		uchain=chainInd[u];
		++f[posInBase[chainHead[uchain]]],--f[posInBase[u]+1];
		u=par[chainHead[uchain]];
	}
}
int main()
{
	freopen("maxflow.in","r",stdin);
	freopen("maxflow.out","w",stdout);
	int u,v;
	scanf("%d%d",&n,&k);
	for (long i=1; i<n; ++i)
	{
		scanf("%d%d",&u,&v);
		g[u].pb(v),g[v].pb(u);
	}
	par[1]=0;
	dfs(1,1);
	nChain=1;
	HLD(1);
	BuildLCA();
	while (k--)
	{
		scanf("%d%d",&u,&v);
		int tmp=lca(u,v);
		update(u,tmp);
		update(v,tmp);
		--f[posInBase[tmp]],++f[posInBase[tmp]+1];
	}
	int res=0;
	for (int i=1; i<=n; ++i) f[i]+=f[i-1],res=max(res,f[i]);
	printf("%d",res);
}
