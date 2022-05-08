//tc,sc-o(n)
class Solution {
public:
    bool solve(TreeNode * r1, TreeNode * r2)
    {    
        if(r1 == NULL && r2 == NULL)
            return true; 
		
        else if(r1 == NULL || r2 == NULL || r1->val != r2->val)
            return false; 
        
        return solve(r1->left, r2->right) && solve(r1->right, r2->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        return solve(root->left, root->right);     
    }
};

//iteratiive 
//tc-o(n)
//sc-o(n)
class Solution {
public:
 
        bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> queue;
        queue.push(root->left);
        queue.push(root->right);
        while(!queue.empty()) {
            TreeNode *left = queue.front(); queue.pop();
            TreeNode *right = queue.front(); queue.pop();
            if(!left && !right) continue;
            if(!left || !right) return false;
            if(left->val != right->val) return false;
            queue.push(left->left);
            queue.push(right->right);
            queue.push(left->right);
            queue.push(right->left);
        }
        return true;
    
    }
};