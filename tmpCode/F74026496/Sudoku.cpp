#include"Sudoku.h"
void Sudoku::print(int arr[81])
{
        for(i=0;i<9;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=9;i<18;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=18;i<27;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=27;i<36;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=36;i<45;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=45;i<54;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=54;i<63;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=63;i<72;i++){cout<<arr[i]<<" ";}cout<<endl;
        for(i=72;i<81;i++){cout<<arr[i]<<" ";}cout<<endl;
}
void Sudoku::GiveQuestion()
 {
        pro1[1]=5; pro1[3]=4; pro1[10]=9; pro1[12]=5; pro1[19]=4; pro1[21]=6; pro1[29]=7; pro1[33]=3; pro1[38]=8; pro1[42]=7; pro1[47]=3; pro1[51]=2; pro1[59]=7; pro1[61]=8; pro1[68]=8; pro1[70]=9; pro1[77]=9; pro1[79]=5;
        for(n=0;n<81;n++)
        {
                if(n!=1&&n!=3&&n!=10&&n!=12&&n!=19&&n!=21&&n!=29&&n!=33&&n!=38&&n!=42&&n!=47&&n!=51&&n!=59&&n!=61&&n!=68&&n!=70&&n!=77&&n!=79)pro1[n]=0;
        }
        pro2[1]=5; pro2[3]=4; pro2[10]=9; pro2[12]=5; pro2[19]=4; pro2[21]=6; pro2[29]=7; pro2[33]=3; pro2[38]=8; pro2[42]=7; pro2[47]=3; pro2[51]=1; pro2[59]=7; pro2[61]=8; pro2[68]=8; pro2[70]=9; pro2[77]=9; pro2[79]=5;
        for(n=0;n<81;n++)
        {
                if(n!=1&&n!=3&&n!=10&&n!=12&&n!=19&&n!=21&&n!=29&&n!=33&&n!=38&&n!=42&&n!=47&&n!=51&&n!=59&&n!=61&&n!=68&&n!=70&&n!=77&&n!=79)pro2[n]=0;
        }
        pro3[1]=1; pro3[3]=4; pro3[10]=5; pro3[12]=1; pro3[19]=4; pro3[21]=6; pro3[29]=7; pro3[33]=3; pro3[38]=8; pro3[42]=7; pro3[47]=3; pro3[51]=2; pro3[59]=7; pro3[61]=8; pro3[68]=8; pro3[70]=5; pro3[77]=5; pro3[79]=2;
        for(n=0;n<81;n++)
        {
                if(n!=1&&n!=3&&n!=10&&n!=12&&n!=19&&n!=21&&n!=29&&n!=33&&n!=38&&n!=42&&n!=47&&n!=51&&n!=59&&n!=61&&n!=68&&n!=70&&n!=77&&n!=79)pro3[n]=0;
        }
	srandom(time(NULL));
        int choose = ((random()%3)+1);
	if(choose == 1)print(pro1);
        else if(choose == 2)print(pro2);
        else if(choose == 3)print(pro3);
}
void Sudoku::ReadIn()
{
        int i;
        for(i=0; i<81; i++)
        {
                cin >> arr[i];
        }
}
bool Sudoku::ans_check(int x, int &ans)
{
        int i,j,k;
        int found;//which cell is x in
        int remain;
        int n;
        for(remain=0;remain<=8;remain++)
        {
                if(x%9==remain)//column do not repeat
                {
                        for(n=0;n<=8;n++)
                        {
                                int column = remain+n*9;
                                if(x!=column&&arr[column]==ans)return false;
                        }
                }
                if(x/9==remain)//row do not repeat
                {
                        for(n=0;n<=8;n++)
                        {
                                int row = 9*remain+n;
                                if(x!=row&&arr[row]==ans)return false;
                        }
                }
        }
        for(i=0;i<9;i++)//find which cell is x in
        {
                for(j=0;j<9;j++)
                {
                        int n = 27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
                        if(x == n)found = i;
                }
        }
        for(k=0;k<9;k++)
        {
                int cell = 27*(found/3)+3*(found%3)+9*(k/3)+(k%3);
                if(x!=cell&&arr[cell]==ans)return false;
        }
        return true;
}
bool Sudoku::ques_check()
{
        int i;
        for(i=0;i<81;i++)
        {
                if(arr[i]<0||arr[i]>9||(arr[i]%1)!=0)
                {
                        return false;
                }
                else if(arr[i]!=0)
                {
			
			int ans=arr[i];
			if(ans_check(i,ans)==false)return false;
				
                }
        }
return true;
}
void Sudoku::equal()
{
	int i;
	for(i=0;i<81;i++)
	{
		final[i]=arr[i];
	}
}
void Sudoku::print()//唯一解才會印
{
        int i;
	cout<<endl;
        for(i=0;i<9;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=9;i<18;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=18;i<27;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=27;i<36;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=36;i<45;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=45;i<54;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=54;i<63;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=63;i<72;i++){cout<<final[i]<<" ";}cout<<endl;
        for(i=72;i<81;i++){cout<<final[i]<<" ";}cout<<endl;
	cout<<endl;
}
bool Sudoku::fill(int n)//n=0~80
{
        int ans;
        if(n==81)
        {
               num++;
		equal();//print();
                return true;
        }
	else if(num>1)return true;//若程式執行兩次就停止
        else if(arr[n]==0)//是空格
        {
                for(ans=1;ans<=9;ans++)
                {
                        if(ans_check(n,ans)==true)
                        {
                                arr[n]=ans;
				fill(n+1);
				arr[n]=0;
                        }
//			else arr[n]=0;
                }
        }
	else if(arr[n]!=0) fill(n+1);
}
bool Sudoku::Solve()
{
	if(ques_check()==false){cout<<endl<<"0\n";return false;}
	else if(ques_check()==true)
	{
		fill(0);
		if(num==0)cout<<endl<<"0\n";
		else if(num==1){cout<<endl<<"1"<<endl;print();}//唯一解
		else if(num>1)cout<<endl<<"2\n";//多重解	
	}
}
