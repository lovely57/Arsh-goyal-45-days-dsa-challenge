//brute force
// find inorder traversal of whhole bst as it will be in sorted order then just return 
// value just before after the given key 
// tc- o(n), sc-o(n) as storing the sorted array 

//optimised 
// while for predecessor(key )
// go one left -> then extreme right till reach leaf node
// while for succesoor(key )
// go one right -> then extreme left till reach leaf node
// tc-o(h) height of tree as traversing acc if key is greater or smaller than root->key , sc-o(1)
Node*inpre(Node*root)   //compiled on gfg
{
    Node*p= root->left;
    while(p->right)
      p=p->right;
      return p;
}
Node*insuc(Node*root)
{
    Node*p= root->right;
    while(p->left)
      p=p->left;
      return p;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
if(!root) return;
if(key==root->key)
{
    if(root->left) pre=inpre(root);
    if(root->right) suc=insuc(root);
    return;
}
if(key>root->key)
{
    pre=root;
    findPreSuc(root->right,pre,suc,key);
    
}
else if(key<root->key)
{
     suc=root;
      findPreSuc(root->left,pre,suc,key);
}

}
