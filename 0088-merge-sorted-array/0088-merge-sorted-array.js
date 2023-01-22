/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(arr1, n1, arr2, n2) {

     let i = n1-1, j = n2-1, k = n1+n2 -1; 
     
     
        while (i>=0 && j >=0) 
        { 
            if (arr1[i] >= arr2[j]) 
                arr1[k--] = arr1[i--]; 
            else
                arr1[k--] = arr2[j--]; 
        } 
      
        while (i >= 0) 
            arr1[k--] = arr1[i--]; 
      
        while (j >= 0) 
            arr1[k--] = arr2[j--]; 

            return;
    
};