struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode* newRoot = NULL;
    struct TreeNode* prev = NULL;
    
    void in_order_traversal(struct TreeNode* node) {
        if (node == NULL) return;
        
        in_order_traversal(node->left);
        
        node->left = NULL;
        if (prev) {
            prev->right = node;
        } else {
            newRoot = node;
        }
        prev = node;
        
        in_order_traversal(node->right);
    }
    
    in_order_traversal(root);
    return newRoot;
}
