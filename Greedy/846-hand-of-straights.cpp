// 846. 一手顺子
// Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，并且由 groupSize 张连续的牌组成。

// 给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。如果她可能重新排列这些牌，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// 输出：true
// 解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
// 示例 2：

// 输入：hand = [1,2,3,4,5], groupSize = 4
// 输出：false
// 解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
 

// 提示：

// 1 <= hand.length <= 104
// 0 <= hand[i] <= 109
// 1 <= groupSize <= hand.length
 

// 注意：此题目与 1296 重复：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    	int n = hand.size();

    	if(n % groupSize != 0) return false;

    	sort(hand.begin(), hand.end());
    	unordered_map<int, int> cnt;

    	for(auto& num : hand) {
    		// 统计出现过的数的次数
    		cnt[num]++;
    	}

    	for(auto& x : hand) {
    		// 为什么hash表可能不存在这个hand中的这个数，因为被后续操作删除了
    		if(!cnt.count(x)) {
    			continue;
    		}

    		for(int i = 0; i < groupSize; ++i) {
    			int num = x + i;

    			// 不存在后续的这个数
    			if(!cnt.count(num)) {
    				return false;
    			}
    			// 存在
    			cnt[num]--;
    			if(cnt[num] == 0) {
    				// 这个数被前面连续的已经用完，删掉
    				cnt.erase(num);
    			}
    		}
    	}
    	return true;
    }
};