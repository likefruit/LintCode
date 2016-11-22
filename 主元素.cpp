class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int count=1;
        int mark=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==mark) count++;
            else
            {
                count--;
                if(count==0)
                {
                    count=1;
                    mark=nums[i];
                }
            }
        }
        return mark;
    }
};

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        int ans = nums[0], cnt = 1;
        for (const auto& i : nums) {
            if (i == ans) {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    ans = i;
                    cnt = 1;
                }
            }
        }
        return ans;
    }
};

