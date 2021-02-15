class MaxQueue {
    
    LinkedList<Integer> queue;
    LinkedList<Integer> maxq;

    public MaxQueue() {
        queue = new LinkedList<Integer>();
        maxq = new LinkedList<Integer>();
    }
    
    public int max_value() {
        if(maxq.size() == 0) {
            return -1;
        }
        return maxq.getFirst();
    }
    
    public void push_back(int value) {
        queue.add(value);
        while(maxq.size() != 0 && maxq.getLast() < value) {
            maxq.removeLast();
        }
        maxq.add(value);
    }
    
    public int pop_front() {
        if(queue.size() == 0) {
            return -1;
        }
        int v = queue.getFirst();
        queue.removeFirst();
        if(maxq.getFirst() == v) {
            maxq.removeFirst();
        }
        return v;
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */