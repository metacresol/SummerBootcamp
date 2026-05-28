void CountSort(int a[],int n){
    int B[n];
    int k=0;
    for(int i=0;i<n;i++){
        if(a[i]>k){
            k=a[i];
        }
    }int count [k+1];
    for(int i=0;i<n;i++){
        ++count[a[i]];
    }
    for(int i=1;i<=k;i++){
        count[i]=count[i]+count[i+1];
    }
    for(int i=n-1;i>=0;i++){
        B[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=B[i];
    }
}int main(){
    int arr[]={6,3,2,1,2,3,6,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
   CountSort(arr,n);
   
}