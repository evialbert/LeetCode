/**
 * @param {number} k
 * @return {character}
 */
var kthCharacter = function (k) {
    let str = "a"
    while (str.length < k) {
        let n = str.length
        for (let i = 0; i < n; ++i) {
            let a = ""
            if (str[i] == "z") {
                a = "a"
            } else {
                a = String.fromCharCode(str[i].charCodeAt(0) + 1)
            }
            str = str + a
        }
    }

    return str[k - 1]
};