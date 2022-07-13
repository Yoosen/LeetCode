// 给定一个只包含大小写字母的字符串（大小写敏感），若相邻两个元素相等则消除，直到最后字符串消除不了了，输出消消乐后字符串的长度，若遇到非大小写字母以外的字符，则输出0。

// 示例
// 输入：mMbccbc
// 输出：3

// 解释：cc消掉，然后bb消掉，最后剩余mMc,输出长度3

#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
	string str;
	cin >> str;

	stack<char> st;

	for(int i = 0; i < str.length(); ++i) {
		if(!st.empty() && st.top() == str[i]) {
			st.pop();
		}
		else {
            st.push(str[i]);
		}
	}

	printf("%d\n", st.size());

    return 0;
}
