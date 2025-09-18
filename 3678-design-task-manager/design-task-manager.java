class TaskManager {
    private Map<Integer, Task> taskMap; // taskId -> current Task
    private PriorityQueue<Task> maxHeap; // Max-heap by priority then taskId

    public TaskManager(List<List<Integer>> tasks) {
        taskMap = new HashMap<>();
        maxHeap = new PriorityQueue<>((a, b) -> {
            if (a.priority != b.priority) {
                return Integer.compare(b.priority, a.priority); // Higher priority first
            }
            return Integer.compare(b.taskId, a.taskId); // Larger taskId first
        });
        
        for (List<Integer> task : tasks) {
            addTask(task.get(0), task.get(1), task.get(2));
        }
    }
    
    public void add(int userId, int taskId, int priority) {
        addTask(userId, taskId, priority);
    }
    
    private void addTask(int userId, int taskId, int priority) {
        Task task = new Task(userId, taskId, priority);
        taskMap.put(taskId, task);
        maxHeap.offer(task);
    }
    
    public void edit(int taskId, int newPriority) {
        // Mark old task invalid and create new one
        Task oldTask = taskMap.get(taskId);
        if (oldTask != null) {
            oldTask.invalidate();
        }
        addTask(oldTask.userId, taskId, newPriority);
    }
    
    public void rmv(int taskId) {
        Task task = taskMap.remove(taskId);
        if (task != null) {
            task.invalidate();
        }
    }
    
    public int execTop() {
        while (!maxHeap.isEmpty()) {
            Task task = maxHeap.poll();
            if (task.isValid()) {
                taskMap.remove(task.taskId);
                return task.userId;
            }
        }
        return -1;
    }
}

class Task {
    int userId;
    int taskId;
    int priority;
    boolean valid;
    
    public Task(int userId, int taskId, int priority) {
        this.userId = userId;
        this.taskId = taskId;
        this.priority = priority;
        this.valid = true;
    }
    
    public void invalidate() {
        this.valid = false;
    }
    
    public boolean isValid() {
        return valid;
    }
}