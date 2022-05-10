//recursive 
//tc,sc- o(n)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
            return root->left->val+sumOfLeftLeaves(root->right);
        
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};

//iterative  bfs 
//tc,sc-o(n)
class Solution {
public:
   int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i =0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                if(node->left and (!node->left->left and !node->left->right))
                    ans+=node->left->val;
            }
        }
        return ans;
    }
};