/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number[]}
 */
class Node {
    constructor(n) {
        this._n = n;
        this.dep_mask = new Array(n).fill(0);
    }

    setPd(x) {
        this.dep_mask = x;
    }

    incPd(pd) {
        this.dep_mask[pd]++;
    }

    getPd() {
        return this.dep_mask;
    }

    getPdAt(id) {
        return this.dep_mask[id];
    }

    clearPd() {
        for (let i = 0; i < this._n; i++) {
            this.dep_mask[i] = 0;
        }
    }
}

class SegTree {
    constructor(n) {
        this.sz = 1;
        while (this.sz < n) this.sz *= 2;
        this.T = new Array(2 * this.sz).fill(null).map(() => new Node(6));
    }

    mergePd(a, b) {
        const c = new Array(6).fill(0);
        for (let i = 0; i < 6; i++) c[i] = a.dep_mask[i] + b.dep_mask[i];
        return c;
    }

    update(id, pd) {
        this.updateRecursive(0, 0, this.sz, id, pd);
    }

    calc(l, r, k) {
        return this.calcRecursive(0, 0, this.sz, l, r, k);
    }

    updateRecursive(x, l, r, pos, pd) {
        if (r - l === 1) {
            this.T[x].clearPd();
            this.T[x].incPd(pd);
            return;
        }

        const m = Math.floor((l + r) / 2);
        if (pos < m) this.updateRecursive(2 * x + 1, l, m, pos, pd);
        else this.updateRecursive(2 * x + 2, m, r, pos, pd);
        this.T[x].setPd(this.mergePd(this.T[2 * x + 1], this.T[2 * x + 2]));
    }

    calcRecursive(x, l, r, ql, qr, req_pd) {
        if (ql >= r || qr <= l) return 0;
        if (l >= ql && r <= qr) return this.T[x].getPdAt(req_pd);
        const m = Math.floor((l + r) / 2);
        const le = this.calcRecursive(2 * x + 1, l, m, ql, qr, req_pd);
        const ri = this.calcRecursive(2 * x + 2, m, r, ql, qr, req_pd);
        return le + ri;
    }
}

function calcPd(x) {
    let dep = 0;
    while (x > 1n) {
        x = BigInt(x.toString(2).split('1').length - 1);
        dep++;
    }

    return dep;
}

function popcountDepth(nums, queries) {
    const n = nums.length, st = new SegTree(n);
    let id = 0, ans = [];

    for (const x of nums) {
        const pd = calcPd(x);
        if (pd <= 5) st.update(id, pd);
        id++;
    }

    for (const v of queries) {
        if (v[0] === 1) ans.push(st.calc(v[1], v[2] + 1, v[3]));
        else {
            const pd = calcPd(BigInt(v[2]));
            if (pd <= 5) st.update(v[1], pd);
        }
    }

    return ans;
}

const nums = [1n, 5n, 7n, 10n];
const queries = [
    [1, 0, 3, 1],
    [2, 2, 8],
    [1, 0, 3, 2]
];