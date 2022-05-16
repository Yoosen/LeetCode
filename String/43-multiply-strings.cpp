// LeetCode 43 字符串相乘

// 43. 字符串相乘
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

 

// 示例 1:

// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:

// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
 

// 提示：

// 1 <= num1.length, num2.length <= 200
// num1 和 num2 只能由数字组成。
// num1 和 num2 都不包含任何前导零，除了数字0本身。

class Solution {
public:
    string multiply(string num1, string num2) {

    	if (num1 == "0" || num2 == "0")
    		return "0";
    	
    	vector<int> res(num1.length() + num2.length());

    	for(int i = num1.length() - 1; i>= 0; i--) {
    		int n1 = num1[i] - '0';
    		for(int j = num2.length() - 1; j >= 0; j--) {
    			int n2 = num2[j] - '0';
    			int sum = (res[i + j + 1] + n1 * n2);
    			res[i + j + 1] = sum % 10;
    			res[i + j] += sum / 10;
    		}
    	}
    	
    	string ans;
    	for(int i = 0; i < res.size(); i++) {
    		if(i == 0 && res[i] == 0) continue;
    		ans.push_back(res[i] + '0');
    	}
    	return ans;
    }
};