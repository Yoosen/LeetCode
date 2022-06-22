// 并查集

class unionFind
{
public:
	unionFind();
	~unionFind();

	unionFind(int n) {
		this.count = n;

		// 对parent数组进行初始化
		for(int i = 0; i < n; i++) {
			// 默认这个森林有count棵树，
            //而且每棵树只有一个节点，也就是
            // 根结点，默认根结点的父节点是根结点本身
			parent[i] = i;
		}
	}

	// 并查集的方法定义-----------------
    // 查找一个节点所属树的根节点
	int find(int x) {
		if (parent[x] != x)
		{
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void union(int p, int q) {
		// 先分别获取到 p 节点和 q节点 所属树的根节点
		int rootP = find(p);
		int rootQ = find(q);

		// 如果两个节点的根节点相等，就不需要合并，是同一颗树的节点
		if (rootP == rootQ)
			return ;

		// 如果不相等，由于是 q 所属树合并到 p 所属树上
    	// 所以让 q所属树的根节点的父节点赋值为x所属树的根节点
		parent[rootQ] = rootP;
		// 同时, 此时森林少了一颗树
		count--;
	}
	

private:
	int count;	// 连通分量个数
	// 存储每个节点的父节点
	vector<int> parent;

	// n为图中节点的个数
};