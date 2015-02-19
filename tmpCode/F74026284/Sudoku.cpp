#include "Sudoku.h"
const int MAXN=(9+9+9)*9 +9*9 + 9*9*9*9*9*4;
int Up[MAXN],Down[MAXN],Left[MAXN],Right[MAXN];
    int Head[MAXN],Row[MAXN],Column[MAXN],S[MAXN],A[MAXN];
    Sudoku::Sudoku()
    {
        depth=0;
        Answer=0;
        head=0;
        size=0;
        int i,j;
        for(i=0;i<81;i++)
        {
          map[i]=0;
          res[i]=0;
        }
    }
    
    void Sudoku::DLX()
    {
//      printf("Depth:%d\n",depth);
        if(Answer>1)return ;
        if(Right[head]==head)
        {
//      printf("Success.\n");
            int num;
                Answer++;
                std::sort(A,A+81);
            int p=0;
            int i,j,rs=0;
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    num=A[p++];
                    num-=(i*9+j)*9;
                    res[rs++]=num;
//                  printf("%d ",num);
                }
//              printf("\n");
            }
        return ;
        }
        int s=INF,pivot;
        int i,j;
        for (i=Right[head];i!=head;i=Right[i])
        {
            if (S[i]<s)
            {
                s=S[i];
                pivot=i;
            }
        }
//      printf("2");
        remove(pivot);
        for(i=Down[pivot];i!=pivot;i=Down[i])
        {
//            printf("Default");
              A[depth++]=Row[i];
              for(j=Right[i];j!=i;j=Right[j])
                remove(Column[j]);
              DLX();
              for(j=Left[i];j!=i;j=Left[j])
                resume(Column[j]);
        }
//      printf("3");
        resume(pivot);
        return ;
    }

    void Sudoku::Initialization(int n)
    {
        size=n+1;
		int i;
        for(i=0;i<=n;i++)
        {
			Head[i]=0;
			Up[i]=i;
            Down[i]=i;
            Left[i]=i-1;
            Right[i]=i+1;
            S[i]=0;
        }
		Right[n]=0;
        Left[0]=n;
        S[0]=INF+1;         
    }

    void Sudoku::insert(int i, int j)
    {
        if(Head[i])
        {
            Left[size]=Left[Head[i]];
            Right[size]=Head[i];
            Left[Right[size]]=size;
            Right[Left[size]]=size;
        }
        else
        {
            Left[size]=size;
            Right[size]=size;
            Head[i]=size;
        }
        Up[size]=Up[j];
        Down[size]=j;
        Up[Down[size]]=size;
        Down[Up[size]]=size;
        Column[size]=j;
        Row[size]=i;
        ++S[j];
        ++size;
    }
	void Sudoku::remove(int pivot)
    {
        Left[Right[pivot]]=Left[pivot];
        Right[Left[pivot]]=Right[pivot];
        for(int i=Down[pivot];i!=pivot;i=Down[i])
        {
            for(int j=Right[i];j!=i;j=Right[j])
            {
                Up[Down[j]]=Up[j];
                Down[Up[j]]=Down[j];
                S[Column[j]]--;
            }
        }
    }
    void Sudoku::resume(int pivot)
    {
	Left[Right[pivot]]=pivot;
        Right[Left[pivot]]=pivot;
        for(int i=Up[pivot];i!=pivot;i=Up[i])
        {
            for(int j=Left[i];j!=i;j=Left[j])
            {
                S[Column[j]]++;
                Up[Down[j]]=j;
                Down[Up[j]]=j;
            }
         }  
    }

    void Sudoku::buildDL()
    {
        int p=0;
        int i,j,key,grid,b;
        Initialization(324);
        for(i=0;i<9;i++)
        {
            for(j=1;j<=9;j++,p++)
            {
                grid=(j-1)/3*3+i/3;
                b=(i*9+j-1)*9;
                if(map[p]==0)
                {
                    for(key=1;key<=9;key++)
                    {
                        insert(b+key,i*9+key);
                        insert(b+key,9*9+(j-1)*9+key);
                        insert(b+key,9*9*2+grid*9+key);
                        insert(b+key,9*9*3+i*9+j);
                    }
                }
                else
                {
                    key=map[p];
                    insert(b+key,i*9+key);
                    insert(b+key,9*9+(j-1)*9+key);
                    insert(b+key,9*9*2+grid*9+key);
                    insert(b+key,9*9*3+i*9+j);
                }
            }
        }
    }
    void Sudoku::Solve()
    {

        int i;
        buildDL();
        DLX();
                if(Answer)
                        {
                           if(Answer==1)
                                    {   printf("1\n");
                                       for(i=0;i<81;i++)
                                                    {
                                                        printf("%d ",res[i]);
                                                        if((i+1)%9==0)putchar('\n');
                                                    }
                                    }
                            else printf("2\n");
                        }
                else printf("0\n");
        return ;
    }
    void Sudoku::ReadIn()
    {
        int i;
        for(i=0;i<81;i++)
        {
                scanf(" %d",&map[i]);
        }
    }

void Sudoku::GiveQuestion()
{
        int i,j;
        int array[9][9]=
        {
                0,0,0,0,0,0,0,1,2,
                                0,4,0,0,5,0,0,0,0,
                                0,0,0,0,0,9,0,0,0,
                                0,7,0,6,0,0,4,0,0,
                                0,0,0,1,0,0,0,0,0,
                                0,0,0,0,0,0,0,5,0,
                                0,0,0,0,8,7,5,0,0,
                                6,0,1,0,0,0,3,0,0,
                                2,0,0,0,0,0,0,0,0
        };
        int array2[9][9]=
        {
0,0,0,0,0,0,0,1,5,
3,0,0,6,0,0,0,0,0,
0,0,0,0,0,0,0,8,0,
6,0,0,0,5,0,2,0,0,
0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,4,0,
0,1,0,2,0,0,7,0,0,
0,0,0,7,6,0,3,0,0,
0,0,8,0,0,0,0,0,0
        };
        int array3[9][9]=
        {
                0,0,0,0,0,2,7,5,0,
                0,1,8,0,9,0,0,0,0,
                0,0,0,0,0,0,0,0,0,
                4,9,0,0,0,0,0,0,0,
                0,3,0,0,0,0,0,0,8,
                0,0,0,7,0,0,2,0,0,
                0,0,0,0,3,0,0,0,9,
                7,0,0,0,0,0,0,0,0,
                5,0,0,0,0,0,0,8,0
        };
 
        {
                for(i=0;i<9;i++)
                        {
                                for(j=0;j<9;j++)
                                        {
                                                printf("%d ",array2[i][j]);
                                        }
                                        printf("\n");
                        }
        }
        
        

}