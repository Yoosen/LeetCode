#include<bits/stdc++.h>//有手就行系列
using namespace std;
int main(){
    for(int i = 1; i <= 26; ++i){
        for(int j = 1; j <= 26 - i; ++j)cout<<' ';
        for(int j = 1; j <= i; ++j)cout<<(char)('A' + j - 1);
        for(int j = i - 1; j >= 1; --j)cout<<(char)('A' + j - 1);
        cout<<endl;
    }
}
