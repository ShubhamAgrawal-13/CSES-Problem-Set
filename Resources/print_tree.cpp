#include <bits/stdc++.h>  
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(){}

        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int l = height(root->left);
    int r = height(root->right);
    
    return 1+max(l,r);
    
}


void func1(vector<vector<string>> &ans, vector<vector<string>> &bars, Node* root, int r,int c,int level,int height)
{
    if(root==NULL)
        return;
    int mid = (r+c)/2;
    ans[level][mid]=to_string(root->data);
    if(root->left!=NULL && level<height-1)
    {
        int mm = floor(((r + mid-1)/2.0 + mid)/2);
        bars[level][mm]="/";
    }

    if(root->right!=NULL && level<height-1)
    {
        int mm = ceil(((mid+1+c)/2.0 + mid)/2);
        bars[level][mm]="\\";
    }
    
    func1(ans,bars,root->left,r,mid-1,level+1,height);
    func1(ans,bars,root->right,mid+1,c,level+1,height);
}

void printt(vector<vector<string>> &ans, vector<vector<string>> &bars)
{
    for(int i=0;i<ans.size();i++)
    {
        //cout<<"[ ";
        for(int j=0;j<ans[i].size();j++)
        {
            if(ans[i][j]=="")
            {
                cout<<setw(2)<<" ";
            }
            else
            {
                cout<<setw(2)<<ans[i][j];
            }
        }
        //cout<<" ]"<<endl;
        cout<<"\n\n";

        for(int j=0;j<ans[i].size() && i!=ans.size();j++)
        {
            if(bars[i][j]=="")
            {
                cout<<setw(2)<<" ";
            }
            else
            {
                cout<<setw(2)<<bars[i][j];
            }
        }

        cout<<"\n\n";
    }
}

void printTree(Node* root) 
{
    int h=height(root);
    //vector<vector<string>> ans(h,vector<string>());
    // cout<<h<<endl;
    // func(ans,root,0,h-1);

    int c = (1<<h) - 1;
    cout<<h<<" "<<c<<endl;
    vector<vector<string>> ans(h,vector<string>(c,""));
    vector<vector<string>> bars(h,vector<string>(c,""));
    func1(ans,bars,root,0,c-1,0,h);
    printt(ans,bars);
    // return ans;
}


void solve()
{
	Node *root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
  
    //root->left->left = new Node(4);  
    root->left->right = new Node(5);  
    root->right->left = new Node(6);  
    root->right->right = new Node(7);  
  
    //root->left->left->left = new Node(8);  
    //root->left->left->right = new Node(9);  
    root->left->right->left = new Node(10);  
    root->left->right->right = new Node(11);  
    //root->right->left->left = new Node(12);  
    root->right->left->right = new Node(13);  
    root->right->right->left = new Node(14);  
    root->right->right->right = new Node(15);

    printTree(root);
}

		

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--)  
    {  
        solve(); 
    }  
  
    return 0;  
} 