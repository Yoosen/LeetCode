#include<bits/stdc++.h>
using namespace std;

int dp(int t) {
	int dp_3;
	if(t == 0) dp_3 = 0;
	if(t == 1 || t == 2 || t == 3) dp_3 = 1;

	int dp_0 = 1, dp_1 = 1, dp_2 = 1;
	if (t > 3) {
		for (int i = 3; i < t; i++) {
			dp_3 = dp_0 + dp_1 + dp_2;
			dp_0 = dp_1;
			dp_1 = dp_2;
			dp_2 = dp_3;
		}
	}
	

	return dp_3 % 425;

}

int main(){
	int t;
	scanf("%d", &t);
	t = t / 60;

	int ans = dp(t);

	printf("%d\n", ans);

	return 0;
}