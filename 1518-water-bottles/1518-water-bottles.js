/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
    let drinks = numBottles;
    let emptyBottles = numBottles;
    
    while(emptyBottles >= numExchange) {
        const newFullBottles = (emptyBottles / numExchange) | 0;
        emptyBottles = emptyBottles % numExchange + newFullBottles;
        drinks += newFullBottles;
    }
    
    return drinks;
};