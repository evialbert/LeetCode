function filterOccupiedIntervals(occupiedIntervals: number[][], freeStart: number, freeEnd: number): number[][] {
    occupiedIntervals.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

    const merged = [];

    let prevMinStart = occupiedIntervals[0][0];
    let prevMaxEnd = occupiedIntervals[0][1];
    for (let i = 1; i < occupiedIntervals.length; i++) {
        const [start, end] = occupiedIntervals[i];
        if (start > prevMaxEnd + 1) {
            pushToMerged();
            prevMinStart = start;
            prevMaxEnd = end;
        } else {
            prevMinStart = Math.min(prevMinStart, start);
            prevMaxEnd = Math.max(prevMaxEnd, end);
        }
    }

    function pushToMerged() {
        if (freeStart <= prevMinStart && freeEnd >= prevMaxEnd) {
            // FS S E FE - when interval is inside free interval => do nothing
        } else if (freeStart > prevMinStart && freeEnd < prevMaxEnd) {
            // S FS FE E - when free interval is inside interval => push 2 parts
            merged.push([prevMinStart, freeStart - 1]);
            merged.push([freeEnd + 1, prevMaxEnd]);
        } else if (freeEnd < prevMinStart || freeStart > prevMaxEnd) {
            // FS FE S E  FS FE - when intervals does not intersect => push interval as it is
            merged.push([prevMinStart, prevMaxEnd]);
        } else if (freeStart <= prevMinStart && freeEnd < prevMaxEnd) {
            // FS S FE E - when first part is intersected => push the second one
            merged.push([freeEnd + 1, prevMaxEnd]);
        } else if (freeStart > prevMinStart && freeEnd >= prevMaxEnd) {
            // S FS E FE - when second part is intersected => push the first one
            merged.push([prevMinStart, freeStart - 1]);
        }
    }

    pushToMerged();

    return merged;
};