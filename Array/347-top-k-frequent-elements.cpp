// 347. 前 K 个高频元素
// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

// 示例 1:

// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
// 示例 2:

// 输入: nums = [1], k = 1
// 输出: [1]
 

// 提示：

// 1 <= nums.length <= 105
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	unordered_map<int, int> m;	//两个int分别是元素和出现的次数
    	int n = nums.size();

    	//1.m 记录元素出现的次数
    	for(auto& c : nums) {
    		m[c]++;
    	}
    	// 2.利用优先队列，将出现的次数排序
    	// 自定义优先队列的比较方式，小顶堆
    	struct myComparison {
    		bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
    			return p1.second > p2.second;
    		}
    	};

    	// 创建优先队列
    	priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> q;
    	//遍历map中的元素
        //1.管他是啥，先入队列，队列会自己排序将他放在合适的位置
        //2.若队列元素个数超过k，则将栈顶元素出栈（栈顶元素一定是最小的那个）
        for(auto& a : m) {
        	q.push(a);
        	if(q.size() > k) {
        		q.pop();
        	}
        }

        vector<int> res;
        while(!q.empty()) {
        	res.emplace_back(q.top().first);
        	q.pop();
        }

        return res;

    }
};