// 剑指 Offer II 048 & LeetCode 297 序列化与反序列化二叉树

// 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 前序序列化和反序列化，使用 Vector 会超时，只能用双向链表 list
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    void serialize(TreeNode* root, string& res) {
    	if(root == NULL) {
    		res += "null,";
            return ;
    	}

    	res += to_string(root->val) + ",";

    	serialize(root->left, res);
    	serialize(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;

        for(auto& ch : data) {
        	if(ch == ',') {
        		dataArray.push_back(str);
        		str.clear();
        	} else {
        		str.push_back(ch);
        	}
        }
        if(!str.empty()) {
        	dataArray.push_back(str);
        	str.clear();
        }

        return rdeserialize(dataArray);
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
    	if(dataArray.front() == "null") {
    		dataArray.erase(dataArray.begin());
    		return NULL;
    	}

    	// 取出第一个作为根
    	TreeNode* root = new TreeNode(stoi(dataArray.front()));
    	dataArray.erase(dataArray.begin());

    	root->left = rdeserialize(dataArray);
    	root->right = rdeserialize(dataArray);

    	return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));