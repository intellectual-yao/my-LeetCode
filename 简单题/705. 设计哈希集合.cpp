// Source : https://leetcode-cn.com/problems/design-hashset/submissions/
// Author : GuoQiang Yao
// Date : 2022-2-21

/**************************************************************************************
不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

实现 MyHashSet 类：

void add(key) 向哈希集合中插入值 key 。
bool contains(key) 返回哈希集合中是否存在这个值 key 。
void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

示例：

输入：
[“MyHashSet”, “add”, “add”, “contains”, “contains”, “add”, “contains”, “remove”, “contains”]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
输出：
[null, null, null, true, false, null, true, null, false]

解释：
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1); // set = [1]
myHashSet.add(2); // set = [1, 2]
myHashSet.contains(1); // 返回 True
myHashSet.contains(3); // 返回 False ，（未找到）
myHashSet.add(2); // set = [1, 2]
myHashSet.contains(2); // 返回 True
myHashSet.remove(2); // set = [1]
myHashSet.contains(2); // 返回 False ，（已移除）

提示：

0 <= key <= 106
最多调用 104 次 add、remove 和 contains

**************************************************************************************/

/*******************************************************************************************************
题目分析：从题目描述可以看出，本题使用的数据结构为二维数组，因此开始的时候使用Public定义好二维数组，
然后对其在类内进行初始化，因为实现的是哈希表，因此在进行增删改查操作的时候都需要进行相应的判断，然后进行相应的基本操作即可。
********************************************************************************************************/
class MyHashSet {
private:
	vector<list<int>> nums;
	static const int base = 911;
	int hash(int key) {
		return key % base;
	}

public:
	/** Initialize your data structure here. */
	MyHashSet() {
		nums.resize(base);
	}

	void add(int key) {
		int index = hash(key);
		for (auto it = nums[index].begin(); it != nums[index].end(); ++it) {
			if (*it == key) {
				return;
			}
		}
		nums[index].push_back(key);
	}

	void remove(int key) {
		int index = hash(key);
		for (auto it = nums[index].begin(); it != nums[index].end(); ++it) {
			if (*it == key) {
				nums[index].erase(it);
				break;;
			}
		}
		return;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int index = hash(key);
		for (auto it = nums[index].begin(); it != nums[index].end(); ++it) {
			if (*it == key) {
				return true;
			}
		}
		return false;
	}
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
