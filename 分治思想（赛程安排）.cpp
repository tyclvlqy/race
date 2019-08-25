#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int Max = 500 + 5;
int a[Max][Max];
int k, n;
void mery(int x, int y) {
	for(int i = 1; i <= y / 2; i++) {
		for(int j = x; j <= x + y / 2 - 1; j++) {
			a[i + y / 2][j + y / 2] = a[i][j];
		}
	}
	for(int i = 1; i <= y / 2 + 1; i++) {
		for(int j = x + y / 2; j <= x + y - 1; j++) {
			a[i + y / 2][j - y / 2] = a[i][j];
		}	 
	}
}
void ap(int x, int y) {
	if(y == 2) {
		a[1][x] = x; a[1][x + 1] = x + 1;
		a[2][x] = x + 1; a[2][x + 1] = x;
	}
	else {
		ap(x,y / 2);
		ap(x + y / 2, y / 2);
		mery(x, y);
	}
}
int main() {
	scanf("%d", &k);
	n = pow(2, k);
	ap(1, n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}		
	return 0;
}
