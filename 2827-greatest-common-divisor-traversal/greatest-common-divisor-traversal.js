/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canTraverseAllPairs = function(nums) {
  let n = nums.length, map = new Map(), uf = new UnionFind(n);
  for (let i = 0; i < n; i++) {
    let primeFactors = getPrimeFactors(nums[i]);
    for (let factor of primeFactors) {
      if (map.has(factor)) uf.union(i, map.get(factor));
      else map.set(factor, i);
    }
  }
  return uf.size === 1;
};

function getPrimeFactors(n) {
  let res = new Set();
  for (let x = 2; (x * x) <= n; x++) {
    // loop while n is divisible by x
    while (n % x === 0) {
      res.add(x);
      n /= x;
    }
  }
  if (n > 1) res.add(n);
  return res;
}

class UnionFind {
  constructor(size) {
    this.size = size;
    this.root = Array(size);
    this.rank = Array(size);
    for (let i = 0; i < size; i++) {
      this.root[i] = i;
      this.rank[i] = 1;
    }
  }
  find(x) {
    if (this.root[x] === x) return x;
    return this.root[x] = this.find(this.root[x]);
  }
  union(x, y) {
    let rootX = this.find(x), rootY = this.find(y);
    if (rootX === rootY) return false;
    if (this.rank[rootX] < this.rank[rootY]) {
      this.root[rootX] = rootY;
    } else if (this.rank[rootX] > this.rank[rootY]) {
      this.root[rootY] = rootX;
    } else {
      this.root[rootY] = rootX;
      this.rank[rootX]++;
    }
    this.size--;
    return true;
  }
  isConnected(x, y) {
    return this.find(x) === this.find(y);
  }
}