/**
 * @param {number[]} hours
 * @return {number}
 */
var countCompleteDayPairs = function(hours) {
    
    const mods = new Array(25).fill(0);

    let days = 0;

    for(const hour of hours) {

        const mod = hour % 24;

        days += mods[(24 - mod) % 24];
        mods[mod]++;
    }
    
    return days;
};