var shortestPathBinaryMatrix = function(grid) {  
    if (grid[0][0] !== 0 || grid[grid.length-1][grid.length-1] !== 0) { //if start/end points are not 0
        return -1;
    }
    
    let directions = [
            [0,1],
            [0,-1],
            [-1,0],
            [1,0],
            [-1,1],
            [1,1],
            [-1,-1],
            [1,-1]
        ];
    
    grid[0][0] = 1; //visited
    
    let queue = [];
    queue.push([0,0,1]); //start with 0,0 and number of cell 1
    
    while(queue.length > 0) {
        let [row,column, cell] = queue.shift();

        if (row === grid.length -1 && column === grid.length-1) { //reached end
            return cell;
        }

        for (const direction of directions) { //find neighbors and push to queue only if the cell is valid
            const [rowMove, columnMove] = direction;
            const nextRow = row + rowMove;
            const nextColumn = column + columnMove;

            if (nextRow >= 0 && nextColumn >= 0 && nextRow < grid.length && nextColumn < grid[0].length && grid[nextRow][nextColumn] === 0) {
                grid[nextRow][nextColumn] = 1; //mark it as visited
                queue.push([nextRow, nextColumn, cell+1]); //number of cells increased when moved to neighbor
            } 
        }
    }
    
    
    return -1; //end was not reached
};