2022.8.30 携程4.cpp

// 游游得到了一个有n个数字的数列。
// 游游定义了“平滑值”的概念：平滑值指任意两个相邻的数的差的绝对值的量大值。例[1,2,5,7,8]的平滑值是3。
// 游游现在想知道，在只修改一个位置的数字(可以修改为任意值)或者不修改的情况下，数列的平滑值最小是多少？

// 输入描述:
// 第一行包含一个数字n(2 <=n <= 2 * 10^5)，数字个数。
// 第二行包含n个数字,代表数列1e-9 <= ai <= 1e9。

// 输出描述:
// 输出一个整数，代表数列最小的平滑值。

// 示例1：
// 输入
// 3
// 1 3 4

// 输出
// 1

// 说明
// 将第一个数字修改为3， 平滑值变为 1，可以证明这是最优的方案之一

// 示例2：
// 输入
// 5
// -1 1 2 5 7

// 输出
// 2

// 最开始的平滑值最大值是maxValue
// 然后再遍历一下，如果当前num[i]和前面的num[i-1]的平滑值==maxValue，
// 我们进行这样的操作
// 令 num[i] = (num[i - 1] + num[i + 1]) / 2求一次maxValue（整个数组），还原num[i]
// 令 num[i - 1] = (num[i - 2] + num[i]) / 2求一次maxValue（整个数组），还原num[i - 1]
// break，不用继续循环了。答案就是三次maxValue的最小值。

#include <bits/stdc++.h>

using namespace std;


// 返回数组中最大差值
int getMax(const vector<int>& nums) {
    int maxValue = 0;
    int n = nums.size();

    for(int i = 1; i < n; ++i) {
        maxValue = max(maxValue, abs(nums[i] - nums[i - 1]));
    }

    return maxValue;
}



int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);

    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
    }

    int maxValue = getMax(nums);
    for(int i = 1; i < n; ++i) {
        if(abs(nums[i] - nums[i - 1]) == maxValue) {
            int tmp;

            //num[i - 1] = (num[i - 2] + num[i]) / 2
            // num[i - 1] 要修改
            tmp = nums[i - 1];      // 暂存
            if(i == 1) {
                nums[i - 1] = nums[i];
            } else {
                nums[i - 1] = (nums[i - 2] + nums[i]) / 2;
            }
            maxValue = min(maxValue, getMax(nums));
            nums[i - 1] = tmp;  // 还原

            tmp = nums[i];      // 暂存
            if(i == n - 1) {
                nums[i] = nums[i - 1];
            } else {
                nums[i] = (nums[i - 1] + nums[i + 1]) / 2;
            }
            maxValue = min(maxValue, getMax(nums));
            nums[i] = tmp;  // 还原

            break;
        }
    }

    cout << maxValue << endl;
    return 0;
}






// 携程3.java

import java.util.*;

public class Solution3 {
    static int n;
    static int[] count; // count数组统计树中颜色为r g b的节点数量
    static int[] colors; // 表示节点 i的颜色
    static boolean[] visited; // 节点i是否访问过
    static int ans; // 合法的边的数量

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());
        count = new int[3]; // count[0]代表树中颜色为 r 的节点数量，count[1]代表树中颜色 g...，
        colors = new int[n + 1];  // colors[i]代表节点i的颜色
        visited = new boolean[n + 1]; // 用来记录节点 i是否被访问过
        String s = scanner.nextLine();
        for (int i = 0; i < s.length(); i++) { // 给 count和 colors数组赋值
            if (s.charAt(i) == 'r') {
                count[0]++;
                colors[i + 1] = 0;
            } else if (s.charAt(i) == 'g') {
                count[1]++;
                colors[i + 1] = 1;
            } else {
                count[2]++;
                colors[i + 1] = 2;
            }
        }


        ArrayList<Integer>[] graph = new ArrayList[n + 1]; // 用来表示题目中所述无向图（树）
        for (int i = 0; i < n + 1; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n - 1; i++) {
            String[] split = scanner.nextLine().split(" ");
            int a = Integer.parseInt(split[0]);
            int b = Integer.parseInt(split[1]);
            graph[a].add(b);
            graph[b].add(a);
        }
        int[] dfs = dfs(1, graph); // 随便选一个节点作为根节点，这里选择 节点 1，验证代码是否正确只需要把所有可能的根节点枚举一遍，看是否结果是相同的即可
        System.out.println(ans);
    }

    public static int[] dfs(int root, ArrayList<Integer>[] graph) { // 返回以root为根节点的子树的有多少个r节点，g节点，b节点
        visited[root] = true; // 把 root标记为已访问，那么就相当于把root节点的所有边全部砍断
        int[] sumCount = new int[3];
        for (Integer child : graph[root]) { // 对于 删除root节点后的每个子树child
            if (visited[child]) {
                continue;
            }
            int[] dfs = dfs(child, graph); // 返回以child为根节点的子树的有多少个r节点，g节点，b节点
            if (check(dfs) && check(new int[]{count[0] - dfs[0], count[1] - dfs[1], count[2] - dfs[2]})) { // 如果子树child中的rgb节点数符合要求，且剩下的另一半树的节点值也符合要求
                ans++; // 从root到child的这条边是合理的
            }
            for (int i = 0; i < sumCount.length; i++) { // 以root为根节点的树的中包含rgb节点的数量是其所有子树的和
                sumCount[i] += dfs[i];
            }
        }
        sumCount[colors[root]]++; // 加上root本身的颜色
        visited[root] = false;
        return sumCount;
    }

    public static boolean check(int[] arr) {
        for (int i : arr) {
            if (i <= 0) {
                return false;
            }
        }
        return true;
    }
}








