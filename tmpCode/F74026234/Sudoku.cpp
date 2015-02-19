#include "Sudoku.h"

Sudoku::Sudoku()
{
        k = 0;
        mut_ans = 0;
        for(int i=0; i<9; i++)
        {
                for(int j=1; j<=9; j++)
                {
                        row[i][j] = false;
                        col[i][j] = false;
                        sqr[i][j] = false;
                        ans[i][j-1] = 0;
                }
        }
        
        int qb[5][9][9]={    8 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                            ,0 ,0 ,3 ,6 ,0 ,0 ,0 ,0 ,0
                            ,0 ,7 ,0 ,0 ,9 ,0 ,2 ,0 ,0
                            ,0 ,5 ,0 ,0 ,0 ,7 ,0 ,0 ,0
                            ,0 ,0 ,0 ,0 ,4 ,5 ,7 ,0 ,0
                            ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,3 ,0
                            ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,6 ,8
                            ,0 ,0 ,8 ,5 ,0 ,0 ,0 ,1 ,0
                            ,0 ,9 ,0 ,0 ,0 ,0 ,4 ,0 ,0
                            
                            ,0 ,0 ,9 ,0 ,0 ,0 ,6 ,0 ,4
                            ,0 ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,0
                            ,8 ,0 ,0 ,0 ,7 ,0 ,0 ,0 ,0                            
                            ,3 ,0 ,0 ,0 ,0 ,0 ,0 ,5	,0
                            ,0 ,0 ,0 ,0 ,2 ,6 ,0 ,0	,0
                            ,0 ,0 ,0 ,4	,0 ,9 ,0 ,0	,0
                            ,0 ,0 ,0 ,0	,3 ,0 ,0 ,0	,0
                            ,0 ,0 ,6 ,0	,0 ,0 ,9 ,0	,0
                            ,1 ,0 ,0 ,0	,0 ,0 ,0 ,7	,0
                            
                            ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,6
                            ,0 ,4 ,0 ,0 ,0 ,5 ,0 ,0 ,0
                            ,0 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,0
                            ,0 ,0 ,0 ,6 ,0 ,0 ,4 ,3 ,0
                            ,2 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0
                            ,3 ,0 ,0 ,0 ,0 ,0 ,5 ,0 ,0
                            ,0 ,0 ,0 ,0 ,0 ,3 ,7 ,0 ,0
                            ,1 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0
                            ,0 ,0 ,2 ,0 ,0 ,0 ,0 ,0 ,0
                            
                            ,0 ,6 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                            ,0 ,0 ,0 ,7 ,3 ,0 ,0 ,0 ,1
                            ,0 ,2 ,4 ,0 ,0 ,0 ,9 ,0 ,0
                            ,0 ,0 ,0 ,8 ,0 ,0 ,0 ,0 ,0
                            ,3 ,0 ,0 ,0 ,0 ,0 ,7 ,0 ,0
                            ,0 ,0 ,0 ,0 ,0 ,2 ,0 ,6 ,0
                            ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                            ,9 ,8 ,0 ,0 ,7 ,0 ,0 ,0 ,0
                            ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2
                            
                            ,0  ,0  ,6  ,0  ,0  ,0  ,0  ,0  ,0
                            ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,8
                            ,0  ,0  ,2  ,4  ,0  ,1  ,0  ,0  ,0
                            ,0  ,0  ,4  ,0  ,0  ,0  ,0  ,0  ,0
                            ,0  ,3  ,0  ,0  ,8  ,0  ,0  ,0  ,5
                            ,0  ,0  ,0  ,0  ,0  ,9  ,0  ,0  ,0
                            ,5  ,8  ,0  ,0  ,7  ,0  ,0  ,0  ,0
                            ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0
                            ,0  ,7  ,0  ,0  ,0  ,3  ,4  ,1  ,0};
                            
        /*srand(time(NULL));
        int t=rand()%5;*/
        
        for(int a=0; a<5; a++)
        {
                for(int i=0; i<9; i++)
                {
                        for(int j=0; j<9; j++) qus_x[a][i][j] = qb[a][i][j];
                }
        }
                 
} 

