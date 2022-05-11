//iterative using stack 
//tc,sc -o(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode*node=root;
        vector<int>inorder;
        while(true)
        {
            if(node!=NULL)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty()==true) break;
                else
                {
                 node=st.top();
                st.pop();
                inorder.push_back(node->val);
                node=node->right;
                }
              
            }
        }
        return inorder;
        
    }
};

//recursive
//tc,sc-o(n)
class Solution {
public:
    void helper(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
        {
            return ;
        }
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>ans;
       helper(root,ans);
         return ans;
        
    }
};