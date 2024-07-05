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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpoint;
        ListNode* prev=NULL;
        ListNode* curr=head;
        int pos=0;

        while(curr!=NULL && curr->next!=NULL){
            if(prev!=NULL && curr->next!=NULL){
                if((curr->val>prev->val && curr->val>curr->next->val) ||
                (curr->val<prev->val && curr->val<curr->next->val))
                criticalpoint.push_back(pos);
            }
            prev=curr;
            curr=curr->next;
            pos++;
        }
        if(criticalpoint.size()<2){
            return {-1,-1};
        }
        int minDistance=INT_MAX;
        int maxDistance=criticalpoint.back()-criticalpoint.front();

        for(int i=1;i<criticalpoint.size();i++){
            minDistance=min(minDistance,criticalpoint[i]-criticalpoint[i-1]);
        }
        return {minDistance,maxDistance};
    }
};