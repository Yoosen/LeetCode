// 208. 实现 Trie (前缀树)
// Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

// 请你实现 Trie 类：

// Trie() 初始化前缀树对象。
// void insert(String word) 向前缀树中插入字符串 word 。
// boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
// boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

// 示例：

// 输入
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// 输出
// [null, null, true, false, true, null, true]

// 解释
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // 返回 True
// trie.search("app");     // 返回 False
// trie.startsWith("app"); // 返回 True
// trie.insert("app");
// trie.search("app");     // 返回 True
 

// 提示：

// 1 <= word.length, prefix.length <= 2000
// word 和 prefix 仅由小写英文字母组成
// insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次

class Trie {
private:
	bool isEnd;
	Trie* next[26];

public:
    Trie() {
    	isEnd = false;
    	memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
    	Trie* node = this;
    	for(char c : word) {
    		if(node->next[c - 'a'] == NULL) {
    			node->next[c - 'a'] = new Trie();
    		}
    		node = node->next[c - 'a'];
    	}
    	node->isEnd = true;
    }
    
    bool search(string word) {
    	Trie* node = this;
    	for(char c : word) {
    		node = node->next[c - 'a'];
    		if(node == NULL) {
    			return false;
    		}
    	}
    	return node->isEnd;
    }
    
    bool startsWith(string prefix) {
    	Trie* node = this;
    	for(char c : prefix) {
    		node = node->next[c - 'a'];
    		if(node == NULL) {
    			return false;
    		}
    	}
    	return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */