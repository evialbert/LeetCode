/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    function toBe(value) {
        if(val === value) return true;
        else throw Error("Not Equal");
    }

    function notToBe(value) {
        if(val !== value) return true;
        else throw Error("Equal");
    }

    return { toBe, notToBe };
};