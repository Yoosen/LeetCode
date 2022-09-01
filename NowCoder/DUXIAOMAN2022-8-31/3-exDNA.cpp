// 科学家在外星球发现了一种全新的生物，该种生物的遗传物质与DNA类似，被称为exDNA。
// 与DNA类似，exDNA由9种碱基对依次连接而成，将这9种碱基对分别编号为1至9，则一段exDNA链可以写成一个字符串，例如：
// 1376329476294518......
// 进一步研究发现，如果exDNA中存在两个相邻的1号碱基对，则该段exDNA的表征将出现问题。因此科学家将exDNA分为两类：正常exDNA和错误exDNA。正常exDNA中不含相邻的1号碱基对，错误exDNA包含至少一处相邻的1号碱基对。形式化地，设exDNA长度为n，第i个碱基对编号为ai，则当存在一个i使ai=ai+1=1(1≤i≤n-1)时，该exDNA为错误exDNA，反之为正常exDNA。
// 例如12445，2414183，1都是正常exDNA；11244，52112，67113都是错误exDNA。
// 更进一步的研究发现，exDNA在复制时可能产生复制错误，表现为相邻的两个碱基对交换位置，例如12345复制后可能得到13245。由于发生错误的可能性很低，可以认为一段exDNA在复制时至多只会发生一次复制错误。在至多产生一次复制错误的条件下，如果一段exDNA复制后得到的一定是正常exDNA，则称其为安全exDNA；如果复制后可能得到错误exDNA，则称其为不安全exDNA。
// 例如12445，1，123123都是安全exDNA，2414183，1214，311都是不安全exDNA。

// 请编写一个程序，计算有多少种不同的长度为n的安全exDNA链，结果对1000000007取模。
#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    // dp[i][j] 为第 i + 1 位 以 j + 1 结尾的安全 DNA
    vector<vector<int>> dp(n, vector<int>(9, 0));

    for (int i = 0; i < 9; i++) dp[0][i] = 1;    // 第 0 位 初始化为 1，只有一个数，都是安全且为 1
    for (int i = 1; i < 9; i++) dp[1][i] = 9;    // 第 1 位 以 j + 1 结尾的安全 是 9
    dp[1][0] = 8;           // 第 2 位 为 1 的安全 DNA
    for (int i = 2; i < n; i++) {     // 从第 3 位开始遍历
        for (int j = 0; j < 9; j++) { // 遍历 1 ~ 9 9个数字为结尾
            int cur = j + 1;    // 当前 i + 2 结尾的数字是 cur
            if (cur != 1) {       // 结尾数不为 1
                int num = 0;
                for (int k = 0; k < 9; k++) {
                    num = (num + dp[i - 1][k]) % MOD;   // 等于 i - 1 位 以 1 ~ 9结尾的所有方式
                }
                dp[i][j] = num;
            } else {
                int num = 0;
                for (int k = 1; k < 9; k++) {             // i - 2 为 以 2 ~ 9结尾的所有方式
                    num = (num + dp[i - 2][k]) % MOD;
                }
                int summ = 0;
                // 相等于 * 8 i - 1为只有 2 ~ 9 八种可能，所以 * 8
                // 没有直接 * 8，采用累加方式，考虑整数溢出可能
                for (int k = 1; k < 9; k++) summ = (summ + num) % MOD;
                dp[i][j] = summ;
            }
        }
    }
    int sum = 0;
    for (int k = 0; k < 9; k++) {
        sum = (sum + dp[n - 1][k]) % MOD;
    }
    cout << sum << endl;
    return 0;
}