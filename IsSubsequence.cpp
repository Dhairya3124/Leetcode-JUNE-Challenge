class Solution {
public:

    bool isSubsequence(string s, string t) {
       int sp = 0;
       int tp = 0;
        if(s.size() == 0)return true;
        while(tp<t.size())
        {
            if(s[sp]==t[tp])
            {
                sp++;
                if(sp == s.size())
                {
                    return true;
                }
            }
            tp++;
        }
        return false;
    }
};
