//top down approach
//tc- o(n^2), as each level we r finding height of tree below that level
//sc-o(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //top-down 
        if(root==NULL ) return true;
        if(abs(height(root->left)-height(root->right))>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
public:
    int height(TreeNode* node)
    {
        if(node==NULL) return 0;
        return 1+ max(height(node->left),height(node->right));
    }
};

//bottom -up approach /optimised 
//tc- o(n) 
//auxiliary sc-o(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //bottom -up
        if(root==NULL) return true;
        return height(root)!=-1;
    }
public:
     int height(TreeNode* node)
     {
         if(node==NULL) return 0;
         int left=height(node->left);
         int right= height(node->right);
         int bf= abs(left-right);
         
         if(bf>1||left==-1 ||right==-1) return -1;
         return 1+ max(left,right);
     }

};
