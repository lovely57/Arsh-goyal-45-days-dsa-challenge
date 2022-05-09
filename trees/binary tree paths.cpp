//recursive dfs approach
//tc-o(n), sc-o(n)
class Solution {
public:
    void helper(TreeNode* root,vector<string>& answer,string curr){
        if(!root)return;
        if(root->left||root->right)curr+=(to_string(root->val)+"->");
        else{
            curr+=(to_string(root->val));
            answer.push_back(curr);
        }
        helper(root->left,answer,curr);
        helper(root->right,answer,curr);  
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        string curr="";
        helper(root,answer,curr);
        return answer;
    }
};

//using bfs
//tc- o(n),sc-o(n)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        queue<pair<TreeNode*, string>> bfs;
        bfs.push({root, to_string(root->val)});
        bfs.push({NULL, ""});
        while (!bfs.empty()) {
            auto currNode = bfs.front();
            bfs.pop();
            if (currNode.first) {
                auto currPath = currNode.second;
                if (!currNode.first->left and !currNode.first->right)
                    paths.push_back(currPath);
                else {
                    if (currNode.first->left)
                        bfs.push({currNode.first->left, currPath + "->" + to_string(currNode.first->left->val)});
                    if (currNode.first->right)
                        bfs.push({currNode.first->right, currPath + "->" + to_string(currNode.first->right->val)});
                }
            }
            else if (!bfs.empty())
                bfs.push({NULL, ""});
        }
        return paths;
    }
};
