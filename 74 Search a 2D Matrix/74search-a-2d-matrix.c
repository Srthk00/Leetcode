bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if(matrixSize==0 || matrixColSize[0]==0){
        return false;
    }
    int rows=matrixSize;
    int cols=matrixColSize[0];
    int left=0,right=rows-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(matrix[mid][cols-1]<target){
            left=mid+1;
        }
        else if(matrix[mid][0]>target){
            right=mid-1;
        }
        else{
            break;
        }
    }
    if(left>right){
        return false;
    }
    int row=(left+right)/2;
    left=0,right=cols-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(matrix[row][mid]==target){
            return true;
        }
        else if(matrix[row][mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return false;
}