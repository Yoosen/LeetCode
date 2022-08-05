// 2.小美的评分计算器
// 时间限制：C/C++ 1秒，其他语言2秒

// 空间限制：C/C++ 256M，其他语言512M

// 美团对于商家的评价体系是1-5星评价体系，用户在完成订单之后可以对商家打1/2/3/4/5星，而在客户端上，商家的评级却不一定是整数，而是会显示小数点后的一位。很显然这就需要一个计算器了，小美拥有了一些商户的评价数据，希望可以计算出商家在客户端上显示出的评分。

// 这个评分的计算非常简单，就是对该商家的所有客户的星级评价做求一个平均，然后去尾法显示小数点后的一位即可，例如平均得分是3.55，则显示的是3.5。例如某商家获得了1-5星评价各一个，则显示的评分是(1+2+3+4+5)/5=3.0。

// 如果商家没有获得评价，则显示0.0。


// 输入描述:
// 输入包含5个整数，依次分别表示商家获得1星到5星的评价数量，每一种评价的数量都不大于1000。

// 输出描述:
// 输出仅包含一个保留一位的小数，表示商家在客户端上显示的评级。

// 输入例子1:
// 2 2 1 1 2

// 输出例子1:
// 2.8

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    double sum = 0, count = 0;
    for(int i = 1; i <= 5; ++i) {
        int tmp = 0;
        cin >> tmp;
        sum += (i * tmp);
        count += tmp;
    }

    printf("%.1f", sum / count - 0.05);

    return 0;
}