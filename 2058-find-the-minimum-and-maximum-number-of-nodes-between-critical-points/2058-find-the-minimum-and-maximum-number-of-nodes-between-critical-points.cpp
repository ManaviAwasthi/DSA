class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next== nullptr || head->next->next== nullptr){
            return {-1,-1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        vector<int> v;

        int ind = 1;

        while(next != nullptr){
            if(curr->val < prev->val && curr->val < next->val) v.push_back(ind);
            else if(curr->val > prev->val && curr->val > next->val) v.push_back(ind);
            ind++;
            prev = curr;
            curr = next;
            next = next->next;
        }
        int size = v.size();
        if(size<2) return {-1,-1};
        int maxi = v[size-1] - v[0];
        int mini = maxi;
        
        for(int i=1;i<size;i++){
            mini = min(mini,v[i]-v[i-1]);
        }
        return {mini,maxi};
    }
};