// this is from gfg solutions and is better and easy then rbr's solution 

//   https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/

//  http://eclassesbyravindra.com/mod/page/view.php?id=6287



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root,vector<int> &A)
{
    //Your code here
    Node* curr;
    queue<Node*> Q;
    Q.push(root);
    A.push_back(root->data);
    while(!Q.empty()){
        curr = Q.front();
        Q.pop();
        if(curr->left){
            Q.push(curr->left);
            A.push_back(curr->left->data);
        }else
            A.push_back(0);
        
        if(curr->right){
            Q.push(curr->right);
            A.push_back(curr->right->data);
        }else
            A.push_back(0);
    }
}
/*this function deserializes
 the serialized vector A*/

Node * deSerialize(vector<int> &A)
{
    //Your code here
    Node *root = newNode(A[0]);
    Node* curr;
    queue<Node*> Q;
    Q.push(root);
    int i = 0;
    while(!Q.empty() && i<A.size()){
        curr = Q.front();
        Q.pop();
        if(A[++i]){
            curr->left = newNode(A[i]);
            Q.push(curr->left);
        }
        if(A[++i]){
            curr->right = newNode(A[i]);
            Q.push(curr->right);
        }
    }
    return root;
}
