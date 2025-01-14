const findThePrefixCommonArray = (A, B, f = new Array(A.length + 1).fill(0)) =>
    A.map((a, i) => (f[a] += 1,f[B[i]] += 2,f.filter(v => v == 3).length));