void Sudoku::ReadIn()
{
             k=0;
		     for(int i=0; i<9; i++)
     		{
             	for(int j=1; j<=9; j++)
             	{
                     row[i][j] = false;
                     col[i][j] = false;
                     sqr[i][j] = false;
                     ans[i][j-1] = 0;
             	}
     		}   
             //ifstream input("input.cpp", ios::in);        
             for(int i=0; i<9; i++)
             {
                     for(int j=0; j<9; j++)
                     {
                             //input >> tmp[i][j];
                             scanf(" %d", &tmp[i][j]);
                             if(tmp[i][j]==0) 
                             {
                                block[k].a = i;
                                block[k].b = j;
                                k++;
                                cout << "now k: " << k<< endl;
                             }
                             else 
                             {
                                  row[i][tmp[i][j]] = true;
                                  col[j][tmp[i][j]] = true;
                                  sqr[3*(i/3)+j/3][tmp[i][j]]= true;
                             }
                     }
             }        
             
             return;
}

void Sudoku::Solve()
{
     mut_ans = 0;
     
     
     if(k>64) 
     {
              printf("2\n");
              return;
     }
     use_able();
     backtracking(0);
     //printf("waste time: %llf\n", t2-t1);
     
     //ofstream output("output", ios::out);
     if(mut_ans==1)
     {
                   //output << mut_ans << endl;
                   printf("1\n");
                   for(int i=0; i<9; i++)
                   {
                           for(int j=0; j<9; j++)
                           {
                                   if(j!=8) printf("%d ", ans[i][j]);
                                   else printf("%d\n", ans[i][j]);
                           }
                   }
     }
     else if(mut_ans==0) printf("0\n");
     else printf("2\n");
     
     return;
}

void Sudoku::GiveQuestion()
{
     //ofstream output("output.2", ios::out);
     srand(time(NULL));
     int t1=rand()%5;
     
     /*if(t1)  
     {
           for(int i=0; i<9; i++)
           {
                   for(int j=0; j<9; j++)
                   {
                           t2 = rand()%3;
                           if(t2) qus[i][j] = 0;
                           else qus[i][j] = rand()%9+1;
                           
                   }
           }
     }*/ 
     
     for(int i=0; i<9; i++)
     {
             for(int j=0; j<9; j++)
             {
                     if(j!=8) printf("%d ", qus_x[t1][i][j]);
                     else printf("%d\n", qus_x[t1][i][j]);
             }
     } 
                                
                                 
       
} 
     
       
void Sudoku::backtracking(int len)
{
             if(mut_ans>1) return;                
             if(len==k)
             {
                       mut_ans++;
                       if(mut_ans>1) return;
                       for(int i=0; i<9; i++)
                       for(int j=0; j<9; j++) ans[i][j] = tmp[i][j];
                        
                       return;
             }
             
             for(int i=0; i<block[len].num; i++)
             {
                     if(mut_ans>1) return;
                     if(row[block[len].a][block[len].n[i]] == false && col[block[len].b][block[len].n[i]] == false && sqr[3*(block[len].a/3)+block[len].b/3][block[len].n[i]] == false)
                     {
                        row[block[len].a][block[len].n[i]] = true;
                        col[block[len].b][block[len].n[i]] = true;
                        sqr[3*(block[len].a/3)+block[len].b/3][block[len].n[i]] = true;
                        
                        tmp[block[len].a][block[len].b] = block[len].n[i];
                        
                        backtracking(len+1);
                        
                        row[block[len].a][block[len].n[i]] = false;
                        col[block[len].b][block[len].n[i]] = false;
                        sqr[3*(block[len].a/3)+block[len].b/3][block[len].n[i]] = false;
                     }
             }
}

void Sudoku::use_able()
{
     int x;
     for(int i=0; i<k; i++)
     {
             x = 0;
             for(int j=1; j<=9; j++)
             {
                     if(row[block[i].a][j] == false && col[block[i].b][j] == false && sqr[3*(block[i].a/3)+block[i].b/3][j] == false)
                     {
                        block[i].n[x] = j;
                        x++;
                     }
             }
             block[i].num = x;
     }
     
     return;
}
                                         
  