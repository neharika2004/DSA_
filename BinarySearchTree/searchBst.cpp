#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void levelOrderTraversal(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
              q.push(temp->left);
            }
            
            if(temp->right){
              q.push(temp->right);
            }
        }
    }
}

// we can also do it by making a temp variable 
// Node*temp=root;
// while(temp!=NULL) then follow the same thing.
Node* insertIntoBst(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d >root->data){
        //right
        root->right=insertIntoBst(root->right,d);
    }
    else{
        // left
        root->left=insertIntoBst(root->left,d);
    }
    return root;
}

void takeInput(Node*&root){
    int data;
    cin>>data;

    while(data!=-1){
        root = insertIntoBst(root,data);
        cin>>data;
    }
}

bool searchElement(Node*&root,int x){

    if(root==NULL){
        return false;
    }

    if(root->data==x){
        return true;
    }
    if(root->data > x){
        return searchElement(root->left,x);
    }
    else{
        return searchElement(root->right,x);
    }
}

int main(){

    Node*root=NULL;
    // 10 8 22 27 5 4 3
    cout<<"Enter data to create BST:"<<endl;
    takeInput(root);
    cout<<"Printing"<<endl;
    levelOrderTraversal(root);
    
    int value;
    cout<<"Enter value to search:";
    cin>>value;

    if(searchElement(root,value)){
        cout<<value<<" is present in the BST"<<endl;
    }
    else{
        cout<<value<<" is not  present in the BST"<<endl;
    }

    return 0;
}