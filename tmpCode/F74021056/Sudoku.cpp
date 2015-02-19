#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<time.h> 
#include "Sudoku.h"
#define SIZE 9
using namespace std;


		Sudoku::Sudoku(){
				no=0;
			count=0;
			int a;
			for(a=0;a<81;a++)
			{
				map[a]=0;
			}
		};
		void Sudoku::GiveQuestion()
		{srand(time(NULL));
		int a8[2]={04};
		int b1[81]={0,4,9,3,8,0,1,5,6,8,0,6,5,1,4,9,7,2,1,7,5,6,2,0,4,8,0,4,8,7,9,5,6,3,0,0,3,0,0,0,0,0,0,0,5,0,0,1,8,3,2,7,6,4,0,2,4,0,9,8,5,3,7,7,5,8,4,6,3,2,0,9,9,1,3,0,7,5,6,4,0};
		int b2[81]={0,1,2,7,6,8,5,9,4,5,0,7,9,0,0,0,8,0,8,9,6,5,4,3,1,7,0,0,6,5,0,3,7,4,0,8,1,7,3,8,0,4,2,6,5,2,0,4,6,5,0,7,3,0,0,5,8,1,7,9,3,2,6,0,2,0,0,0,5,9,0,7,7,3,9,4,2,6,8,5,0};
		int b3[81]={7,9,2,4,0,3,5,0,1,0,0,3,7,8,9,6,0,4,4,8,6,0,5,2,9,3,7,3,7,4,2,0,1,8,6,0,8,2,0,0,0,0,0,9,3,0,5,9,3,0,8,1,7,2,2,6,7,9,1,0,3,5,8,9,0,8,5,3,7,2,0,0,1,0,5,8,0,6,7,4,9};
		int b4[81]={6,5,1,0,0,2,0,3,7,9,0,7,1,0,5,2,8,6,2,8,3,7,9,0,5,4,1,3,1,0,9,0,7,8,5,0,5,0,4,3,0,8,7,0,9,0,7,9,5,0,4,0,6,2,4,9,8,0,7,3,1,2,5,7,3,6,2,0,1,4,0,8,1,2,0,8,0,0,6,7,3};
		int b5[81]={2,6,0,4,0,8,9,5,1,1,0,3,0,2,6,8,4,0,4,9,8,7,0,1,3,6,2,9,8,6,5,4,2,7,0,3,0,0,5,0,0,0,2,0,0,3,0,2,6,7,9,4,8,5,8,7,9,2,0,5,1,3,4,0,2,1,3,9,0,5,0,8,5,3,4,8,0,7,0,2,9};
		int b6[81]={5,2,3,0,9,1,6,4,0,9,0,4,5,7,2,8,3,1,0,1,0,3,4,6,5,0,0,3,0,7,0,1,8,2,6,5,0,8,5,7,0,9,3,1,0,6,4,1,2,3,0,7,0,8,0,0,9,6,2,7,0,8,0,4,7,6,9,8,3,1,0,2,0,3,2,1,5,0,9,7,6};
		int b7[81]={1,0,3,7,5,6,0,4,2,4,9,0,0,2,8,1,6,7,0,2,6,4,9,1,3,8,5,8,3,9,2,6,0,0,1,4,5,0,4,0,0,0,6,0,3,6,1,0,0,4,3,7,9,8,3,6,7,0,8,4,2,5,0,9,5,8,1,7,0,0,3,6,2,4,0,6,3,5,8,0,9};
		int print[81];
		switch(rand()%7)
       {
          case 0:
               for(int f=0;f<81;f++)
			   {print[f]=b1[f];}
               break;
          case 1:
               for(int f=0;f<81;f++)
			   {print[f]=b2[f];}
               break;
          case 2:
                for(int f=0;f<81;f++)
			   {print[f]=b3[f];}
               break;
          case 3:
               for(int f=0;f<81;f++)
			   {print[f]=b4[f];}
               break;
          case 4:
                for(int f=0;f<81;f++)
			   {print[f]=b5[f];}
               break;
          case 5:
                for(int f=0;f<81;f++)
			   {print[f]=b6[f];}
               break;
          case 6:
                for(int f=0;f<81;f++)
			   {print[f]=b7[f];}
               break;
       }
        int t1[9] = {1,2,3,4,5,6,7,8,9};
        int tmp;
        int i,j;
       for (i=0;i<9;i++)
       {
          j = rand() % 9;
          tmp = t1[i];
          t1[i] = t1[j];
          t1[j] = tmp;
       }
       int print2[81]={0};
       for(j=0;j<81;j++)
       {          
          switch(print[j]) 
          {
             case 0:
                print2[j]=0;
                break;
			 case 1:
                print2[j]=t1[0];
                break;
             case 2:
                print2[j]=t1[1];
                break;
             case 3:
                print2[j]=t1[2];
                break;
             case 4:
                print2[j]=t1[3];
                break;
             case 5:
                print2[j]=t1[4];
                break;
             case 6:
                print2[j]=t1[5];
                break;
             case 7:
                print2[j]=t1[6];
                break;
             case 8:
                print2[j]=t1[7];
                break;
             case 9:
                print2[j]=t1[8];
                break;

          }
       } 
       for(j=0;j<81;j++)
       {
          cout<<print2[j]<<" ";
          if((j+1)%9==0)cout<<endl;
       }
       return; 
		};

		void Sudoku::ReadIn()
		{
//		FILE * ftpr;	
//	ftpr=freopen("output.txt","r",stdin);
		int i;
		vector<int>read(81);
/*		cout << "Please enter a sudoku type(9*9格式):\n" << "記得加空格!!\n" << endl;
		for(i=0;i<81;i+=9)
		{
			cin >> read[i] >> read[i+1] >> read[i+2] >> read[i+3] >> read[i+4] >> read[i+5] >> read[i+6] >> read[i+7] >> read[i+8];//讀檔 
		}*/ for(i=0;i<81;i+=9)
		{
		scanf("%d %d %d %d %d %d %d %d %d",&read[i] , &read[i+1], &read[i+2] , &read[i+3] , &read[i+4] , &read[i+5] ,&read[i+6] , &read[i+7] , &read[i+8]);//讀檔 
		}

/*		ifstream inFile("output.txt", ios::in);
		if(!inFile) {
		 cerr << "Failed opening" << endl;
		 exit(1);
		 }
		for(i=0;i<81;i+=9)
		{
			inFile >> read[i] >> read[i+1] >> read[i+2] >> read[i+3] >> read[i+4] >> read[i+5] >> read[i+6] >> read[i+7] >> read[i+8];//讀檔 
		}*/	
/*		for(i=0;i<81;i++)
		{
		cout << read[i] << " ";
		if((i+1)%9==0)
		{
		cout << "\n";
		}
		}
		cout << "\n";*/
		int a;
		for(a=0;a<81;a++)
			{
				map[a]=read[a];
			}
			cout << "\n";
		mysolve(0);
		if(count==1)
           {cout<<endl<<"1.唯一解"<<endl<<endl;
			   for(int s3=0;s3<81;s3++)
				{
				cout << print[s3] << " ";
				if((s3+1)%9==0)
				{cout << "\n";}
				}
		   }
		};
		
		void Sudoku::mysolve(int Len)
		{
			int i;
			i=Len;
			int j;
			bool check[10]={0};
			no++;			
       		 if(no>500000)   //無解 (輪迴1000000次就無解)
       		 {
       	 	   cout<<endl<<"0.無解"<<endl<<endl;
      	     	count=2;         //重要 
      	  	   return;
      		  } 
			if(Len==81)
			{
				count++;
          	 if(count>2){return;}
         	  if(count==2)
         	  {cout<<endl<<"2.多解"<<endl;
          		 return;}
			
	/*		for(int s3=0;s3<81;s3++)
				{
				cout << print[s3] << " ";
				if((s3+1)%9==0)
				{cout << "\n";}
				}//輸出*/ 
			return; 
			}
			if(map[Len]!=0) //	本來就有值的		
			{
				print.push_back(map[Len]);
				mysolve(Len+1);
			}
			if(map[Len]==0)
			{
				for (j=0;j<SIZE;j++)
            {
            	int x1=map[(i/SIZE)*SIZE+j]-1;
            	if(x1==(-1)){x1=9; check[x1]=0;}//除錯 
                if (map[(i/SIZE)*SIZE+j] && !check[x1])
                {
                    check[x1] = true;
                }//in_board橫排數字&& 無意義(1)--->count+1 ，tag排除一個數字 
                int x2=map[j*SIZE+i%SIZE]-1;
                if(x2==(-1)){x2=9; check[x2]=0;}//除錯 
				if (map[j*SIZE+i%SIZE] && !check[x2])
                {
                    check[x2] = true;
                }//in_board直排數字 && 無意義(1)----->count+1 ,tag排除一個數字 用tag&&是避免重複扣除數字 
                int x3 = map[((i/(SIZE*3))*3+j/3)*SIZE + ((i%SIZE)/3)*3+j%3] - 1;
                if(x3==(-1)){x3=9; check[x3]=0;}
                if (map[((i/(SIZE*3))*3+j/3)*SIZE + ((i%SIZE)/3)*3+j%3] && !check[x3])
                {
                    check[x3] = true;

                }//檢查正方形的數字 ----->count+1 , tag排除一個數字 
            }
      /*      for(int s3=0;s3<9;s3++)
				{
				cout << check[s3] << " ";
				if((s3+1)%9==0)
				{
				cout << "\n";
				}
				}*/
			}
			    for (int s = 0; s < 9; ++s) {
       			 if (check[s] == 0 && map[Len]==0)
					{      // 如果這個編號還沒出現過(可行性檢查)
        		    print.push_back(s+1); // 則將它放入Ans
        		    check[s] = 1;        // 並且讓choosed[i]變成1,避免下個遞迴選到
 
    		        mysolve(Len+1);       // 進入下一層遞迴
 
    		        print.pop_back();        // 將編號i這個字從Ans移除
    		        check[s] = 0;        // 並標示成未選過
        			}
        			if(count==2)return;
  			  }
			
			 
		};
		void Sudoku::Solve()
		{
			return;
		};
/*int	main()
{
	freopen("output.txt","r",stdin);
	Sudoku ss;
	ss.ReadIn();
	ss.Solve();
	return 0;
}*/
