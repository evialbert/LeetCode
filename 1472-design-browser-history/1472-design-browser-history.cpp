class Node {
public:
    string url;
    Node *next;
    Node *prev;

    Node(string url_) {
        url = url_;
        prev = next = nullptr;
    }
};

class BrowserHistory {
public:
    Node *ptr;

    BrowserHistory(string homepage) {
        ptr = new Node(homepage);
    }
    
    void visit(string url) {
        Node *newNode = new Node(url);
        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = newNode;
    }
    
    string back(int steps) {
        while(steps-- && ptr->prev != nullptr) {
            ptr = ptr->prev;
        }
        return ptr->url;
    }
    
    string forward(int steps) {
        while(steps-- && ptr->next != nullptr) {
            ptr = ptr->next;
        }
        return ptr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */