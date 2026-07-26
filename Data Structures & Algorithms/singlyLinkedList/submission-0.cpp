class LinkedList {
private:
    struct Node {
        
        int val;
        Node *next;
Node(int v, Node* n = nullptr) 
        : val(v), 
          next(n) {
        // Constructor body remains empty
    }
    };
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        if (index >= size) {
            return -1;
        }
        Node *curr = head;
        for (int i=0; i<index; i++) {
            curr = curr->next;

        }
        return curr->val;

    }

    void insertHead(int val) {
        Node* newHead = new Node(val, head);
        head = newHead;
        if (size == 0) {
            tail = newHead;
        }
        size ++;
        
    }
    
    void insertTail(int val) {
        Node* newTail = new Node(val);
        if (!head) {
            tail = newTail;
            head = newTail;
        } else {
            tail->next = newTail;
            tail = newTail;
        }
        size ++;
    }

    bool remove(int index) {
        if (index >= size) {
            return false;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (size == 1) {
                tail = nullptr;
            }
        }
        else {
            Node* curr = head;
            Node *prev = nullptr;
            for (int i=0; i<index; i++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            if (index == size - 1) {
                tail = prev;
            }
            delete curr;
        }
        size --;
        return true;

    }

    vector<int> getValues() {
        vector<int> values;
        Node *curr = head;
        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
        
    }
};