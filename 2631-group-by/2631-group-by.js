/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    var map={}
    for (let i=0;i<this.length;i++){
        var key=fn(this[i])
        if (map.hasOwnProperty(key)){
            map[key].push(this[i])
        }else{
            map[key]=[this[i]]
        }
    }
    return map
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */