class Solution {
    private boolean equalOrNot(int a, int b) {
        if(a==b)
        return true;
        if(a>b)
        return equalOrNot(b,a);
        char[] charA=Integer.toString(a).toCharArray();
        char[] charB=Integer.toString(b).toCharArray();
        for(int i=0;i<charB.length;i++){
            for(int j=i+1;j<charB.length;j++){
                char ch=charB[i];
                charB[i]=charB[j];
                charB[j]=ch;
                String charA1=new String(charA);
                String charB1=new String(charB);
                int aNum=Integer.parseInt(charA1);
                int bNum=Integer.parseInt(charB1);
                if(aNum==bNum)
                return true;
                ch=charB[i];
                charB[i]=charB[j];
                charB[j]=ch;
            }
        }
        return false;
    }

    public int countPairs(int[] nums) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (equalOrNot(nums[i], nums[j])) 
                    count++;
            }
        }
        return count;
    }
}