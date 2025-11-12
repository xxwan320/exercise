#ifndef array_h
#define array_H
#include<iostream>
using namespace std;

class myarray {
private:
    int length = 0;
    int* arr = nullptr;
    int capability = 0;

public:
    void createarray() {
        cout << "Enter array length:" << endl;
        cin >> length;
        if (length > capability) {
            delete[] arr;
            capability = length * 2; 
            arr = new int[capability];
        }
        cout << "Enter " << length << " elements:" << endl;
        for (int i = 0; i < length; ++i) {
            cin >> arr[i];
        }
    }

    void Initarray() {
        length = 0;
        capability = 10;
        arr = new int[capability];
    }

    void Destroyarray() {
        delete[] arr;
        arr = nullptr;
        capability = 0;
        length = 0;
    }

    myarray(){
        Initarray();
    }   

    ~myarray(){
        Destroyarray();
    }
    bool Value(int i, int &x) {
        if(i < 0 || i >= length) return false;
        x = arr[i];
        return true;
    }

    
    bool Assign(int i, int x) {
        if(i < 0 || i >= length) return false;
        arr[i] = x;
        return true;
    }
    void display(){
        for(int i = 0;i < length;++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};



#endif
