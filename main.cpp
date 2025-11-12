#include<iostream>
#include "string.h"
#include"skmp.h"
#include"KMP.h"
#include"array.h"
#include"matrix.h"
using namespace std;

//测试test1创建字符串输入输出
/*
int main() {
    myString s1;
    s1.createstring();
    cout << "s1:";
    s1.display();
    cout << endl;
    myString s2;
    s2.createstring();
    cout << "s2:";
    s2.display();
    cout << endl;  
    return 0;
}
*/

//测试test2naivekmp算法
/*
int main(){
    myString s;
    s.createstring();
    myString t;
    t.createstring();
    int pos = 0;      //这里记录模式串首字母在主串中的位置，主串位置从0开始
    naivestrmatch match;
    pos = match.Nstrmatch(s,t);
    cout << "result is" << " " << pos << endl;
    return 0;
}
 */   

//测试KMP算法
/*
int main(){
    myString s;
    s.createstring();
    myString t;
    t.createstring();
    int pos = 0;      //这里记录模式串首字母在主串中的位置，主串位置从0开始
    KMPmatch match;
    pos = match.KMPSearch(s,t);
    cout << "result is" << " " << pos << endl;
    return 0;
}
    */

//测试数组顺序存储功能实现
/*
int main(){
    myarray arr;
    arr.createarray();
    int index,value;
    cout << "Enter index to get value:" << endl;
    cin >> index;
    if(arr.Value(index,value)){
        cout << "Value at index " << index << " is " << value << endl;
    } else {
        cout << "Index out of bounds." << endl;
    }

    cout << "Enter index to assign value:" << endl;
    cin >> index;
    cout << "Enter value to assign:" << endl;
    cin >> value;
    if(arr.Assign(index,value)){
        cout << "Assigned value " << value << " at index " << index << endl;
        arr.display();
    } else {
        cout << "Index out of bounds." << endl;
    }
    return 0;
}
    */

    //测试稀疏矩阵两种转置方法：三元组法和十字链表法
    int main(){
        mysparematrix sm;
        sm.display();
        cout << "Creating sparse matrix using triple representation:" << endl;
        sm.createMatrix();
        mysparematrix tsm = sm.tanspose();
        tsm.display();

        linkmatrix lm;
        lm.initlinkmatrix();
        cout << "Creating sparse matrix using linked list representation:" << endl;
        lm.createMatrix();
        linkmatrix tlm = lm.transpose();
        tlm.display();

        return 0;
    }