#include<cstdio>
#include<cstring>//strlen���ͷ�ļ� 
#include<cctype>//islower, isupper���ͷ�ļ� 
#include<algorithm>
using namespace std;
int n;
char c[205],s1[5],s2[5];
int main()
	{
		gets(c);
		n=strlen(c);//���ַ�������c[]�ĳ��� 
		for(int i=0;i<n;i++)//��Ч�Ǳ���1~n 
			if(islower(c[i]))//�����Сд�ַ� 
				putchar(toupper(c[i]));//�����д�ַ� 
			else printf("%c",c[i]);//����ԭ����� 
		return 0;
	}

