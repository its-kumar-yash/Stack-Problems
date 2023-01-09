#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    public: 
    Node* head;
    int size;

    Stack(){
        this->head = NULL;
        size = 0;
    }

    void push(int data){
        //create a new node
        Node* temp = new Node(data);
        //overflow check
        if(temp == NULL){
            cout<<"Stack overflow"<<endl;
            return;
        }

        temp->next = head;
        //make temp as top of stack
        head = temp;
    }

    void pop(){
        if(head == NULL){
            cout<<"Stack underflow"<<endl;
            return;
        }
        else{
            Node* temp = head;
            //assign top to temp
            head = head->next;

            delete temp;
        }
    }

    bool isEmpty(){
        return head == NULL;
    }

    int peek(){
        if(head == NULL){
            return -1;
        }
        else{
            return head->data;
        }
    }
};

int main(){
    
    Stack st;

    st.push(12);
    st.push(10);
    st.push(90);
    st.push(87);

    st.pop();
    
    cout<<st.peek()<<endl;



    return 0;
}