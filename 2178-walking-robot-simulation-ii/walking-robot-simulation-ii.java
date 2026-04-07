class Robot {
    private int w, h;
    private int x = 0, y = 0;
    private int index = 0;
    private int rot;
    private String dir = "East";

    public Robot(int width, int height) {
        this.w = width;
        this.h = height;
        this.rot = width * 2 + height * 2 - 4;
    }

    public void step(int num) {
        this.index = (this.index + num) % this.rot;

        if (this.index == 0) {
            this.dir = "South";
            this.x = 0;
            this.y = 0;
        } else if (this.index < this.w) {
            this.dir = "East";
            this.x = this.index;
            this.y = 0;
        } else if (this.index < this.w + this.h - 1) {
            this.dir = "North";
            this.x = this.w - 1;
            this.y = this.index - (this.w - 1);
        } else if (this.index < 2 * this.w + this.h - 2) {
            this.dir = "West";
            this.x = (2 * this.w + this.h - 3) - this.index;
            this.y = this.h - 1;
        } else {
            this.dir = "South";
            this.x = 0;
            this.y = this.rot - this.index;
        }
    }

    public int[] getPos() {
        return new int[]{this.x, this.y};
    }

    public String getDir() {
        return this.dir;
    }
}