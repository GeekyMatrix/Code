Void BubbleSort(vector<int>&arr,int n){
  for(int i=1;<n-1;i++){ //For round 1 to n-1
    bool Swapped=false;
    for(int j=0;j<n-i;j++){// process element till n-ith index
      if(arr[j]>arr[j+1]){
     swapp(arr[j],arr[j+1]);
        Swapped=true;
      }
    }
 if(Swapped==false) { //already Sorted
 break;
 }
  }
}
