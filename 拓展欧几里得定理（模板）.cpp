#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a, b;
ll e_gcd(ll a, ll b, ll& x, ll& y) {
	ll d, temp;
	if(!b) {
		x = 1; y = 0; 
		return a;
	}
	d = e_gcd(b, a % b, x, y);
	temp = x; x = y; y = temp - a / b * y;
	return d;
}

int main() {
	scanf("%lld %lld", &a, &b);
	ll x, y;
	e_gcd(a, b, x, y);
	if(x > 0) x %= b;
	else if(x < 0) x = (x % b) + b;
	printf("%lld\n", x);
	return 0;
}
