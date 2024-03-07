#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;


void storeSwap(node** head,int x){
    node* new = (node*)calloc(1,sizeof(node));
    new->val = x;
    node* temp = *head;
    if(*head==NULL){
        *head = new;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new;
}

int swap(int* a,int* b,node** head){
    storeSwap(head,*a);
    storeSwap(head,*b);
    int temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}

int selectionSort(int* arr,int l,node** head){
    int res = 0;
    int min = 0;
    for(int i = 0;i<l-1;i++){
        min = i;
        for(int j =i+1;j<l;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(arr[i]!=arr[min]){
            res += swap(&arr[i],&arr[min],head);
        }
    }
    return res;
}
int bubbleSort(int* arr,int l,node** head){
    int res = 0;
    for(int i = 0;i<l;i++){
        for(int j=i;j<l;j++){
            if(arr[i]>arr[j]){
                res +=swap(&arr[i],&arr[j],head);
            }
        }
    }
    return res;
}
void printArray(int* arr,int l){
    for(int i = 0;i<l;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void printCounts(int* arr,int l, node** head){
    for(int i =0;i<l;i++){
        node* temp = *head;
        int num = 0;
        while(temp!=NULL){
            if(temp->val==arr[i]){
                num++;
            }
            temp = temp->next;
        }
        printf("%d is swapped %d times\n",arr[i],num);
    }
}

void printNodes(node* head){
    while(head!=NULL){
        printf("not null");
        head = head->next;
    }
}

int* copyArray(int* array,int l){
    int* new = calloc(l,sizeof(int));
    for(int i = 0;i<l;i++){
        new[i] = array[i];
    }
    return new;
}


void main(void){
    int result = 0;
    int array1[9] = {97,16,45,63,13,22,7,58,72};
    int array2[9] = {90,80,70,60,50,40,30,20,10};
    node* head1 = NULL;
    node* head2 = NULL;
    int* arr1S = copyArray(array1,9);
    int* arr2S = copyArray(array2,9);

    result = selectionSort(arr1S,9,&head1);
    printArray(arr1S,9);
    printf("%d total swaps for selectionSort of array1\n",result);
    printCounts(arr1S,9,&head1);

    head1 = NULL;
    result = bubbleSort(array1,9,&head1);
    printArray(array1,9);
    printf("%d total swaps for bubbleSort of array1\n",result);
    printCounts(array1,9,&head1);

    result = selectionSort(arr2S,9,&head2);
    printArray(arr2S,9);
    printf("%d total swaps for selectionSort of array2\n",result);
    printCounts(arr2S,9,&head2);

    head2=NULL;
    result = bubbleSort(array2,9,&head2);
    printArray(array2,9);
    printf("%d total swaps for bubbleSort of array2\n",result);
    printCounts(array2,9,&head2);
    
}