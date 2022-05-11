//brute force approach 
// just store all leaf nodes in a map and all values of tree in another map 
// now find range of leaf nodes and check whether they exists in another map 
// if even one exists ,yes then their exists a dead node 
// else if all ranges are not in another map then only there is no dead node at 
// all tc,sc- o(n) as using map 


//optimised approach 
//tc-o(n), sc-o(1)
bool solve(Node*root, int min,int max)
{
    if(!root) return false;
    if(min==max) return true; // dead end found
    return solve(root->left,min,root->data-1)||solve(root->right,root->data+1,max);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root,1,INT_MAX);
}