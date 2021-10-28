#include <iostream>

// Node 
class Node{
    public:
    Node();
    Node(int);

    int data;
    Node* next;
};
Node::Node(){
    data = 0;
    next = NULL;
}
Node::Node(int value){
    data = value;
    next = NULL;
}

// Linked List
class LinkedList{
    public:
    LinkedList();
    LinkedList(int);
    void append(int);
    void prepend(int);
    void insert(int, int);
    void print();
    int getsize();
    int front();
    int back();
    int get(int);

    private:
    int size;
    Node* head;
    Node* tail;
};
LinkedList::LinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
};
LinkedList::LinkedList(int value){
    head = new Node(value);
    tail = head;
    size++;
};
void LinkedList::append(int value){
    if(size==0){
        head = new Node(value);
        tail = head;
        size++;
    }else{
        tail->next = new Node(value);
        tail = tail->next;
        size++;
    }
};
void LinkedList::prepend(int value){
    if(size==0){
        append(value);
    }
    else{
        Node* node = new Node(value);
        node->next=head;
        head=node;
        size++;
    }
}
void LinkedList::insert(int i,int value){
    if(i > size || i<0){
        std::cout<<"insert::Enter a Valid Index\n";
    }else if(i==0){
        prepend(value);
    }else if(i==size){
        append(value);
    }else{
        Node* node = new Node(value);
        Node* temp = head;
        for (int j = 0; j < i-1; j++) temp = temp->next;
        node->next = temp->next;
        temp->next = node;
        size++;
    }
}
int LinkedList::get(int i){
    if(i>=0 && i<size){
        Node* temp = head;
        for (int j = 0; j < i; j++) temp = temp->next;
        return temp->data;
    }
    return -1;
}
int LinkedList::getsize(){
    return size;
}
int LinkedList::front(){
    return head->data;
}
int LinkedList::back(){
    return tail->data;
}
void LinkedList::print(){
    Node* temp = head;
    while(temp!=NULL){
        std::cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    std::cout<<" Null\n";
}

/* 
Entry
*/
int main(){
    LinkedList ll;
    Node three(30);
    ll.append(10);
    ll.append(20);
    ll.prepend(30);
    ll.insert(3,80);
    ll.print();

    std::cout<<"Front: "<<ll.front()<<'\n';
    std::cout<<"Back: "<<ll.back();
}