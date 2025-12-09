#ifndef Qaftertraversal_h
#define Qaftertraversal_h
#include <iostream>
#include <vector>
using namespace std;

class Qaftertraversal{
private:  
    struct binarytreenode{
        char value;
        binarytreenode *left;
        binarytreenode *right;
        binarytreenode(char val):value(val),left(nullptr),right(nullptr){}
    };

    void buildPostorder(
        vector<char>& preorder, int preStart, int preEnd,
        vector<char>& inorder, int inStart, int inEnd
    ){
        if(preStart > preEnd || inStart > inEnd) return;

        char root = preorder[preStart];

        // 在中序数组中找到根节点位置
        int rootIndex = inStart;
        for(; rootIndex <= inEnd; ++rootIndex){
            if(inorder[rootIndex] == root) break;
        }

        int leftSize = rootIndex - inStart;

        // 递归左子树
        buildPostorder(preorder, preStart+1, preStart+leftSize,
                       inorder, inStart, rootIndex-1);

        // 递归右子树
        buildPostorder(preorder, preStart+leftSize+1, preEnd,
                       inorder, rootIndex+1, inEnd);

        // 输出根节点
        cout << root << " ";
    }

public:
    void aftertraversal(vector<char> pretraversal, vector<char> intraversal){
        if(pretraversal.size() == 0 || intraversal.size() == 0 
            || pretraversal.size() != intraversal.size()){
            return;
        }

        int n = pretraversal.size();
        buildPostorder(pretraversal, 0, n-1, intraversal, 0, n-1);
        cout << endl;
    }
};



#endif