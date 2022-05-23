// Source : https://leetcode-cn.com/problems/design-hashmap/
// Author : GuoQiang Yao
// Date : 2022-2-24

/**************************************************************************************
不使用任何内建的哈希表库设计一个哈希映射（HashMap）。

实现 MyHashMap 类：

MyHashMap() 用空映射初始化对象
void put(int key, int value) 向 HashMap 插入一个键值对 (key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 -1 。
void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。

示例：

输入：
[“MyHashMap”, “put”, “put”, “get”, “get”, “put”, “get”, “remove”, “get”]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
输出：
[null, null, null, 1, -1, null, 1, null, -1]

解释：
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(1); // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
myHashMap.get(3); // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
myHashMap.get(2); // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
myHashMap.get(2); // 返回 -1（未找到），myHashMap 现在为 [[1,1]]

提示：

0 <= key, value <= 106
最多调用 104 次 put、get 和 remove 方法

**************************************************************************************/

/*******************************************************************************************************
题目分析：此题很像设计哈希集合，可以通过find函数查找插入删除获取的元素的位置，然后进行判断，只要可以查找到合适的位置，那么就进行相应的位置即可。
********************************************************************************************************/

class MyHashMap {
public:
    MyHashMap() {
        hashTable = vector<pair<int, int>>(N, {-1, -1});
    }
    // 用来查找后续所需的位置的函数
    int find(int key) {
        int k = key % N;
        while (hashTable[k].first != key && hashTable[k].first != -1) {
            k = (k + 1) % N;
        }

        return k;
    }

    void put(int key, int value) {
        auto k = find(key);
        hashTable[k] = {key, value};
    }
    
    int get(int key) {
        auto k = find(key);
        if (hashTable[k].first == -1) {
            return -1;
        }
        else
            return hashTable[k].second;
    } 
    
    void remove(int key) {
        auto k = find(key);
        if (hashTable[k].first != -1) {
            hashTable[k].first = -2; // Mark as deleted (use a different value with -1)
        }
    }

private:
    const static int N = 20011;
    vector<pair<int, int>> hashTable;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
