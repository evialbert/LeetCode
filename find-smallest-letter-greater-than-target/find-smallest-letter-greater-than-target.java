class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int index = 0;
        for (; index < letters.length; index++) {
            if (letters[index] > target) break;
        }
        return index == letters.length ? letters[0] : letters[index];
    }
}
