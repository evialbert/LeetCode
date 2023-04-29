/**
 * @param {Function} fn
 */
function memoize(fn) {
    const root = new Map();
    return function(...args) {
        let cache = root;
        for (const arg of args) {
            if(!cache.has(arg)) cache.set(arg, new Map());
            cache = cache.get(arg);
        }
        let key = '_cache_';
        if (!cache.has(key)) cache.set(key, fn(...args));
        return cache.get(key);
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */