/**
 * @param {number[]} seats
 * @param {number[]} students
 * @return {number}
 */
var minMovesToSeat = function(seats, students) {
    let ans = 0, sub;
    seats.sort((a,b)=>(a-b));
    students.sort((a,b)=>(a-b));
	
    for(let i=0;i<seats.length;i++) {
        if(seats[i] >= students[i]) sub = seats[i] - students[i];
        else sub = students[i] - seats[i];
        ans+=sub;
    }
    return ans;
};
