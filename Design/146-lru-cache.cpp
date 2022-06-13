// 146. LRU 缓存
// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

 

// 示例：

// 输入
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// 输出
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// 解释
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // 缓存是 {1=1}
// lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
// lRUCache.get(1);    // 返回 1
// lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
// lRUCache.get(2);    // 返回 -1 (未找到)
// lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
// lRUCache.get(1);    // 返回 -1 (未找到)
// lRUCache.get(3);    // 返回 3
// lRUCache.get(4);    // 返回 4
 

// 提示：

// 1 <= capacity <= 3000
// 0 <= key <= 10000
// 0 <= value <= 10^5
// 最多调用 2 * 10^5 次 get 和 put

class LRUCache {
public:

	// 定义双链表
	struct Node {
		int key, value;
		Node* left, *right;
		Node(int _key, int _value): key(_key), value(_value), left(NULL), right(NULL){}
	}*L, *R;

	int n;
	unordered_map<int, Node*>hash;

	void remove(Node* p) {
		p->right->left = p->left;
		p->left->right = p->right;
	}

	void insert(Node* p) {
		p->right = L->right;
		p->left = L;
		L->right->left = p;
		L->right = p;
	}
    LRUCache(int capacity) {
    	n = capacity;
    	L = new Node(-1, -1), R = new Node(-1, -1);
    	L->right = R;
    	R->left = L;
    }
    
    int get(int key) {
    	if(hash.count(key) == 0) return -1;
    	auto p = hash[key];
    	remove(p);
    	insert(p);
    	return p->value;
    }
    
    void put(int key, int value) {
    	// 如果 hash 有这个关键字，双向链表更新顺序
    	if(hash.count(key)) {
    		auto p = hash[key];
    		p->value = value;
    		remove(p);
    		insert(p);
    	} 

    	// 如果没有该关键字，那要更新双向链表和 hash
    	else {
    		// 如果 hash 满了，删除最后一个节点，后续再增加
    		if(hash.size() == n) {
    			auto p = R->left;
    			remove(p);
    			hash.erase(p->key);
    			delete(p);
    		}
    		// 增加一个节点到双向链表中，同时更新 hash
    		auto p = new Node(key, value);
    		hash[key] = p;
    		insert(p);
    	}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */