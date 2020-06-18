#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

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

void post_order(Node* root)
{
    if(root==NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}

int binarySearch(vector<int> &a, int start, int end, int item)
{
    while(start<=end)
    {   
        int mid = start + (end - start)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]>item)
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}

Node* build_tree(vector<int> &preorder, vector<int> &inorder,int start, int end, int& pindex,unordered_map<int,int> &map)
{
    if(start>end)
    {
        return NULL;
    }

    if(start == end)
    {
        pindex++;
        return new Node(inorder[start]);
    }

    //int mid = start + (end - start)/2;
    //int index= binarySearch(inorder,start,end,preorder[pindex]);
    //cout<<"[ "<<start<<", "<<end<<" ] ---> "<<preorder[pindex]<<" "<<index<<"\n";
    int index=map[preorder[pindex]];
    // for (int i = start; i <= end; ++i)
    // {
    //     if(inorder[i]==preorder[pindex])
    //     {
    //         index = i;
    //     }
    // }

    Node* root = new Node(preorder[pindex]);
    pindex++;

    root->left = build_tree(preorder,inorder,start,index-1,pindex,map);
    root->right = build_tree(preorder,inorder,index+1,end,pindex,map);

    return root;
}

void solve()
{
	int n;
    cin>>n;
    unordered_map<int,int> map;
    vector<int> preorder(n,0);
    vector<int> inorder(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
        map[inorder[i]]=i;
    }

    int start=0;
    int end = n-1;
    int pindex=0;

    Node* root = build_tree(preorder,inorder,start,end,pindex,map);
    //printTree(root);
    post_order(root);
    cout<<"\n";
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