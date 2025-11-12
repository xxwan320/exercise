#ifndef matrix_h
#define matrix_h
#include<iostream>
#include<vector>
using namespace std;
class mysparematrix{

struct Triple {
    int row, col; 
    int val;     
};
private:
    Triple *data;   
    int rows, cols;
    int nums;       

public:
    mysparematrix(int r, int c, int n) {
        rows = r;
        cols = c;
        nums = n;
        data = new Triple[n];
    }

    
    void init(int index, int r, int c, int v) {
        data[index].row = r;
        data[index].col = c;
        data[index].val = v;
    }
    
   void createMatrix() {
    cout << "输入非零元素 (row col val)，输入 -1 结束输入：" << endl;
    int r, c, v;
    nums = 0;

    // 初次分配10个空间
    int capacity = 10;
    data = new Triple[capacity];

    while (true) {
        cin >> r;
        if (r == -1) break;
        cin >> c >> v;

        // 若空间不够就扩容
        if (nums >= capacity) {
            capacity *= 2;
            Triple* newdata = new Triple[capacity];
            for(int i = 0; i < nums; i++) newdata[i] = data[i];
            delete[] data;
            data = newdata;
        }

        data[nums].row = r;
        data[nums].col = c;
        data[nums].val = v;
        nums++;

        // 更新行列
        rows = max(rows, r + 1);
        cols = max(cols, c + 1);
    }
}

    mysparematrix() {
        rows = 0;
        cols = 0;
        nums = 0;
        data = nullptr;
    }

    ~mysparematrix() {
        delete[] data;
    }

    mysparematrix  tanspose(){
        mysparematrix T(cols,rows,nums);
        int *colsize = new int[cols+1]{0};
        for(int i = 0;i < nums;i++){
            colsize[data[i].col]++;
        }
        int *rownext = new int[cols+1]{0};
        rownext[0] = 0;
        for(int j = 1;j < cols;j++){
            rownext[j] = rownext[j-1] + colsize[j-1];

        }
        for(int i = 0; i < nums; i++) {
            int col = data[i].col;   
            int pos = rownext[col];  

            T.data[pos].row = data[i].col; 
            T.data[pos].col = data[i].row; 
            T.data[pos].val = data[i].val;

            rownext[col]++;  
            }
            delete[] colsize;
            delete[] rownext;
            return T;

    }
    void display(){
        cout << "Sparse Matrix (" << rows << "x" << cols << ") with " << nums << " non-zero elements:" << endl;
        for(int i = 0;i < nums;++i){
            cout << "(" << data[i].row << ", " << data[i].col << ") = " << data[i].val << endl;
        }
    }

};

class linkmatrix{
private:
    int rows;
    int cols;

    struct extendchainnode{
        int col;
        int value;
        extendchainnode *next;
        extendchainnode(int c,int v):col(c),value(v),next(nullptr){}
    };

    struct rowheadnode{
        int row;
        extendchainnode *rowchain;   
        rowheadnode *next;           
        rowheadnode(int r):row(r),rowchain(nullptr),next(nullptr){}
    };

    rowheadnode *rowhead = nullptr;  

public:
    
    void initlinkmatrix(){
        rows = 0;
        cols = 0;
        rowhead = nullptr;

    }

    linkmatrix(){
        rowhead = nullptr;
        rows = cols = 0;
    }

    ~linkmatrix(){
        rowheadnode *p = rowhead;
        while(p){
            extendchainnode *q = p->rowchain;
            while(q){
                extendchainnode *tmp = q;
                q = q->next;
                delete tmp;
            }
            rowheadnode *tmp = p;
            p = p->next;
            delete tmp;
        }
    }

    void createMatrix(){
        cout << "请输入元素 (row col val)，输入 -1 结束：" << endl;
        int r, c, v;

        while(true){
            cin >> r;
            if(r == -1) break;
            cin >> c >> v; 

            
            if(r + 1 > rows) rows = r + 1;
            if(c + 1 > cols) cols = c + 1;

            
            rowheadnode *p = rowhead, *pre = nullptr;
            while(p && p->row < r){
                pre = p;
                p = p->next;
            }
            if(!p || p->row != r){ 
                rowheadnode *newrow = new rowheadnode(r);
                newrow->next = p;
                if(pre) pre->next = newrow;
                else rowhead = newrow;
                p = newrow;
            }

          
            extendchainnode *q = p->rowchain, *pre2 = nullptr;
            while(q && q->col < c){
                pre2 = q;
                q = q->next;
            }
            extendchainnode *newnode = new extendchainnode(c, v);
            newnode->next = q;

            if(pre2) pre2->next = newnode;
            else p->rowchain = newnode;
        }
    }

        void clear(){
                rowheadnode *p = rowhead;
            while(p){
                extendchainnode *q = p->rowchain;
            while(q){
                extendchainnode *tmp = q;
                    q = q->next;
                    delete tmp;  
            }
                rowheadnode *tmp = p;
                    p = p->next;
                    delete tmp;       
        }

                    rowhead = nullptr;  
                    rows = 0;
                    cols = 0;
    }



    linkmatrix transpose(){
            linkmatrix T;        
            T.rows = this->cols; 
            T.cols = this->rows; 

            rowheadnode *p = rowhead;

        while(p){
            extendchainnode *q = p->rowchain;
            while(q){
                int newr = q->col; 
                int newc = p->row; 
                int val  = q->value;

           
            rowheadnode *tp = T.rowhead, *pre = nullptr;

           
        while(tp && tp->row < newr){
                pre = tp;
                tp = tp->next;
            }

            
        if(!tp || tp->row != newr){
                rowheadnode *newrow = new rowheadnode(newr);
                newrow->next = tp;
                if(pre) pre->next = newrow;
                else T.rowhead = newrow;
                tp = newrow;
            }

            
            extendchainnode *tq = tp->rowchain, *pre2 = nullptr;
        while(tq && tq->col < newc){
                pre2 = tq;
                tq = tq->next;
            }

            extendchainnode *newnode = new extendchainnode(newc, val);
            newnode->next = tq;

          if(pre2) pre2->next = newnode;
            else tp->rowchain = newnode;

            q = q->next;
        }
        p = p->next;
    }

    return T;
}

    void display(){
        cout << "Linked Sparse Matrix (" << rows << "x" << cols << "):" << endl;
        rowheadnode *p = rowhead;
        while(p){
            extendchainnode *q = p->rowchain;
            while(q){
                cout << "(" << p->row << ", " << q->col << ") = " << q->value << endl;
                q = q->next;
            }
            p = p->next;
        }
    }

};


#endif
