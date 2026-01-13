#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<vector>
using namespace std;
    

class mygraph{ 
private: 
        struct graphnode{  
            int point;
            graphnode* next; 
            graphnode(int p):point(p),next(nullptr){} 
        }; 
        int pointnum; 
        graphnode** aList = nullptr; 
public: 
        
    void myinitgraph(){ 
            pointnum = 0;  
            aList = nullptr; 
        } 
    void mycreategraph(){
        cout << "the number of points" << endl;
        cin >> pointnum;

        aList = new graphnode *[pointnum+1];
        for(int i = 1; i <= pointnum; ++i){
                aList[i] = nullptr;
            }

        cout << "input each point and end with -1" << endl;

        for(int i = 1; i <= pointnum; ++i){
            graphnode* head = new graphnode(0);   
            graphnode* tail = head;              

            int p;
            cin >> p;

        while(p != -1){
            graphnode* newnode = new graphnode(p);
            tail->next = newnode;
            tail = newnode;
            cin >> p;
        }
            aList[i] = head->next;  
    }
}


    void mydestroygraph(){
        for(int i = 1;i <= pointnum;++i){   
            graphnode* current = aList[i];
            while(current != nullptr){
                graphnode* temp = current;
                current = current->next;
                delete temp;
         }
         }
        delete[] aList;
        aList = nullptr;
        pointnum = 0;
    }

    mygraph(){
        myinitgraph();
    }

    ~mygraph(){
        mydestroygraph();
    }

    void displaygraph(){
        for(int i = 1;i <= pointnum;++i){   
            cout << "Point " << i << ":";
            graphnode* current = aList[i];  
        while(current != nullptr){
            cout << current->point << " ";
            current = current->next;
        }
            cout << endl;
        }
    }

    void BFSsearch(int startpoint){
        bool* visited = new bool[pointnum+1];   
        for(int i = 1;i <= pointnum;++i){
            visited[i] = false;
        }
        visited[startpoint] = true;

        cout << "BFS traversal starting from point " << startpoint << ":";

            int* queue = new int[pointnum+1];       
            int front = 1, rear = 1;
            queue[rear] = startpoint;
            rear++;

        while(front < rear){
            int currentpoint = queue[front++];
            graphnode* currentnode = aList[currentpoint];

            while(currentnode != nullptr){
                int adjpoint = currentnode->point;
                if(!visited[adjpoint]){
                    visited[adjpoint] = true;
                    queue[rear++] = adjpoint;
                }
                currentnode = currentnode->next;
            }
        }

        for(int i = 1;i < rear;++i){
             cout << queue[i] << " ";   
        }

        delete[] visited;
        delete[] queue;
    }


    void DFSsearch(int startpoint){

        bool* visited = new bool[pointnum+1];
        for(int i = 1;i <= pointnum;++i) visited[i] = false;

            vector<int> order;               
            int* stack = new int[pointnum+1]; 
            int top = 0;

        visited[startpoint] = true;
        stack[++top] = startpoint;

        while(top > 0){
            int currentpoint = stack[top];
            top--;
            order.push_back(currentpoint);
            graphnode* currentnode = aList[currentpoint];
            while(currentnode != nullptr){
                int adjpoint = currentnode->point;
                if(adjpoint >= 1 && adjpoint <= pointnum){
                    if(!visited[adjpoint]){
                        visited[adjpoint] = true;
                            if(top < pointnum) stack[++top] = adjpoint;
                }
            } 
            currentnode = currentnode->next;
        }
    }

        cout << "DFS traversal starting from point " << startpoint << ": ";
        for(int v : order) cout << v << " ";
        cout << endl;

            delete[] visited;
            delete[] stack;
    }

    };

#endif