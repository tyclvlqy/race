#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,p,a[505],b[505],f[505][505],ans;
int main()
	{
		scanf("%d",&n);
		while(n--)
			{
				scanf("%d",&m);
				for(int i=1;i<=m;i++)
					scanf("%d",&a[i]);
				scanf("%d",&p); 
				for(int i=1;i<=p;i++)
					scanf("%d",&b[i]);
				for(int i=1;i<=m;i++)
					{
						int maxn=0;
						for(int j=1;j<=p;j++)
							{
								f[i][j]=f[i-1][j];
								if(a[i]>b[j]) maxn=max(maxn,f[i-1][j]);
								if(a[i]==b[j]) f[i][j]=maxn+1;
							}
					}
				int ans=0;
				for(int i=1;i<=p;i++)
					ans=max(ans,f[m][i]);
				printf("%d\n",ans);		
			}
		return 0;
	}
