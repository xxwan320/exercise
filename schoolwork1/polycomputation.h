#ifndef polycomputation_h
#define polycomputation_h
#include <iostream>
using namespace std;
//多项式加法和乘法运算

class polycomputation{
    public:
    struct polyterm{
        int coef;
        int expn;
        polyterm* next;
        polyterm(int c,int e):coef(c),expn(e),next(nullptr){}
    };

    void creatpoly(polyterm*& head){
        head=new polyterm(0,0);
        polyterm* tail=head;
        int c,e;
        std::cout<<"end with -1 -1:"<<endl;
        while(true){
            cin>>c>>e;
            if(c==-1&&e==-1) break;
            polyterm* newNode=new polyterm(c,e);
            tail->next=newNode;
            tail=newNode;
        }
        tail->next=nullptr;
    }

        void initpoly(polyterm*& head){
        head=new polyterm(0,0);
        head->next=nullptr;
    }
        polyterm* addpoly(polyterm* A,polyterm* B){
            polyterm* C;
            initpoly(C);
            polyterm* tail=C;
            polyterm* pa=A->next;
            polyterm* pb=B->next;
            if(pa==nullptr) return B;
            if(pb==nullptr) return A;
            while(pa!=nullptr&&pb!=nullptr){
                if(pa->expn==pb->expn){
                    int sum=pa->coef+pb->coef;
                    if(sum!=0){
                        polyterm* newNode =new polyterm(sum,pa->expn);
                        tail->next=newNode;
                        tail=newNode;
                    }
                    pa=pa->next;
                    pb=pb->next;
                }
                    
                else if(pa->expn>pb->expn){
                    polyterm*newNode=new polyterm(pa->coef,pa->expn);
                    tail->next=newNode;
                    tail=newNode;
                    pa=pa->next;
                }
                else if(pa->expn<pb->expn){
                    polyterm*newNode=new polyterm(pb->coef,pb->expn);
                    tail->next=newNode;
                    tail=newNode;
                    pb=pb->next;
                }
            }                                                                                                                                           
                while(pa!=nullptr){
                    polyterm*newNode=new polyterm(pa->coef,pa->expn);
                    tail->next=newNode;
                    tail=newNode;
                    pa=pa->next;
                }
                while(pb!=nullptr){
                    polyterm*newNode=new polyterm(pb->coef,pb->expn);
                    tail->next=newNode;
                    tail=newNode;
                    pb=pb->next;
                }
            
                return C;
        }

        //使多项式按指数大小排序
        void Sortexpn(polyterm* head){
            if(head==nullptr||head->next==nullptr) return;
            polyterm* p=head->next;
            while(p!=nullptr){
                polyterm* q=p->next;
                while(q!=nullptr){
                    if(p->expn < q->expn){
                        swap(p->expn,q->expn);
                        swap(p->coef,q->coef);
                    }
                    q=q->next;
                }
                p=p->next;
            }
        }
        
        //合并同类项
         void combine(polyterm* head){
            if(head==nullptr||head->next==nullptr) return;
            polyterm* p=head->next;
            Sortexpn(head);
            while(p!=nullptr&&p->next!=nullptr){
                if(p->expn==p->next->expn){
                    p->coef+=p->next->coef;
                    polyterm* tmp=p->next;
                    p->next=tmp->next;
                    delete tmp;
                }
                else{
                    p=p->next;
                }
            }
        }

        //删除0常数项
        void deletezero(polyterm* head){
            if(head==nullptr||head->next==nullptr) return;
            polyterm* p=head;
            while(p->next!=nullptr){
                if(p->next->coef==0){
                    polyterm* tmp=p->next;
                    p->next=tmp->next;
                    delete tmp;
                }
                else{
                    p=p->next;
                }
            }
        }
        
        
        polyterm* mulpoly(polyterm* A,polyterm* B){
            polyterm* C;
            initpoly(C);
            polyterm* tail=C;
            polyterm* pa=A->next;
            polyterm* pb=B->next;
            if(pa==nullptr||pb==nullptr) return C;
            while(pa!=nullptr){
                while(pb!=nullptr){
                    int c=pa->coef*pb->coef;
                    int e=pa->expn+pb->expn;
                    if(c!=0){
                        polyterm* newNode=new polyterm(c,e);
                        tail->next=newNode;
                        tail=newNode;
                    }
                    pb=pb->next;
                }

                pa=pa->next;
                pb=B->next;
            }
            Sortexpn(C);
            combine(C);
            deletezero(C);
            tail->next = nullptr;
            return C;

        }

        polyterm* polycout(polyterm* head){
            polyterm* p=head->next;
            while(p!=nullptr){
                std::cout<<p->coef<<"x^"<<p->expn;
                if(p->next!=nullptr){
                    std::cout<<" + ";
                }
                p=p->next;
            }
            std::cout<<endl;
            return head;
        }

    };

#endif