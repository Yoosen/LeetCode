#include <bits/stdc++.h>
#include <string>
#include <vector>
#define ll long long
using namespace std;

// 设 x 为最短跳跃距离
// f(x) 是在 x 下，需要移走的石头数，x 越大，所需移走的就越多，递增
// target 就是至多要移走的石头数



int f(vector<int> v, int x) {
	int n = v.size();

	int cnt = 0;		// 要搬走的石块数量
	// 循环控制变量：s: 当前石块编号，prev: 前一块石块的编号
	for (int s = 1, prev = 0; s < n; ++s)
		if (v.at(s) - v.at(prev) < x)
			++cnt;	// 搬走当前石块，此时下一轮的前一石块不变
		else
			prev = s;	// 当前石块变成下一轮的前一石块
	return cnt;
}

// 移走石头数最少就是0，不移走，最大就是全移走，也就是n
int main()
{
	int l, n, m;
	scanf("%d%d%d", &l, &n, &m);
	vector<int> v;
	// v.clear();

	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	v.push_back(l);

    int left = 0, right = n, mid;

    while(left < right) {
    	mid = left + (right - left) / 2;

    	if(f(v, mid) <= m) {
    		left = mid + 1;
    	}
    	else {
    		right = mid;
    	}
    }

    printf("%d\n", left - 1);

    return 0;
}
