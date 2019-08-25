#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
bool solve(int x) {
	if(x <= 3)
		return x > 1;
	if(x % 6 != 1 && x % 6 != 5)
		return false;
	int sq = ceil(sqrt(x));
	for(int i = 5; i <= sq; i += 6) {
		if(!(x % i) || !(x % (i + 2)))
			return false;
	}
	return true;
}

int a, b;

int main() {
	scanf("%d", &a);
	if(solve(a)) {
		puts("yes");
	}
	else puts("no");
	return 0;
}
