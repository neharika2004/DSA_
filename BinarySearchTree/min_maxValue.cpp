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

Node*minVal(Node*root){
    Node*temp=root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node*maxVal(Node*root){
    Node*temp=root;

    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

int main(){

    Node*root=NULL;

    cout<<"Enter data to create BST:"<<endl;
    takeInput(root);
    cout<<"Printing"<<endl;
    levelOrderTraversal(root);
    cout<<"Min val: "<<minVal(root)->data<<endl;
    cout<<"Max val: "<<maxVal(root)->data<<endl;


    return 0;
}