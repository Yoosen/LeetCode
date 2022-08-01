// 1、查找舆情热词

// 网上新闻越来越多，希望对新闻进行热词处理并归类，方便获取信息、现在已经将每篇新闻处理为2个字符串，即一个标题串和一个正文串，字符串中使用” “（空格）作为分隔词语的分隔符进行分词。

// M篇新闻按照新闻发布的先后顺序处理完并输入，现在希望对所有新闻中出现的词语进行处理，输出出现频率最高的topN个词语作为热词。

// 排序规则

//  标题中出现的词语频率系数为3，正文中出现的词语频率系数为1；
// 返回的答案应该按照词语出现频率由高到低排序，当词语出现的频率相同时，在标题中出现的频率次数高的排在前面；
// 如果仍然相同，则按照词语在标题中出现的先后顺序进行排序，先出现的排在前面；
// 如果仍然相同，则按照词语在正文中出现的先后顺序进行排序，先出现的排在前面。
// 解答要求

// 时间限制：C/C++2000ms，其他语言：4000ms

// 内存限制：C/C++256MB，其他语言：512MB

// 输入

//  第一行输入为正整数topN和文章数M，即要输出的出现频率最高的词语的个数和处理的文章的数量，
// 由于每篇文章被处理为标题和正文2行，因此后面有2*M行数据。
// 从第二行起，是按顺序处理后每篇文章的标题串和正文串，
// 即第二行是第一篇文章的标题串，第三行是第一篇文章的正文串，
// 第四行是第二篇文章的标题串，第五行是第二篇文章的正文串，以此类推。
// 参数限制如下：

// 0 < topN < 1000
// 0 < M < 100000
// 0 < 每篇文章的词语数 < 5000
// 输出
//     使用一行输出出现频率最高的topN个词语，每个词语以” “隔开。
// 样例 1

// 输入：
// 3 2
// xinguan feiyan xinzeng bendi quezhen anli
// ju baodao chengdu xinzeng xinguan feiyan bendi quezhen anli yili shenzhen xinzeng bendi quezhen anli liangli yiqing zhengti kongzhi lianghao
// xinguan yimiao linchuang shiyan
// wuzhong xinguan yimiao tongguo sanqi linchaung shiyan xiaoguo lianghao

// 新冠肺炎本地确诊案例
// 据报道成都新增新冠肺炎本地确诊案例一例，深圳新增案例两例，疫情整体控制良好，本地确诊案例两例，疫情整体控制良好。
// 新冠疫苗临床试验
// 五种新冠疫苗通过三期临床试验，效果良好。

// 输出：

// xinguan xinzeng bendi

#include <bits/stdc++.h>

using namespace std;

// 大致的思路，不完全满足要求，需要创建一个结构体，否则信息处理不完全，无法全部通过

bool cmp(pair<string, int> &p1, pair<string, int> &p2) {
    return p1.second > p2.second;
}

// 分割字符串
void split(string s, vector<string>& words, char c) {
    stringstream ss(s);
    string tmp;
    while(getline(ss, tmp, c)) words.push_back(tmp);
}

int main() {
    int topN = 3, M = 2;
    //cin >> topN >> M;

    unordered_map<string, int> m;

    for (int i = 0; i < 2 * M; ++i) {
        //string word = "";
        string s;
        getline(cin, s);
        //cin >> word;
        vector<string> words;
        split(s, words, ' ');

        if (i % 2 == 0) {
            for(int j = 0; j < words.size(); ++j) {
                m[words[j]] += 3;
            }
        }
        else {
            for(auto & word : words) {
                m[word]++;
            }
        }
    }

    vector<pair<string, int>> vm;

    for (auto it = m.begin(); it != m.end(); ++it)
        vm.push_back(make_pair(it->first, it->second));

    sort(vm.begin(), vm.end(), cmp);

    for (int i = 0; i < vm.size(); ++i) {
        //if(i == 0)
        //    cout << vm[i].first;
        //else
        //    cout << " " << vm[i].first;
    }
    cout << endl;

}