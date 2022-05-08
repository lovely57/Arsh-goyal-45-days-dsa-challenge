//brute force
//tc- o(n2)
class Solution {
public:
    int height(TreeNode*root){
        if(!root) return 0;
        return 1+max(height(root->left),height(root->right));   
    }
//     preorder traversal
    void solve(TreeNode*root,int &ans){
          if(!root) return;
        int left = height(root->left);
        int right = height(root->right);
       ans = max(ans,(left+right));  //as question mention about edges
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int ans = 0;
        solve(root,ans);
        return ans;
    }
};

//optimised solution 
//tc- o(n)
//sc-o(n)
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;   
    }
private:
     int height(TreeNode* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
         
     }
};



