/**
 * @param {number} n
 * @param {number[][]} pick
 * @return {number}
 */
var winningPlayerCount = function (n, pick) {
	const g = Array.from({ length: n }, () => new Array(12).fill(0));
	for (const [player, color] of pick) {
		g[player][color] = g[player][color] || 0;
		g[player][color]++;
	}
	let playerCount = 0;
	for (let i = 0; i < n; i++) {
		const sameColorBallCounts = Math.max(...g[i]);
		if (sameColorBallCounts > i) playerCount++;
	}
	return playerCount;
};
