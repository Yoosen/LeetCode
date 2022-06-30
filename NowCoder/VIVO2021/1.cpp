// 1.编译依赖问题

// 一个完整的软件项目往往会包含很多由代码和文档组成的源文件。编译器在编译整个项目的时候，可能需要按照依赖关系来依次编译每个源文件。
// 比如，A.cpp 依赖 B.cpp，那么在编译的时候，编译器需要先编译 B.cpp，才能再编译 A.cpp。 
// 假设现有 0，1，2，3 四个文件，0号文件依赖1号文件，1号文件依赖2号文件，3号文件依赖1号文件，则源文件的编译顺序为 2,1,0,3 或 2,1,3,0。
// 现给出文件依赖关系，如 1,2,-1,1，表示0号文件依赖1号文件，1号文件依赖2号文件，2号文件没有依赖，3号文件依赖1号文件。
// 请补充完整程序，返回正确的编译顺序。注意如有同时可以编译多个文件的情况，按数字升序返回一种情况即可，比如前述案例输出为：2,1,0,3


// 输入例子1:
// "1,2,-1,1"

// 输出例子1:
// "2,1,0,3"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 编译顺序
     * @param input string字符串 
     * @return string字符串
     */
	string compileSeq(string input) {
    	// write code here
		vector<vector<int>> vc;

		int i = 0, num = 0, flag = 1;
	    for(auto& c : input)   // "1,2,-1,1"
	    {
	    	if(c == ',')
	    	{
	            vc.push_back({i, num * flag});	// (当前节点，当前节点的前序)
	            i++;
	            num = 0;
	            flag = 1;
	        }
	        else if (c == '-')
	        {
	        	flag = -1;
	        }
	        else
	        {
	        	num = num * 10 + c - '0';
	        }
	    }

	    vc.push_back({i, num * flag});

	    vector<int> inDegree(i + 1);			// 每个节点的入度
	    unordered_map<int, vector<int>> mp;	// (节点， 后续节点)

	    for(int j = 0; j < vc.size(); ++j)
	    {
	    	if(vc[j][1] != -1)
	    		inDegree[vc[j][0]]++;
	    	mp[vc[j][1]].push_back(vc[j][0]);
	    }

	    // que 不能排序，属于序列式，因此使用双端队列 deque
	    deque<int> dq;
	    vector<int> res;

	    for(int j = 0; j < inDegree.size(); ++j)
	    {
	    	if(inDegree[j] == 0)
	    		dq.push_back(j);
	    }

	    while(!dq.empty())
	    {
	    	sort(dq.begin(), dq.end(), [](int x, int y)
	    	{
	    		return x < y;
	    	});

	    	int selected = dq.front();
	    	dq.pop_front();

	        res.push_back(selected);// 2,1,0,3

	        vector<int> toEnQue = mp[selected];	//更新当前出节点的后续节点

	        if(toEnQue.size())
	        {
	        	for(int j = 0; j < toEnQue.size(); ++j)
	        	{
	                inDegree[toEnQue[j]]--;		// 入度减 1
	                if(inDegree[toEnQue[j]] == 0)
	                {
	                	dq.push_back(toEnQue[j]);
	                }
	            }
	        }
	    }

	    string ans = "";
	    for(int num : res)
	    {
	    	ans = ans + to_string(num) + ",";
	    }

	    return ans.substr(0, ans.length() - 1);
	}
};