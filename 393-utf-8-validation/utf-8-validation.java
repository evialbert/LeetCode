class Solution {
    public boolean validUtf8(int[] data) {
        int nextToCheck=0;
        for(int i=0;i<data.length;i++)
            if( nextToCheck>0 )
                if( data[i]>127 && data[i]<192 ) nextToCheck--;
                else return false;
            else
                if( data[i]<128 );
                else if( data[i]>191 && data[i]<224 ) nextToCheck=1;
                else if( data[i]>223 && data[i]<240 ) nextToCheck=2;
                else if( data[i]>239 && data[i]<248 ) nextToCheck=3;
                else return false;
        if(nextToCheck>0) return false;
        return true;
    }
}