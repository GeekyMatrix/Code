Void InsertionSort(int n,vector<int>&arr){
for(int i=0;i<n;i++){
    int temp=arr[i];
   int j=i-1;
  for(; j>=0;j--){
>temp){  //SHIFT
 arr[j+1]=arr[j];
}
else{ //ruk jao
  break;
}
}
//Copy temp value
  arr[j+1]=temp;
}
