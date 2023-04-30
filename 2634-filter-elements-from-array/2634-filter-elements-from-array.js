/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

var filter = function(arr, fn) {
    
    let arr1=[];
    for(let i=0; i<arr.length;i++){
        let n=arr[i];
        if(fn(n,i)){
        arr1.push(n);
        }
        
    }
    return arr1;
};