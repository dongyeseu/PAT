def Callatz(n):
  i=0;
  while n!=1:
    if n%2==0:
      n=n/2;
      i+=1;
    else:
      n = (n*3+1)/2;
      i+=1;
  return i;
  
n = int(input());
res = Callatz(n);
print(res);
