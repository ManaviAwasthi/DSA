class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* dummy= new ListNode(0);
        ListNode* curr=dummy;
        head=head->next;
        while (head!=nullptr){
            if (head->val!=0){
                sum+=head->val;
            }
            else {
                curr->next= new ListNode (sum);
                sum=0;
                curr=curr->next;
            }
            head=head->next;
        }
        return dummy->next;
    }
};