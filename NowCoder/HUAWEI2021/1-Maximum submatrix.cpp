// HUAWEI 2021 1.最大子矩阵

// 求矩阵的最大子矩阵，比较大小的依据是子矩阵所有元素和的大小

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int m, n;
	int res = INT_MIN;
	scanf("%d%d", &m, &n);

	vector<vector<int>> matrix(m, vector<int>(n));

	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &matrix[i][j]);
		}
	}

	int ans = INT_MIN;

	for(int i = 0; i < m; ++i) {
		vector<int> b(n);

		for(int j = i; j < m; ++j) {
			// 看成一维
			// 不用dp数组动态记录，用一个值curMax代表当前的最大值
			int curMax = 0;
			for(int k = 0; k < n; ++k) {
				b[k] += matrix[j][k];	// 上面的列总和加上当前位置的数，i~j行之间第k列的总和

				curMax = max(curMax + b[k], b[k]);
				res = max(curMax, res);
			}
		}
	}

	printf("%d\n", res);

	return 0;
}
