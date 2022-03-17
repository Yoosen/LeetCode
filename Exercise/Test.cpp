#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> need, window;
    vector<int> ans;

    for(char c : p) need[c]++;

    int left = 0, right = 0, valid = 0;

    while(right < s.size())
    {
        char c = s[right];
        right++;

        if(need.count(c))
        {
            window[c]++;

            if(window[c] == need[c])
            {
                valid++;
            }
        }

        while(right - left >= p.size())
        {
            if(valid == need.size())
            {
                ans.push_back(left);
            }

            char d = s[left];
            left++;

            if(need.count(d))
            {
                if(window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return ans;
}


int main()
{
    string s = "abab", p = "ab";
    vector<int> result;
    result = findAnagrams(s, p);
    for(int i: result)
        cout<<i<<endl;
    cout<<"中文测试"<<endl;
}

