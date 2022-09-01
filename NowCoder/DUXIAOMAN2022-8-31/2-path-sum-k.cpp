// 2.cpp，题目大意是从网格左上角走到右下角，每次只能向下或者向右走一步，每个网格都有一个值，然后求左上角到右下角有没有一种可能等于 x
#include <bits/stdc++.h>

using namespace std;

// 使用深度遍历
bool dfs(vector<vector<int>> &graph, int i, int j, int preSum, int x) {
   int n = graph.size(), m = graph[0].size();

   if (i < 0 || i >= n || j < 0 || j >= m) return false;

   preSum += graph[i][j];

   if (preSum == x && i == n - 1 && j == m - 1) return true;

   bool res =  dfs(graph, i + 1, j, preSum, k) || dfs(graph, i, j + 1, preSum, x);

   return res;
}

int main() {
   int T;
   cin >> T;

   vector<bool> ans(T, false);
   int count = 0;
   while (T--) {
       int n, m, k, x;
       cin >> n >> m >> k >> x;

       vector<vector<int>> graph(n, vector<int>(m, 0));
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               int tmp;
               cin >> tmp;
               graph[i][j] = tmp;
           }
       }

       bool res = dfs(graph, 0, 0, 0, x);

       //ans[count++] = res;

       if(res) {
           cout << "yes" << endl;
       } else {
           cout << "no" << endl;
       }

   }

   //for(int i = 0; i < count; ++i) {
   //    if(ans[i]) {
   //        cout << "yes" << endl;
   //    } else {
   //        cout << "no" << endl;
   //    }
   //}

}