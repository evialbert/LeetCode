/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    return function curried(...args) {
        if (fn.length === args.length) {
            return fn(...args);
        } else {
            return function(...newArgs) {
                return curried(...args, ...newArgs)
            }
        }
    };
};