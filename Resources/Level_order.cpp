// My Approach

vector<TreeNode* > q1;
vector<TreeNode* > q2;
q1.push_back(A);
    
while(!q1.empty() || !q2.empty())
{
        if((!q1.empty()))
        {
            vector<int> v;
            for(int i=0;i<q1.size();i++)
            {
                v.push_back(q1[i]->val);
            }
            ans.push_back(v);
        }
        while(!q1.empty())
        {
            TreeNode* node = q1[0];
            q1.erase(q1.begin());
            if(node->left)
                q2.push_back(node->left);
            if(node->right)
                q2.push_back(node->right);
        }
        if(!q2.empty())
        {
            vector<int> v;
            for(int i=0;i<q2.size();i++)
            {
                v.push_back(q2[i]->val);
            }
            ans.push_back(v);   
        }
        while(!q2.empty())
        {
            TreeNode* node = q2[0];
            q2.erase(q2.begin());
            if(node->left)
                q1.push_back(node->left);
            if(node->right)
                q1.push_back(node->right);
        }
        
}

//Abhinav's Approach
queue<TreeNode* > q;
q.push(A);

while(q.size()!=0)
{
    vector<int> v;
    int s=q.size();
    while(s--)
    {
        TreeNode* node=q.front();
        q.pop();
        v.push_back(node->val);
        
        if(node->left)
            q.push(node->left);
            
        if(node->right)
            q.push(node->right);
    }
    ans.push_back(v);
}

//Shrayans's Approach

void buildVector(TreeNode *root, int depth, vector<vector<int> > &ret) 
{
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.push_back(vector<int>());

        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1, ret);
        buildVector(root->right, depth + 1, ret);
}

vector<vector<int> > levelOrder(TreeNode *root) 
{
        vector<vector<int> > ret;
        buildVector(root, 0, ret);
        return ret;
}