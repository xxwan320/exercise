#ifndef KMP_h
#define KMP_h
#include<iostream>
#include"string.h"
using namespace std;
#include <vector>

class KMPmatch {
public:
   
    vector<int> buildLPS(myString& t) {
        int len = t.getLength();
        std::vector<int> lps(len, 0);
        const char* p = t.c_str();

        int k = 0;
        for (int i = 1; i < len; ++i) {
            while (k > 0 && p[k] != p[i]) {
                k = lps[k - 1];
            }
            if (p[k] == p[i]) {
                k++;
            }
            lps[i] = k;
        }
        return lps;
    }

    
    int KMPSearch(myString& s, myString& t) {
        int lenS = s.getLength();
        int lenT = t.getLength();
        const char* s_ptr = s.c_str();
        const char* t_ptr = t.c_str();

        if (lenT == 0) return 0; 
        if (lenS < lenT) return -1;

        std::vector<int> lps = buildLPS(t);

        int q = 0; 
        for (int i = 0; i < lenS; i++) {
            while (q > 0 && t_ptr[q] != s_ptr[i]) {
                q = lps[q - 1];
            }
            if (t_ptr[q] == s_ptr[i]) {
                q++;
            }
            if (q == lenT) {
                return i - lenT + 1; 
            }
        }
        return -1; 
    }
};



#endif
