//recursive
//tc-o(h) as we r traversing in bst and not all nodes
//sc- o(1) if not considering stack space else o(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val <root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(p->val >root->val && q->val>root->val)
             return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    }
};

//iterative
//tc- o(h)
//sc-o(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL){
            if(root->val > p->val and root->val > q->val){
                root = root->left;
            }    
            else if(root->val < p->val and root->val < q->val){
                root = root->right;
            }
            else
                break;
        }
        return root;
    }
};
