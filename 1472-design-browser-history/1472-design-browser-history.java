class BrowserHistory {
    class DNode
    {
        DNode prev,next;
        String val;
        DNode(String s)
        {
            this.val = s;
        }
    }
    
    DNode head,tail;
    DNode cur;
    public BrowserHistory(String homepage) {
        head = new DNode(homepage);
        tail = new DNode("");
        head.next = tail;
        tail.prev = head;
        cur = head;
    }
    
    public void visit(String url) {
        DNode next = new DNode(url);
        cur.next = next;
        next.prev = cur;
        next.next = tail;
        tail.prev = next;
        cur = next;
    }
    
    public String back(int steps) {
        while(steps>0 && cur.prev!=null)
        {
            cur = cur.prev;
            steps--;
        }
        
        return cur.val;
    }
    
    public String forward(int steps) {
        while(steps>0 && cur.next!=tail)
        {
            cur = cur.next;
            steps--;
        }
        
        return cur.val;
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */