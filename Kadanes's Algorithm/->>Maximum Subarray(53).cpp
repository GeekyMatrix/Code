int sum=0;
int maxi=INT_MIN;

for(int i=0;i<nums.size();i++){
sum+=arr[i];
maxi=max(maxi,sum);

  if(sum<0) sum=0;
}

return maxi;
}