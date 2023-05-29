class ParkingSystem {
public:
int big,medium,small;
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->medium=medium;
        this->small=small;
    }
    
    bool addCar(int carType) {

        if(carType==1){
            if(big>0){
                big--;
                return true;
                
            }
        }else if(carType==2){
            if(medium>0){
                medium--;
                return true;
                
            }
        }else if(carType==3){
            if(small>0){
                small--;
                return true;
                
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */