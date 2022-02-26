int getHeight(struct node* root) {
    int a,b;
    if(root)
    {
       a=getHeight(root->left);
       b=getHeight(root->right);
       if(a>=b)
    return a+1;
    else
    return b+1;
    }
    
    return -1;
}
