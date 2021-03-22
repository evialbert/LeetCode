/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {

    /**
    Lets take input is 1000.
    The count will get incremented by 1, everytime the method rand10() is called.
    The idea here is to distribute values 1 to 10 equally.
    
    Let's say rand10() is called for 447th time.
    At this point c = 447
    and 447%10 + 1 = 7 + 1 = 8 will be returned.
    
    
    */
    int count = 1;
    
    public int rand10() {
        return (count++)%10 + 1;
    }
}