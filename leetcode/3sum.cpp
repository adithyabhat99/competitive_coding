#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        int i=0;
        int count=0;
        while(i<nums.size()-2)
        {
            int l=i+1;
            int r=nums.size()-1;
            int target=nums[i]*(-1);
            while(l<r)
            {
                int sum=nums[l]+nums[r];
                if(sum<target)
                {
                    l++;
                }
                else if(sum>target)
                {
                    r--;
                }
                else
                {
                    vector<int> p ={nums[i],nums[l],nums[r]};
                    count++;
                    while(l<r && nums[l]==p[1])
                        l++;
                    while(l<r && nums[r]==p[2])
                        r--;
                }
            }
            int cur=nums[i];
            while(i<nums.size()-2 && nums[i]==cur)
                i++;
        }
        return res;
}