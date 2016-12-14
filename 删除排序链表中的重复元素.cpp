class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.empty()) return 0;
        
        size_t size=nums.size();
        auto it=nums.begin();
        
        while(it!=nums.end()-2)
        {
            if(*it!=*(it+1))
                it++;
            else
            {
                if(*it==*(it+2))
                {
                    it=nums.erase(it);
                    size--;
                }
                else
                    it++;
            }
        }
        
        
        
        return size;
    }
};
