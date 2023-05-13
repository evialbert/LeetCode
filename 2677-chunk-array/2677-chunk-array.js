/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    let ans = [];
    let vec = [];
    let k = size;
    let n = arr.length;

    for(let i=0; i<n; i++){
        vec.push(arr[i]);
        k--;
        if(k == 0){
            ans.push(vec);
            vec = [];
            k = size;
        }
    }
    if(vec.length != 0) ans.push(vec);
    return ans;
};