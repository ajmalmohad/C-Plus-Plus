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
    void removevalue(int);
    void reverse_iterative();
    void reverse_recursive(Node*);
    bool empty();
    void print();
    int getsize();
    int front();
    int back();
    int get(int);
    int remove(int);
    int find(int);
    int pop_back();
    int pop_front();
    Node* getHead();

    private:
    int size;
    Node* head;
    Node* tail;
    void checkEmpty();
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
void LinkedList::checkEmpty(){
    if(size==0){
        head=NULL;
        tail=NULL;
    }
}
Node* LinkedList::getHead(){
    return head;
}
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
bool LinkedList::empty(){
    if(size==0)return 1;
    else return 0;
}
int LinkedList::get(int i){
    if(i>=0 && i<size){
        Node* temp = head;
        for (int j = 0; j < i; j++) temp = temp->next;
        return temp->data;
    }else{
        return -1;
    }
}
int LinkedList::getsize(){
    return size;
}
int LinkedList::front(){
    if(head!=NULL) return head->data;
    else return -1;
}
int LinkedList::back(){
    if(tail!=NULL) return tail->data;
    else return -1;
}
int LinkedList::remove(int i){
    if(head==NULL){
        return -1;
        std::cout<<"remove:Head is Null";
    }
    if(i>=1 && i<size){
        Node* temp = head;
        for (int j = 0; j < i-1; j++) temp = temp->next;
        Node* nextnode = temp->next->next;
        int value = temp->next->data; 
        delete temp->next;
        temp->next = nextnode;
        size--;
        checkEmpty();
        return value;
    }else if(i==0){
        return pop_front();
    }else{
        std::cout<<"remove::Can't Remove\n";
        return -1;
    }
}
int LinkedList::pop_back(){
    if(tail!=NULL) return remove(size-1);
    else return -1;
}
int LinkedList::pop_front(){
    if(head!=NULL){
        int value = head->data;
        Node* temp = head->next;
        delete head;
        head = temp;
        size--;
        checkEmpty();
        return value;
    }else{
        return -1;
    }
}
void::LinkedList::removevalue(int value){
    if(head!=NULL){
        Node* temp = head;
        int index = 0;
        while(temp!=NULL){
            if(temp->data==value){
                remove(index);
                return;
            }
            index++;
            temp = temp->next;
        }
        std::cout<<"removevalue::Item not found\n";
    }else{
        std::cout<<"removevalue::Head is Null\n";
    }
}
int LinkedList::find(int value){
    if(head!=NULL){
        Node* temp = head;
        int index = 0;
        while(temp!=NULL){
            if(temp->data==value){
                return index;
            }
            index++;
            temp = temp->next;
        }
        std::cout<<"find::Item not found\n";
        return -1;
    }else{
        std::cout<<"find::Head is Null\n";
        return -1;
    }
}
void LinkedList::reverse_iterative(){
    if (head == NULL || head->next == NULL) return;
    Node* prev = NULL;
    Node* current = head;
    Node* next;
    while(current!=NULL){
        next = current->next; 
        current->next = prev;
        prev = current;
        current = next;
    }
    tail = head;
    head = prev;
}
void LinkedList::reverse_recursive(Node* node){
    if (head == NULL || head->next == NULL) return;
    if(node->next == NULL){
        head = node;
        return;
    };
    reverse_recursive(node->next);
    Node* nextnode = node->next;
    nextnode->next = node;
    node->next = NULL;
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
    ll.append(10);
    ll.append(20);
    ll.append(30);
    ll.append(40);
    ll.reverse_recursive(ll.getHead());
    ll.print();
}

//Powershell: g++ linked_list.cpp -o linked_list; .\linked_list