#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll Max = 1000 + 5;
bool prime[Max];
ll n;
void isprime(int n) {
	ll sq = ceil(sqrt(n));
	for(int i = 2; i <= n; i++)
		prime[i] = true;
	for(int i = 2; i <= sq; i++) {
		if(prime[i]) {
			for(int j = i * i; j <= n; j += i)
				prime[j] = false; 
		}
	} 
}

int main() {
	scanf("%lld", &n);
	isprime(n);
//	for(int i = 1; i <= n; i++)
//		printf("%d ", prime[i]);
	for(int i = 1; i <= n; i++) {
		if(prime[i]) 
			printf("%d ", i);
	}
	return 0;
}
