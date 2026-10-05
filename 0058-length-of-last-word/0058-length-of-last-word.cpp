class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int cnt=0;
        int i=n-1;
        while(i>=0&&s[i]==' ')
        {
            i--;
        }
        for(;i>=0;i--)
        {
            if(s[i]==' ') break;
            else cnt++;
        }
        return cnt;
    }
};