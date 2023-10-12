/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 0;
        int e = mountainArr.length()-1;
        
        while(s<e){
            int m = (s+e)/2;
            if(mountainArr.get(m) < mountainArr.get(m+1)){
                s = m+1;
            }
            else e = m;
        }
        
        int peak = s;
        
        s = 0;
        e = peak;
        
        int ans1 = -1;
        
        while(s <= e){
            int m = s+(e-s)/2;
            if(mountainArr.get(m) == target){
                ans1 = m;
                break;
            }
            else if(mountainArr.get(m) < target){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        
        if(ans1 != -1) return ans1;
        
        
        s = peak+1;
        e =  mountainArr.length()-1;
        
        int ans2 = -1;
        while(s <= e){
            
            int m = s+(e-s)/2;
            if(mountainArr.get(m) == target){
                ans2 = m;
                break;
            }
            else if(mountainArr.get(m) < target){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        
        return ans2;
        
    }
};