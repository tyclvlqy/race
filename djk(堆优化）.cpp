#include<bits/stdc++.h>
using namespace std;
vector<int>ve[100005];
queue<int>q;
int dis[100005];
struct pt
{
	int u,d;
	bool operator<(const pt&a) const
	{
		return d>a.d;
	}
};
struct Eg
{
	int fr,to,V;
}eg[200005];
int n,m,s,egnum;
void addegs(int fr,int to,int v)
{
	eg[++egnum]=(Eg){fr,to,v};
	ve[fr].push_back(egnum);
}
priority_queue<pt>qp;
bool flag[200005];
void djkp(int s)
{
	memset(dis,127/2,sizeof(dis));
	qp.push((pt){s,0}); dis[s]=0;
	while(qp.size())
	{
		int u=qp.top().u;
		qp.pop();
		if(flag[u]) continue;
		flag[u]=true;
		for(int i=0;i<ve[u].size();i++)
		{
			Eg e=eg[ve[u][i]];
			if(dis[e.to]<=dis[u]+e.V) continue;
			dis[e.to]=dis[u]+e.V;
			qp.push((pt){e.to,dis[e.to]});
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		int fr,to,v;
		scanf("%d%d%d",&fr,&to,&v);
		addegs(fr,to,v);
	}
	djkp(s);
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}
