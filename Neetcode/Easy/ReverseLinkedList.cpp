//https://leetcode.com/problems/reverse-linked-list

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* next = head->next;
        ListNode* prev = nullptr;

        while (head) {            
            head->next = prev;
            prev = head;
            head = next;
            next = next ? next->next : nullptr;
        }

        return prev;
    }
};