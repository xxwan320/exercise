#include<iostream>
#include"sort.h"
using namespace std;

int main(){

    Sort mysort;
    Sort::mysequence sequence;
    //直接插入排序测试
    mysort.myinitsort();
    mysort.mycreateinsertsort(sequence);
    mysort.insertsort(sequence);
    mysort.prinfsort(sequence);
    mysort.mydestroysort(sequence);
    //折半插入排序测试
    mysort.myinitsort();
    mysort.mycreateinsertsort(sequence);
    mysort.blnsort(sequence);
    mysort.prinfsort(sequence);
    mysort.mydestroysort(sequence);
    
    //快速排序测试
    mysort.myinitsort();
    mysort.mycreateinsertsort(sequence);
    mysort.quicksort(sequence,1,sequence.seq.size()-1);
    mysort.prinfsort(sequence);
    mysort.mydestroysort(sequence);
    return 0;
}