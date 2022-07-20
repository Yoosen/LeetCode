// 125. 验证回文串
// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

 

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 解释："amanaplanacanalpanama" 是回文串
// 示例 2:

// 输入: "race a car"
// 输出: false
// 解释："raceacar" 不是回文串
 

// 提示：

// 1 <= s.length <= 2 * 10^5
// 字符串 s 由 ASCII 字符组成

class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;

        for(char ch : s) {
            if(isalnum(ch)) {
                tmp += tolower(ch);
            }
        }


        int l = 0, r = tmp.length() - 1;

        while(l < r) {

            if(tmp[l] != tmp[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int l = 0, r = s.length() - 1;

//         while(l < r) {
//             while(!isalnum(s[l])) l++;
//             while(!isalnum(s[r])) r--;

//             if(l < r && s[l] != s[r] && s[l] != 32 + s[r] && s[r] != 32 + s[l])
//                 return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
// };