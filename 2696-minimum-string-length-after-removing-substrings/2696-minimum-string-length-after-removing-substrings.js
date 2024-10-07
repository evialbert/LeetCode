/**
 * @param {string} s
 * @return {number}
 */
var minLength = function(s) {
    const st = [];
    const ref = { D: 'C', B: 'A' };
    for(const c of s){
        if(st.length > 0 && ref[c] === st.at(-1)) st.pop();
        else st.push(c)
    }
    return st.length;
};