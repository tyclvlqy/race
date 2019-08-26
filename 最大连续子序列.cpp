#include <bits/stdc++.h>
using namespace std;
const int Max = 3000 + 5;
int n, a[Max], opt[Max];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	opt[1] = a[1];
	for(int i = 2; i <= n; i++) {
		opt[i] = max(opt[i - 1], 0) + a[i];
	}
	int ans = -999999999;
	for(int i = 1; i <= n; i++)
		ans = max(ans, opt[i]);
	printf("%d", ans);
	return 0;
}
