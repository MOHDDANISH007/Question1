class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> heap;
        for(int i=0;i<happiness.size();i++){
            heap.push(happiness[i]);
        }

        long long cnt = 0;
        long long sum = 0;
        while(k!=0){
            int nums = 0;

            if(heap.top() == 0){
                nums = heap.top();
                heap.pop();
            }else{
                nums = heap.top()-cnt;
                if(nums < 0){
                    nums = 0;
                }
                heap.pop();
            }
            sum += nums;
            cnt++;
            k--;
        }
        return sum;
    }
};
