import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.lang.Math;

class LongestSubstringWithoutRepeatingCharacters{


	public static int lengthOfLongestSubstring(String s) {
		Map<Character, Integer> window = new HashMap<>();

		int left = 0, right = 0;
		int res = 0;

		while(right < s.length()) {
       		// c 是将移入窗口的字符
			char c = s.charAt(right);
       		// 右移窗口
			right++;

			window.put(c, window.getOrDefault(c, 0) + 1);

			// 判断左侧是否需要收缩
			while(window.get(c) > 1) {
				char d = s.charAt(left);
				left++;

				window.put(d, window.get(d) - 1);
			}

			res = Math.max(res, right - left);
			
		}

		return res;
	}

	public static void main(String[] args) {
		int a = lengthOfLongestSubstring("au");
		System.out.println(a);
	}
	
}
