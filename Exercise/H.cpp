#include <bits/stdc++.h>
#include <string>
#define ll long long
using namespace std;


ll f(ll n, int a, int b) {
    if (n == 1 || n == 2)
    	return 1;
    ll fn1 = 1, fn2 = 1, fn;

    for(ll i = 0; i < n; i++) {
    	fn = a * fn1 + b * fn2;
    	fn1 = fn2;
    	fn2 = fn;
    }
    return fn;
}

int cfik(ll fi, ll k) {
	if
	dp[fi][k] = dp[fi-1][k-1] + dp[fi-1][k];
}

int main()
{
    int k, a, b;
    ll l, r, n;
	scanf("%d %d %d %d %d", &k, &a, &b, &l, &r);
	int sum;

	for(ll i = l; i <= r; i++) {

	}
	
	
    
    
    return 0;
}
