#include <cstdio>
#include <algorithm>
using namespace std;
const int Max = 100000 + 5;
int n, m, a[Max], Sum = 0;
bool check(int k) {
	int sum = 0, cnt = 1;
	for(int i = 1; i <= n; i++) {
		if(a[i] > k) {
			return false;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(sum + a[i] <= k) {
			sum += a[i];
		}
		else {
			sum = a[i];
			cnt++;
		}
	}
	if(cnt <= m) {
		return true;
	}
	else return false;
}
int main() {
	scanf("%d %d", &n, &m);
	int Min = 0x3f3f3f3f;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		Min = min(Min, a[i]);
		Sum += a[i];
	}
	int Left = 1, Right = 1e9, ans;
	for(int i = 1; i <= 100; i++) {
		int mid = (Left + Right) / 2;
		if(check(mid)) {
			ans = mid;
			Right = mid - 1;
		}
		else Left = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}
