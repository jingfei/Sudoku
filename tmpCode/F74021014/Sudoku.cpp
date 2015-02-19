#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Sudoku.cpp"

using namespace std;

int sudoku::ReadIn(){
    int m,n;
    for(n=0;n<9;n++){
        for(m=0;m<9;m++){
            cin>>map[m][n];
            if(map[m][n]>9 || map[m][n]<0)return -1;        
            }
    }    
    return 0;
}

//==========================================================

int sudoku::check_fill(int x,int y,int map1[9][9]){
    
    int m,n=y;
    int check[9]={0};
    //======================check x line
    for(m=0;m<9;m++){
        if(map1[m][n]!=0)check[map1[m][n]-1]++;
    }

     for(m=0;m<9;m++){
            if(check[m]>1)return 0;
     }
   
     for(m=0;m<9;m++)check[m]=0;
     //=====================check y line
      n=x;
      for(m=0;m<9;m++){
        if(map1[n][m]!=0)check[map1[n][m]-1]++;
    }

     for(m=0;m<9;m++){
            if(check[m]>1)return 0;
     }
    
     for(m=0;m<9;m++)check[m]=0;
     
     //=====================check square
    int x2=x-x%3;
    int y2=y-y%3;
    
    
    for(n=0;n<3;n++){
        for(m=0;m<3;m++){
            if(map1[x2+m][y2+n]!=0)check[map1[x2+m][y2+n]-1]++;
        }
     }
     for(m=0;m<9;m++){
            if(check[m]>1)return 0;
     }
    //==================================
    
    return 1;
}

//==========================================================

int sudoku::link(int x,int y){
    blank_amount++;
    start[blank_amount].x=x;
    start[blank_amount].y=y;
    start[blank_amount].point=0;
       
    int x2=x-x%3;
    int y2=y-y%3;
 
    //=========================
    int m,n,check=0;
    for(n=0;n<9;n++)start[blank_amount].num[n]=1;
  
    n=x;
    for(m=0;m<9;m++){
        if(map[n][m]!=0)start[blank_amount].num[map[n][m]-1]=0;
        }   
        
    n=y;     
    for(m=0;m<9;m++){
        if(map[m][n]!=0)start[blank_amount].num[map[m][n]-1]=0;
    }
  
    for(n=0;n<3;n++){
        for(m=0;m<3;m++){
            if(map[x2+m][y2+n]!=0)start[blank_amount].num[map[x2+m][y2+n]-1]=0;
        }
    }

    for(m=0;m<9;m++){
        if(start[blank_amount].num[m]==1)check++;
    }
    
    start[blank_amount].amount=check;    
}

