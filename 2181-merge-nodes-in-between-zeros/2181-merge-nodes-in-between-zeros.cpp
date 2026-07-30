class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* dummy= head->next;
        ListNode* curr=dummy;
        while (curr!=nullptr){
            if (curr->val!=0){
                sum+=curr->val;
            }
            else {
                dummy->val= sum;
                sum=0;
                if (curr->next != nullptr)
                    dummy = dummy->next;
            }
            curr=curr->next;
        }
        dummy->next=nullptr;
        return head->next;;
    }
};