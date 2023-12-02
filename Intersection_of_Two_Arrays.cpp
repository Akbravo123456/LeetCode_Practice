class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        set<int> st;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) i++;
            else if(nums2[j]<nums1[i]) j++;
            else {st.insert(nums1[i]);i++;j++;}
        }
        vector<int> vec(st.begin(),st.end());
        return vec;
    }
};