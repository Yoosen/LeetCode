// 67. 二进制求和
// 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

 

// 示例 1：

// 输入:a = "11", b = "1"
// 输出："100"
// 示例 2：

// 输入：a = "1010", b = "1011"
// 输出："10101"
 

// 提示：

// 1 <= a.length, b.length <= 10^4
// a 和 b 仅由字符 '0' 或 '1' 组成
// 字符串如果不是 "0" ，就不含前导零

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        string res = "";

        int carry = 0;

        while(i >= 0 || j >= 0 || carry != 0) {
            int x = (i >= 0 ? a[i] - '0' : 0);
            int y = (j >= 0 ? b[j] - '0' : 0);

            int sum = 0;
            if(x + y + carry >= 2) {
                sum = x + y + carry - 2;
                carry = 1;
            } else {
                sum = x + y + carry;
                carry = 0;
            }
            --i;
            --j;

            res += (sum + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};