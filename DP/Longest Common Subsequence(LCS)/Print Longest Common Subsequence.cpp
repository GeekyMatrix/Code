String Plcs(string s1,string s2){
 int m=s1.length();
 int n=s2.length();

  int t[m+1][n+1];

  for(int i=0;i<=m;i++){
      for(int j=0;j<=m;j++){
        if(i==0 || j==0) t[i][j]=0;
      }
      }

  int i=m,j=n;
 string s="";
  while(i>0 && j>0){
    if(s1[i-1]==s2[j-1]){
      s.push_back(a[i-1]);
      i--;
      j--;
    }
else { 
  if(t[i][j-1]>t[i-1][j]) j--;
  else i--;
}
  }
 reverse(s.begin(),s.end());
  return s;
}
