// Source : https://leetcode.cn/problems/sort-list/
// Author : GuoQiang Yao
// Date : 2022-10-27
/**************************************************************************************　
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

示例 1：

输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：



输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105
**************************************************************************************/

/*******************************************************************************************************
题目分析 : 首先套用给整数数组归并排序的模板，首先使用快慢指针找到链表中间节点，然后将链表断开，
递归下去；划分到单个节点后，开始进行回退合并链表，通过设置伪头节点便于处理，最后返回.
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
    ListNode *merge(ListNode *L1, ListNode *L2)
    {
        if(L1 == nullptr || L2 == nullptr)
            return L1;
        // 创建头节点
        ListNode *head = new ListNode(-1);
        ListNode *new_head = head;
        while(L1 && L2)
        {
            if(L1 -> val > L2 -> val)
            {
                head -> next = L2;
                L2 = L2 -> next;
            }
            else
            {
                head -> next = L1;
                L1 = L1 -> next;
            }
            head = head -> next;
        }
        head -> next = L1 ? L1 : L2;
        return new_head -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *slow = head, *fast = head -> next;
        // 原始链表的分割，快慢指针走，慢指针在中间
        while(fast && fast -> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        // 划分剩下的序列(快慢指针按照前中后再次分割)
        fast = slow -> next;
        slow -> next = nullptr;
        slow = head;
        return merge(sortList(slow), sortList(fast));
    }
};
