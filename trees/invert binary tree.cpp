//recursive approach
//tc- o(n)
//space complexity, If we don’t consider the size of the recursive stack for
// function calls then O(1) otherwise O(h) where h is the height of the tree.
class Solution {
    void swap(TreeNode*curr)
    {
        if(!curr)
            return ;
        swap(curr->left);
        swap(curr->right);
        
        TreeNode*temp;
        temp=curr->left;
        curr->left=curr->right;
        curr->right=temp;
        
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};

//iterative approach
//tc-o(n) visiting every node at once
//sc- o(n)  using stack
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      stack<TreeNode*>s;
      s.push(root);
        
        while(!s.empty())
        {
            TreeNode*curr=s.top();
            s.pop();
            if(!curr) continue;
            s.push(curr->left);
            s.push(curr->right);
            swap(curr->left,curr->right);
        }
        return root;
    }
};