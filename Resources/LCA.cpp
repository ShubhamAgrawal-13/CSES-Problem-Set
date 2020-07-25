// Lowest Common Ancestor (LCA)

1. Two Traversals // O(N)

bool findPath(Node *root, vector<int> &path, int k) 
{ 
    if (root == NULL) return false; 

    path.push_back(root->key); 

    if (root->key == k) 
        return true;

    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 

    path.pop_back(); 

    return false; 
} 

int findLCA(Node *root, int n1, int n2) 
{
    vector<int> path1, path2; 
 
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2)) 
          return -1; 

    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++) 
        if (path1[i] != path2[i]) 
            break; 
    return path1[i-1]; 
} 


2. Single Traversal // O(N) 

Node* findLCA(Node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
   
    if (root->key == n1 || root->key == n2) 
        return root; 

    Node *left_lca  = findLCA(root->left, n1, n2); 
    Node *right_lca = findLCA(root->right, n1, n2); 
 
    if (left_lca && right_lca)  return root; 

    return (left_lca != NULL)? left_lca: right_lca; 
} 

3. Using parent pointer; (you can optimize by using depth) //O(h)

Node *LCA(Node *n1, Node *n2) 
{
   map <Node *, bool> ancestors; 
  
   while (n1 != NULL) 
   { 
       ancestors[n1] = true; 
       n1 = n1->parent; 
   } 
  
   while (n2 != NULL) 
   { 
       if (ancestors.find(n2) != ancestors.end()) 
           return n2; 
       n2 = n2->parent; 
   } 
  
   return NULL; 
} 

4. LCA in BST // O(log(N))

Node *lca(Node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
   
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
} 

5. Using RMQ (Range Minimum Query) // O(h)

Euler Tour

Algorithm:

   1. Do a Euler tour on the tree, and fill the euler, 
   	  level and first occurrence arrays.

   2. Using the first occurrence array, get the indices 
   	  corresponding to the two nodes which will be the 
   	  corners of the range in the level array that is fed
   	  to the RMQ algorithm for the minimum value.
   	  
   3. Once the algorithm return the index of the minimum 
   	  level in the range, we use it to determine the LCA
   	  using Euler tour array.


