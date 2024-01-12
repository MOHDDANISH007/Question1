
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
 queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    int size = q.size();
    int remaining_elements = size - k;

    // Step 1: Dequeue the first K elements and push them onto the stack
    for (int i = 0; i < k; ++i) {
        int element = q.front();
        s.push(element);
        q.pop();
    }

    // Step 2: Pop elements from the stack and enqueue them back into the queue
    while (!s.empty()) {
        int element = s.top();
        q.push(element);
        s.pop();
    }

    // Step 3: Dequeue the remaining elements and enqueue them back
    for (int i = 0; i < remaining_elements; ++i) {
        int element = q.front();
        q.pop();
        q.push(element);
    }

    return q;
}
};
