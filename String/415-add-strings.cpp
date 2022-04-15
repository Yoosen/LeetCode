// LeetCode 415 字符串相加

// 415. 字符串相加
// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

// 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

 

// 示例 1：

// 输入：num1 = "11", num2 = "123"
// 输出："134"
// 示例 2：

// 输入：num1 = "456", num2 = "77"
// 输出："533"
// 示例 3：

// 输入：num1 = "0", num2 = "0"
// 输出："0"
 

 

// 提示：

// 1 <= num1.length, num2.length <= 104
// num1 和num2 都只包含数字 0-9
// num1 和num2 都不包含任何前导零

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;

        string ans = "";
        while(i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int res = x + y + add;

            ans += (res % 10 + '0');
            add = res / 10;
            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;

        // reverse(num1.begin(), num1.end());
        // reverse(num2.begin(), num2.end());
        // int n1 = num1.length(), n2 = num2.length();

        // if(n1 == 1 && n2 == 1)
        // 	return to_string(num1[0] - '0' + num2[0] - '0');

        // if(n1 > n2) {
        // 	for(int i = 0; i < n1 - n2; i++) {
        // 		num2 += '0';
        // 	}
        // }
        // else {
        // 	for(int i = 0; i < n2 - n1; i++) {
        // 		num1 += '0';
        // 	}
        // }

        // n1 = num1.length();

        // string temp = "";
        // int extra = 0;

        // for(int i = 0; i < n1; i++) {
        // 	int t = num1[i] - '0' + num2[i] - '0' + extra;
        // 	int s = t % 10;

        // 	if(t >= 10)
        // 		extra = 1;
        // 	else
        // 		extra = 0;

        // 	temp += s + '0';
        // }

        // reverse(temp.begin(), temp.end());
        // return temp;
    }
};