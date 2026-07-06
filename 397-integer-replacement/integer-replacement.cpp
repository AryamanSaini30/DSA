class Solution {
public:
    void recurse(long long argo, int& count, int amx) {
        if(argo == 1) {
            count = std::min(count, amx); // Minimum steps taken
            return;
        }
        if(argo % 2 != 0) { 
                        recurse(argo + 1, count, amx + 1); 
            recurse(argo - 1, count, amx + 1); 
        }
        else {
               recurse(argo / 2, count, amx + 1);
        }
    }

    int integerReplacement(int n) {
        long long argo = n;
        int count = INT_MAX;
        int amx = 0;
        recurse(argo, count, amx);
        return count;
    }
};