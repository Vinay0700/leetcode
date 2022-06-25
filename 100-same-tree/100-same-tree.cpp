class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		
		if(p==NULL && q!=NULL)return false;
		if(q==NULL && p!=NULL)return false;

		if(p==NULL && q==NULL)return true;

		bool l=false;
		bool r = false;

		if(p->val == q->val){
			l = isSameTree(p->left,q->left);
			r = isSameTree(p->right,q->right);
		}

		return l&r;        
	}
};