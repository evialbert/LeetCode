/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */

const countPaths = function (n, roads) {
  // Mode value stored
  const mod = 10 ** 9 + 7;
  // graph array of array
  let graph = new Array(n).fill().map((_) => new Array());
  // created adj matrix
  for (let road of roads) {
    let u = road[0];
    let v = road[1];
    // weight
    let w = road[2];
    graph[u].push([v, w]);
    graph[v].push([u, w]);
  }

  // initially set all as time infinity
  let time = new Array(n).fill(Infinity);
  // initially set all as ways to Zero
  let ways = new Array(n).fill(0);

  // queue with source, time
  let pq = [[0, 0]];
  // both set as 0 & 1 as for zero time will be Zero & No of ways to reach zero is only 1
  time[0] = 0;
  ways[0] = 1;

  while (pq.length) {
    let [currentNode, currentTime] = pq.shift();

    for (let [nextNode, w] of graph[currentNode]) {
      let newTime = currentTime + w;

      if (newTime < time[nextNode]) {
        time[nextNode] = newTime;
        pq.push([nextNode, newTime]);
        // alternative of priority queue DS
        pq.sort((a, b) => a[1] - b[1]);
        ways[nextNode] = ways[currentNode];
      } else if (newTime === time[nextNode]) {
        ways[nextNode] += ways[currentNode] % mod;
      }
    }
  }
  return ways[n - 1] % mod;
};