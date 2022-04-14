// 未完成

class Solution {
public:
    string longestPalindrome(string s) {
    	int n = s.length();
    	int i = 0, j = n - 1;
    	int left, right;

    	while(i <= j) {
    		if(s[i] == s[j]) {
    			i++;
    			j--;
    		}
    		else {
    			left = -1;
    			right = n;
    		}
    	}
    }
};