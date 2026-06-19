class MedianFinder {

    PriorityQueue<Integer>maxHeap;
    PriorityQueue<Integer>minHeap;

    public MedianFinder() 
    {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }
    
    public void addNum(int num) 
    {
        maxHeap.add( num );
        minHeap.add( maxHeap.remove());

        if(minHeap.size()>maxHeap.size())
            maxHeap.add( minHeap.remove());
    }
    
    public double findMedian() 
    {
         if(maxHeap.size()>minHeap.size())
            return maxHeap.peek();
        else
            return (maxHeap.peek()+minHeap.peek())/2.0;
    }
}