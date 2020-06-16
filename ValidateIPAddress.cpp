class Solution {
public:
    string validIPAddress(string ip) 
    {
        if (ipv4(ip)) return "IPv4";
        else if (ipv6(ip)) return "IPv6";
        else return "Neither";
    }
    bool ipv4(string ip)
    {
        int curval = 0, count = 0;
        ip.push_back('.');
        for (int i=0; i<ip.length(); i++)
        {
            if (ip[i]=='.')
            {
                if (curval>255 || (i>0 && ip[i-1]=='.')) return false;
                curval = 0; count++;
            }
          else if(ip[i]>='0' && ip[i]<='9')
          {
                curval = curval*10 + (ip[i]-'0');
                if ((curval==0 && ip[i+1]!='.') || curval>255) return false;
          }
          else
          {
                return false;
          }
        }
        return count==4;
    }
    bool ipv6(string ip)
    {
        string cur = "";
        ip.push_back(':');
        int count=0, lastind = -1;
        for (int i=0; i<ip.length(); i++)
        {
            if (ip[i]==':')
            {
                if ((i>0 && ip[i-1]==':') || i-lastind-1>4) return false;
                lastind = i; count++;
            }
            else if ((ip[i]>='0'&&ip[i]<='9') || (ip[i]>='a'&&ip[i]<='f') || (ip[i]>='A'&&ip[i]<='F'))
            {
                continue;
            }
           else
           {
                return false;
           }
        }
        return count==8;
    }
};
