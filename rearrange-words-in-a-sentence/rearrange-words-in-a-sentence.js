/**
 * @param {string} text
 * @return {string}
 */
var arrangeWords = function(text) {
    // turn string into an array of words. "Leetcode is cool" becomes ["Leetcode", "is", "cool"]
    text = text.split(" ")
	
	// turn the first letter of the first word to lowercase. text[0] = "Leetcode" becomes "leetcode".
    text[0] = text[0].charAt(0).toLowerCase() + text[0].slice(1)
	
	// sort array by length (number of characters) of each element
    text.sort((a, b) => a.length - b.length)
	
	// turn first letter of the first word to uppercase.
    text[0] = text[0].charAt(0).toUpperCase() + text[0].slice(1)
	
	// Join the array into a single string, putting a single space " " between elements
    return text.join(" ")
};