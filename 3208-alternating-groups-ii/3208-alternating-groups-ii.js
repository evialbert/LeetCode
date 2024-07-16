/**
 * @param {number[]} colors
 * @param {number} k
 * @return {number}
 */
var numberOfAlternatingGroups = function(colors, k) {
    let left = [0];
    let curr = 0;
    
    for(let i=1;i<colors.length;i++) {
        if(colors[i]===colors[i-1]) {
            curr = 1-curr;
        }
        left.push(curr);
    }

    for(let i=0;i<k-1;i++) {
        if(i===0) {
            if(colors[colors.length-1]===colors[i]) {
                curr = 1-curr;
            }
        }else {
            if(colors[i]===colors[i-1]) {
                curr = 1-curr;
            }
        }
        left.push(curr);
    }

    // yaha se sab easy hai
    let res = 0;
    let sum = 0;
    
    for(let i=0;i<k;i++) {
        sum+=left[i];
    }
    
    if(sum===0 || sum===k) res++;
    
    for(let j=k;j<left.length;j++) {
        sum-=left[j-k];
        sum+=left[j];
        if(sum===0 || sum===k) res++;
    }
    
    return res;
};