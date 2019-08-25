#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e_gcd(ll a, ll b, ll& x, ll& y) {	
	ll temp, d;
	if(!b) {
		x = 1; y = 0;
		return a;
	}
	d = e_gcd(b, a % b, x, y);
	temp = x; x = y; y = temp - a / b * y;
	return d;
}

ll a, b, c;

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	ll X, Y, d;
	d = e_gcd(a, b, X, Y);
	ll k = c / d;
	X *= k;
	Y *= k;
	ll x0 = X, y0 = Y;
	ll ans1 = abs(X) + abs(Y), ans2 = abs(X) + abs(Y);
	while(ans1 > abs(X + b / d) + abs(Y - a / d)) {
		ans1 = abs(X + b / d) + abs(Y - a / d);
		X = X + b / d;
		Y = Y - a / d;
	}
	while(ans2 > abs(x0 - b / d) + abs(y0 + a / d)) {
		ans2 = abs(x0 - b / d) + abs(y0 + a / d);
		x0 = x0 - b / d;
		y0 = y0 + a / d;
	}
	printf("%lld\n", min(ans1, ans2));
	return 0;
}

