#include<iostream>
#include<vector>
#include"binarytree.h"
#include"Qaftertraversal.h"
using namespace std;
/*
int main(){
    //测试输入前序数组，如果数组元素为#，则表示该节点为空
    vector<char> preorder;
    cout<<"Enter preorder traversal of binary tree (0 for null nodes), end with $:"<<endl;
    while(true){
        char val;
        cin>>val;
        if(val == '$') break;
        preorder.push_back(val);
    }
    binarytree tree(preorder);
    //输入前序，中序和后序遍历结果
    tree.coutbinarytree(tree.root);
    return 0;
}
    */
   /*
int main(){
    //计算叶子节点数目和树的深度
    vector<char> preorder;
    cout<<"Enter preorder traversal of binary tree (0 for null nodes), end with $:"<<endl;
    while(true){
        char val;
        cin>>val;
        if(val == '$') break;
        preorder.push_back(val);
    }
    binarytree tree(preorder);
    int leafNum = tree.computeLeafNum(tree.root);
    int depth = tree.computeDepth(tree.root);
    cout<<"Number of leaf nodes: "<<leafNum<<endl;
    cout<<"Depth of the tree: "<<depth<<endl;
    return 0;
}
    */
//已知前序中序遍历求后续遍历
    int main(){
    vector<char> preorder, inorder;
    cout<<"Enter preorder traversal of binary tree and inorder traversal, end with $:"<<endl;
    while(true){
        char val;
        cin>>val;
        if(val == '$') break;
        preorder.push_back(val);
    }
    while(true){
        char val;
        cin>>val;
        if(val == '$') break;
        inorder.push_back(val);
    }
    Qaftertraversal getpost;
    cout << "Postorder traversal: ";
    getpost.aftertraversal(preorder, inorder);
    return 0; 
}