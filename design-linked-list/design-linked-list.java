class MyLinkedList {

    Node head;
    int size;
    
    /** Initialize your data structure here. */
    public MyLinkedList() {
        this.size = 0;
    }
	
	class Node{
		int value;
		Node next=null;
		
		Node(int value){
			this.value = value;		
		}	
		Node(int value,Node next){
			this.value = value;	
			this.next = next;
		}	
	}
	
	public int get(int index) {
       if(index<0 || index>=size)
			return -1;
		Node cur = head;
		int tmpIndex = 0;
		while(cur!=null && tmpIndex<index) {
			cur = cur.next;
			tmpIndex++;
		}	
		return cur.value;
    }
	
	public Node getNode(int index) {
		if(index<0 || index>=size)
			return null;
		Node cur = head;
		int tmpIndex = 0;
		while(cur!=null && tmpIndex<index) {
			cur = cur.next;
			tmpIndex++;
		}	
		return cur;
    }
	public void addAtHead(int val) {
		Node cur = new Node(val);		
		cur.next = head;
		head = cur;		
		this.size++;
    }
	public void addAtTail(int val) {
		Node cur = new Node(val);	
		if(this.head == null){
            this.head = cur;        
        }
        else{
            Node tmp = this.head;
            while(tmp.next!=null) {
                tmp = tmp.next;			
            }		
            tmp.next = cur;
        }
		this.size++;
	}
	public void addAtIndex(int index, int val) {
		Node cur = new Node(val);
		Node prev = getNode(index-1);
		if(index == 0){
            addAtHead(val);
        }
        else{
            cur.next = prev.next;
		    prev.next = cur;
		    
        }
        this.size++;
    }
	public void deleteAtIndex(int index) {		 
        if(index>=this.size)
            return;
        if(index == 0){
            this.head = getNode(index).next;
        }
        else{           
            Node cur = getNode(index);            
            Node prev = getNode(index-1);		            
            prev.next = cur.next;
        }
		this.size--;
    }
}
