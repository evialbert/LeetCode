/**
 * @param {number} row
 * @param {number} col
 * @param {number[][]} cells
 * @return {number}
 */
var latestDayToCross = function(row, col, cells) {
    let left = 1, right = cells.length;
    let lastDay = 0;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (canCross(mid, row, col, cells)) {
            lastDay = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return lastDay;
};

function canCross(day, row, col, cells) {
    const grid = Array.from({ length: row }, () => new Uint8Array(col).fill(0));
    
    
    for (let i = 0; i < day; i++) {
        grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
    }

    const queue = [];
    for (let c = 0; c < col; c++) {
        if (grid[0][c] === 0) {
            queue.push([0, c]);
            grid[0][c] = 1; 
        }
    }

    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    let head = 0;
    while (head < queue.length) {
        const [r, c] = queue[head++];
        
        if (r === row - 1) return true; 

        for (const [dr, dc] of directions) {
            const nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] === 0) {
                grid[nr][nc] = 1; 
                queue.push([nr, nc]);
            }
        }
    }

    return false;
};