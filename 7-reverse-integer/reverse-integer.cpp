class Solution {
public:
    int reverse(int x) {
        long long int n = x;
        if(n < 0)
        {
            n = -n;
        }
        string s = to_string(n);
        for(int i = 0 ; i < s.size() / 2 ;i++)
        {
            swap(s[i],s[s.size()- 1 - i]);
        }
        long long int k  = stoll(s);//stl convert srign
        if(x < 0)
        {
            k = -k;
        }
        if(k < INT_MIN || k > INT_MAX)
        {
            return 0;
        }
        return k;

    }
};