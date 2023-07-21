/*Eg:-
arr[]={2,3,5,6,8,10}
sum=10
{2,3,5}
{2,8}
{10}
Total =3
  */

//CODE
int Count(vector<int> arr,int Sum){
  int n=arr.aize();
  int m=sum;
  
 int **t=new int*[n+1];
  for(int i=0;i<=n;i++){
 t[i]=new int[m+1];
  }
  //FILL THE IST row and ist col
  for(int i=0;i<n+1;i++){
     for(int j=0;j<m+1;j++){
     if(i==0) t[i][j]=0;
       if(j==0) t[i][j]=1;
     }
     }
//CHOICE DIAGRAM
  for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
        if(arr[i-1]<=j){
        t[i[[j]=t[i-1][j-arr[i-1]+t[i-1][j]);
        }
       else t[i][j]=t[i-1][j];
      }
  }
  return t[n][m];
}
