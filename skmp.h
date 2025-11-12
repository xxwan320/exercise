#ifndef skmp_h
#define skmp_h
#include<iostream>
#include"string.h"
using namespace std;
class naivestrmatch{
    private:
        char* str = nullptr;
        int length = 0;
    public:
        int Nstrmatch(myString& s,myString& t){
            
            int num1 = s.getLength();
            int num2 = t.getLength();
            //不妨假设在s中匹配t
            if(num1 < num2) return -1;
            int pos = -1; //返回-1表示没有找到
            for(int i = 0; i < num1 - num2 + 1;++i){
                const char* s_ptr = s.c_str() + i;
                const char* t_ptr = t.c_str();
                
                int num = 0; 
                for(int j = 0; j < num2; ++j){
                    if(*s_ptr != *t_ptr){
                        break;
                    }
                    s_ptr++;
                    t_ptr++;
                    num++;
                }
                
                if(num == num2){
                    pos = i;
                    break;
                }
                
            }
            return pos;

    }


};        

#endif