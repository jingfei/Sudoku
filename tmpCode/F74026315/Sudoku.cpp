#include "wnew.h"

//Public
void Sudoku::GiveQuestion(){
	int i,j,a[9]={0},D;
	Type_Map One,Two,VeryHard,EXTREME,Multi,NoAns;
		srand(time(NULL));
		for(i=0;i<9;i++){ /*random get 9 numbers*/
			a[i]=(rand()%9)+1;
				for(j=i-1;j>=0;j--){
					if(a[i]==a[j]){
						a[i]=(rand()%9)+1;
						j=i;
					}
				}
		}
		D=1;
		if(D==0){
		One.m[0][4]=a[6];
        One.m[0][5]=a[3];
        One.m[0][6]=a[2];
        One.m[0][7]=a[0];
        One.m[0][8]=a[5];
        One.m[1][3]=a[5];
        One.m[1][5]=a[2];
        One.m[1][6]=a[7];
        One.m[1][7]=a[3];
        One.m[2][5]=a[7];
        One.m[2][6]=a[4];
        One.m[3][0]=a[6];
        One.m[3][1]=a[1];
        One.m[3][2]=a[4];
        One.m[3][3]=a[7];
        One.m[3][7]=a[2];
        One.m[3][8]=a[3];
        One.m[4][4]=a[2];
        One.m[4][7]=a[4];
        One.m[5][5]=a[1];
        One.m[5][6]=a[6];
        One.m[5][7]=a[8];
        One.m[5][8]=a[7];
        One.m[6][2]=a[7];
        One.m[6][3]=a[8];
        One.m[6][4]=a[3];
        One.m[7][1]=a[3];
        One.m[7][4]=a[7];
        One.m[7][5]=a[4];
        One.m[7][6]=a[8];
        One.m[8][0]=a[8];
        One.m[8][1]=a[6];
        One.m[8][2]=a[0];
        One.m[8][3]=a[2];
        One.m[8][4]=a[1];
        One.m[8][5]=a[5];
        One.m[8][6]=a[3];
        One.m[8][7]=a[7];
        One.m[8][8]=a[4];
		
        	ReturnMap(One);
    	}
		else if(D==1){
		Two.m[0][2]=a[7];
        Two.m[0][3]=a[1];
        Two.m[0][7]=a[6];
        Two.m[1][4]=a[4];
        Two.m[1][8]=a[2];
        Two.m[2][0]=a[5];
        Two.m[3][1]=a[2];
        Two.m[3][8]=a[3];
        Two.m[4][8]=a[4];
        Two.m[5][2]=a[8];
        Two.m[5][5]=a[7];
        Two.m[6][7]=a[7];
        Two.m[7][5]=a[2];
        Two.m[7][7]=a[8];
        Two.m[8][1]=a[4];
        Two.m[8][4]=a[3];
        Two.m[8][5]=a[0];
		ReturnMap(Two);	
		}
		else if(D==2){
		VeryHard.m[0][3]=a[5];
        VeryHard.m[0][6]=a[0];
        VeryHard.m[0][7]=a[3];
        VeryHard.m[0][8]=a[1];
        VeryHard.m[1][1]=a[1];
        VeryHard.m[1][2]=a[5];
        VeryHard.m[2][0]=a[6];
        VeryHard.m[2][5]=a[3];
        VeryHard.m[2][8]=a[8];
        VeryHard.m[3][5]=a[5];
        VeryHard.m[3][6]=a[1];
        VeryHard.m[4][1]=a[5];
        VeryHard.m[4][3]=a[8];
        VeryHard.m[4][5]=a[0];
        VeryHard.m[4][7]=a[4];
        VeryHard.m[5][2]=a[4];
        VeryHard.m[5][3]=a[2];
        VeryHard.m[6][0]=a[8];
        VeryHard.m[6][3]=a[3];
        VeryHard.m[6][8]=a[6];
        VeryHard.m[7][6]=a[7];
        VeryHard.m[7][7]=a[0];
        VeryHard.m[8][0]=a[7];
        VeryHard.m[8][1]=a[3];
        VeryHard.m[8][2]=a[1];
        VeryHard.m[8][5]=a[6];
        ReturnMap(VeryHard);
    	}
    	else{
        EXTREME.m[0][0]=a[7];
        EXTREME.m[1][2]=a[2];
        EXTREME.m[1][3]=a[5];
        EXTREME.m[2][1]=a[6];
        EXTREME.m[2][4]=a[8];
        EXTREME.m[2][6]=a[1];
        EXTREME.m[3][1]=a[4];
        EXTREME.m[3][5]=a[6];
        EXTREME.m[4][4]=a[3];
        EXTREME.m[4][5]=a[4];
        EXTREME.m[4][6]=a[6];
        EXTREME.m[5][3]=a[0];
        EXTREME.m[5][7]=a[2];
        EXTREME.m[6][2]=a[0];
        EXTREME.m[6][7]=a[5];
        EXTREME.m[6][8]=a[7];
        EXTREME.m[7][2]=a[7];
        EXTREME.m[7][3]=a[4];
        EXTREME.m[7][7]=a[0];
        EXTREME.m[8][1]=a[8];
        EXTREME.m[8][6]=a[3];        	
        ReturnMap(EXTREME);        	
        }
        
}
void Sudoku::ReadIn(){
	int i,j;
	int TheNum;
	CheckReadIn=1;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cin>>TheNum;
			if(!SetMap(TheNum,i,j))CheckReadIn=0;
			if(TheNum==0)SetPossible(i,j);
		}
	}
	if(Waiting.size()==0)CheckReadIn=2;
	for(i=0;i<Waiting.size();i++){
		if(!FindPossible(i))CheckReadIn=0;
	}
}
int Sudoku::Solve(){
	if(CheckReadIn==0){cout<<0<<endl;return 0;}
	else if(CheckReadIn==2){cout<<1<<endl;ReturnMap(Map);return 1;}
	int i,j,Min,N;
	int NofAns=0,TheNum,RunTime,check;
	Type_P Possible;
	
	while(Waiting.size()>0){
		Min=9;
		
		for(i=0;i<Waiting.size();i++){ //find the Least Possibility
		if(Min>Waiting[i].num){
			Min=Waiting[i].num;
			N=i;
			if(Min==1)break;
		}
		}

		if(Waiting[N].num<=0){NofAns=0;break;}
		else if(Waiting[N].num==1){
			if(!SetMap(Waiting[N].P[0],Waiting[N].R,Waiting[N].C)){NofAns=0;break;}
			if(!DeleteOnePossible(N)){NofAns=0;break;}
			NofAns=1;
		}
		else{
			SMap.push_back(Map);SWaiting.push_back(Waiting);//store old map
			RunTime=Waiting[N].num; check=0;
			NofAns=0;
			for(j=0;j<RunTime;j++){ //Wash danger
				TheNum=Waiting[N].P[j];
				Waiting[N].num=1; //reset Waiting
				Waiting[N].P.clear();Waiting[N].P.push_back(TheNum);
				
				check=Solve();
				NofAns+=check;
				
				if(j==RunTime-1){ //Last
					SWaiting.erase(SWaiting.end());
					SMap.erase(SMap.end());
					
					if(check){//11  or 01
						if(NofAns>1)NofAns=2;
						else NofAns=1;
					}
					else if((!check)&&NofAns){//10
						Map=RMap;Waiting=RWaiting;
						if(NofAns>1)NofAns=2;
						else NofAns=1;
					}
					else if((!check)&&(!NofAns)){//00
						NofAns=0;
					}
				}
				else {//Not Last
					
					if(check){
						RMap=Map;RWaiting=Waiting;
						Map=SMap[SMap.size()-1];Waiting=SWaiting[SWaiting.size()-1];//recover
					}
					else{
						Map=SMap[SMap.size()-1];Waiting=SWaiting[SWaiting.size()-1];//recover
					}
					if(NofAns>=2){
						SWaiting.erase(SWaiting.end());
						SMap.erase(SMap.end());
						break;
					}
				}
				
			}
			if(NofAns>=2){NofAns=2;break;}
		}
		
	}
	if(SWaiting.size()==0)
		switch (NofAns){
			case 0:
				cout<<0<<endl;break;
			case 1:
				cout<<1<<endl;
				ReturnMap(Map);break;
			case 2:
				cout<<2<<endl;break;		
		}
	 
		switch (NofAns){
			case 0:
				return 0;
			case 1:
				return 1;
			case 2:
				return 2;		
		}
		
	return -1;
}
//Private
void Sudoku::SetPossible(int R,int C){
	Type_P possible;
	int K=3*((int)R/3)+(C/3);
	
	possible.R=R;
	possible.C=C;
	possible.K=K;
	possible.num=0;
	Waiting.push_back(possible);
}
bool Sudoku::SetMap(int Num,int R,int C){
	int K=3*((int)R/3)+(C/3);
	if(Num>9||Num<0)return 0;
		
	if(Num!=0){
		if(Map.row[R][Num-1]!=0||Map.col[C][Num-1]!=0||Map.cell[K][Num-1]!=0)return 0;
		Map.row[R][Num-1]++;
		Map.col[C][Num-1]++;
		Map.cell[K][Num-1]++;
	}
	Map.m[R][C]=Num;
	return 1;
}
bool Sudoku::FindPossible(int N){
	int i,count=0,R=Waiting[N].R,C=Waiting[N].C,K=Waiting[N].K;
	bool check;
	for(i=0;i<9;i++){
		check=!(Map.row[R][i]+Map.col[C][i]+Map.cell[K][i]);
		if(check){
			count++;
			Waiting[N].P.push_back(i+1);
		}
	}
	if(count==0)return 0;
	
	Waiting[N].num=count;
	return 1;
} 


bool Sudoku::DeleteOnePossible(int N){//Wait for Update
	int i,k;
	for(i=0;i<Waiting.size();i++){
		if(i==N)continue;
		
		if( Waiting[N].R==Waiting[i].R|| \
			Waiting[N].C==Waiting[i].C|| \
			Waiting[N].K==Waiting[i].K)
			for(k=0;k<Waiting[i].num;k++){
				if(Waiting[i].P[k]>Waiting[N].P[0])break;
				else if(Waiting[i].P[k]==Waiting[N].P[0]){
					Waiting[i].P.erase(Waiting[i].P.begin()+k);
					Waiting[i].num--;
					if(Waiting[i].num<=0)return 0;
					/*
					else if(Waiting[i].num==1){
						if(!SetMap(Waiting[i].P[0],Waiting[i].R,Waiting[i].C))return 0;
						if(!DeleteOnePossible(i))return 0;
					}*/
					break;
				}
			}
	}
	Waiting.erase(Waiting.begin()+N);
	return 1;	
}
void Sudoku:: ReturnMap(Type_Map map){
	int i,j;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				cout<< map.m[i][j]<<" "; 
		cout<<endl;	
		}
}
