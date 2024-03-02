class LUPrefix {
    private boolean[] videos;
    private int maxIdx = 0;

    public LUPrefix(int n) {
        this.videos = new boolean[n + 1];
    }
    
    public void upload(int video) {
        this.videos[video] = true;

        while(maxIdx < this.videos.length - 1 && videos[maxIdx + 1])
            maxIdx++;
    }
    
    public int longest() {
        return maxIdx;
    }
}

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix obj = new LUPrefix(n);
 * obj.upload(video);
 * int param_2 = obj.longest();
 */