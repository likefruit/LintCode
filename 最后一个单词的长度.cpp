class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int res=0;
        size_t len=s.size()-1;
        while(s[len]==' '&&len>-1)
            len--;
        for(int i=len;i>-1;--i)
        {
            if(s[i]!=' ')
                res++;
            else
                break;
        }
        return res;
    }
};

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int counter = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if(s[i] == ' ') {
                if (counter > 0) {
                    break;
                }
            } else {
                ++counter;
            }
        }
        return counter;
    }
};
