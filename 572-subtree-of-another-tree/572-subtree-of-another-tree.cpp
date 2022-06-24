class Solution {
public:
    bool ans = false;
    bool match(TreeNode *s , TreeNode *t){
        if(s!= NULL && t!=NULL){
           bool a = match(s->right , t->right);
           bool b = match(s->left , t->left);
           if(s->val== t->val && a && b) 
               return true;
           else 
               return false;
       } 
        else if(s==NULL && t==NULL){
            return true;
        }
        else return false;
    }
    
    void inorder(TreeNode *root , TreeNode *subroot){
        if(root!=NULL){
            inorder(root->left,subroot);
            bool x= match(root,subroot);
            if(x) ans=x;
            inorder (root->right,subroot);
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        inorder(s,t);
        return ans;
    }
};