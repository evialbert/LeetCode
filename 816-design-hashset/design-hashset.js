let MyHashSet = function() {
    // intialize the size of the buckets and an array of empty buckets
    this.size = 1000;
    this.buckets = Array.from({ length: this.size }, () => []);
};

/**
 * hash function to map keys to bucket indices
 * @param {number} key
 * @return {number}
 */
MyHashSet.prototype.hash = function(key) {
    // simple modulus-based hash function
    return key % this.size;
}

/** 
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.add = function(key) {
    // get bucket index
    const bucketIndex = this.hash(key);
    const bucket = this.buckets[bucketIndex];

    // only add the key if it doesn't already exist in the bucket
    if(!bucket.includes(key)){
        bucket.push(key);
    }
};

/** 
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.remove = function(key) {
    // get bucket index
    const bucketIndex = this.hash(key);
    const bucket = this.buckets[bucketIndex];

    // check if the key is already present in the bucket
    const keyIndex = bucket.indexOf(key);
    if(keyIndex !== -1){
        // remove the key if it exist
        bucket.splice(keyIndex, 1);
    }
};

/** 
 * @param {number} key
 * @return {boolean}
 */
MyHashSet.prototype.contains = function(key) {
    // get bucket index
    const bucketIndex = this.hash(key);
    const bucket = this.buckets[bucketIndex];
    
    // check if the key exists in the bucket
    return bucket.includes(key);
};