// LeetCode 56 合并区间

// 56. 合并区间
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

 

// 示例 1：

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：

// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 

// 提示：

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	vector<vector<int>> res;

    	sort(intervals.begin(), intervals.end());
    	int n = intervals.size();

    	for(int i = 0; i < n; i++) {
    		int left = intervals[i][0];	// 当前区间的左侧端点
    		int right = intervals[i][1];	// 当前区间的右侧端点

    		// 如果当前 res 为空，则将第一个直接加入
    		// 如果当前左侧节点大于上一个节点的右侧，加入 res
    		if (res.size() == 0 || left > res.back()[1]) {
    			res.push_back({left, right});
    		}
    		// 否则的话，更新上一个区间的右侧端点
    		else {
    			res.back()[1] = max(res.back()[1], right);
    		}
    	}

    	return res;
    }
};