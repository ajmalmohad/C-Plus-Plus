#include <iostream>

class MyVector{
    public:
        MyVector(int);
        
        void print();
        int size();
        int capacity();
        bool is_empty();
        void memory_status();
        void append(int);
        void prepend(int);
        void insert(int,int);
        void delete_index(int);
        int get(int);
        int find(int);
        int pop();
        void remove(int);

    private:
        int *arr;
        int room;
        int length=0;

        void resize(int);
        void check_resize();
};

//Constructor
MyVector::MyVector(int init=2){
    room = init;
    arr = (int*) calloc(room,sizeof(int));
}

//Private
void MyVector::resize(int r){
    int *temp = (int*) calloc(room,sizeof(int));
    for (int i = 0; i < length; i++) *(temp+i) = *(arr+i);
    delete[] arr;
    arr = temp;
}

void MyVector::check_resize(){
    if(length==room){
        room*=2;
        resize(room);
    }else if(length<(room/4)){
        room /= 2;
        resize(room);
    }
}

//Public
void MyVector::print(){
    std::cout<<"[";
    for (int i = 0; i < length; i++)
    {
        std::cout<<*(arr+i);
        (i<length-1)? std::cout<<", " : std::cout<<"";
    }
    std::cout<<"]\n";
}

void MyVector::memory_status(){
    for (int i = 0; i < room; i++) 
        std::cout<<arr+i<<" = "<<*(arr+i)<<'\n';
    std::cout<<'\n';
}

int MyVector::size(){
    return length;
}

int MyVector::capacity(){
    return room;
}

bool MyVector::is_empty(){
    return !length ? true: false;
}

void MyVector::append(int n){
    length++;
    check_resize();
    *(arr+(length-1))=n;
};

void MyVector::prepend(int n){
    insert(0,n);
};

void MyVector::insert(int i,int n){
    if(i>length || i<0) return;
    length++;
    check_resize();
    for (int j = length; j >i ; j--) *(arr+(j-1)) = *(arr+(j-2));
    *(arr+i) = n;
}

int MyVector::pop(){
    int temp = *(arr+(length-1));
    *(arr+(length-1))=0;
    length--;
    check_resize();
    return temp;
}

void MyVector::delete_index(int idx){
    if(idx>=length || idx<0) return;
    length--;
    for (int i = idx; i <length; i++) *(arr+i) = *(arr+(i+1));
    *(arr+length)=0;
    check_resize();
}

int MyVector::get(int i){
    return (i<length && i>=0) ? *(arr+i) : -1;
}

int MyVector::find(int v){
    for (int i = 0; i < length; i++) if(*(arr+i)==v)return i;
    return -1;
}

void MyVector::remove(int v){
    for (int i = 0; i < length; i++){
        if(*(arr+i)==v){
            delete_index(i);
            i--;
        }
    }
}

//Entry
int main(){
    MyVector myarr = MyVector();
    myarr.append(8);
    myarr.append(10);
    myarr.append(10);
    myarr.append(10);
    myarr.append(10);
    myarr.remove(10);
    myarr.memory_status();
};


// print(); Prints all Elements of Array
// size(); Prints Size of Array
// capacity(); Prints Capacity of Array
// is_empty(); Know whether empty or not
// memory_status(); Display values stored in allocated memories
// append(int); Append Element to End
// prepend(int); Prepend Element to Start
// insert(int,int); Inserts Element at desired Index (index, Value)
// delete_index(int); Deletes Value at Specified Index
// get(int); Gets element at specified index
// find(int); Find index by value
// pop(); Pops Last Item
