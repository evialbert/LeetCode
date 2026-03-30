class RideSharingSystem {
    Queue<Integer> driver;
    Queue<Integer> rider;
    boolean exists[];
    public RideSharingSystem() {
        driver=new LinkedList<>();
        rider=new LinkedList<>();
        exists=new boolean[1001];
    }
    
    
    public void addRider(int riderId) {
        rider.add(riderId);
        exists[riderId]=true;
    }
    
    public void addDriver(int driverId) {
     driver.add(driverId);
    }
    
    public int[] matchDriverWithRider() {
      if(driver.isEmpty()||rider.isEmpty()){
        return new int[]{-1,-1};
      }
      while(!rider.isEmpty() && !exists[rider.peek()]){
        rider.remove();
      }
      if(!rider.isEmpty() && !driver.isEmpty()){
      int ride=rider.remove();
      int drive=driver.remove();
      exists[ride]=false;
      return new int[]{drive,ride};
    }
    return new int[]{-1,-1};
    }
    
    public void cancelRider(int riderId) {
        if(exists[riderId]){
            exists[riderId]=false;
        }
    }
}

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem obj = new RideSharingSystem();
 * obj.addRider(riderId);
 * obj.addDriver(driverId);
 * int[] param_3 = obj.matchDriverWithRider();
 * obj.cancelRider(riderId);
 */