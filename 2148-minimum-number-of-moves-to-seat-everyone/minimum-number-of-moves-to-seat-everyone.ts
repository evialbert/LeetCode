function minMovesToSeat(seats: number[], students: number[]): number {
    // sort the array seats and students in ascending order
    seats.sort((a, b) => a - b);
    students.sort((a, b) => a - b);

    // initialize result to count moves of students
    let result: number = 0;

    // run for in loop for seats
    for (let key in seats) {

        // take absolute difference between every element of seats and students and add in result
        result += Math.abs(seats[key] - students[key]);
    }

    // return answer result
    return result;
};