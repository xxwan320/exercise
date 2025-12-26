
#include"polycomputation.h"
#include"DLcode.h"
#include"Lcode.h"
#include"sequence.h"
#include"noheadDL.h"
#include<bits/stdc++.h>

using namespace std;


Linkcodesolution::Linknode* inversion(Linkcodesolution::Linknode*& head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    Linkcodesolution::Linknode* newHead = inversion(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newHead;
}



//以下为任务1-5的测试函数，未完全按照顺序排列

//测试多项式加法和乘法
/*
int main(){
    polycomputation pc;
    polycomputation::polyterm* A;
    polycomputation::polyterm* B;
    pc.creatpoly(A);
    pc.creatpoly(B);
    polycomputation::polyterm* C=pc.addpoly(A,B);
    std::cout<<"A+B=" << C << endl;
    pc.polycout(C);
    polycomputation::polyterm* D=pc.mulpoly(A,B);
    std::cout<<"A*B=" << D << endl;
    pc.polycout(D);
    return 0;
}
*/

//测试无头线性表的反转
int main(){
    ListNode* head;
    creatList(head);
    std::cout << "Original List: ";
    coutList(head);
    head = reverseList(head);
    std::cout << "Reversed List: ";
    coutList(head);
    deleteList(head);
    return 0;
}



//测试双链表的基本操作
/*
int main(){
    doubleLinkcodesolution dlcs;
    
    dlcs.creatLinkheader(dlcs.L);
    std::cout << "Initial headList: ";
    dlcs.coutnum(dlcs.L);
    std::cout << endl;
    dlcs.destorylist(dlcs.L);
    std::cout << "Initial tailList: ";
    std::cout << endl;
    dlcs.creatLinktail(dlcs.L);
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;
    
    dlcs.insertbefore(dlcs.L, 15, 2);
    std::cout << "After Insertion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;
    
    dlcs.deletenumbetween(dlcs.L, 2);
    std::cout << "After Deletion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;

    
    dlcs.insertafter(dlcs.L, 40, 3);
    std::cout << "After Insertion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;
    
    dlcs.deletenumbefore(dlcs.L, 5);
    std::cout << "After Deletion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;

    
    
    dlcs.insertafter(dlcs.L, 12, 1);
    std::cout << "After Insertion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;
  
    dlcs.deletenumafter(dlcs.L, 1);
    std::cout << "After Deletion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;


  
    dlcs.insertbefore(dlcs.L, 5, 1);
    std::cout << "After Insertion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;
    

    dlcs.deletenumbefore(dlcs.L, 2);
    std::cout << "After Deletion: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;
    std::cout << "Final List: ";
    dlcs.coutnum(dlcs.L);
    std::cout << std::endl;
    
    //第一个数位置序号为0
    std::cout << "find value 4 at position: " << dlcs.findnumvalue(dlcs.L, 4) << std::endl;
    std::cout << "find position 13 value: " << dlcs.findnumvalue(dlcs.L, 13) << std::endl;
    std::cout << "find position 2 value: " << dlcs.findnumpos(dlcs.L, 2) << std::endl;

    return 0;
}
*/

//测试顺序表的基本操作
/*
int main(){
    Sequencesolution ss;
    Sequencesolution::sequence seq;
    ss.create(seq);
    ss.insert(seq,10,2);
    ss.coutnum(seq);
    cout<<endl;
    ss.deletenum(seq,2);
    ss.coutnum(seq);
    cout<<endl;
    cout<<"Find 8 at position: "<<ss.findnum(seq,8)<<endl;
    cout << "Find 100 at position: " << ss.findnum(seq, 100) << endl;
    cout << "Find value at position 3: " << seq.sequence[3] << endl;
    ss.average(seq);
    ss.coutnum(seq);
    cout<<endl;
    ss.destory(seq);
    return 0;
}
*/

//测试单链表基本操作
/*
int main(){
    Linkcodesolution lcs;
    lcs.creatLinktail(lcs.L);
    lcs.coutnum(lcs.L);
    cout<<endl;
    lcs.insert(lcs.L,25,2);
    lcs.coutnum(lcs.L);
    cout<<endl;
    lcs.deletenum(lcs.L,4);
    lcs.coutnum(lcs.L);
    cout<<endl;
    //第一位置序号为0
    cout<<"Find 7 at position: "<<lcs.findnumvalue(lcs.L,7)<<endl;
    cout<<"Find 89 at position: "<<lcs.findnumvalue(lcs.L,89)<<endl;
    cout<<"Find value at position 3: "<<lcs.findnumpos(lcs.L,3)<<endl;
    return 0;
}
*/