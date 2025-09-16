function subarrayMajority(nums: number[], queries: number[][]): number[] {
  const n = nums.length, q = queries.length;

  const vals = Array.from(new Set(nums)).sort((a, b) => a - b);
  const comp = new Map(vals.map((v, i) => [v, i]));
  const arr = nums.map(v => comp.get(v)!);
  const m = vals.length;

  const B = Math.max(1, Math.floor(Math.sqrt(n)));
  const qs = queries.map((it, i) => [it[0], it[1], it[2], i] as [number, number, number, number]);
  qs.sort((a, b) => {
    const ab = Math.floor(a[0] / B), bb = Math.floor(b[0] / B);
    if (ab !== bb) return ab - bb;
    return (ab & 1) ? b[1] - a[1] : a[1] - b[1];
  });

  const freq = new Uint32Array(m);
  const freqCount = new Uint32Array(n + 1); // counts for frequencies >= 1
  const valBlockSize = Math.max(1, Math.floor(Math.sqrt(m)));
  const valBlocks = Math.ceil(m / valBlockSize);
  const blockMax = new Uint32Array(valBlocks); // upper bounds; lazily decreased

  let curL = 0, curR = -1, maxFreq = 0;

  const add = (idx: number) => {
    const v = arr[idx];
    const f = freq[v];
    if (f >= 1) freqCount[f]--;
    const nf = f + 1;
    freq[v] = nf;
    freqCount[nf]++;
    if (nf > maxFreq) maxFreq = nf;
    const b = (v / valBlockSize) | 0;
    if (nf > blockMax[b]) blockMax[b] = nf;
  };

  const remove = (idx: number) => {
    const v = arr[idx];
    const f = freq[v];
    if (f >= 1) freqCount[f]--;
    const nf = f - 1;
    freq[v] = nf;
    if (nf >= 1) freqCount[nf]++;
    while (maxFreq > 0 && freqCount[maxFreq] === 0) maxFreq--;
    // leave blockMax stale; fix lazily when querying
  };

  const getMinAtMaxFreq = (): number => {
    if (maxFreq === 0) return -1;
    for (let b = 0; b < valBlocks; b++) {
      if (blockMax[b] < maxFreq) continue;
      const start = b * valBlockSize;
      const end = Math.min(m, start + valBlockSize);
      let trueMax = 0;
      for (let v = start; v < end; v++) {
        const f = freq[v];
        if (f > trueMax) trueMax = f;
        if (f === maxFreq) return vals[v];
      }
      blockMax[b] = trueMax; // deflate stale bound
    }
    return -1;
  };

  const ans = new Array<number>(q);
  for (const [l, r, t, i] of qs) {
    while (curL > l) add(--curL);
    while (curR < r) add(++curR);
    while (curL < l) remove(curL++);
    while (curR > r) remove(curR--);

    ans[i] = maxFreq >= t ? getMinAtMaxFreq() : -1;
    // if multiple values have maxFreq, returns the smallest by value
  }
  return ans;
}