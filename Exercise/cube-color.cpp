#include<bits/stdc++.h>
#include<vector>
using namespace std;


int main(){
	int n;
	cin >> n;

	vector<vector<char>> cubes(n + 2, vector<char>(n + 2, 'X'));
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; j++) {
			cin >> cubes[i][j];
		}
	}

	int ans = 0;

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; j++) {
			// 四个方位有三个是红色就将空白块染色
			if (cubes[i - 1][j] == 'X' && cubes[i][j - 1] == 'X' && cubes[i - 1][j] == 'X')
			{
				/* code */
			}
		}
	}


	return 0;
}