//======================================================================
int sudoku::Solve(){
    int m,n; 
    for(n=0;n<9;n++){
        for(m=0;m<9;m++){
            if(map[m][n]==0)link(m,n);           
        }
    }       
    int point_blank=1;
      
    //------------------------------------------------------------------------------------------------------
    int map1[9][9];
    int map2[9][9];
    for(n=0;n<9;n++){
        for(m=0;m<9;m++){
            map1[m][n]=map[m][n];
            map2[m][n]=map[m][n];
        }
    }

    while(point_blank<=blank_amount){
                 
        while(start[point_blank].num[start[point_blank].point]==0){
            if(start[point_blank].point>8)break;
            start[point_blank].point++;
            }
       
        if(start[point_blank].point<9)map1[start[point_blank].x][start[point_blank].y]=start[point_blank].point+1;
               
        if(check_fill(start[point_blank].x,start[point_blank].y,map1)==1 && start[point_blank].point<9)point_blank++;
        else{
             if(start[point_blank].point<9)start[point_blank].point++;
             else{
                  start[point_blank].point=0;
                  map1[start[point_blank].x][start[point_blank].y]=0;
                  point_blank--;
                  start[point_blank].point++;
                  }
             
              if(point_blank<=0){
                  def();
                  return 0;
               }   
            }            
        }
    
    //======================================
    point_blank=1;
    for(n=1;n<=blank_amount;n++)start[n].point=8;
    while(point_blank<=blank_amount){
                    
        while(start[point_blank].num[start[point_blank].point]==0){
            if(start[point_blank].point<0)break;
            start[point_blank].point--;
            }
       
        if(start[point_blank].point>=0)map2[start[point_blank].x][start[point_blank].y]=start[point_blank].point+1;
              
        if(check_fill(start[point_blank].x,start[point_blank].y,map2)==1 && start[point_blank].point>=0)point_blank++;
        else{
             if(start[point_blank].point>=0)start[point_blank].point--;
             else{
                  start[point_blank].point=8;
                  map2[start[point_blank].x][start[point_blank].y]=0;
                  point_blank--;
                  start[point_blank].point--;
                  }
             
              if(point_blank<=0){
                  def();
                  return 0;   
                  }
            }            
        }
     
   //===============================================
     
   for(n=0;n<9;n++){
       for(m=0;m<9;m++){
           ans[m][n]=map1[m][n];
       }
   }
   for(n=0;n<9;n++){
       for(m=0;m<9;m++){
           if(map1[m][n]!=map2[m][n]){
               def();
               return 2;
           }
       }
   }
   
    
   ok=1;
    def();
   return 1;
} 
//===========================================================
int sudoku::def(){
    int n,m;
  for(n=0;n<=81;n++){
         start[n].x=0;
         start[n].y=0;
         for(m=0;m<9;m++)start[n].num[m]=0;
         start[n].amount=0;
         start[n].point=0;
    }
    blank_amount=0;
}
//--------------------------
int sudoku::get(int x,int y){
    return map[x][y];
}
int sudoku::geta(int x,int y){
    return ans[x][y];
}
//===========================================================   
int sudoku::GiveQuestion(){
    int i,n=0;
    
    for(n=0;n<9;n++){
        for(i=0;i<9;i++){
            map[i][n]=0;
        }
    }
    
    Solve();
    int ran[9]={0};
    
    int ch=0;
    int seed = (unsigned)time(NULL);
    srand(seed);
    for(n=0;n<9;n++){
        ran[n]=rand()%9;
        for(i=0;i<n;i++){
            if(ran[n]==ran[i])ch=1;
            
        }
        if(ch==1)n--;
        ch=0;
    }
   /*//// 
    for(i=0;i<9;i++)cout<<ran[i]<<" ";
    cout<<endl;
    system("pause");
   ////*/ 
    for(n=0;n<9;n++){
        for(i=0;i<9;i++){
            map[i][n]=ran[ans[i][n]-1]+1;
        }
    }

   ch=0;
   int x,y,mid;
   while(1){
       x=rand()%9;
       y=rand()%9;
       if(map[x][y]!=2){
           mid=map[x][y];
           map[x][y]=0;
           /*///
       cout<<x<<" "<<y<<" ";
    cout<<endl;
     for(n=0;n<9;n++){
        for(i=0;i<9;i++){
            cout<<map[i][n]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    ///*/
           if(Solve()!=1){
                          //cout<<"LLL";
               ch++;
               map[x][y]=mid;
           }
           else ch=0;
                
       }
       if(ch>2)break;
    }
    
    
    ////
    cout<<endl;
     for(n=0;n<9;n++){
        for(i=0;i<9;i++){
            cout<<map[i][n]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    ////
           
}


//=========================================================== 
int main(){
    sudoku a;
   // a.GiveQuestion();
    if(a.ReadIn()==-1){
        cout<<endl<<0;
        system("pause");
        return 0;
    }
    
    int n,m;
    cout<<endl;
    
    cout<<a.Solve()<<endl;
    if(ok==1){
       for(n=0;n<9;n++){
         for(m=0;m<9;m++){
           cout<<a.geta(m,n)<<" ";
       }
       cout<<endl; 
      }        
    }
   
    system("pause");
    return 0;
}              
//===========================================================  */   
                