#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int n,m,a[1000005],b[2005],cnt[1000005];
queue<int>qq;
set<int>s;
priority_queue<int>cd;
int main()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			{
				b[i]=i;
				qq.push(i);
			}
		for(int i=1;i<=n;i++)
			{
				if(a[i]==qq.front()) 
					{
						cd.push(i);
						i=1;
						qq.pop();
					}
				else continue;
			}
		if(qq.size()>0) printf("-1");
		for(int i=i+1;i<=cd.top();i++)
			{
				s.insert(a[i]);
				if(s.count(qq.front())) cd.top()--;
			}
		printf("%d",cd.top());
		return 0;
	}
//continue
