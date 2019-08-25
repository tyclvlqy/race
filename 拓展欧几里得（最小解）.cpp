#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll x, y, m, l, n, t;
ll gcd(ll a, ll b) {
	if(!b) return a;
	else return gcd(b, a % b);
}
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

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
		ll tj, yj, k;
		ll d = e_gcd(n - m, l, tj, yj);
		if((x - y) % d) {
			puts("Impossible");
			continue;
		}
		ll c = x -  y;
        tj *= c / d;
        if(tj < 0)
        	tj = (tj % abs(l / d) + abs(l / d)) % abs(l / d);//Y %= (a / d); 
        else 
        	tj %= abs(l / d);
        printf("%lld\n", tj);
	}
	return 0;
}
