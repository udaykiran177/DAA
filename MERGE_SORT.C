#include <stdio.h>


void merge(int a[],int l,int m,int h){
    int n1=m-l+1;
    int n2=h-m;
    
    int a1[n1],a2[n2];
    
    for (int i=0;i<n1;i++){
        a1[i]=a[i+l];
    }
    for (int i=0;i<n2;i++){
        a2[i]=a[m+i+1];
    }
    
    int i=0,j=0,k=l;
    
    while(i<n1 && j<n2){
        if (a1[i]<a2[j]){
            a[k++]=a1[i++];
        }
        else{
            a[k++]=a2[j++];
        }
    }
    
    while (i<n1){
        a[k++]=a1[i++];
    }
    while (j<n2){
        a[k++]=a2[j++];
    }
}


void mergesort(int a[],int low,int high){
    if (low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void print(int a[],int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}


int main(){
    int n;
    printf("enter the no of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements in array: ");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("elements in the array: ");
    print(a,n);
    mergesort(a,0,n);
    printf("after sort:\n");
    print(a,n);
}
