#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
queue<int>q;
vector<int>ve[10005];
struct Eg
{
	int fr,to,V;
}eg[500005];
int egnum,dis[10005];
bool flag[10005];
int addeg(int fr,int to,int V)
{
	eg[++egnum]=(Eg){fr,to,V};
	ve[fr].push_back(egnum);
}
void spfa(int s)
{
	memset(dis,127/2,sizeof(dis));
	dis[s]=0;
	q.push(s);
	while(q.size())
	{
		int fr=q.front();
		q.pop(); flag[fr]=false;
		for(int i=0;i<ve[fr].size();i++)
		{
			Eg e=eg[ve[fr][i]];
			if(dis[e.to]<=dis[e.fr]+e.V) continue;
			dis[e.to]=dis[e.fr]+e.V;
			if(flag[e.to]) continue;
			q.push(e.to);
			flag[e.to]=true;
		}
	}
}
int n,m,s;
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int fr,to,V,i=1;i<=m;i++)
	{
		scanf("%d%d%d",&fr,&to,&V);
		addeg(fr,to,V); 
	}
	spfa(s);
	for(int i=1;i<=n;i++)
		if(dis[i]>=dis[0]) printf("2147483647 ");
		else printf("%d ",dis[i]);
	return 0;
}
