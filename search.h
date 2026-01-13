#ifndef SEARCH_H
#define SEARCH_H
#include<iostream>
#include<vector>
using namespace std;
class Search{

    private:
        int size;
        int*data;
        int key;
    public:

        struct keytypesearch{
            int keyvalue;
            int keyindex;
            vector<int> seq;
        };
        struct binarysearchtree{
            int val;
            binarysearchtree* left;
            binarysearchtree* right;
            binarysearchtree(int v):val(v),left(nullptr),right(nullptr){}
        };

        void myinitsearch(){
            size = 0;
            data = nullptr;
            key = 0;
        }
        void mydestroysearch(){
            if(data != nullptr){
                delete[] data;
                data = nullptr;
            }        
        }
        void mycreatkeysearch(keytypesearch &seqsearch){
            seqsearch.keyindex = -1;
            seqsearch.seq.clear();
            seqsearch.seq.push_back(seqsearch.keyvalue); // 0号位作为哨兵
            cout << "input key value" << endl;
            cin >> seqsearch.keyvalue;
            cout << "input the number of data" << endl;
            cin >> size;
            data = new int[size+1];
            cout << "input data" << endl;
            for(int i = 1;i <=size;i++){
                cin >> data[i];
                seqsearch.seq.push_back(data[i]);
            }
            delete[] data;
            data = nullptr;
        }

        void insertbst(binarysearchtree* &root,int val){
            if(root == nullptr){
                root = new binarysearchtree(val);
                return;
            }
            if(val < root->val){
                insertbst(root->left,val);
            }
            else{
                insertbst(root->right,val);
            }
        }
       
        void mycreatbinarysearchtree(binarysearchtree* &root){
            cout << "input the number of data" << endl;
            cin >> size;
            cout << "input data" << endl;
            root = nullptr;
            for(int i = 0;i < size;i++){
                int val;
                cin >> val;
                insertbst(root,val);
            }
        }


        int keysearchlin(keytypesearch &seqsearch){
            for(int i = 1;i <=size;i++){
                if(seqsearch.seq[i] == seqsearch.keyvalue){
                    seqsearch.keyindex = i;
                    return i;
                }
            }
            return -1;
        }
        
        int keysearchbin(keytypesearch &seqsearch,int &count){
            count = 0;
            int left = 1;
            int right = size;
            while(left <= right){
                int mid = (left + right)/2;
                if(seqsearch.seq[mid] == seqsearch.keyvalue){
                    seqsearch.keyindex = mid;
                    count++;
                    return mid;
                }
                else if(seqsearch.seq[mid] < seqsearch.keyvalue){
                    left = mid + 1;
                    count++;
                }
                else{
                    right = mid - 1;
                    count++;
                }
            }
            return -1;
        }

        
        int binarysearchtreefind(binarysearchtree* root,int key,int* leftval,int* rightval){
             while (root != NULL) {
                 if (key < root->val) {
                        root = root->left;
                    } else if (key > root->val) {
                        root = root->right;
                    } else {  
                        *leftval  = (root->left  != NULL) ? root->left->val  : -1;
                        *rightval = (root->right != NULL) ? root->right->val : -1;
                                return 1;
                    //这里我们在函数使用时传入两个指针来存储左右节点的信息
                    }
                }
                     return -1; 
            }
       

};

#endif