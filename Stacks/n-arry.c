class Solution {
public:
    void post(Node* root,vector<int> &v)
    {
        if(root==NULL)
        return;
        for(auto temp : root->children)
        {
           post(temp,v); 
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> v;
        post(root,v);
        return v;
    }
};
