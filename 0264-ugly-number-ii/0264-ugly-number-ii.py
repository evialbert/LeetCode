class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_numbers=[0] * n
        ugly_numbers[0]=1

        #pointers for multiples if 2,3,5
        i2=i3=i5=0

        #next multiples of 2,3 5
        multiple_of_two=2
        multiple_of_three=3
        multiple_of_five=5

        #iterate from 1 to n
        for i in range(1,n):
            #choose the min miltiple as next ugly number
            nextUgly=min(multiple_of_two,multiple_of_three,multiple_of_five)
            ugly_numbers[i]=nextUgly

            #update the pointers correspondingly
            if nextUgly==multiple_of_two:
                i2+=1
                multiple_of_two=ugly_numbers[i2] * 2

            if nextUgly==multiple_of_three:
                i3+=1
                multiple_of_three=ugly_numbers[i3] * 3

            if nextUgly==multiple_of_five:
                i5+=1
                multiple_of_five=ugly_numbers[i5] *5

        return ugly_numbers[-1]

        #time complexity=O(n)
        #space complexity=O(n)