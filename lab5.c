int max(int a, int b)
{
    return (a > b)? a : b;
}

int Height(AVLNode *root){
    // if root return -1, compare left & right to get height
    if(root == NULL) return -1;
    else
    {
       int left = Height(root->left);
       int right= Height(root->right);

       if(left > right) return left+1;
       else return right+1;
    }
}

AVLNode *RightRotate(AVLNode *y)
{
    AVLNode *x   = y->left;
    AVLNode *T2  = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}


AVLNode *LeftRotate(AVLNode *x)
{
    AVLNode  *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}


