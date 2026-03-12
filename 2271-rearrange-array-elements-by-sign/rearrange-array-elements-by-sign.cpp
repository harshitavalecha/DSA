class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n=nums.size();
        vector<int>arr(n,0);
        int pindex=0;
        int nindex=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
            arr[pindex]=nums[i];
            pindex+=2;
            }else{
            arr[nindex]=nums[i];
            nindex+=2;
            }

        }
        return arr;
    }
};