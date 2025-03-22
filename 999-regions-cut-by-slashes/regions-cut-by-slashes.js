/**
 * @param {string[]} grid
 * @return {number}
 */
var regionsBySlashes = function (grid) {
    let n = grid.length;
    let pointsPerSide = n+1;
    let totalPoints = pointsPerSide * pointsPerSide;
    let parentArr = new Array(totalPoints).fill(-1);

    for(let i=0; i<pointsPerSide; i++) {
        for(let j=0; j<pointsPerSide; j++) {
            if(i===0 || j===0 || i === pointsPerSide-1 || j === pointsPerSide-1) {
                let point = i * pointsPerSide + j;
                parentArr[point] = 0;
            }
        }
    }

    let regions = 1;
    parentArr[0] = -1;

    for(let i=0; i<n; i++) {
        for(let j=0; j<n; j++) {
            if(grid[i][j] === "/") {
                let topRight = i * pointsPerSide + (j+1);
                let bottomLeft = (i+1) * pointsPerSide + j;
                regions += union(topRight, bottomLeft, parentArr);
            }
            else if(grid[i][j] === "\\") {
                let topLeft = i * pointsPerSide + j;
                let bottomRight = (i+1) * pointsPerSide + (j+1);
                regions += union(topLeft, bottomRight, parentArr);
            }
        }
    }

    return regions;
}

function find(parentArr, node) {
    if(parentArr[node] === -1) return node;

    return parentArr[node] = find(parentArr, parentArr[node]);
}

function union(node1, node2, parentArr) {
    let p1 = find(parentArr, node1);
    let p2 = find(parentArr, node2);

    if(p1 === p2) return 1;

    parentArr[p2] = p1;
    return 0;
}