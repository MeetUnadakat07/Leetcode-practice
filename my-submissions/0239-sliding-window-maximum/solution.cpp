class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> dq;

        int left = 0;
        for(int right = 0; right < nums.size(); right++) {

            // Agar koi value choti hai right wale se to usko dq ke rear se remove karo 
            while(dq.size() != 0 && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // Out of window elements ko dq se remove karna hai 
            if(right >= k && dq.size() != 0 && dq.front() == left) {
                dq.pop_front();
            }

            // Include the right index in the window always 
            dq.push_back(right);

            // Left ko hamesha exclude karna hai window ka size maintain karne ke liye
            if(right >= k) left++;
            // Push to the result vector if we have filled the window 
            if(right >= k - 1) {
                int max = nums[dq.front()];
                result.push_back(max);
            }
        }
        return result;
    }
};
