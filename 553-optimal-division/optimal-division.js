/**
 * @param {number[]} nums
 * @return {string}
 */
const optimalDivision = (n) => {
    let len = n.length;
    let ans = "";
    ans += n[0];
    if(len === 0) return "";
    if(len === 1) return ans;
    if(len > 2){
        ans += '/(';
    }else{
        ans += '/';
    }

    for(let i=1;i<len;i++){
        ans += n[i];
        if( i !== len - 1) ans += '/';
    }
    
    if(len > 2) ans += ')';

    return ans;
};