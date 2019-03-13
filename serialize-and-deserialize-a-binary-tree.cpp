/*

https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

*/




void serialize(Node *root,vector<int> &A)
{
    if(root == nullptr) {
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
    
}
/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
   int data = A.front(); A.erase(A.begin());
   if(data == -1) return nullptr;
   Node*node = newNode(data);
   node->left = deSerialize(A);
   node->right = deSerialize(A);
   return node;
}
