/**
 * @param {number[]} days
 * @param {number[]} costs
 * @return {number}
 */
var mincostTickets = function (days, costs) {
  // Create an array to store the minimum cost for each day of the year
  const minCosts = new Array(days[days.length - 1] + 1).fill(0);
  
  // Create a set of the days you will be traveling on for faster lookup
  const travelDays = new Set(days);
  
  // Loop through each day of the year, starting from day 1
  for (let day = 1; day < minCosts.length; day++) {
    // If you're not traveling on this day, the minimum cost is the same as the previous day
    if (!travelDays.has(day)) {
      minCosts[day] = minCosts[day - 1];
    } else {
      // If you're traveling on this day, calculate the minimum cost by comparing the costs
      // of buying a 1-day pass, a 7-day pass, or a 30-day pass on this day, and adding the
      // cost of the minimum cost of traveling up to 1, 7, or 30 days ago respectively
      minCosts[day] = Math.min(
        minCosts[day - 1] + costs[0],
        minCosts[Math.max(0, day - 7)] + costs[1],
        minCosts[Math.max(0, day - 30)] + costs[2]
      );
    }
  }
  
  // Return the minimum cost for traveling on all the given days
  return minCosts[minCosts.length - 1];
};