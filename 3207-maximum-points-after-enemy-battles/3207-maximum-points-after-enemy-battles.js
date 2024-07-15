/**
 * @param {number[]} enemyEnergies
 * @param {number} currentEnergy
 * @return {number}
 */
var maximumPoints = function(enemyEnergies, currentEnergy) {

    let minEnergy = Infinity, totalEnergy = 0;

    for(let i = 0; i < enemyEnergies.length; i++) {

        minEnergy = Math.min(minEnergy, enemyEnergies[i]);
        totalEnergy += enemyEnergies[i];
    }

    if(currentEnergy < minEnergy) return 0;

    currentEnergy += totalEnergy - minEnergy; //last enemy cannot be consumed

    return Math.floor(currentEnergy / minEnergy);
};