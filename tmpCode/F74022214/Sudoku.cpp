 /*
 * Sudoku.cpp
 *
 *  Created on: 2014/3/27
 *      Author: LukeWu
 */

#include <iostream>
#include <algorithm>
#include <ctime>
#include "Sudoku.h"

Sudoku::Sudoku() {
	int i;
	for (i = 0; i < size; i++) {
		solvable = 0;
		sure = true;
		map[i] = 0;
		possible[i].num = 9;
		possible[i].candidate[1] = 0;
		possible[i].candidate[2] = 0;
		possible[i].candidate[3] = 0;
		possible[i].candidate[4] = 0;
		possible[i].candidate[5] = 0;
		possible[i].candidate[6] = 0;
		possible[i].candidate[7] = 0;
		possible[i].candidate[8] = 0;
		possible[i].candidate[9] = 0;
		possible[i].no = i;
	}
}

Sudoku::~Sudoku() {
	int i;
	buf.clear();
	logger.clear();
	for(i=0;i<10;i++){
		possibility_counter[i].clear();
	}
}

void Sudoku::ReadIn() {
	int i;
	for (i = 0; i < size; i++) {
		std::cin >> map[i];
		if (map[i] != 0)
			FindPossibility(i, 0);
	}
	return;
}

bool Sudoku::FindPossibility(int position, int x) {
	int i,j, num = map[position], row = position / 9, col = position % 9;
	bool b=true;

	for (i = col; i < size; i += 9) {
		if(i!=position)
			if(!DeletePossibility(i, num, x))b=false;
	}
	for (i = row * 9; i < row * 9 + 9; i++) {
		if(i!=position)
			if(!DeletePossibility(i, num, x))b=false;
	}
	for(i=(row/3)*3;i<(row/3+1)*3;i++){
		for(j=(col/3)*3;j<(col/3+1)*3;j++){
			if(i!=row && j!=col)
				if(!DeletePossibility(i*9+j , num, x))b=false;
		}
	}
	possible[position].num = 0;
	return b;
}

bool Sudoku::DeletePossibility(int position, int num, int x) {
	if (possible[position].candidate[num] == 0 && possible[position].num != 0) {
		if (x == 1){
			if(possible[position].num==1) {
				return false;
			}
			SwapLevel(position, possible[position].num, possible[position].num - 1);
		}
		possible[position].num--;
	}
	if(possible[position].num>0)possible[position].candidate[num]++;
	return true;
}

void Sudoku::Solve() {
	int i,j;
	for (i = 0; i < size; i++) {
		possibility_counter[possible[i].num].push_back(possible[i].no);
	}
	fill(FindTarget(),true);
	Output();
	return;
}

int Sudoku::FindTarget() {
	int i;
	for (i = 1; i <= 9; i++) {
		if (possibility_counter[i].size() != 0) {
			return i;
		}
	}
	return 0;
}

void Sudoku::SwapLevel(int no, int before, int after) {
	std::vector<int>::iterator it;
	log l;
	l.before = before;
	l.after = after;
	l.no=no;
	it = std::find(possibility_counter[before].begin(),
			possibility_counter[before].end(), no);
	if(it<possibility_counter[before].end())possibility_counter[before].erase(it);
	possibility_counter[after].push_back(no);
	logger.push_back(l);
	if (possibility_counter[0].size() == 81){
		solvable++;
		buf.assign(map,map+size);	
	}
	return;
}

void Sudoku::RestoreCounter(unsigned int log_size) {
	int after,before,no,i;
	std::vector<int>::iterator it;
	while(logger.size()>log_size) {
		after=logger.back().after;
		before=logger.back().before;
		no=logger.back().no;
		it = std::find(possibility_counter[after].begin(),
                        possibility_counter[after].end(), no);

		possibility_counter[before].push_back(*it);
		it=possibility_counter[after].erase(it);
		logger.pop_back();
		possible[no].num = before;
	}
	return;
}

void Sudoku::Restore(int position,int num) {

	if(possible[position].num>0 && possible[position].candidate[num]>0)possible[position].candidate[num]--;
	return;
}

void Sudoku::RestorePossibility(int position) {
	int i,j, row = position / 9, col = position % 9 ,num = map[position];

	for (i = col; i < size; i += 9) {
		if (i != position)Restore(i,num);
	}
	for (i = row * 9; i < row * 9 + 9; i++) {
		if (i != position)Restore(i,num);
	}
	for(i=(row/3)*3;i<(row/3+1)*3;i++){
		for(j=(col/3)*3;j<(col/3+1)*3;j++){
			if(i!=row && j!=col)Restore(i*9+j,num);
		}
	}
	map[position]=0;
	return;
}

void Sudoku::fill(int num,bool sure) {
	if(num==0)return;
	unsigned int i,j,l,sum=0,log_size=logger.size();
	int target= possibility_counter[num][0],t=0,count=possible[target].num;
	bool b;

	for (i = 1; i <= 9; i++){
		if(possible[target].candidate[i] == 0) {
		
			t++;

			map[target] = i ;
			b=FindPossibility(target, 1);
			SwapLevel(target, num, 0);
			if(solvable>1)return;;
			if(sure && t==count && b)fill(FindTarget(),true);
			else if(b) fill(FindTarget(),false);
			if ( !sure || t<count) {

				RestoreCounter(log_size);
				RestorePossibility(target);
				possible[target].num=count;
			} else if(t==count){
				return;
			}
		};
	}
	return;
}

void Sudoku::Output() {
	int i,j;
	switch (solvable) {
	case 0:
		std::cout << "0" << std::endl;
		break;
	case 1:
		std::cout << "1" << std::endl;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				std::cout<<buf[i*9+j]<<" ";
			}
			std::cout<<std::endl;
		}
		break;
	case 2:
		std::cout << "2" << std::endl;
		break;
	}
	return;
}

void Sudoku::GiveQuestion()
{
	srand(time(NULL));
	int i,position=rand()%81,num=rand()%9+1,space[10];
	map[position]=num;
	FindPossibility(position,0);
	 for (i = 0; i < size; i++) {
                possibility_counter[possible[i].num].push_back(possible[i].no);
        }	
	fill(FindTarget(),true);
	for(i=0;i<10;i++){
		space[i]=rand()%81;
		buf[space[i]]=0;
	}
	for(i=0;i<size;i++){
		std::cout<<buf[i]<<" ";
		if(i%9==8)std::cout<<std::endl;
	}
	return;	
}
