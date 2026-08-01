class Solution {
public:
    Node* connect(Node* root) {
        if (root==nullptr) return nullptr;
        queue <Node*> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()){
            Node* curr= q.front();
            q.pop();
            if (curr == nullptr){
                if (!q.empty())
                    q.push(nullptr);
                continue;
            }
            curr->next=q.front();
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
        return root;
    }
};