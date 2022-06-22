// 547. & 剑指 Offer II 116 省份数量
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

// 返回矩阵中 省份 的数量。

 

// 示例 1：


// 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// 输出：2
// 示例 2：


// 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// 输出：3
 

// 提示：

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] 为 1 或 0
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

class Solution {
public:
    void Union(vector<int>& parent, int p, int q) {
    	// 先分别获取到 p 节点和 q节点 所属树的根节点
		int rootP = Find(parent, p);
		int rootQ = Find(parent, q);

		// 如果两个节点的根节点相等，就不需要合并，是同一颗树的节点
		if (rootP == rootQ)
			return ;

		// 如果不相等，由于是 q 所属树合并到 p 所属树上
    	// 所以让 q所属树的根节点的父节点赋值为x所属树的根节点
		parent[rootQ] = rootP;
    }

    int Find(vector<int>& parent, int x) {
    	if (parent[x] != x)
    	{
    		parent[x] = Find(parent, parent[x]);
    	}
    	return parent[x];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
    	int cities = isConnected.size();
    	vector<int> parent(cities);

    	for(int i = 0; i < cities; ++i) {
    		parent[i] = i;
    	}

    	for(int i = 0; i < cities; ++i) {
    		for(int j = i + 1; j < cities; j++) {
    			if (isConnected[i][j] == 1) {
    				Union(parent, i, j);
    			}
    		}
    	}

    	int provinces = 0;
    	for(int i = 0; i < cities; ++i) {
    		if(parent[i] == i) {
    			provinces++;
    		}
    	}
    	return provinces;
    }
};