class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        
        if(A.empty()) return 0;
        size_t size=A.size();
        auto iter=A.begin();
        while(iter!=A.end())
        {
            if(*iter==elem)
            {
                iter=A.erase(iter);
                size--;
            }
            else
                iter++;
        }
        
        return size;
    }
};
