/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

var searchMatrix = function(matrix, target) {
    for(let arr of matrix){
       if(binarySearch(arr,target)){
        return true
       }
       
    }
    return false
};
function binarySearch(array,target){
 let leftIndex = 0
 let rightIndex = array.length-1
 while(leftIndex <= rightIndex ){
    let mid = Math.floor((leftIndex+rightIndex)/2)
    if(target == array[mid]){
        return true
    }else if(target < array[mid]){
        rightIndex= mid-1
    }else{
        leftIndex = mid+1
    }
 }
    
}