/**
 * @param {string[]} req_skills
 * @param {string[][]} people
 * @return {number[]}
 */
var smallestSufficientTeam = function(req_skills, people) {
    //bitmask
    let skm = new Map();
    for(let [ind,skill] of req_skills.entries())
        skm.set(skill,ind);
    let dp = new Map();
    dp.set(0,[]);
    for(let [ind,ar] of people.entries()){
        let skill = 0;
        for(let sk of ar)
            skill=skill|(1<<skm.get(sk));
        for(let [val,ar] of dp){
            val=val|skill;
            if((!dp.has(val))||(dp.get(val).length>ar.length+1))
                dp.set(val,[...ar,ind]);
        }
    }
    //console.log(dp)
    return dp.get((1<<(req_skills.length))-1);
};
/*

Example 2:

req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],                         ["csharp","math"],["aws","java"]]

algorithm 000001
math      000010
java      000100
reactjs   001000
csharp    010000
aws       100000

GOAL      111111

Person 0  000111
Person 1  001011
Person 2  110100
Person 3  011000
Person 4  010010
Person 5  100100

dp
Map {
  0 => [],          
  7 => [ 0 ],       
  11 => [ 1 ],
  15 => [ 0, 1 ],
  52 => [ 2 ],
  55 => [ 0, 2 ],
  63 => [ 1, 2 ],
  24 => [ 3 ],
  31 => [ 0, 3 ],
  27 => [ 1, 3 ],
  60 => [ 2, 3 ],
  18 => [ 4 ],
  23 => [ 0, 4 ],
  54 => [ 2, 4 ],
  26 => [ 3, 4 ],
  62 => [ 2, 3, 4 ],
  36 => [ 5 ],
  39 => [ 0, 5 ],
  47 => [ 1, 5 ] }
*/