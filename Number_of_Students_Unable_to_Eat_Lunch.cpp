class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len = students.size();
        queue<int> studentQueue;
        for(auto i: students)
            studentQueue.push(i);
        stack<int> sandwichStack;
        for(int i = len - 1; i >= 0; i--) 
            sandwichStack.push(sandwiches[i]);
        
        int served = 0;
        while (!studentQueue.empty() && !sandwichStack.empty()) {
            if (sandwichStack.top() == studentQueue.front()) {
                sandwichStack.pop();
                studentQueue.pop(); 
                served = 0; // Reset served only when a sandwich is served
            } else {
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                served++;
                // If all students have been checked and no sandwich served, break the loop
                if (served == studentQueue.size())
                    break;
            }
        }
        return studentQueue.size();
    }
};

