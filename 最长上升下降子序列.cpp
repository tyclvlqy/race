#include <cstdio>
#include <algorithm>
using namespace std;
const int Max = 500 + 5;
int n, a[Max], opt1[Max], opt2[Max];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		opt1[i] = 1;
	for(int i = n - 1; i >= 1; i--) {
		for(int j = i + 1; j <= n; j++) {
			if(a[j] > a[i])
				opt1[i] = max(opt1[i], opt1[j] + 1);
		}
	}
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i++)
		ans1 = max(ans1, opt1[i]);
	for(int i = 1; i <= n; i++)
		opt2[i] = 1;
	for(int i = n - 1; i >= 1; i--) {
		for(int j = i + 1; j <= n; j++) {
			if(a[j] < a[i])
				opt2[i] = max(opt2[i], opt2[j] + 1);
		}
	}
	for(int i = 1; i <= n; i++)
		ans2 = max(ans2, opt2[i]);
	printf("%d\n%d", ans2, ans1);
	return 0;
}
