
var TimeLimitedCache = function() {
    
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    if(!this[key]){
        this[key] = {
            value, duration, ttl: duration + Date.now()
            }
        return false;
    }
    const {value: v, ttl} = this[key];
    if(Date.now() >= ttl){
        this[key] = {
            value, duration, ttl: duration + Date.now()
            }
        return false
    }
    this[key] = {
             value, duration, ttl: duration + Date.now()
        }
    return true;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if(!this[key]) return -1;
    const {value, ttl} = this[key];
    if(Date.now() >= ttl){
        delete this[key];
        return -1;
    }
    return value;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    const keys = Object.keys(this);
    let nonExpiredKeys = 0;
    keys.forEach(k=>{
        const {ttl} = this[k];
        if(Date.now() >= ttl){
            delete this[k];
        }
        else nonExpiredKeys++;
    })
    return nonExpiredKeys;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */