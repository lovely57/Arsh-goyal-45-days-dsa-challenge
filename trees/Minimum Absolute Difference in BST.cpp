//inorder traversal
//tc-o(n), sc-o(1)
// Here we are just maintaining the previous element, as the elements are traversed in sorted order (because of 
// inorder traversal)
// so subtracting the current element with the previous visited element will give us our potential answer
//  and minimum of all those potential answers will give us final result.
class Solution {
public:
    
    void func(TreeNode * root, int & prev, int & ans){               //inorder traversal
        if(root){
            func(root->left, prev, ans);
            
            if(prev!=INT_MAX){
                ans = min(ans, abs(prev - root->val));
            }
            
            prev = root->val;
            
            func(root->right, prev, ans);
        }
        return;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MAX;
        int ans = INT_MAX;
        func(root, prev, ans);
        return ans;
    }
};

//iterative bfs 
//tc,sc-o(n)
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        priority_queue<int, vector<int>> que;
        TreeNode* curr;
        
        while(!bfs.empty()){
            curr = bfs.front();
            bfs.pop();
            
            que.push(curr->val);
            
            if(curr->left) bfs.push(curr->left);
            if(curr->right) bfs.push(curr->right);
        }
        
       int min_diff = INT_MAX;
       int  pre_value = que.top();
        que.pop();
        
        while(!que.empty()){
            if(pre_value - que.top() < min_diff){
                min_diff = pre_value - que.top();
            }
            
            pre_value = que.top();
            que.pop();
        }
        
        return min_diff;
    }
};


