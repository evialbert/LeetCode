/**
 * @param {number[][]} nums1
 * @param {number[][]} nums2
 * @return {number[][]}
 */
const updateMap = (map, arr) => {
    for(let i=0;i<arr.length;i++){
        let key = arr[i][0];
        if(map.has(key)){
            let currVal = map.get(key);
            currVal += arr[i][1];
            map.set(key, currVal)
        }else map.set(key, arr[i][1])
    }
    return map;
}

const mergeArrays = (nums1, nums2) => {
    const map = new Map();
    updateMap(map, nums1);
    updateMap(map, nums2);
    return Array.from(map).sort((a,b) => a[0] - b[0])
};