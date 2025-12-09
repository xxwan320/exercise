class MyLinkedList {
public:
    struct Linknode {
        int val;
        Linknode* next;
        Linknode(int x) : val(x), next(nullptr) {}
    };

    Linknode* L;
    int _size;

    bool Initlist(Linknode*& head) {
        head = new Linknode(0);
        if (head == nullptr) return false;
        _size = 0;
        return true;
    }

    MyLinkedList() { Initlist(L); }

    int get(int index) {
        if (index < 0 || index >= _size) return -1;
        Linknode* cur = L->next;
        for (int i = 0; i < index; ++i) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        Linknode* p = new Linknode(val);
        p->next = L->next;
        L->next = p;
        _size++;
    }

    void addAtTail(int val) {
        Linknode* p = new Linknode(val);
        Linknode* cur = L;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = p;
        _size++;
    }

    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > _size) return;
        Linknode* p = new Linknode(val);
        Linknode* cur = L;
        int j = 0;
        while (cur != NULL && j < index) {          
            cur = cur->next;
            ++j;
        }
        p->next = cur->next;
        cur->next = p;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size) return;
        Linknode* cur = L;
        int j = 0;
        while (j < index) {         
            cur = cur->next;
            ++j;
        }
        Linknode* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        _size--;
    }
};