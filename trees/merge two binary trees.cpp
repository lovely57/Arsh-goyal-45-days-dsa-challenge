 //1. recursive dfs       
//tc- o(n)
//sc-o(h)The depth of the recursion tree can go upto n in case of 
//a skewed tree.then o(n) In average case, depth will be O(logn).
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        t1->val+=t2->val;
        if(t2->left) t1->left=mergeTrees(t1->left,t2->left);
        if(t2->right) t1->right=mergeTrees(t1->right,t2->right);
        return t1;
        
    
   }
};

//2. iterative(dfs using stack)
//tc- o(n), sc-o(h) but o(n) in case of skewed tree
class Solution {//iterative stack
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
      if(!t1 && !t2) return NULL;
      if(!t1) return t2;
      if(!t2) return t1;
        
      stack<TreeNode*>s1,s2;
        s1.push(t1);
        s2.push(t2);
        
        while(!s1.empty())
        {
            TreeNode*c1(s1.top());
             TreeNode* c2(s2.top());
            s1.pop();
            s2.pop();
            
            c1->val+=c2->val;
            
            if(!c1->left && c2->left) 
                c1->left=c2->left;
            else if(c1->left &&c2->left)
            {
                s1.push(c1->left);
                s2.push(c2->left);
            }
            
             if(!c1->right && c2->right) 
                c1->right=c2->right;
            else if(c1->right &&c2->right)
            {
                s1.push(c1->right);
                s2.push(c2->right);
            }
        }
      return t1;
   }
};


//3.iterative (bfs using queue) (more optimised in case of skeewed tree as we do level order traversal here)
//tc-o(n), sc-o(h) ,o(n) in case of skewed tree
class Solution {//iterative queue
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
      if(!t1 && !t2) return NULL;
      if(!t1) return t2;
      if(!t2) return t1;
        
    queue<TreeNode*>q1,q2;
    q1.push(t1);
    q2.push(t2);
        
    while(!q1.empty() && !q2.empty())
    {
        TreeNode*c1(q1.front());
        TreeNode*c2(q2.front());
        q1.pop();
        q2.pop();
        
        c1->val+=c2->val;
        
        if(!c1->left && c2->left)
            c1->left=c2->left;
        else if(c1->left && c2->left)
        {
            q1.push(c1->left);
            q2.push(c2->left);
            
        }
         
        if(!c1->right && c2->right)
            c1->right=c2->right;
        else if(c1->right && c2->right)
        {
            q1.push(c1->right);
            q2.push(c2->right);
            
        }
    }
      return t1;
   }
};