2022.8.28 字节

#include <bits/stdc++.h>

using namespace std;

//struct cmp {
//    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
//        if(a.first != b.first) return a.first > b.first;
//        return a.second < b.second;
//    }
//};

int main() {
    int t;
    cin >> t;

    int count = 0;
    while(t--) {
        vector<pair<int, int>> pairs;
        pairs.clear();
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            nums[i] = tmp;
        }

        stack<int> st;
        long long mul = 1;

        int size = nums.size();
        int start = 1, end = size;
        for(int i = 0; i < size; ++i) {
            long long curMul = 1;
            while(!st.empty() && nums[i] == 0) {

                int curEnd = st.top();
                int curStart = 0;
                while(!st.empty()) {

                    curMul *= nums[st.top()];

                    if(st.size() == 1) {
                        curStart = st.top();
                    }
                    st.pop();

                }

                if(curMul >= mul) {
                    mul = curMul;
                    end = curEnd + 1;
                    start = curStart + 1;

                    pairs.push_back({start, end});
                }

            }

            if(nums[i] != 0)
                st.push(i);
        }

        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        //cout << pairs[0].first << " " << pairs[0].second << endl;

        pairs[count] = {start, end};
        count++;
    }

    for(int i = 0; i < count; ++i) {
        cout << pairs[i].first << " " << pairs[i].second << endl;
    }


    return 0;
}
























// 松鼠藏干果
//#include <bits/stdc++.h>
//
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//void split(string tree_str, vector<int> &nums, char c) {
//    stringstream ss(tree_str);
//    string tmp;
//    while (getline(ss, tmp, c)) nums.push_back(stoi(tmp));
//}
//
//TreeNode *creatTree(vector<int> nums, int i) {
//    TreeNode *root = nullptr;
//    int size = nums.size();
//    if (i < size) {
//        TreeNode *tmp = new TreeNode(nums[i]);
//        root = tmp;
//        root->left = creatTree(nums, 2 * i + 1);
//        root->right = creatTree(nums, 2 * i + 2);
//    }
//    return root;
//}
//
////判断树是否合法
//bool isLeagal(TreeNode* root) {
//    bool flag = true;
//
//    queue<TreeNode *> que;
//    que.push(root);
//    while (!que.empty()) {
//        TreeNode *node = nullptr;
//        node = que.front();
//        if(node->val == -1) {
//            if(node->left != nullptr || node->right != nullptr) {
//                return false;
//            }
//        }
//
//        if (node->left != nullptr) {
//            que.push(node->left);
//        }
//        if (node->right != nullptr) {
//            que.push(node->right);
//        }
//    }
//    return true;
//}
//
//int main() {
//    string tree_str;
//    int n;
//    getline(cin, tree_str);
//    cin >> n;
//
//    vector<int> nums;
//    nums.clear();
//    split(tree_str, nums, ' ');
//
//    int size = nums.size();
//    bool flag = true;
//    for (int i = 0; i < size; ++i) {
//        int val = nums[i];
//        if (val < -1 || val > 5) {
//            flag = false;
//            break;
//        }
//    }
//
//    // 判断树是否合法
//
//
//    if (flag) {
//        TreeNode *root = nullptr;
//        root = creatTree(nums, 0);
//
//        queue<TreeNode *> que;
//        que.push(root);
//
//
//        while (!que.empty()) {
//            TreeNode *node = nullptr;
//            node = que.front();
//            que.pop();
//            int val = node->val;
//
//            int realNum = val;
//            if(val == -1) val = 5;
//
//
//
//            n -= (5 - val);
//            if (n <= 0) break;
//
//            if(realNum == -1 && (node->left != nullptr || node->right != nullptr)) {
//                flag = false;
//                break;
//            }
//            if (node->left != nullptr) {
//                que.push(node->left);
//            }
//            if (node->right != nullptr) {
//                que.push(node->right);
//            }
//        }
//    }
//
//    if (!flag) {
//        cout << "false" << endl;
//        cout << 0 << endl;
//    } else {
//        cout << "true" << endl;
//        if(n <= 0) n = 0;
//        cout << n << endl;
//    }
//    return 0;
//}


// 2022.8.27 360 图

