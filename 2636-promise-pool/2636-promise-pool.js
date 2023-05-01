/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
const next = async () => {
        if (!functions.length) {
            return Promise.resolve();
        }

        await functions.shift()();
        await next();
    }


    await Promise.all(new Array(n).fill(0).map(next));
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */