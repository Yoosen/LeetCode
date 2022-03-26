#include<bits/stdc++.h>
#include<vector>
using namespace std;
//未完成
int main() {
	int n, count = 0, temp;
	scanf("%d", &n);
	vector<int> v;

	for(int i = 0; i < 2 * n; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}

	temp = 0;
	for (int i = 0; i < 2 * n; ++i)
	{
		if(v[i] >= 0) {
			for (int j = i + 1; j < 2 * n; ++j)
			{
				if(v[j] >= 0 && v[j] != v[i]) {
					temp++;
				}
			}
		}
	}


	return 0;
}