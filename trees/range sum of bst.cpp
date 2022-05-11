//using inorder traversal
//tc- o(n)
//sc- o(h) height of tree This is because at max there will be 
//h nodes in recursive stack(Because when left call is finished then only right call starts)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int l, int h) {
        if(!root) return 0;
        
        if(root->val>=l && root->val<=h)
            return root->val+rangeSumBST(root->left,l,h)+rangeSumBST(root->right,l,h);
        else if(root->val<l)
            return rangeSumBST(root->right,l,h);
        else
            return rangeSumBST(root->left,l,h);
    }
};

//using bfs/iterative 
//tc- o(n)
//sc- o(n)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
       int sum=0;
        list<TreeNode*>queue;
        queue.push_back(root);
        
        while(queue.size()!=0)
        {
            TreeNode*cur= queue.front();
            queue.pop_front();
            if(cur->val >high)
            {
                if(cur->left)
                    queue.push_front(cur->left);
                
            }
            else if(cur->val<low)
            {
                if(cur->right)
                    queue.push_front(cur->right);
            }
            else
            {
                sum+=cur->val;
                if(cur->right)
                    queue.push_front(cur->right);
                if(cur->left)
                    queue.push_front(cur->left);
                
            }
        }
        return sum;
    }
};
