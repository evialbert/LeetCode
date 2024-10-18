/**
 * @param {string} s
 * @return {string}
 */
var findLatestTime = function(s) {

    const splitted = s.split("");
    
        if(splitted[0] === "?") {
            if(splitted[1] <= 1) {
                splitted[0] = "1";
            } else if(splitted[1] > 1) {
                splitted[0] = "0";
            } else {
                splitted[0] = "1";
            }
        }
        if(splitted[1] === "?") {
            if(splitted[0] == 1) {
                splitted[1] = "1";
            } else if(splitted[0] == 0) {
                splitted[1] = "9";
            } else {
                splitted[1] = "1";
            }
        }
        if(splitted[3] === "?") {
            splitted[3] = "5";
        }
        if(splitted[4] === "?") {
            splitted[4] = "9";
        }

    return splitted.join("");
};