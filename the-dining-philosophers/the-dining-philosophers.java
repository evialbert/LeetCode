class DiningPhilosophers {

    private static final int COUNT = 5;

    private int current = 0;

    public synchronized void wantsToEat(
            int philosopher,
            Runnable pickLeftFork,
            Runnable pickRightFork,
            Runnable eat,
            Runnable putLeftFork,
            Runnable putRightFork
    ) throws InterruptedException {
        while (current != philosopher) {
            wait();
        }
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        current = (current + 1) % COUNT;
        notifyAll();
    }
}