#ifndef binarytree_h
#define binarytree_h
#include <iostream>
#include <vector>
using namespace std;

class binarytree {
private:
    struct binarytreenode {
        char value;
        binarytreenode *left;
        binarytreenode *right;
        binarytreenode(char val) : value(val), left(nullptr), right(nullptr) {}
    };

    size_t index;  

    
    binarytreenode* buildPre(const vector<char>& nodes) {
        if (index >= nodes.size() || nodes[index] == '#') {
            index++;
            return nullptr;
        }
        binarytreenode* node = new binarytreenode(nodes[index++]);
        node->left = buildPre(nodes);  
        node->right = buildPre(nodes); 
        return node;
    }

  
    void destroy(binarytreenode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    
    void pretraversal(binarytreenode* node, vector<char>& result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(node->value); 
        pretraversal(node->left, result);  
        pretraversal(node->right, result); 
    }

    void intraversal(binarytreenode* node, vector<char>& result) {
        if (node == nullptr) {
            return;
        }
        intraversal(node->left, result);   
        result.push_back(node->value);     
        intraversal(node->right, result);  
    }

    
    void aftertraversal(binarytreenode* node, vector<char>& result) {
        if (node == nullptr) {
            return;
        }
        aftertraversal(node->left, result);  
        aftertraversal(node->right, result); 
        result.push_back(node->value);       
    }

public:
    binarytreenode* root;    
    binarytree(const vector<char>& nodes) {
        index = 0;
        root = buildPre(nodes);
    }

    ~binarytree() {
        destroy(root);
    }

    void coutbinarytree(binarytreenode* root) {
        vector<char> pre, in, post;
        pretraversal(root, pre);
        intraversal(root, in);
        aftertraversal(root, post);

        cout << "Preorder: ";
        for (size_t i = 0; i < pre.size(); ++i) {
            if (i > 0) cout << " ";
            cout << pre[i];
        }
        cout << endl;

        cout << "Inorder: ";
        for (size_t i = 0; i < in.size(); ++i) {
            if (i > 0) cout << " ";
            cout << in[i];
        }
        cout << endl;

        cout << "Postorder: ";
        for (size_t i = 0; i < post.size(); ++i) {
            if (i > 0) cout << " ";
            cout << post[i];
        }
        cout << endl;
    }
    int computeLeafNum(binarytreenode* node) {
        if (node == nullptr) {
            return 0;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        return computeLeafNum(node->left) + computeLeafNum(node->right);
    }

    int computeDepth(binarytreenode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = computeDepth(node->left);
        int rightDepth = computeDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }


};

#endif