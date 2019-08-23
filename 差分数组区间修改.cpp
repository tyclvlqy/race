#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Max = 10000 + 5;
ll a[Max], d[Max], sum[Max], l, m;

int main() {
    scanf("%lld %lld", &l, &m);
    while(m--) {
        int s, t;
        scanf("%d %d", &s, &t);
        a[s]++;
        a[t + 1]--;
    }
    sum[0] = a[0];
    for (int i = 1; i <= l; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i <= l; i++) {
        if(!sum[i])
            ans++;
    }
    printf("%lld", ans);
    return 0;
}