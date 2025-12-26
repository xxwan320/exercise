#ifndef sequence_h
#define sequence_h
#include <iostream>
#include <vector>
using namespace std;

class Sequencesolution{
    public:
    struct sequence{
        vector<int> sequence;
        int length = 0;
    };
    
    
    void create(sequence& seq){
        seq.length=0;
        seq.sequence.clear();
        int val;
        cout<<"Enter numbers to create sequence, end with -1:"<<endl;
        while(true){
            cin>>val;
            if(val==-1) break;
            seq.sequence.push_back(val);
            seq.length++;
        }
       
    }
    
    void insert(sequence& seq,int value,int pos){    
        for(int i=seq.length-1;i>=pos;i--){
                seq.sequence[i+1]=seq.sequence[i];
            }
            seq.sequence[pos]=value;
            seq.length++;
    }
    void deletenum(sequence& seq,int pos){
        for(int i=pos;i<seq.length-1;i++){
            seq.sequence[i]=seq.sequence[i+1];
        }
        seq.length--;
    }

    int findnum(sequence& seq,int value){
        for(int i=0;i<seq.length;i++){
            if(seq.sequence[i]==value){
                return i;
            }
        }
        return -1;
    }

    int findpos(sequence& seq,int pos){
        if(pos<0||pos>=seq.length){
            return -1;
        }
        return seq.sequence[pos];
    }

    

    void coutnum(sequence& seq){
        for(int i=0;i<seq.length;i++){
            cout<<seq.sequence[i]<<" ";
        }
    }

    void average(sequence& seq){
        int sum=0;
        for(int i=0;i<seq.length;i++){
            sum+=seq.sequence[i];
        }
        int avg=sum/seq.length;
        insert(seq,avg,seq.length/2);
    }
    
    int destory(sequence& seq){
        seq.length=0;
        seq.sequence.clear();
        return 0;
    }
    
    void coutvalue(sequence& seq,int pos){
        cout<<seq.sequence[pos];
    }

};

#endif