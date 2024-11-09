/**
 * @param {number} capacity
 */
class Node{
    constructor(val = null, key = null){
        this.prev = null;
        this.next = null;
        this.val = val;
        this.key = key;
    }
}

var LRUCache = function(capacity) {
    this.cache = {}
    this.capacity = capacity;
    this.head = new Node()
    this.tail = new Node()
    this.head.next = this.tail;
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
   const node = this.cache[key];
   if(!node) return -1
   this.remove(node)
   this.add(node)
   return node.val;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if(this.cache[key] !== undefined){
        this.remove(this.cache[key])
    }else if(this.cache[key] === undefined && this.capacity > 0){
        this.capacity--
    }else if(this.cache[key] === undefined && this.capacity === 0){
        const lastNode = this.tail.prev;
        delete this.cache[lastNode.key]
        this.remove(lastNode);
    }
    const newNode = new Node(value, key)
    this.add(newNode)
    this.cache[key] = newNode;
};

LRUCache.prototype.add = function(node){
    const nextNode = this.head.next;
    this.head.next = node;
    node.prev = this.head;
    node.next = nextNode;
    nextNode.prev = node;
}

LRUCache.prototype.remove = function(node){
    const prevNode = node.prev;
    const nextNode = node.next;
    prevNode.next = nextNode;
    nextNode.prev = prevNode;
    return node;
}

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */