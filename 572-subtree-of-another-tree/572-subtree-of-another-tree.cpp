class Solution {
public:
    bool isIdentical(TreeNode* s, TreeNode* t){
        if(!s || !t)
            return s==t;
        
        return(s->val==t->val && isIdentical(s->left,t->left) && isIdentical(s->right,t->right));
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(!t) return true;
        if(isIdentical(s,t)) return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
};