#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    int n, m;
    cin >> n >> m;  // 节点和道路树

    //vector<vector<int>> graph(n, vector<int>(n, 0));

    vector<int> us(m, 0), vs(m, 0), ws(m, 0);

    for (int i = 0; i < m; ++i) {
        int tmp = 0;
        cin >> tmp;
        us[i] = tmp;
    }
    for (int i = 0; i < m; ++i) {
        int tmp = 0;
        cin >> tmp;
        vs[i] = tmp;
    }
    for (int i = 0; i < m; ++i) {
        int tmp = 0;
        cin >> tmp;
        ws[i] = tmp;
    }
    vector<vector<int>> connection(m, vector<int>(3, 0));
    for (int i = 0; i < m; ++i) {
        int x = us[i];
        int y = vs[i];
        int w = ws[i];
        connection[i] = {x, y, w};
    }

    vector<bool> vis(m + 1, false);
    vector<vector<pair<int, int>>> edges(m + 1, vector<pair<int, int>>());
    for(auto& c : connection) {
        edges[c[0]].push_back({c[1], c[2]});
        edges[c[1]].push_back({c[0], c[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    int to, dis, total = 0, edge = 0;
    vis[1] = true;

    // 遍历所有的 顶点和代价 都加入优先级队列中
    for(auto& e : edges[1])
        q.push(e);

    while(!q.empty()) {
        to = q.top().first; // 选择代价最小的顶点的相邻节点 to
        dis = q.top().second;   // 到相邻节点的代价
        q.pop();

        if(!vis[to]) {      // 如果相邻的节点没有访问过
            vis[to] = true; // 置为已访问
            total += dis;   // 总和相加
            edge++;         // 访问过的边 + 1

            if(edge == m - 1)
                break;

            // 将相邻节点的相连节点都加入到优先级队列中
            for(auto& e : edges[to])
                q.push(e);
        }
    }

    cout << total << endl;


    return 0;
}




















// 360 变换字符串 基因交换
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    string str1, str2;
//    cin >> str1 >> str2;
//
//    int n = str1.length();
//    //vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//    //
//    //// 第一列
//    //for(int i = 1; i <= n; ++i) {
//    //    dp[i][0] = i;
//    //}
//    //
//    //// 第一行
//    //for(int j = 1; j <= n; ++j) {
//    //    dp[0][j]
//    //}
//    int a2t = 0, t2a = 0;
//    //for(int i = 0; i < n; ++i) {
//    //    if(str1[i] == 'A') {
//    //        a1++;
//    //    }
//    //    if(str2[i] == 'A') {
//    //        a2++;
//    //    }
//    //}
//    //int count = abs(a1 - a2);
//    for(int i = 0; i < n; ++i) {
//        if(str1[i] != str2[i] && str1[i] == 'A') {
//            a2t++;
//        }
//        if(str1[i] != str2[i] && str1[i] == 'T') {
//            t2a++;
//        }
//    }
//
//    int sw = min(a2t, t2a); //交换次数
//    int res = t2a + a2t - sw;
//
//    cout << res << endl;
//
//
//    return 0;
//}













8.27 猿辅导 微软

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A, int M) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = A.size();
    // vector<bool> used(n, false);
    int ans, res = 1;
    for(int i = 0; i < n; ++i) {
        int t = A[i];
        ans = 1;
        for(int j = i + 1; j < n; ++i) {
            if(abs(A[i] - A[j]) % M == 0) {
                ans++;
            }
        }
        res = max(ans, res);
    }
    cout << res << endl;
    return res;
}

int main() {
    int M;
    cin >> M;
    int K, N;
    cin >> K >> N;

    queue<int> res;
    vector<int> arr(N, 0);
    for(int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    int l = 0, r = 0;
    unordered_set<int> nums;
    nums.clear();
    int ans = INT_MAX;
    while(r < N) {
        res.push(arr[r]);
        if(K % arr[r] == 0 && arr[r] != 1) {
            nums.insert(arr[r]);
            nums.
        }

        while(multi(nums, K)) {
            ans = ans < res.size() ? ans : res.size();
            int tmp = res.front();
            res.pop();
            nums.erase(tmp);

            l++;
        }
        r++;
    }
    cout << ans << endl;

    return 0;
}
























//
//
//
//
//
//string lowercase(string str) {
//    int len = str.length();
//    for(int i = 0; i < len; ++i) {
//        if(str[i] > 'A' && str[i] < 'Z')
//            str[i] += 32;
//    }
//    return str;
//}
//
//int main() {
//    int M;
//    cin >> M;
//
//    while(M--) {
//        int N;
//        cin >> N;
//
//        unordered_map<string, int> mp;
//        for(int i = 0; i < N; ++i) {
//            string str;
//            cin >> str;
//            str = lowercase(str);
//            mp[str]++;
//        }
//
//        int K = 0;
//        cin >> K;
//
//        unordered_set<string> stop_string;
//        for(int i = 0; i < K; ++i) {
//            string stopstr;
//            cin >> stopstr;
//
//            stop_string.insert(stopstr);
//        }
//
//        int maxn = 0;
//        for(auto it = mp.begin(); it != mp.end(); ++it) {
//            string str = it->first;
//
//            int len = str.length();
//            for(auto setit = stop_string.begin(); setit != stop_string.end(); ++setit) {
//                string tmp = *setit;
//                if(tmp.size() == len) {
//                    if(regex_match(str,tmp))
//                        it->second = 0;
//                }
//            }
//            maxn = max(maxn, it->second);
//        }
//
//        cout << maxn << endl;
//    }
//
//    return 0;
//}






//
//bool isSame(string s1, ) {
//
//}












#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int DagPathNum(vector<vector<int> > &nodes) {
    int n = nodes.size();

    queue<int> que;
    que.push(0);

    int max_size = 1, second = 1;

    for(int i = 0; i < nodes.size(); ++i) {
        max_size = max_size > nodes[i].size() ? max_size : nodes[i].size();
    }

    for(int i = 0; i < nodes.size(); ++i) {
        if(nodes[i].size() > second && nodes[i].size() != max_size) {
            second = nodes[i].size();
        }
    }

    return max_size * second;

    //while (!que.empty()) {
    //    int cur = que.front();
    //    vector<int> curNodes = nodes[cur];
    //    max_size = max_size > curNodes.size() ? max_size : curNodes.size();
    //
    //    //for(int i = 0; i < curNodes.size(); ++i) {
    //    //    que.push()
    //    //}
    //}
}

int main() {


    return 0;
}





//#include <bits/stdc++.h>
//
//using namespace std;
//
//void split(string str, vector<int>& nums, char c) {
//    stringstream ss(str);
//    string tmp;
//    while(getline(ss, tmp, c)) nums.push_back(stoi(tmp));
//}
//
//int main() {
//    //int length;
//    //cin >> length;
//    //vector<int> array(length, 0);
//
//    string str;
//    cin >> str;
//    int len = str.size();
//    str = str.substr(1, len - 2);
//    vector<int> nums;
//    nums.clear();
//    split(str, nums, ',');
//
//    //for(int i = 0; i < length; ++i) {
//    //    int tmp;
//    //    cin >> tmp;
//    //    array[i] = tmp;
//    //}
//    //单调栈好像没办法解决，双指针？
//    int left = 0, right = nums.size() - 1;
//
//    int ans = 0;
//    while(left < right) {
//        ans = max((right - left) * (min(nums[left], nums[right])), ans);
//        if(nums[left] < nums[right]) {
//            ++left;
//        }
//        else {
//            --right;
//        }
//    }
//
//
//
//    cout << ans << endl;
//
//    return 0;
//}
































//using namespace std;


// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
//void spilt(string s, vector<int> &adj, char c) {
//    stringstream ss(s);
//    string tmp;
//    while (getline(ss, tmp, c)) adj.push_back(stoi(tmp));
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<vector<int>> adjacent(n);
//    adjacent.clear();
//    getchar();
//    for(int i = 0; i < n; ++i) {
//        string str;
//        getline(cin, str);
//
//        vector<int> adj;
//        spilt(str, adj, ' ');
//        adjacent.push_back(adj);
//    }
//
//    //for(int i = 0; i < n; ++i) {
//    //    cout << adjacent[0][0] << endl;
//    //}
//
//    cout << n - 1 << endl;
//    return 0;
//}










// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

//void spilt(string s, vector<string> &strs, char c) {
//    stringstream ss(s);
//    string tmp;
//    while (getline(ss, tmp, c)) strs.push_back(tmp);
//}
//
//unordered_map<string, int> indegree;   // 每个对象的入度信息
//unordered_map<string, vector<string>> m;    // 每个对象的后续对象
//void updateInDegree(const vector<string>& tmp_yilai) {
//    indegree[tmp_yilai[0]]++;
//
//    // 不存在，置为 0
//    if(!indegree.count(tmp_yilai[1])) {
//        indegree[tmp_yilai[1]] = 0;
//    }
//    m[tmp_yilai[1]].push_back(tmp_yilai[0]);
//}
//
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<string> dep(n, "");
//
//    vector<vector<string>> yilai(n);
//    for(int i = 0; i < n; ++i) {
//        string tmp;
//        cin >> tmp;
//        vector<string> tmp_yilai;
//
//        spilt(tmp, tmp_yilai, '>');
//        updateInDegree(tmp_yilai);
//    }
//
//    queue<string> que;
//    int size = indegree.size();
//    for(auto it = indegree.begin(); it != indegree.end(); ++it) {
//        if(it->second == 0) {
//            que.push(it->first);
//        }
//    }
//
//    int count = 0;
//    while(!que.empty()) {
//        string selected = que.front();
//        que.pop();
//        count++;
//
//        vector<string> toEnQueue = m[selected];
//        if(toEnQueue.size()) {
//            for(int i = 0; i < toEnQueue.size(); ++i) {
//                indegree[toEnQueue[i]]--;
//                if(indegree[toEnQueue[i]] == 0)
//                    que.push(toEnQueue[i]);
//            }
//        }
//    }
//
//    if(count == indegree.size())
//        cout << "NA" << endl;
//    else {
//        vector<string> res;
//        for(auto it = indegree.begin(); it != indegree.end(); ++it) {
//            if(it->second != 0) {
//                res.push_back(it->first);
//            }
//        }
//        sort(res.begin(), res.end());
//
//        for(int i = 0; i < res.size(); ++i) {
//            if(i ==0) cout << res[i];
//            else cout << " " << res[i];
//        }
//        cout << endl;
//    }
//    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
//    // please finish the function body here.
//    // please define the C++ output here. For example:cout<<____<<endl;
//
//    return 0;
//}











//#include <bits/stdc++.h>
//
//using namespace std;
//// we have defined the necessary header files here for this problem.
//// If additional header files are needed in your program, please import here.
//
//void spilt(string s, vector<int> &nums, char c) {
//    stringstream ss(s);
//    string tmp;
//    while (getline(ss, tmp, c)) nums.push_back(stoi(tmp));
//}
//
//int main() {
//    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
//    // please finish the function body here.
//    // please define the C++ output here. For example:cout<<____<<endl;
//    string s;
//    cin >> s;
//    vector<int> nums;
//    spilt(s, nums, ',');
//
//
//    unordered_set<int> num_set;
//    for (const int&num : nums) {
//        num_set.insert(num);
//    }
//
//    int len = 0;
//    int startNum = 0;
//    int minNum = INT_MAX;
//    for(const int& num : num_set) {
//        if(!num_set.count(num - 1)) {
//            int curNum = num;
//
//            int curStreak = 1;
//
//            while(num_set.count(curNum + 1)) {
//                curNum += 1;
//                curStreak += 1;
//            }
//
//            if(curStreak >= len) {
//                //startNum = num;
//                minNum = min(minNum, num);
//                len = curStreak;
//            }
//        }
//    }
//
//    cout << minNum << "," << len << endl;
//
//    return 0;
//}


2022.8.24
华为



2022.8.24
shein
#include <bits/stdc++.h>

using namespace std;

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param haystack string字符串
 * @param needle string字符串
 * @return int整型
 */
//int strStr(string haystack, string needle) {
//    // write code here
//    int t = haystack.find(needle);
//    return t;
//}

int ans = 0;

void backtrack(const string &s, int index, int len) {

    string curStr = s.substr(index, len);
    if (curStr[0] == '0') return;
    if (index + len > s.length()) return;


    int num = stoi(curStr);
    if (num < 1 || num > 26) return;

    if (index + len == s.length()) {
        ans++;
        return;
    }


    index += 1;
    backtrack(s, index, 1);
    index -= 1;

    index += 2;
    backtrack(s, index, 2);
    index -= 2;

}

int numDecoding(string s) {
    // write code here
    backtrack(s, 0, 1);
    backtrack(s, 0, 2);

    int len = s.length();
    vector<int> dp(len + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= len; ++i) {
        if(s[i] == '0') {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    return dp[len];
}

int main() {
    //string haystack = "shein", needle = "in";
    //int res = strStr(haystack, needle);
    string s = "12";
    int res = numDecoding(s);

    cout << res << endl;
}






#include <bits/stdc++.h>

using namespace std;


























// 网易题目链接 http://solitude0325.top/archives/2022%E5%B9%B4%E5%85%AB%E6%9C%88%E7%A7%8B%E6%8B%9B%E7%AC%94%E8%AF%95%E7%AE%80%E8%AE%B0%E4%BA%8C


//int main() {
//    int n;
//    cin >> n;
//    int a[n];
//
//    int maxIndex = 0;
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &a[i]);
//        maxIndex = a[i] > a[maxIndex] ? i : maxIndex;
//    }
//
//    int ans = 0;
//    int i = maxIndex;
//    while (i >= 0) {
//        ans += (a[maxIndex] - a[i]);
//        a[i] = a[maxIndex];
//        i -= 2;
//    }
//    i = maxIndex;
//    while (i < n) {
//        ans += (a[maxIndex] - a[i]);
//        a[i] = a[maxIndex];
//        i += 2;
//    }
//
//    bool flag = false;
//    for (int j = 0; j < n - 1; ++j) {
//        if (a[j] == a[j + 1]) {
//            flag = true;
//            break;
//        }
//    }
//
//    if (flag) {
//        for (int j = 0; j < n; ++j) {
//            ans += (a[maxIndex] - a[j]);
//        }
//    } else {
//        int secondIndex = 0;
//        for (int j = 0; j < n; ++j) {
//            if (a[j] != a[maxIndex]) {
//                secondIndex = a[j] > a[secondIndex] ? j : secondIndex;
//            }
//        }
//
//        int j = secondIndex;
//        while (j >= 0) {
//            ans += (a[secondIndex] - a[j]);
//            a[j] = a[secondIndex];
//            j -= 2;
//        }
//        j = secondIndex;
//        while (j < n) {
//            ans += (a[secondIndex] - a[j]);
//            a[j] = a[secondIndex];
//            j += 2;
//        }
//    }
//
//    cout << ans << endl;
//
//
//    return 0;
//}











//int main() {
//    int n;
//    cin >> n;
//    int a[n];
//
//    // 数值，下标集合
//    unordered_map<int, vector<int>> mp;
//
//    for(int i = 0; i < n; ++i) {
//        scanf("%d", &a[i]);
//        mp[a[i]].push_back(i);
//    }
//
//    for(auto it = mp.begin(); it != mp.end(); ++it) {
//        vector<int> cur = it->second;
//        if(cur.size() >= 2) {
//
//        }
//    }
//
//    int ans = 0;
//
//
//
//
//    cout << ans << endl;
//
//    return 0;
//}





























//// 概率，分值
//bool cmp(const pair<int, int> a, const pair<int, int> b) {
//    if (a.second != b.second) {
//        return a.second > b.second;
//    }
//    return a.first < b.first;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<int> p(n, 0);
//    vector<int> a(n, 0);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &p[i]);
//    }
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &a[i]);
//    }
//
//    vector<pair<int, int>> v;
//    v.clear();
//    for (int i = 0; i < n; ++i) {
//        pair<int, int> cur;
//        cur.first = p[i];   // 概率
//        cur.second = a[i];  // 分值
//        v.push_back(cur);
//    }
//
//    sort(v.begin(), v.end(), cmp);
//
//    double res = 0;
//
//    for (int i = 0; i < n; ++i) {
//        if (m > 0) {
//            res += v[i].second;
//        }
//        else {
//            res += v[i].second * v[i].first * 0.01;
//        }
//        m--;
//    }
//
//    res = 0.005;
//
//    printf("%.2f", res);
//
//    return 0;
//}


















//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<int> b(n, 0);    // 需求
//    vector<int> a(m, 0);    // 现有配重块
//
//    for (int i = 0; i < n; ++i) {
//        int tmp;
//        cin >> tmp;
//        b[i] = tmp;
//    }
//
//    for (int i = 0; i < m; ++i) {
//        int tmp;
//        cin >> tmp;
//        a[i] = tmp;
//    }
//
//    // 从小到大
//    sort(b.begin(), b.end());
//    sort(a.begin(), a.end());
//
//    int ans = 0;
//    // n 个需求
//    int last = -1;
//
//    //先找到第一个合适的配重块
//    for(int i = 0; i < m; ++i) {
//        if(a[i] >= b[0]) {
//            last = i;   // 记住上一次位置
//            break;
//        }
//    }
//
//    if(last == -1) {
//        cout << -1 << endl;
//        return 0;
//    }
//
//    for(int i = 0; i < n; ++i) {
//        if(a[last] >= b[i]) {
//            ans += a[last];
//        }
//        // 找到一个合适的配重块
//        else {
//            while(last < m) {
//                last++;
//                if(a[last] >= b[i]) {
//                    break;
//                }
//            }
//
//            ans += a[last];
//        }
//    }
//
//    cout << ans << endl;
//
//
//    return 0;
//}




















// 2.cpp
//map<pair<int, int>, int> res;
//// 得到 node 的哈曼顿距离的坐标点
//void getMHD(int n, int dis, pair<int, int> node) {
//    int top = node.first - dis <= 0 ? 1 : (node.first - dis);
//    int bottom = node.first + dis > n ? n : (node.first + dis);
//    int left = node.second - dis <= 0 ? 1 : (node.second - dis);
//    int right = node.second + dis > n ? n : (node.second + dis);
//
//    for(int i = top; i <= bottom; ++i) {
//        for(int j = left; j <= right; ++j) {
//            if(abs(i - node.first) + abs(j - node.second) == dis) {
//                pair<int, int> curNode(i, j);
//                res[curNode]++;
//            }
//        }
//    }
//}
//
//bool cmp(const pair<int, int> a, const pair<int, int> b) {
//    if(a.first < b.first) {
//        return a < b;
//    } else {
//        return a.second < b.second;
//    }
//}
//
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<pair<int, int>> nodes(3, {0, 0});
//    for(int i = 0; i < 3; ++i) {
//        int x, y;
//        cin >> x >> y;
//        pair<int, int> node{x, y};
//        nodes[i] = node;
//    }
//
//    for(int i = 0; i < 3; ++i) {
//        int dis;
//        cin >> dis;
//        getMHD(n, dis, nodes[i]);
//    }
//
//    vector<pair<int, int>> ans;
//    ans.clear();
//    for(auto it = res.begin(); it != res.end(); ++it) {
//        if(it->second == 3) {
//            ans.push_back(it->first);
//        }
//    }
//
//    sort(ans.begin(), ans.end(), cmp);
//
//    cout << ans[0].first << " " << ans[0].second << endl;
//
//}















//int main() {
//    int n;
//    cin >> n;
//
//    string a, b;
//    cin >> a >> b;
//
//    for (int i = 0; i < n; ++i) {
//        cout << a[i] << b[i];
//    }
//    cout << endl;
//}


















//struct Box {
//    int l;  // 长
//    int w;  // 宽
//    int h;  // 高
//
//    Box(int L, int W, int H) {
//        l = L;
//        w = W;
//        h = H;
//    }
//};
//
//bool cmp(Box a, Box b) {
//    // 比较长度，长宽小于第二个，
//    if (a.l < b.l && a.w < b.w) {
//        return false;
//    } else {
//        return true;
//    }
//}
//
//bool cmp2(Box a, Box b) {
//    return a.h > b.h;
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<Box> boxes(n, {0, 0, 0});
//
//    for (int i = 0; i < n; ++i) {
//        int l, w, h;
//        cin >> l >> w >> h;
//        Box box(l, w, h);
//
//        boxes[i] = box;
//    }
//
//    sort(boxes.begin(), boxes.end(), cmp);
//    sort(boxes.begin(), boxes.end(), cmp2);
//
//    int ans = 0;
//
//    Box curBox(INT_MAX, INT_MAX, INT_MAX);
//    for (int i = 0; i < n; ++i) {
//        if (boxes[i].l < curBox.l && boxes[i].w < curBox.w) {
//            ans += boxes[i].h;
//            curBox = boxes[i];
//        } else {
//            break;
//        }
//    }
//
//    cout << ans << endl;
//}
















//int main() {
//    int n;
//    cin >> n;
//    int a[n + 1];
//    a[0] = 0;
//
//    bool flag = false;
//    for (int i = 1; i <= n; ++i) {
//        scanf("%d", &a[i]);
//        if(a[i] % 2 == 1) {
//            flag = true;
//        }
//    }
//
//    int sum = 0;
//    for (int i = 1; i <= n; ++i) {
//        if (a[i] % 2 == 1) {
//            sum += a[i];
//        } else {
//            sum += (a[i] - 1);
//        }
//    }
//
//    if (sum % 2 == 0) {
//        sum--;
//    }
//
//    // 全是偶数
//    if(!flag) {
//        sum -= 2;
//    }
//    // 全是奇数，花的种类
//
//    cout << sum << endl;
//}


















//int main() {
//    int N, M, P, Q;     // P月开始 Q个月掉落 2 M
//    cin >> N >> M >> P >> Q;
//
//    vector<bool> bigWind(13, false);
//
//    for (int i = 1; i < 13; ++i) {
//        if (i == P) {
//            for (int j = P; j < P + Q; ++j) {
//                bigWind[j] = true;
//            }
//            break;
//        }
//    }
//
//    int res = 0;
//    int month = 1;
//    while (true) {
//        month = month % 12;
//        if (month == 0) month = 12;
//        if (!bigWind[month]) {
//            N -= M;
//        } else {
//            N -= 2 * M;
//        }
//
//        month++;
//        res++;
//
//        if(N <= 0) break;
//    }
//
//    cout << res << endl;
//}


























//int main() {
//    int length, tag;
//    cin >> length >> tag;
//
//    if(length < 22 || length > 1024) {
//        cout << -4 << endl;
//    }
//
//    string msg;
//    cin >> msg;
//
//    int cur = 32;   // 跳过模块号、PID、接收模块号、PID
//    string msgLength = msg.substr(cur, 8);
//
//    int msgLength2 = 0; // 消息体长度
//    int cifang = 0;
//
//    for(int i = msgLength.length() - 1; i >= 0; --i) {
//        msgLength2 = msgLength2 + (msgLength[i] - '0') * pow(16, cifang);
//        cifang++;
//    }
//
//
//    cur += 8;   // 消息体长度
//    cur += 4;   // 消息类型
//
//
//    while(true) {
//        //int cifang = 0;
//        // tag 字符串
//        //0002
//        if(cur > length * 2) break;
//
//        string tagString = msg.substr(cur, 4);
//        cur += 4;
//
//        cifang = 0;
//        int tagNum = 0;
//        for(int i = tagString.length() - 1; i >= 0; --i) {
//            tagNum = tagNum + (tagString[i] - '0') * pow(16, cifang);
//            cifang++;
//        }
//
//        if(tagNum == tag) {
//            cur -= 4;
//            break;
//        }
//
//        //信元长度 0004 length
//        string tagLength = msg.substr(cur, 4);
//        cur += 4;
//        int tagLength2 = 0;
//        cifang = 0;
//        for(int i = tagLength.length() - 1; i >= 0; --i) {
//            tagLength2 = tagLength2 + (tagLength[i] - '0') * pow(16, cifang);
//            cifang++;
//        }
//
//        cur += tagLength2 * 2;
//    }
//    cout << cur / 2 << endl;
//
//
//
//}














//
//// we have defined the necessary header files here for this problem.
//// If additional header files are needed in your program, please import here.
//void split(string name, vector<string> &names, char c) {
//    stringstream ss(name);
//    string tmp;
//    while (getline(ss, tmp, c)) names.push_back(tmp);
//}
//
//
//int main() {
//    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
//    // please finish the function body here.
//    // please define the C++ output here. For example:cout<<____<<endl;
//    string name;
//    vector<string> names;
//    getline(cin, name);
//    split(name, names, ' ');
//    set<string> names3;
//    for(int i = 0; i < names.size(); ++i) {
//        names3.insert(names[i]);
//    }
//
//    int m, n;
//    cin >> m >> n;
//
//    vector<vector<string>> employees(m, vector<string>(n, ""));
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            string tmp;
//            cin >> tmp;
//            employees[i][j] = tmp;
//        }
//    }
//
//    set<string> res;
//    int size = names.size();
//
//    vector<string> names2;
//
//    for (int i = 0; i < size; ++i) {
//        string sill = names[i];
//        int x = -1, y = -1;
//
//        for (int j = 0; j < m; ++j) {
//            for (int k = 0; k < n; ++k) {
//                if (sill == employees[j][k]) {
//                    x = j;
//                    y = k;
//                    break;
//                }
//            }
//        }
//
//        if (x - 1 >= 0 && y - 1 >= 0) {
//            res.insert(employees[x - 1][y - 1]);
//            names2.push_back(employees[x - 1][y - 1]);
//        }
//
//        if (x - 1 >= 0 && y + 1 < n) {
//            res.insert(employees[x - 1][y + 1]);
//            names2.push_back(employees[x - 1][y + 1]);
//        }
//
//        if (x - 1 >= 0) {
//            res.insert(employees[x - 1][y]);
//            names2.push_back(employees[x - 1][y]);
//        }
//
//        if (y - 1 >= 0) {
//            res.insert(employees[x][y - 1]);
//            names2.push_back(employees[x][y - 1]);
//        }
//
//        if (y + 1 < n) {
//            res.insert(employees[x][y + 1]);
//            names2.push_back(employees[x][y + 1]);
//        }
//
//        if (x + 1 < m && y - 1 >= 0) {
//            res.insert(employees[x + 1][y - 1]);
//            names2.push_back(employees[x + 1][y - 1]);
//        }
//
//        if (x + 1 < m) {
//            res.insert(employees[x + 1][y]);
//            names2.push_back(employees[x + 1][y]);
//        }
//
//        if (x + 1 < m && y + 1 < n) {
//            res.insert(employees[x + 1][y + 1]);
//            names2.push_back(employees[x + 1][y + 1]);
//        }
//    }
//
//    int size2 = names2.size();
//    set<string> res2;
//    for (int i = 0; i < size2; ++i) {
//        string sill = names2[i];
//        int x = -1, y = -1;
//
//        for (int j = 0; j < m; ++j) {
//            for (int k = 0; k < n; ++k) {
//                if (sill == employees[j][k]) {
//                    x = j;
//                    y = k;
//                    break;
//                }
//            }
//        }
//
//        if (x - 1 >= 0 && y - 1 >= 0) {
//            res2.insert(employees[x - 1][y - 1]);
//        }
//
//        if (x - 1 >= 0 && y + 1 < n) {
//            res2.insert(employees[x - 1][y + 1]);
//        }
//
//        if (x - 1 >= 0) {
//            res2.insert(employees[x - 1][y]);
//        }
//
//        if (y - 1 >= 0) {
//            res2.insert(employees[x][y - 1]);
//        }
//
//        if (y + 1 < n) {
//            res2.insert(employees[x][y + 1]);
//        }
//
//        if (x + 1 < m && y - 1 >= 0) {
//            res2.insert(employees[x + 1][y - 1]);
//        }
//
//        if (x + 1 < m) {
//            res2.insert(employees[x + 1][y]);
//        }
//
//        if (x + 1 < m && y + 1 < n) {
//            res2.insert(employees[x + 1][y + 1]);
//        }
//    }
//
//    vector<string> res3;
//    vector<string> res4;
//    for (auto it = res.begin(); it != res.end(); ++it) {
//        res3.push_back(*it);
//    }
//    for (auto it = res2.begin(); it != res2.end(); ++it) {
//        res4.push_back(*it);
//    }
//
//    cout << "[";
//    for (int i = 0; i < res3.size(); ++i) {
//        if (i == 0) {
//            cout << res3[i];
//        } else {
//            cout << ", " << res3[i];
//        }
//    }
//    for (int i = 0; i < res4.size(); ++i) {
//        if(res.count(res4[i]) || names3.count(res4[i])) continue;
//        cout << ", " << res4[i];
//    }
//    cout << "]";
//    cout << endl;
//
//
//    return 0;
//}
