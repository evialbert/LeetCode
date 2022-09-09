class Robot {

    int height;
    int width;
    int totalSquares;
    int currPos;
    boolean started;
    
    public Robot(int width, int height) {
        this.width = width;
        this.height = height;
        
        started = false;
        currPos = 0;
        
        totalSquares = 2 * width + 2 * height - 4;  
    }
    
    public void step(int num) {
        
        currPos += num; 
 
        if (currPos > 0){
            started = true; 
        }
        
        currPos = currPos % totalSquares;
    }
    
    public int[] getPos() {
        
        if (currPos < width){
            return new int[]{currPos, 0};
        }
        
        if (currPos >= width - 1 && currPos <= width + height - 2){
            return new int[]{width - 1, currPos - width + 1};
        }
        
        if (currPos >= width + height - 2 && currPos < 2 * width + height - 2){
            return new int[]{width - (currPos - (width + height - 2)) - 1, height - 1};
        }
        
        if (currPos >= 2 * width + height - 4){
            return new int[]{0, (totalSquares - currPos)};
        }
        
        return null;
        
    }
    
    public String getDir() {
        
        if (currPos == 0 && started){
            return "South";
        }
        else if (currPos < width){
            return "East";
        }
        else if (currPos >= width - 1 && currPos <= width + height - 2){
            return "North";
        }
        else if (currPos >= width + height - 2 && currPos < 2 * width + height - 2){
            return "West";
        }
        else {
            return "South";
        }        
    }
}

/**
 * Your Robot object will be instantiated and called as such:
 * Robot obj = new Robot(width, height);
 * obj.step(num);
 * int[] param_2 = obj.getPos();
 * String param_3 = obj.getDir();
 */