#ifndef SORT_H
#define SORT_H
using namespace std;
#include<iostream>
#include<vector>

class Sort {
private:
    int size;
    int* data;

public:
    struct mysequence {
        int index;
        vector<int> seq;
    };

    void myinitsort() {
        size = 0;
        data = nullptr;
    }

    void mydestroysort(mysequence& sequence) {
        size = 0;

        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
        sequence.seq.clear();   
        sequence.index = -1;
}

    void mycreateinsertsort(mysequence& sequence) {
        sequence.index = -1;
        sequence.seq.clear();
        sequence.seq.push_back(0); 
        cout << "input the number of data" << endl;
        cin >> size;

        data = new int[size + 1];

        cout << "input data" << endl;
        for (int i = 1; i <= size; i++) {
            cin >> data[i];
            sequence.seq.push_back(data[i]);
        }

        delete[] data;
        data = nullptr;
    }

    void prinfsort(mysequence& seqsearch) {
        for (int i = 1; i <= size; i++) {
            cout << seqsearch.seq[i] << " ";
        }
        cout << endl;
    }

    void insertsort(mysequence& seqsearch) {
        for (int i = 2; i <= size; i++) {
            seqsearch.seq[0] = seqsearch.seq[i];
            int j = i - 1;
            while (j >= 1 && seqsearch.seq[j] > seqsearch.seq[0]) {
                seqsearch.seq[j + 1] = seqsearch.seq[j];
                j--;
            }
            seqsearch.seq[j + 1] = seqsearch.seq[0];
        }
    }

    void blnsort(mysequence& seqsearch) {
        for (int i = 2; i <= size; i++) {
            seqsearch.seq[0] = seqsearch.seq[i];
            int low = 1;
            int high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (seqsearch.seq[mid] > seqsearch.seq[0]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            for (int j = i - 1; j >= low; j--) {
                seqsearch.seq[j + 1] = seqsearch.seq[j];
            }
            seqsearch.seq[low] = seqsearch.seq[0];
        }
    }


    int partition(mysequence& sequence, int low, int high) {
        int pivot = sequence.seq[low];

        while (low < high) {
            while (low < high && sequence.seq[high] >= pivot)
                    high--;
            sequence.seq[low] = sequence.seq[high];   

            while (low < high && sequence.seq[low] <= pivot)
                low++;
            sequence.seq[high] = sequence.seq[low];   
        }

        sequence.seq[low] = pivot;
        //由于low这里就是所谓枢纽的位置，于是我们简单添加一个cout函数在每次调用时候都进行输出
        cout << "Current pivot position: " << low << endl;
        prinfsort(sequence);//打印每次排序结果
        return low;
}

    
    void quicksort(mysequence& sequence, int low, int high) {
        if (low < high) {
            int q = partition(sequence, low, high);
            quicksort(sequence, low, q - 1);
            quicksort(sequence, q + 1, high);
            
        }
    }

    
};

#endif