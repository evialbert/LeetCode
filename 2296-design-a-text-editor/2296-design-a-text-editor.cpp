class TextEditor {
public:
    string b="", a="";
    TextEditor() {
        
    }
    
    void addText(string text) {
        b += text;
    }
    
    int deleteText(int k) {
        int mn = min(int(b.length()), k);
        
        for(int i = 0; i < mn; ++i) b.pop_back();
        
        return mn;
    }
    
    string cursorLeft(int k) {
        int mn = min(k, int(b.length()));
        for(int i = 0; i < mn; ++i) {
            a.push_back(b.back());
            b.pop_back();
        }
        
        int mxlen = min(10, int(b.length()));
        
        return b.substr(b.length() - mxlen);
    }
    
    string cursorRight(int k) {
        int mn = min(k, int(a.length()));
        for(int i = 0; i < mn; ++i) {
            b.push_back(a.back());
            a.pop_back();
        }
        
        int mxlen = min(10, int(b.length()));
        
        return b.substr(b.length() - mxlen);
    }
};
/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */