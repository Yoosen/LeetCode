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

// 1 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti <= endi <= 10^4

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	sort(intervals.begin(), intervals.end());

    	vector<vector<int>> ans;

    	// 遍历区间
    	for(int i = 0; i < intervals.size();) {
    		// 先保存当前的右边界
    		int r = intervals[i][1];

    		// 从当前区间的右边区间开始遍历区间，只要遍历到的区间的左边界小于当前右边界
    		// 就收录进去，同时更新当前的右边界为收录进去的区间的右边界
    		int j = i + 1;
    		while(j < intervals.size() && intervals[j][0] <= r) {
    			r = max(r, intervals[j][1]);
    			j++;
    		}

    		// 更新完了部分连续的区间
    		// 加入到结果集中
    		ans.push_back({intervals[i][0], r});

    		i = j;	// 从 j 继续遍历

    	}

    	return ans;
    }
};