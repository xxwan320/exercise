#ifndef Lode_h
#define Lcode_h
#include <iostream>
#include <vector>
using namespace std;

class Linkcodesolution{
    public:
    struct Linknode{
        int data;
        Linknode* next;
        Linknode(int val):data(val),next(nullptr){}
    };

    Linknode* L;
    int length;


    bool Initlist(Linknode*& head) {
        head = new Linknode(0);
        if (head == nullptr) return false;
        length = 0;
        return true;
    }

    Linkcodesolution() { Initlist(L); }

    void creatLinkheader(Linknode*& head){
        head = new Linknode(0);
        int val;
        cout<<"Enter numbers to create linked list, end with -1:"<<endl;
        while(true){
            cin>>val;
            if(val==-1) break;
            Linknode* newNode=new Linknode(val);
            newNode->next=head->next;
            head->next=newNode;
            length++;
        }
    }

    void creatLinktail(Linknode*& head){
        head = new Linknode(0);
        Linknode* tail=head;
        int val;
        cout<<"Enter numbers to create linked list, end with -1:"<<endl;
        while(true){
            cin>>val;
            if(val==-1) break;
            Linknode* newNode=new Linknode(val);
            tail->next=newNode;
            tail=newNode;
            length++;
        }
        tail->next=nullptr;
    }
    

    bool Destorylist(Linknode*& head) {
        Linknode* p = head;
        while (p != nullptr) {
            Linknode* q = p->next;
            delete p;
            p = q;
        }
        head = nullptr;
        length = 0;
        return true;
    }
    ~Linkcodesolution() { Destorylist(L); }


    void insert(Linknode* head, int value, int pos){
        if(pos<0||pos>length){
            return;
        }
        Linknode* p=new Linknode(value);
        Linknode* current=head;
        for(int i =0;i<pos;i++){
            current=current->next;
        }
        p->next=current->next;
        current->next=p;
        length++;

    }

    void deletenum(Linknode* head,int pos){
        if(pos<0||pos>length){
            return ;
        }
        Linknode* current=head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        Linknode*tmp = current->next;
        current->next=tmp->next;
        delete tmp;
    }

    int findnumvalue(Linknode* head,int value){
        Linknode* current=head->next;
        int pos=0;
        while(current!=nullptr){
            if(current->data==value){
                return pos;
            }
            current=current->next;
            pos++;
        }
        return -1;
    }

    int findnumpos(Linknode*head,int pos){
        if(pos<0||pos>=length){
            return -1;
        }
        Linknode* current=head->next;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        return current->data;

    }

    void coutnum(Linknode* head){
        Linknode* current=head->next;
        while(current!=nullptr){
            std::cout<<current->data<<" ";
            current=current->next;
        }
        
    }
};



#endif