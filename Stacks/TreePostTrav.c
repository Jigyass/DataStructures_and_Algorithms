void postordertravel(struct Node* root, int* returnSize,int*v){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->numChildren;i++){
        postordertravel(root->children[i], returnSize,v);
    }
    v[(*returnSize)++]=root->val;

}

int* postorder(struct Node* root, int* returnSize) {
    *returnSize=0;
    int *v=(int*)malloc(sizeof(int)*10000);
    postordertravel(root, returnSize,v);
    return v;
}
