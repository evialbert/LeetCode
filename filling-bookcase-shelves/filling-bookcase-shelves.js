/**
 * @param {number[][]} books
 * @param {number} shelfWidth
 * @return {number}
 */
var minHeightShelves = function(books, shelf_width) {
    // dp array to track min height @ i-1
    let minHeights = new Array(books.length+1).fill(0);
    
    for(let i=0; i < books.length; i++) {
        let [curWidth, curHeight] = books[i];
        
        // At the very least, we can add a new shelf for each book
        minHeights[i+1] = minHeights[i] + curHeight;
        
        // We then try to backtrack through previous books to see if we can reduce the height
        for(let book=i-1; book >= 0; book--) {
            
            // If the width exceeds our shelf width, we can't go any further
            if(curWidth + books[book][0] > shelf_width) break;
            
            curWidth += books[book][0];
            curHeight = Math.max(curHeight, books[book][1]);
            
            // If our current shelf arrangement reduces the current height, we take it
            minHeights[i+1] = Math.min(minHeights[i+1], minHeights[book] + curHeight);
        }
    }
    
    return minHeights[books.length];
};