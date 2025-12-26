#ifndef DLcode_h
#define DLcode_h
#include <iostream>
#include <vector>
using namespace std;
class doubleLinkcodesolution{
    public:
    struct DLinknode{
        int data;
        DLinknode*prev;
        DLinknode*next;
        DLinknode(int val):data(val),prev(nullptr),next(nullptr){}
    };

    DLinknode* L;
    int length;

    bool Initlist(DLinknode*& head) {
        head = new DLinknode(0);
        if (head == nullptr) return false;
        length = 0;
        return true;
    }

    doubleLinkcodesolution() { Initlist(L); }

   void creatLinkheader(DLinknode*& head){
    head = new DLinknode(0);    
    int val;
        cout<<"Enter numbers to create linked list, end with -1:"<<endl;
        while(true){
            cin>>val;
            if(val==-1) break;
            DLinknode* newNode=new DLinknode(val);
            newNode->next=head->next;
            if(head->next != nullptr){
                head->next->prev=newNode;
            }
            head->next=newNode;
            newNode->prev=head;
            length++;
        }
    }

    void creatLinktail(DLinknode*& head){
        head = new DLinknode(0);
        DLinknode* tail=head;
        int val;
        cout<<"Enter numbers to create linked list, end with -1:"<<endl;
        while(true){
            cin>>val;
            if(val==-1) break;
            DLinknode* newNode=new DLinknode(val);
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
            length++;
        }
        tail->next=nullptr;
    }

     void destorylist(DLinknode*& head) {
        DLinknode* p = head;
        while (p != nullptr) {
            DLinknode* tmp = p;
            p = p->next;
            delete tmp;
        }
        head = nullptr;
        length = 0;
    }


    void insertbefore(DLinknode* head, int value, int pos){
        if(pos<0||pos>length){
            return;
        }
        DLinknode* p = new DLinknode(value);
        DLinknode* current = head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        p->next=current;
        p->prev=current->prev;
        current->prev->next=p;
        current->prev=p;
        length++;
    }
    
    void insertafter(DLinknode* head, int value, int pos){
        if(pos<0||pos>length){
            return;
        }
        DLinknode* p = new DLinknode(value);
        DLinknode* current = head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        p->next=current->next;
        p->prev=current;
    if(current->next != nullptr){
        current->next->prev=p;
    }
        current->next=p;
        length++;
    }

    int findnumvalue(DLinknode* head,int value){
        DLinknode* current = head;
        for(int i=0;i<length;i++){
            current=current->next;
            if(current->data==value){
                return i;
            }
        }
        return -1;
    }

    int findnumpos(DLinknode* head, int pos){
        if(pos<0||pos>length) return -1;
        int mid = length >> 1;
        DLinknode* current;
        if(pos<=mid){
            current=head;
            for(int i=0;i<=pos;i++){
                current=current->next;
            }
        }
        if(pos>mid){
            current=head;
            for(int i=0;i<length-pos;i++){
                current=current->prev;
            }

        }
        return current->data;
    }


   
    void deletenumbetween(DLinknode* head , int pos){
        if(pos<0||pos>length){
            return;
        }
        DLinknode* current = head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        current->prev->next=current->next;
        if(current->next != nullptr){
            current->next->prev=current->prev;
        }
        delete current;
        length--;
    }

    void deletenumbefore(DLinknode* head ,int pos){
        if(pos<0||pos>length){
            return;
        }
        DLinknode* current = head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        if(current->prev == head){
            return;
        }
        DLinknode* toDelete = current->prev;
        toDelete->prev->next=current;
        current->prev=toDelete->prev;
        delete toDelete;
        length--;
    }

    void deletenumafter(DLinknode* head ,int pos){
        if(pos<0||pos>length){
            return;
        }
        DLinknode* current = head;
        for(int i=0;i<pos;i++){
            current=current->next;
        }
        if(current->next == nullptr){
            return;
        }
        DLinknode* afterNode = current->next;
        if(afterNode->next != nullptr){
        afterNode->next->prev=current;
        }
        current->next=afterNode->next;
        delete afterNode;
        length--;
    }

    void coutnum(DLinknode* head){
        DLinknode* current=head->next;
        while(current!=nullptr){
            std::cout<<current->data<<" ";
            current=current->next;
        }
        
    }


};

#endif



