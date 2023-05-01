/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
	return async function(...args) {
        let a = fn(...args);
        let b = new Promise((res,rej)=>{
            setTimeout(()=>{
                rej("Time Limit Exceeded");
            },t);
        })
        return Promise.race([a,b]);
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */