//tc-o(m*n)  where m and n are number of nodes in given two trees. 
//sc-o(n) auxiliary space
class Solution {
public:
    bool isidentical(TreeNode* s, TreeNode* t)
    {
        if(!s|| !t)
            return s==t;
        return(s->val==t->val &&isidentical(s->left,t->left) && isidentical(s->right,t->right));
     }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(!t) return true;
        if(isidentical(s,t)) return true;
        return isSubtree(s->left,t)||isSubtree(s->right,t);
        
    }
};

//optimised 
//tc- o(n)  Inorder and Preorder traversals of Binary Tree take O(n) time.
//sc- o(n)
class Solution {
public:
    // Inorder Traversal
    void inorder(TreeNode* root, string& str)
    {
        if(!root)
        {
            str += '$';
            return;
        }
        
        inorder(root->left,str);
        str += to_string(root->val);
        inorder(root->right,str);
    }
    
	// Preorder Traversal
    void preorder(TreeNode* root, string& str)
    {
        if(!root)
        {
            str += '$';
            return;
        }
        
        str += to_string(root->val);
        preorder(root->left,str);
        preorder(root->right,str);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       // If subRoot is empty
        if(!subRoot)
            return true;
        
		// If root is empty and subRoot is non-empty
        if(!root)
            return false;
        
		// Create a string of inorder traversal of both the trees
        string inT, inS;
        inorder(root,inT);
        inorder(subRoot,inS);
        
		// If inS is not the substring of inT, return false
        if(inT.find(inS) == string::npos)
            return false;
        
		// If inS is the substring of inT
		// Create a string of preorder traversal of both the trees
		// Instead of preorder traversal, you can also take postorder traversal
        string preT, preS;
        preorder(root,preT);
        preorder(subRoot,preS);
        
		// If preS is the substring of preT, return true otherwise return false
        return (preT.find(preS) != string::npos);
        
    }
};

