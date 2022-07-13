// 3.游戏地图路径 迷宫问题
// 时间限制：C/C++ 1秒，其他语言2秒

// 空间限制：C/C++ 256M，其他语言512M

// vivo游戏中心的运营小伙伴最近接到一款新游戏的上架申请，为了保障用户体验，运营同学将按运营流程和规范对其做出分析评估。经过初步了解后分析得知，该游戏的地图可以用一个大小为 n*n 的矩阵表示，每个元素可以视为一个格子，根据游戏剧情设定其中某些格子是不可达的(比如建筑、高山、河流或者其它障碍物等)，现在请你设计一种算法寻找从起点出发到达终点的最优抵达路径，以协助运营小伙伴评估该游戏的可玩性和上手难度。

// 数据范围：
// 进阶：时间复杂度，空间复杂度

// 输入描述:
// 第一行表示矩阵大小 n，5 
// 第二行表示起点和终点的坐标
// 第三行起是一个用矩阵表示的游戏地图，其中#或者@表示障碍物，其他字母、非0数字、以及符号+、-、* 等等均表示普通可达格子，共有 n 行  n 列 

// 输出描述:
// 输出最优路径的长度；若无法到达，则输出-1

// 输入例子1:
// 15
// 0 7 7 7
// *5#++B+B+++++$3
// 55#+++++++###$$
// ###$++++++#+*#+
// ++$@$+++$$$3+#+
// +++$$+++$+4###+
// A++++###$@+$++A
// +++++#++$#$$+++
// A++++#+5+#+++++
// +++$$#$++#++++A
// +++$+@$###+++++
// +###4+$+++$$+++
// +#+3$$$+++$##++
// +#*+#++++++#$$+
// $####+++++++$##
// 3$+++B++B++++#5

// 输出例子1:
// 13

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& in, int i, int j, int end_x, int end_y, int count, vector<vector<int>>& visited);

int main() {
	int n;
	cin >> n;

	int start_x = 0, start_y = 0;
	int end_x = 0, end_y = 0;
	vector<vector<char>> in(n, vector<char>(n));
	vector<vector<int>> visited(n, vector<int>(n));

	cin >> start_y >> start_x >> end_y >> end_x;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> in[i][j];
		}
	}

	int res = INT_MAX;
	dfs(in, start_x, start_y, end_x, end_y, 1, visited);
	if(visited[end_x][end_y] == 0) cout << -1 << endl;
	else cout << visited[end_x][end_y] - 1 << endl;

	return 0;
}

void dfs(vector<vector<char>>& in, int i, int j, int end_x, int end_y, int count, vector<vector<int>>& visited) {
	// 越界
	if(i >= in.size() || i < 0 || j >= in[0].size() || j < 0) return ;

	// 障碍物，或者步数大于当前已经存储的步数，直接返回
	if(in[i][j] == '#' || in[i][j] == '@' || (visited[i][j] != 0 && count >= visited[i][j])) return ;

	visited[i][j] = count;

	// 到达目的地了，提前返回
	if(i == end_x && j == end_y)
		return ;

	// 回溯
	char c = in[i][j];
	in[i][j] = '#';
	dfs(in, i + 1, j, end_x, end_y, count + 1, visited);
	dfs(in, i - 1, j, end_x, end_y, count + 1, visited);
	dfs(in, i, j + 1, end_x, end_y, count + 1, visited);
	dfs(in, i, j - 1, end_x, end_y, count + 1, visited);
	in[i][j] = c;
}