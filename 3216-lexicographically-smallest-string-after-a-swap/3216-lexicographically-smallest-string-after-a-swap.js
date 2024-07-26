/**
 * @param {string} s
 * @return {string}
 */
var getSmallestString = function (s) {
    let arr = s.split('');

    function swap(arr, i, j) {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    let n = arr.length;
    for (let i = 0; i < n - 1; i++) {
        if (parseInt(arr[i]) % 2 === parseInt(arr[i + 1]) % 2 && arr[i] > arr[i+ 1]) {
            swap(arr, i + 1, i);
            break;
        }
    }
    return arr.join('');
}