#ifndef string_h
#define string_h
#include <iostream>
using namespace std;
class myString{
    private:
    char *str = nullptr;
    int length = 0;
    public:
    void initString(){
        str=new char[1];
        str[0]='\0';
        length=0;
    }
     void destroyString(){
        delete[] str;
        str=nullptr;
        length=0;
    }
    myString(){
        initString();
    }
    ~myString(){
        destroyString();
    }
    int getLength(const char* s){
        int len=0;
        while(*s != '\0'){
            len++;
            s++;
        }
        return len;
        
    }

    int getLength(){
        return length;
    }

    const char* c_str() {
    return str;
}

    char *my_strcpy(char *dest, const char *src) {
    
        char *original_dest = dest; 
        while ((*dest = *src) != '\0') {
                    dest++;
                     src++;  
            }
            return original_dest; 
}
   //这里没有动态分配内存，限制字符串最大数为999,如果实际输入更大的字符串，会发生溢出
    void createstring(){
        cout<<"Enter a string:"<<endl;
        destroyString();
        char* buffer = new char[1000];
        if(buffer == nullptr){
            return ;
        }                                                                                                                                                                                                                                                                                                           
        cin.getline(buffer,1000);
        int len=getLength(buffer);
        str=new char[len+1];
        my_strcpy(str,buffer);
        length=len;
        delete[] buffer;
        
    }
    
    void display(){
        cout << str;
    }

};

#endif