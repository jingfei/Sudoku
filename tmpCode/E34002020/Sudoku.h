nt SolveSudoku(int *b)
{
  int p, num, r, c, l, s, i, a=0;
  for(p=Max-1; p>=0 && b[p]!=0; p--);   // 找尋空格 
  if (p>=0)
  {  // p為空格位置 
    r=p/Size; c=p%Size;  l=r/Row*Row*Size+c/Col*Col;  // 位置換算 
    for(num=1; num<=Size; num++)   // 將填入的數字 
    { 
      b[p] = num;       
      for(i=0; i<Size; i++)  // 檢查 行列與小九宮內是否重複 
      {
        s = l + i/Col*Size+i%Col;
        if((i!=c && b[r*Size+i]==num) || ( i!=r && b[i*Size+c]==num)
           || ( s!=p && b[s]==num) )  break;  //有重覆則跳離 
      }
      if (i==Size && SolveSudoku(b)!=0) a=1;  //沒重覆則繼續...[遞迴] 
      if (Ans>1) break;  // 有多重解 -- 
    }
    b[p] = 0;
    return a;
  }
  if (Ans++<1)
    for(p=0; p<Max; p++) Solve[p] = b[p];   // 記錄解答 
  return 1;  