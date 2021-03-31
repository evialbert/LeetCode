// Helper to find the next board based on the inserted color.
// I've tried to clean this up in various ways but the runtime skyrockets
const getNextBoard = (board, insertIdx, color) => {
  const stack = [];
  
  for (let i = 0; i < board.length; i += 1) {
    if (i === insertIdx) {
      if (stack[stack.length - 1] === color) {
        stack[stack.length - 1] += color;
      } else {
        stack.push(color);
      }
    }
    

    if (!stack.length || board[i] !== stack[stack.length - 1][0]) {
      stack.push(board[i]);
    } else if (board[i] !== board[i + 1]) {
      stack[stack.length - 1] += board[i];
      if (stack[stack.length - 1].length >= 3) stack.pop();
    } else {
      stack[stack.length - 1] += board[i];
    }
  }

  return stack.join('');
}

// BFS
var findMinStep = function (board, hand) {
  const colorLookup = 'RYBGW';

  // using an array with counts of each color in hand instead of string manipulation
  const handCounts = hand.split('')
    .reduce((counts, color) => {
      counts[colorLookup.indexOf(color)] += 1;
      return counts;
    }, [0, 0, 0, 0, 0]);

  const visited = new Set();
  const queue = [[board, handCounts]];

  while (queue.length) {
    const [currBoard, currCounts] = pop(queue);

    for (let i = 0; i < currCounts.length; i += 1) {
	  // none of this color in hand
      if (!currCounts[i]) continue;
      const color = colorLookup[i];
      
	  // try inserting the color into each slot
	  for (let j = 0; j < currBoard.length; j += 1) {
        const nextBoard = getNextBoard(currBoard, j, color)
		const nextCounts = [...currCounts];
        nextCounts[i] -= 1;
		
		// if our next board is empty, we're done.
		// calculate the diff between starting and next hand counts
        if (!nextBoard) return hand.length - nextCounts.reduce((sum, count) => sum + count, 0);
        if (visited.has(nextBoard)) continue;
        
		visited.add(nextBoard);
        push([nextBoard, nextCounts], queue);
      }
    }
  }

  return -1;
}


// priority queue.
const pop = (heap) => {
  const last = heap.length - 1;
  [heap[0], heap[last]] = [heap[last], heap[0]];
  const res = heap.pop();
  siftDown(heap);
  return res;
}

const push = (val, heap) => {
  heap.push(val);
  siftUp(heap);
}

const siftUp = (heap) => {
  let current = heap.length - 1;
  while (current > 0) {
    const parent = Math.ceil(current / 2) - 1;
    let next = current;
    if (heap[parent][0].length > heap[next][0].length) next = parent;

    if (next !== current) {
      [heap[next], heap[current]] = [heap[current], heap[next]];
      current = next;
    } else break;
  }
}

const siftDown = (heap) => {
  let current = 0;
  while (true) {
    const left = current * 2 + 1;
    const right = left + 1;
    let next = current;

    if (heap[left] && heap[left][0].length < heap[next][0].length) next = left;
    if (heap[right] && heap[right][0].length < heap[next][0].length) next = right;

    if (next !== current) {
      [heap[next], heap[current]] = [heap[current], heap[next]];
      current = next;
    } else break;
  }
}