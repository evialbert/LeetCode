/**
 * @param {string} s
 * @return {string}
 */
const log = console.log;
var removeDuplicateLetters = function(s) {
  let frequency = {};
  for(let c of s) { 
    frequency[c] = (frequency[c] + 1) || 1; // calculate the frequency (number of times a letter appeared)
  }
  let answer = [];
  const map = {}; // "to track the letter already in solution set or not"
  for(let i = 0; i < s.length; i++) {
    frequency[s[i]]--;
    if(s[i] in map) { // if it already in solution set continue.
      continue;
    }
    let top = answer.slice(-1)[0];
    while(top && frequency[top] && top > s[i] && answer.length) { // check the top bigger than current letter
      delete map[top]; // delete the letter. it will be added in the future. as frequency still positive
      answer.pop(); // pop the last element.
      top = answer.slice(-1)[0];
    }
    answer.push(s[i]); // push current letter 
     
    map[s[i]] = 1; //. update map that letter included in the solution set
  }
  return answer.join('');
};