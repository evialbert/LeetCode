/**
 * @param {string} date
 * @return {string}
 */
var convertDateToBinary = function(date) {
    return date.split('-').reduce((t,i)=>{
      return t + '-'+ Number(i).toString(2)
    },'').slice(1)
};

console.log(convertDateToBinary("2024-03-29"))