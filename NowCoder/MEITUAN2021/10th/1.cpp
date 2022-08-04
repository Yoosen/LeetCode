// [编程题]淘汰分数
// 时间限制：C/C++ 1秒，其他语言2秒

// 空间限制：C/C++ 256M，其他语言512M

// 某比赛已经进入了淘汰赛阶段,已知共有n名选手参与了此阶段比赛，他们的得分分别是a_1,a_2….a_n,小美作为比赛的裁判希望设定一个分数线m，使得所有分数大于m的选手晋级，其他人淘汰。

// 但是为了保护粉丝脆弱的心脏，小美希望晋级和淘汰的人数均在[x,y]之间。

// 显然这个m有可能是不存在的，也有可能存在多个m，如果不存在，请你输出-1，如果存在多个，请你输出符合条件的最低的分数线。

// 数据范围：，
// 进阶：时间复杂度，空间复杂度

// 输入描述:
// 输入第一行仅包含三个正整数n,x,y，分别表示参赛的人数和晋级淘汰人数区间。(1<=n<=50000,1<=x,y<=n)

// 输入第二行包含n个整数，中间用空格隔开，表示从1号选手到n号选手的成绩。(1<=|a_i|<=1000)


// 输出描述:
// 输出仅包含一个整数，如果不存在这样的m，则输出-1，否则输出符合条件的最小的值。


// 输入例子1:
// 6 2 3
// 1 2 3 4 5 6

// 输出例子1:
// 3

// 暴力破解

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> v, int x, int y) {
    if (v.size() < 2 * x || v.size() > 2 * y)
        return -1;

    int a = 0, b = 0;    // 晋级、淘汰

    // 淘汰分数线，i 是分数线
    for (int i = v[0]; i < v.back(); ++i) {
        for(int j = 0; j < v.size(); ++j) {
            if(v[j] <= i) b++;
            if(v[j] > i) a++;
            if(a + b == v.size() && x <= a && a <=y && x <= b  && b <= y)
                return i;
        }
        a = 0;
        b = 0;
    }

    return -1;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int t = solve(v, x, y);

    cout << t << endl;

    return 0;
}