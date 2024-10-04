class Solution {

    public long countOfSubstrings(String word, int k) {
        
        Map<Character, List<Integer>> map = new HashMap<>();
        char[] vowels = new char[]{'a', 'e', 'i', 'o', 'u'};
        for(char ch: vowels) map.put(ch, new LinkedList<>());
        List<Integer> cons = new LinkedList<>();

        long count = 0;

        for(int i=0; i<word.length(); i++){

            char ch = word.charAt(i);

            if(isVowel(ch, vowels)) map.get(ch).add(i);
            else cons.add(i);

            if(cons.size() > k){

                int left = cons.removeFirst();
                for(List<Integer> list: map.values()){

                    while(!list.isEmpty() && list.getFirst() < left) list.removeFirst();
                }
            }

            if(cons.size() == k && isAllVowels(map)){

                if(k == 0){

                    count += (rightBestIndex(map) - leftBestIndex(map) + 1);
                }
                else{

                    int right = Math.min(rightBestIndex(map), cons.getFirst());
                    int left = Math.min(leftBestIndex(map), cons.getFirst());
                    count += (right - left + 1);
                }
            }
        }
        return count;
    }

    private int leftBestIndex(Map<Character, List<Integer>> map){

        int bestVowel = Integer.MAX_VALUE;
        for(List<Integer> list: map.values()){
            bestVowel = Math.min(bestVowel, list.getFirst());
        }
        return bestVowel;
    }

    private int rightBestIndex(Map<Character, List<Integer>> map){

        int bestVowel = Integer.MAX_VALUE;
        for(List<Integer> list: map.values()){
            bestVowel = Math.min(bestVowel, list.getLast());
        }
        return bestVowel;
    }

    private boolean isAllVowels(Map<Character, List<Integer>> map){

        for(List<Integer> list: map.values()){

            if(list.isEmpty()) return false;
        }
        return true;
    }

    private boolean isVowel(char ch, char[] vowels){

        for(char c: vowels){

            if(ch == c) return true;
        }
        return false;
    }
}