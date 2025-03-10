/**
 * @param {number[]} nums
 * @return {number[]}
 */
var transformArray = function(nums) {
    let odd = 0;
    let even = 0;
    nums.forEach((no) => no%2 === 0? ++even: ++odd);
    const res = new Array(even).fill(0);
    res.push(...(new Array(odd).fill(1)));
    return res;
};