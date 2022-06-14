// 207. 课程表
// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：numCourses = 2, prerequisites = [[1,0]]
// 输出：true
// 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
// 示例 2：

// 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
// 输出：false
// 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 

// 提示：

// 1 <= numCourses <= 10^5
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// prerequisites[i] 中的所有课程对 互不相同

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<int> inDegree(numCourses);	// 每个节点的入度信息
    	unordered_map<int, vector<int>> m;	// 每个节点的后续节点

    	for(int i = 0; i < prerequisites.size(); i++) {
    		// 当前课程的入度 +1
    		inDegree[prerequisites[i][0]]++;
    		// 节点的后续节点记录
    		m[prerequisites[i][1]].push_back(prerequisites[i][0]);
    	}

    	queue<int> que;

    	// 遍历入度为 0 的节点，进行入队
    	for(int i = 0; i < numCourses; ++i) {
    		if(inDegree[i] == 0)
    			que.push(i);
    	}

    	int count = 0; // 满足的课程数目
    	// 出队
    	while(!que.empty()) {
    		int selected = que.front();		// 当前选的课程
    		que.pop();						// 出队
    		count++;						// 满足的课程 +1
    		vector<int> toEnQueue = m[selected];	// 获取当前选的课程的后续课程

    		if(toEnQueue.size()) {	// 该课程有后续课程
    			// 更新其后续节点的入度
    			for(int i = 0; i < toEnQueue.size(); ++i) {
    				inDegree[toEnQueue[i]]--;
    				//如果出现入度为 0 的，加入队列
    				if(inDegree[toEnQueue[i]] == 0)
    					que.push(toEnQueue[i]);
    			}
    		}	
    	}

    	return count == numCourses;
    }
};