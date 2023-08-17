int i=0,j=0,maxi=INT_MIN;

int sum=0;

while(j<size()){
sum+=arr[j];

  if(j-i+1==k){
   maxi=max(maxi,sum);
    sum-=arr[i];
    i++;
  }
   j++;
}
return maxi;
