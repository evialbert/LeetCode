/**
 * @param {number[][]} board
 * @return {number}
 */
function slidingPuzzle(board) {

    const target = [1, 2, 3, 4, 5, 0];
    
    const start = [];
    for (let row of board) {
        start.push(...row);
    }

    if (start.toString() === target.toString()) {
        return 0;
    }

    const directions = [-1, 1, -3, 3]; 

    let queue = [[start, 0]];  
    let visited = new Set();
    visited.add(start.toString());  


    while (queue.length > 0) {
        let [current, moves] = queue.shift();

        let emptyPos = current.indexOf(0);

        for (let direction of directions) {
            let newPos = emptyPos + direction;

            if (newPos >= 0 && newPos < 6 && !(emptyPos % 3 === 0 && direction === -1) && !(emptyPos % 3 === 2 && direction === 1)) {
                let newBoard = [...current];

                [newBoard[emptyPos], newBoard[newPos]] = [newBoard[newPos], newBoard[emptyPos]];
                if (newBoard.toString() === target.toString()) {
                    return moves + 1;
                }
                if (!visited.has(newBoard.toString())) {
                    visited.add(newBoard.toString());

                    queue.push([newBoard, moves + 1]);
                    
                }
            }
        }
    }
    return -1;
}
