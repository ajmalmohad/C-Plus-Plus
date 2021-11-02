#include <iostream>

class Node{
    public:
    Node(int);
    int data;
    Node* next;
};
Node::Node(int value){
    data = value;
    next = nullptr;
}

class Queue{
    public:
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    int next();
    void print();
    int getsize();

    private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};
void Queue::enqueue(int value){
    if(!head){
        head = new Node(value);
        tail = head;
        size++;
    }else{
        tail->next = new Node(value);
        tail = tail->next;
        size++;
    }
}
int Queue::dequeue(){
    if(!head) return -1;
    int popped = head->data;
    head = head->next;
    size--;
    if(size==0){
        head= nullptr;
        tail= nullptr;
    }
    return popped;
}
int Queue::next(){
    if(head){
        return head->data;
    }
    return -1;
}
bool Queue::isEmpty(){
    return (size?0:1);
}
int Queue::getsize(){
    return size;
}
void Queue::print(){
    Node* temp = head;
    while(temp!=NULL){
        std::cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    std::cout<<" Null\n";
}

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    std::cout<<q.getsize()<<'\n';
}