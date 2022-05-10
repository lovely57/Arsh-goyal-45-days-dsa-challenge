//recursive 
//tc-o(n), sc-o(h)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
         if(root==NULL) return false;
        
        //we reached here,i.e the root is not NULL, so we took the root value in our sum, and remaining targetSum is targetSum-root value.
        targetSum=targetSum-root->val;
        
        //if the current node is a leaf and its value is equal to the sum, we've found a path
        if(targetSum==0 && root->left==NULL && root->right==NULL) return true;
        
        // recursively call to traverse the left and right sub-tree
        // return true if any of the two recursive call return true
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
    }
};

//iterative dfs solution using stack
//tc,sc-o(n)
class Solution {
public:
        bool hasPathSum(TreeNode* root, int sum) {
         if(!root) return false;
          stack<pair<TreeNode*,int>>s;
          s.push({root,sum});
        
         while(!s.empty())
         {
             auto[node,currsum]=s.top();
             s.pop();
             currsum-=node->val;
             
             if(!node->left && !node->right && currsum==0)
                 return true;
             if (node->right) s.push({node->right, currsum});
             if (node->left) s.push({node->left, currsum});
    }
    return false;
    
    }
};


//iterative bfs solution using queue
//tc,sc-o(n)
class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    queue<pair<TreeNode *, int>> q;
    q.push({root, sum});
    while (!q.empty()) {
      auto [node, curr_sum] = q.front();
      q.pop();
      curr_sum -= node->val;
      if (!node->left && !node->right && curr_sum == 0) return true;
      if (node->left) q.push({node->left, curr_sum});
      if (node->right) q.push({node->right, curr_sum});
    }
    return false;
  }
};
