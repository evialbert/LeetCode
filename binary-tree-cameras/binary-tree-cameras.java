//State=0 --> Its a camera i.e its safe and safeguarding adjacent node
//State=1 --> Its not a camera but it is safe
//State=2 --> Its unsafe
class Solution {
    static int count=0;
    public int minCameraCover(TreeNode root) {
        count=0;
        int state=minCameraHelper(root);
		
        if(state==2)
        count++;
		
        return count;
    }
    public int minCameraHelper(TreeNode root){
        if(root==null)
        return 1;
		
        int leftState=minCameraHelper(root.left);
        int rightState=minCameraHelper(root.right);
        
        int state=1;
        if(leftState==2 || rightState==2){
            count++;
            state=0;
        }else if(leftState==1 && rightState==1){
            state=2;
        }
        return state;
    }
}