// gfg compiler is not working on this because their print function has no "\n"


struct Node * newnode(int x){
    struct Node * nn = (struct Node *)malloc(sizeof(struct node));
    nn->data = x;
    nn->next = NULL;
    return nn;
}

Node* addTwoLists(Node* first, Node* second) {
    // Code here
    
    
    struct Node * temp1 = first;
    struct Node * temp2 = second;
    
    vector <int> v;
    
    int carry = 0;
    
    while(temp1 && temp2){
        int x = temp1->data + temp2->data + carry;
        v.push_back(x%10);
        carry = (x/10);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    if(temp1 && !temp2){
        v.push_back(carry + temp1->data);
        temp1 = temp1->next;
    }
    if(!temp1 && temp2){
        v.push_back(carry + temp2->data);
        temp2 = temp2->next;
    }
    
    while(temp1 && !temp2){
        v.push_back(temp1->data);
        temp1 = temp1->next;
    }
    
    while(!temp1 && temp2){
        v.push_back(temp2->data);
        temp2 = temp2->data;
    }
    
    struct Node * h = NULL;
    struct Node * t = NULL;
    
    for(auto x = v.begin(); x != v.end(); x++){
        if(!h){
            h = newnode(*x);
            t = h;
        }else{
            t->next = newnode(*x);
            t = t->next;
        }
    }
    
    return h;
    
}
