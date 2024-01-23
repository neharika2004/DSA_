#include<iostream>
using namespace std;

class Queue{
    public:
    int front;
    int rear;
    int size;
    int*arr;

    Queue(int size){
        this->size=size;
        arr=new int [size];
        front=0;
        rear=0;
    }

    void push(int data){
    if(rear==size){
        cout<<"Queue is full!";
    }
    else{
        arr[rear]=data;
        rear++;
    }
    }

    int pop(){
        if(rear==front){
            cout<<"Queue is empty!";
        }
        else{
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){
                rear=0;
                front=0;
            }
            return ans;
        }
    }

    bool isEmpty(){
        if(rear==front){
            return true;
        }
        else{
            return false;
        }
    }

    int peek(){
        if(front==rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }
};

int main(){
    Queue q(5);

    q.push(22);
    q.push(43);
    q.push(44);

    cout<< q.peek() <<endl;

    q.pop();
    cout<< q.peek() <<endl;
}