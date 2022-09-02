// 1213.三个有序数组的交集

// 给出三个均为 严格递增排列 的整数数组 arr1，arr2 和 arr3。

// 返回一个由 仅 在这三个数组中 同时出现 的整数所构成的有序数组。

// 示例：

// 输入: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
// 输出: [1,5]
// 解释: 只有 1 和 5 同时在这三个数组中出现.
// 提示：

// 1 <= arr1.length, arr2.length, arr3.length <= 1000
// 1 <= arr1[i], arr2[i], arr3[i] <= 2000

// 将 arr2 和 arr3 数组分别插入到 set 中，遍历 arr1， 如果能同时在 s2 和 s3 set中找到 arr[i]，
// 那么 arr[i] 一定是公共的元素，加入到 ans 结果集

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    	unordered_set<int> s2(arr2.begin(), arr2.end()), s3(arr3.begin(),arr3.end());
    	vector<int> ans;
    	for(int i = 0; i < arr1.size(); ++i)
    	{
    		if(s2.find(arr1[i]) != s2.end() 
    				&& s3.find(arr1[i])!=s3.end())
    			ans.push_back(arr1[i]);
    	}
    	return ans;
    }
};