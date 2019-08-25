#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll fast_pow(ll a, ll b, ll c) {
	ll ans = 1, base = a;
	while(b) {
		if(b & 1) ans = (ans * base) % c;
		base = (base * base) % c;
		b >>= 1;
	}
	return ans;
}
ll a, b, c;

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", fast_pow(a, b, c));
	return 0;
}
