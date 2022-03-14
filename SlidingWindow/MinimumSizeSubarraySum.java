import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.lang.Math;

// LeetCode Problem 209

class MinimumSizeSubarraySum{

	public static int minSubArrayLen(int target, int[] nums) {
		ArrayList<Integer> window = new ArrayList<>();

		int left = 0, right = 0;
		int res = 10001, sum = 0;

		for (int i = 0; i < nums.length; i++) {
			sum += nums[i];
		}

		if (sum < target)
			return 0;

		sum = 0;

		while(right < nums.length) {
            // 即将进入窗口的数字
			int a = nums[right];
            // 窗口右移
			right++;

			window.add(a);

			for (int i = 0; i < window.size(); i++) {
				sum += window.get(i);
			}

			while (sum >= target) {
				res = Math.min(res, window.size());

				window.remove(0);

				sum -= nums[left];

				left++;
			}

			sum = 0;
		}

		return res;   
	}

	public static void main(String[] args) {
		int[] nums = {1,1,1,1,1,1,1,1};
        int a = minSubArrayLen(11, nums);

        // System.out.println(nums.length);
        System.out.println(a);
	}

	// public static int lengthOfLongestSubstring(String s) {
	// 	Map<Integer, Integer> window = new HashMap<>();

	// 	int left = 0, right = 0;
	// 	int res = 0;

	// 	while(right < s.length()) {
 //       		// c 是将移入窗口的字符
	// 		char c = s.charAt(right);
 //       		// 右移窗口
	// 		right++;

	// 		window.put(c, window.getOrDefault(c, 0) + 1);

	// 		// 判断左侧是否需要收缩
	// 		while(window.get(c) > 1) {
	// 			char d = s.charAt(left);
	// 			left++;

	// 			window.put(d, window.get(d) - 1);
	// 		}

	// 		res = Math.max(res, right - left);

	// 	}

	// 	return res;
	// }

	// public static void main(String[] args) {
	// 	int a = lengthOfLongestSubstring("au");
	// 	System.out.println(a);
	// }

}
