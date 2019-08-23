#include<cstdio>
#include<cstring>//strlen需此头文件 
#include<cctype>//islower, isupper需此头文件 
#include<algorithm>
using namespace std;
int n;
char c[205],s1[5],s2[5];
int main()
	{
		gets(c);
		n=strlen(c);//求字符串数组c[]的长度 
		for(int i=0;i<n;i++)//有效角标是1~n 
			if(islower(c[i]))//如果是小写字符 
				putchar(toupper(c[i]));//输出大写字符 
			else printf("%c",c[i]);//否则原样输出 
		return 0;
	}

