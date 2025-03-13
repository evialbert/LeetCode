/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
const openLock = function(deadends, target) {
    const pow10=[1,10,100,1000],cache=new Array(10000).fill(0),dest=parseInt(target);
    for (let i=0;i<deadends.length;i++) cache[parseInt(deadends[i])]=1;
    let steps=0,nums=[0];
    if (cache[0]==1 || cache[dest]==1) return -1;
    cache[0]=1;
    while (nums.length) {
        const newnums=[];
        for (let i=0;i<nums.length;i++) {
            const num=nums[i];
            if (num==dest) return steps;
            else {
                for (let i=0;i<4;i++) {
                    const x=(~~(num/pow10[i]))%10;
                    let number;
                    if (x==9) number=num-9*pow10[i];
                    else number=num+pow10[i];
                    if (!cache[number]) newnums.push(number);
                    cache[number]=1;
                    if (x==0) number=num+9*pow10[i];
                    else number=num-pow10[i];
                    if (!cache[number]) newnums.push(number);
                    cache[number]=1;
                }
            }
        }
        nums=newnums;
        steps++;
    }
    return -1;
};