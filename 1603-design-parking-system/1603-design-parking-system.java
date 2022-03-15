class ParkingSystem {
    int ar[] = new int[3];
    public ParkingSystem(int big, int medium, int small) {
        ar[0]=big;
        ar[1]=medium;
        ar[2]=small;
    }
    
    public boolean addCar(int carType) {
        if(ar[carType-1]>0)
        {
            ar[carType-1]--;
            return true;
        }
        return false;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */