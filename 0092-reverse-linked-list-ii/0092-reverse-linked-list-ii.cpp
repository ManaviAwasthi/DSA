
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==nullptr || left==right) return head;
        ListNode* dummy =  new ListNode (0);
        dummy->next= head;
        ListNode* prev= dummy; 
        for (int i=0; i<left-1; i++){
            prev=prev->next; //moves to the left-1 node
        } 
        ListNode* cur= prev->next;
        for (int i=0; i<right-left; i++){
            ListNode* temp=cur->next;
            cur->next= temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }
        return dummy->next;
    }
};