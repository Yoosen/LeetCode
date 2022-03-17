// 加密的方式很简单：
// 对于一串字符串，如果其中有l，i，n，k，e这五个字母当中的任意一个，帕雅都会在这后面加上bt再加上原来的字母已加密，如love就会加密成lbtlovebte。
// ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s = "ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd";

	size_t i = 0;
	while (i < s.size())
	{
		if (s[i] == 'l' || s[i] == 'i' || s[i] == 'n' || s[i] == 'k' || s[i] == 'e')
		{
			cout << s[i];
			i += 4;
		}
		else 
		{
			cout << s[i];
			i++;
		}
	}
	cout << endl;
	return 0;
}
