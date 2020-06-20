class Solution {
public:
    string getPermutation(int n,int k)
    {
        bool ans = false;
        string s = "";
        for(int i=1;i<=n;i++)
        {
            char c =(char)(i + '0');
            s+=c;
        }

        for(int j=1;j<k;j++)
        {
            next_permutation(s.begin(),s.end());
        }

        return s;
    }
};
