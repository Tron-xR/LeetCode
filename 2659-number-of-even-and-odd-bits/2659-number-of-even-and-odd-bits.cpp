class Solution {
public:
    vector<int> evenOddBit(int n) {
        bitset<32> binary(n);
        int even=0;
        int odd=0;
        for(int i=0;i<binary.size();i++)
        {
            if(binary[i]==1)
            {
                if(i%2==0) even++;
                else odd++;
            }
        }
        return {even,odd};
    }
};