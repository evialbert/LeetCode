/**
 * @param {number[]} apple
 * @param {number[]} capacity
 * @return {number}
 */
var minimumBoxes = function(apple, capacity) {
        let tot = apple.reduce((a, b) => a + b);
    capacity.sort((a, b) => b - a);
    
let hello =0

while(tot>0){
    tot-=capacity[hello++];
}
    
    return hello;
};