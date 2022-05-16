//recursive
//tc-o(n^2), sc-o(n)
class Solution {
public:
   vector<TreeNode*> buildTree(int start, int end) {
	vector<TreeNode*> ans;
        
    // If start > end, then subtree will be empty so add NULL in the ans and return it.
    if(start > end) {
		ans.push_back(NULL);
        return ans;
    }

    // Iterate through all values from start to end to construct left and right subtree recursively
	for(int i = start; i <= end; ++i) {
		vector<TreeNode*> leftSubTree = buildTree(start, i - 1);    // Construct left subtree
        vector<TreeNode*> rightSubTree = buildTree(i + 1, end);     // Construct right subtree
            
		// loop through all left and right subtrees and connect them to ith root  
		for(int j = 0; j < leftSubTree.size(); j++) {
			for(int k = 0; k < rightSubTree.size(); k++) {
				TreeNode* root = new TreeNode(i);   // Create root with value i
				root->left = leftSubTree[j];   // Connect left subtree rooted at leftSubTree[j]
                root->right = rightSubTree[k];   // Connect right subtree rooted at rightSubTree[k]
				ans.push_back(root);    // Add this tree(rooted at i) to ans data-structure
			}
		}
    }
        
	return ans;
}
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1, n);
    }
};

// Memoization: dp method
//tc,sc- 
// Since we have 2 variables in our recursion: start and end, 
// we can create a 2D dp of vector<TreeNode*> to store all bst with numbers from [start,end]

vector<TreeNode*> generateDp(int start, int end, vector<vector<vector<TreeNode*>>>&dp){
    if(start>end) return {nullptr};
    if(dp[start][end].size()!=0) return dp[start][end];
    
    vector<TreeNode*> ans;
    for(int i=start; i<= end; i++){
        vector<TreeNode*> left= generateDp(start, i-1,dp);
        vector<TreeNode*> right = generateDp(i+1,end,dp);
        for(auto eleL:left){
            for(auto eleR:right){
                TreeNode* root= new TreeNode(i);
                root->left=eleL; root->right=eleR;
                ans.push_back(root);
            }
        }
    }
    return dp[start][end]= ans;     
}

vector<TreeNode*> generateTrees(int n) {

    vector<vector<vector<TreeNode*>>> dp(n+1,vector<vector<TreeNode*>>(n+1,vector<TreeNode*>(0)));
    return generateDp(1,n,dp);
}
