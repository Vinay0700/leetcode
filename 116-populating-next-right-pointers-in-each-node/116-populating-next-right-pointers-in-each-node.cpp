class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        auto L = root -> left, R = root -> right, N = root -> next;
        if(L) {
            L -> next = R;                                // next of root's left is assigned as root's right
            if(N) R -> next = N -> left;                  // next of root's right is assigned as root's next's left (if root's next exist)
            connect(L);                                   // recurse left  - simple DFS 
            connect(R);                                   // recurse right
        }
        return root;
    }
};