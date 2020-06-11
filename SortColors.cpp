class Solution {
public:
    void sortColors(vector<int>& nums) {
        int temp;
    for(int k = 0; k< nums.size()-1; k++) {
        for(int i = 0; i < nums.size()-k-1; i++) {
            if(nums[ i ] > nums[ i+1] ) {
                temp = nums[ i ];
                nums[ i ] = nums[ i+1 ];
                nums[ i + 1] = temp;
            }
        }
    }
        for(int i=0;i<nums.size();i++)
            cout<<nums[i];
    }
};
