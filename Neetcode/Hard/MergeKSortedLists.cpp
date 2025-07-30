#include <queue>
#include <vector>

using namespace std;

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
    struct comparator {
        bool operator() (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, comparator> minHeap;

        for(auto node : lists)
            if (node)
                minHeap.push(node);
        
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        
        while (!minHeap.empty()) {

            ListNode *top = minHeap.top();
            minHeap.pop();

            tail->next = new ListNode(top->val);
            tail = tail->next;
            top = top->next;
            if (top) 
                minHeap.push(top);            
        }

        return dummy->next;
    }
};