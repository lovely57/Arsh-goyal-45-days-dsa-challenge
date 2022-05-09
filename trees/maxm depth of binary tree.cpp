// TC - O(num of nodes) as we are traversing all the nodes of the tree
// SC - O(1) without taking the implicit recursive stack into consideration else o(h)
//recursive ,dfs approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxleft=maxDepth(root->left);
        int maxright=maxDepth(root->right);
        return max(maxleft,maxright)+1;
        
    }
};

//bfs approach 
//tc-o(n) sc- o(n) as using queue
class Solution {
public:
    int maxDepth(TreeNode* root) {
         if (root==NULL) return 0; 
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        
        while (!q.empty()) {
            ++depth;
            int s=q.size();
            for (int i=0; i<s; i++) {
                TreeNode* front=q.front();
                q.pop();
                
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
    return depth;
    }
};
