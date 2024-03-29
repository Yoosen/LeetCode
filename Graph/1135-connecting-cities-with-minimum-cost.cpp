// 1135.最低成本联通所有城市
// 想象一下你是个城市基建规划者，地图上有 N 座城市，它们按以 1 到 N 的次序编号。

// 给你一些可连接的选项 conections，其中每个选项 conections[i] = [city1, city2, cost] 表示将城市 city1 和城市 city2 连接所要的成本。（连接是双向的，也就是说城市 city1 和城市 city2 相连也同样意味着城市 city2 和城市 city1 相连）。

// 返回使得每对城市间都存在将它们连接在一起的连通路径（可能长度为 1 的）最小成本。该最小成本应该是所用全部连接代价的综合。如果根据已知条件无法完成该项任务，则请你返回 -1。

// 提示：

// 1 <= N <= 10000
// 1 <= conections.length <= 10000
// 1 <= conections[i][0], conections[i][1] <= N
// 0 <= conections[i][2] <= 10^5
// conections[i][0] != conections[i][1]

// 样例


// 输入：N = 3, conections = [[1,2,5],[1,3,6],[2,3,1]]
// 输出：6
// 解释：
// 选出任意 2 条边都可以连接所有城市，我们从中选取成本最小的 2 条。

// 并查集

class Solution {
public:
    vector<int> p;

    int minimumCost(int n, vector<vector<int>>& connections) {
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        // 按 代价 从小到大排序
        sort(connections.begin(), connections.end(), [](auto & a, auto & b) {
            return a[2] < b[2];
        });
        int ans = 0;
        for (auto& e : connections) {
            int x = e[0] - 1, y = e[1] - 1, cost = e[2];
            if (find(x) == find(y)) continue;
            p[find(x)] = find(y);
            ans += cost;
            if (--n == 1) return ans;
        }
        return -1;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};



// // Prime 算法
// struct cmp {
//     // 根据代价由大到小排序，大根堆
//     bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
//         return a.second > b.second;
//     }
// };

// class Solution {
// public:
//     int minimumCost(int n, vector<vector<int>>& connections) {
//         vector<bool> vis(n + 1, false);
//         vector<vector<pair<int, int>>> edges(n + 1, vector<pair<int, int>>());
//         for(auto& c : connection) {
//             // 顶点 ，<相连顶点，代价>
//             edges[c[0]].push_back({c[1], c[2]});
//             edges[c[1]].push_back({c[0], c[2]});
//         }

//         priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
//         int to, dis, total = 0, edge = 0;
//         vis[1] = true;  // 1号标记已访问

//         // 遍历所有的 顶点和代价 都加入优先级队列中
//         for(auto& e : edges[1])
//             q.push(e);

//         while(!q.empty()) {
//             to = q.top().first; // 选择代价最小的顶点的相邻节点 to
//             dis = q.top().second;   // 到相邻节点的代价
//             q.pop();

//             if(!vis[to]) {      // 如果相邻的节点没有访问过
//                 vis[to] = true; // 置为已访问
//                 total += dis;   // 总和相加
//                 edge++;         // 访问过的边 + 1

//                 if(edge == n - 1)   // 已经访问了 n - 1条边，可以连通 n 个节点
//                     return total;

//                 // 将相邻节点的相连节点都加入到优先级队列中
//                 for(auto& e : edges[to])
//                     q.push(e);
//             }
//         }


//         return -1;
//     }

// };