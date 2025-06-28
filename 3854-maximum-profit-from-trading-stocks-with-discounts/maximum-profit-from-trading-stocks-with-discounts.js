// /**
//  * @param {number} n
//  * @param {number[]} present
//  * @param {number[]} future
//  * @param {number[][]} hierarchy
//  * @param {number} budget
//  * @return {number}
//  */

   function maxProfit(n, present, future, hierarchy, budget) {
        // Initialize dp array with 3D array of dimensions [n+1][2][budget+1]
        const dp = Array.from({ length: n + 1 }, () => Array.from({ length: 2 }, () => Array(budget + 1).fill(0)));

        // Initialize children array with empty arrays
        const children = Array.from({ length: n + 1 }, () => []);

        const deg = Array(n + 1).fill(0);
        const parent = Array(n + 1).fill(0);

        for (const [p, c] of hierarchy) {
            children[p].push(c);
            deg[p]++;
            parent[c] = p;
        }

        const queue = [];
        for (let i = 1; i <= n; i++) {
            if (deg[i] === 0) queue.push(i);
        }

        while (queue.length > 0) {
            const curr = queue.shift();
            for (let s = 0; s <= 1; s++) {
                const price = present[curr - 1] >> s;
                let skip = Array(budget + 1).fill(0);
                let take = Array(budget + 1).fill(Number.NEGATIVE_INFINITY);

                for (let b = 0; b <= budget; b++) {
                    if (b >= price) take[b] = future[curr - 1] - price;
                }

                for (const child of children[curr]) {
                    const dpChildSkip = dp[child][0];
                    const dpChildTake = dp[child][1];

                    let newSkip = Array(budget + 1).fill(Number.NEGATIVE_INFINITY);
                    for (let b = 0; b <= budget; b++) {
                        if (skip[b] === Number.NEGATIVE_INFINITY) continue;
                        for (let spend = 0; spend <= b; spend++) {
                            newSkip[b] = Math.max(newSkip[b], skip[b - spend] + dpChildSkip[spend]);
                        }
                    }

                    let newTake = Array(budget + 1).fill(Number.NEGATIVE_INFINITY);
                    for (let b = 0; b <= budget; b++) {
                        if (take[b] === Number.NEGATIVE_INFINITY) continue;
                        for (let spend = 0; spend <= b; spend++) {
                            newTake[b] = Math.max(newTake[b], take[b - spend] + dpChildTake[spend]);
                        }
                    }

                    skip = newSkip;
                    take = newTake;
                }

                for (let i = 0; i <= budget; i++) {
                    dp[curr][s][i] = Math.max(take[i], skip[i]);
                }
            }

            const p = parent[curr];
            if (--deg[p] === 0) queue.push(p);
        }

        return dp[1][0][budget];
    }