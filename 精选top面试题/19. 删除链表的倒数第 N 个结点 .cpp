// Source : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
// Author : GuoQiang Yao
// Date : 2022-5-31
/**************************************************************************************
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。


示例 1：

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
**************************************************************************************/

/*******************************************************************************************************
题目分析： 本题就是需要找到待删除节点的前驱节点即可，通过长度和给定的n来进行查找，然后走删除操作即可完成。
********************************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* h = head;
        // 计算一共有多少节点数
        while(h)
        {
            ++cnt;
            h = h -> next;
        }
        ListNode* front = new ListNode(0, head);
        ListNode* rear = front;
        // 定位到要删除的节点的前一个节点
        // 不用考虑要删除的是不是最后一个节点，因为最后一个节点的后置节点也是nullptr
        for (int i = 1; i < cnt - n + 1; ++i) 
            rear = rear -> next;
        // 删除节点
        rear -> next = rear -> next -> next;
        // delete front;
        return front -> next; 
    }
}; 
