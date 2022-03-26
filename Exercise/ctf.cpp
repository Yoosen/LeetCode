#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int res(int a) {
	int ans = 2;
	for (int i = 1; i <= a; ++i)
	{
		ans *= 2;
	}
	return ans;
}

int main() {
	int t, sum = 0;
	scanf("%d", &t);

	int i = 1;
	while(t > 0) {
		sum += res(i) * i;
		t -= res(i);
		i++;
	}

	printf("%d\n", sum);
	return 0;
}