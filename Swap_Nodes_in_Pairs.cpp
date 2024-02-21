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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        swap(dummy);
        return dummy->next;
    }

    void swap(ListNode *node){
        if(node == nullptr || node->next == nullptr || node->next->next == nullptr){
            return;
        }

        ListNode* first=node->next;
        ListNode* second=first->next;
        ListNode* secondNext = second->next;
        second->next = first;
        node->next = second;
        first->next = secondNext;
         swap(first);
    }
};