// 1. Without extra space / Converting tree ( Recursive )
// Time - O(n)
// Space - O(1)
class BSTIterator {
public:
    TreeNode*t, *head;
    void convert(TreeNode*root)
    {
        if(!root) return;
        convert(root->left);
        t->right=root;
        t=t->right;
        convert(root->right);
    }
    BSTIterator(TreeNode* root) {
        head=new TreeNode(0);
        t=head;
        convert(root);
    }
    
    int next() {
        head=head->right;
        return head->val;
    }
    
    bool hasNext() {
        return (head->right!=NULL);
    }
};

// 2. Using Stack ( Iterative )
// Time - O(n) (approx.)
// Space - O(h) height of tree
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        while(root->left)
        {
            st.push(root->left);
            root=root->left;
        }
    }
    
    int next() {
       TreeNode*root= st.top();
        st.pop();
        
        int ans=root->val;
        if(root->right)
        {
            root=root->right;
            st.push(root);
            while(root->left)
            {
                st.push(root->left);
                root=root->left;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};