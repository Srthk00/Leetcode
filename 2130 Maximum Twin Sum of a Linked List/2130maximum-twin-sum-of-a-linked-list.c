/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    typedef struct ListNode node;
    node *point=head;
    int n=0;
    while(point!=NULL){
        n++;
        point=point->next;
    }
    point=head;
    int *arr=(int *)malloc(n*sizeof(int));
    int i=0,sum,max=0;
    while(point!=NULL){
        arr[i]=point->val;
        point=point->next;
        i++;
    }
    for(int j=0;j<n/2;j++){
        sum=arr[j]+arr[n-1-j];
        if(sum>max)
            max=sum;
    }
    return max;
}