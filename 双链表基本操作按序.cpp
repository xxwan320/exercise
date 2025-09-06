class MyLinkedList {
public:
    struct DList {
        int  elem;
        DList *next, *prev;
        DList(int e = 0) : elem(e), next(nullptr), prev(nullptr) {}
    };

    DList *sentinelNode;
    int  size;

    MyLinkedList() : size(0) {
        sentinelNode = new DList(0);
        sentinelNode->next = sentinelNode;
        sentinelNode->prev = sentinelNode;
    }

    ~MyLinkedList() {
        DList *cur = sentinelNode->next;
        while (cur != sentinelNode) {
            DList *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        delete sentinelNode;
    }

    /* ===== 以下仅把遍历还原成“二分法”版本 ===== */

    int get(int index) {
        if (index < 0 || index > size - 1) return -1;
        int mid = size >> 1;
        DList *cur = sentinelNode;
        if (index < mid) {                      // 从前走
            for (int i = 0; i < index + 1; ++i) cur = cur->next;
        } else {                                // 从后走
            for (int i = 0; i < size - index; ++i) cur = cur->prev;
        }
        return cur->elem;
    }

    void addAtHead(int val) {
        DList *p = new DList(val);
        DList *nxt = sentinelNode->next;
        p->prev = sentinelNode;  p->next = nxt;
        nxt->prev = p;  sentinelNode->next = p;
        ++size;
    }

    void addAtTail(int val) {
        DList *p = new DList(val);
        DList *prv = sentinelNode->prev;
        p->next = sentinelNode;  p->prev = prv;
        prv->next = p;  sentinelNode->prev = p;
        ++size;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) { addAtHead(val); return; }
        int mid = size >> 1;
        DList *cur = sentinelNode;
        if (index < mid) {                      // 从前走
            for (int i = 0; i < index; ++i) cur = cur->next;
        } else {                                // 从后走
            for (int i = 0; i < size - index; ++i) cur = cur->prev;
        }
        /* 插入逻辑与你原代码完全一致 */
        DList *tmp = (index < mid) ? cur->next : cur->prev;
        DList *p = new DList(val);
        if (index < mid) {
            cur->next = p;  
            tmp->prev = p;
            p->next = tmp;  
            p->prev = cur;
        } else {
            cur->prev = p;  
            tmp->next = p;
            p->prev = tmp;  
            p->next = cur;
        }
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > size - 1) return;
        int mid = size >> 1;
        DList *cur = sentinelNode;
        if (index < mid) {                      // 从前走
            for (int i = 0; i < index; ++i) cur = cur->next;
        } else {                                // 从后走
            for (int i = 0; i < size - index - 1; ++i) cur = cur->prev;
        }
        DList *del = (index < mid) ? cur->next : cur->prev;
        del->prev->next = del->next;
        del->next->prev = del->prev;
        delete del;
        --size;
    }
};