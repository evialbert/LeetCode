/**
 * @param {number} n
 * @param {number[][]} lamps
 * @param {number[][]} queries
 * @return {number[]}
 */
const gridIllumination = (N, lamps, queries) => {
  const ans = [];
  const set = new Set();
  const row = {};
  const col = {};
  const d1 = {};
  const d2 = {};

  for (const lamp of lamps) {
    const [x, y] = lamp;
    const key = `${x}-${y}`;
    if (!set.has(key)) {
      set.add(key);
      row[x] = (row[x] || 0) + 1;
      col[y] = (col[y] || 0) + 1;
      d1[x + y] = (d1[x + y] || 0) + 1;
      d2[x - y] = (d2[x - y] || 0) + 1;
    }
  }

  for (const query of queries) {
    const [x, y] = query;
    if (row[x] > 0 || col[y] > 0 || d1[x + y] > 0 || d2[x - y] > 0) {
      ans.push(1);
      for (let i = x - 1; i <= x + 1; i++) {
        for (let j = y - 1; j <= y + 1; j++) {
          const key = `${i}-${j}`;
		  
          if (set.has(key)) {
            set.delete(key);
            row[i]--;
            col[j]--;
            d1[i + j]--;
            d2[i - j]--;
          }
		  
        }
      }
    } else {
      ans.push(0);
    }
  }
  
  return ans;
};