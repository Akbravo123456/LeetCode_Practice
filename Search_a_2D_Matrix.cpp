class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowId=searchinRow(matrix,target);
        if(rowId!=-1) return binarySearchofrow(rowId,matrix,target);
        else
        return false;
    }

    int searchinRow(vector<vector<int>>& matrix,int target){
        int low=0;
        int high=matrix.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<= target && target<=matrix[mid][matrix[mid].size()-1]){
                return mid;
            }
            else if(matrix[mid][0]<target){
                low=mid+1;
            } 
            else if(matrix[mid][0]>target){
                high=mid-1;
            }
        }
        return -1;
    }

    bool binarySearchofrow(int rowId,vector<vector<int>>& matrix,int target){
        int low=0;
        int high=matrix[rowId].size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[rowId][mid] == target) return true;
            else if(matrix[rowId][mid]>target) high=mid-1;
            else low=mid+1; 
        }
        return false;
    }
};