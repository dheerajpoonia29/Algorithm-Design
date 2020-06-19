#include "../macro.h"

/*
theory: https://www.youtube.com/watch?v=xFv_Hl4B83A&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=64
code: https://www.youtube.com/watch?v=jFwREev_yvU&t=466s
6 lines of code: https://www.youtube.com/watch?v=u6viVC1fJ9g
*/
class N_QUEEN{
	vector<vector<char>> board;
	int n;
	public:		
		N_QUEEN(int board_size){
			this->n = board_size;
			board.resize(n, vector<char>(n, '.'));			
			solve(0);
		}

		bool isQueenSafe(int i, int j){
			int x,y;			

			// case 1: previous queen place on same coloumn above 
			for(int row=0; row<i; row++)
				if(board[row][j]=='Q')
					return false;

			// case 2: previous queen place on left diagonal
			x=i; y=j;
			while(x>=0 && y<n){
				if(board[x][y]=='Q')
					return false;
				x--; y--;
			}
			
			// case 3: previous queen place on right diagonal
			x=i; y=j;
			while(x>=0 && y<n){
				if(board[x][y]=='Q')
					return false;
				x--; y++;
			}

			// case 4: queen is safe 
			return true;
		}

		bool solve(int i){
			// base case 
				if(i==n){
					// filled all row 
					return true; 
					// return false -> for all possible ans 
				}

			// recursive case 
				// filling queen row by row and if queen is unsafe then we backtrack 
				// trying to place queen at all places
				for(int j=0; j<n; j++){
					// 1ST CHOICE: 
					//we are at [i,j]th place, here we have to check wheather [i,j]th position is safe or not
					if(isQueenSafe(i,j)){
						board[i][j] = 'Q';

						// 2ND CONTRAINT:
						//after filling [i,j]th position do we have space for next queen
						bool kyaNexTQueenRakhPayege = solve(i+1);
						if(kyaNexTQueenRakhPayege)
							return true; // go next 
						else{
							board[i][j] = '_'; // here backtracking happen, we reset set queen
						}
					}
				}
				return false;				
		}
		// 3RD GOAL: 
		//fill n queen

		void printBoard(){
			pm(board);
		}
};


/*
theory: https://www.youtube.com/watch?v=kyLxTdsT8ws&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=65
class SUM_OF_SUBSET{
	
};


/*
video: (abdul bari) https://www.youtube.com/watch?v=dQr4wZCiJJ4&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=67

class HAMILTONIAN_CYCLE{

}


/*
video: https://www.youtube.com/watch?v=052VkKhIaQ4&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=66

class GRAPH_COLORING{

}


/*
video: (swe) https://www.youtube.com/watch?v=JzONv5kaPJM&list=PLiQ766zSC5jM2OKVr8sooOuGgZkvnOCTI&index=16
tc(9^(n*n)) sc(n*n)
*/
class SUDOKU{
	vector<vector<int>> board;
	public:
		SUDOKU(vector<vector<int>> input){
			board = input;
			solve();
		}	

		bool doWePlace(int i,int j,int digit){
			// checking on same row			 
			for(int row=0; row<i; row++)
				if(board[row][j]==digit)
					return false;

			// checking on same col
			for(int col=0; col<j; col++)
				if(board[i][col]==digit)
					return false;
				
			// 3*3 grid, digit no present
			int radd = i-i%3, cadd = j-j%3;

			for(int row=0; row<3; row++){
				for(int col=0; col<3; col++)
					if(board[row+radd][col+cadd]==digit)
						return false;
			}	
		
			return true;
		}

		vector<int> findEmptyCell(){
			vector<int> index;
			for(int i=0; i<9; i++)
				for(int j=0; j<9; j++)
					if(board[i][j]==0){
						index.pb(i);	index.pb(j);
					}
			return index;
		}

		bool solve(){
			// BASE CASE
				vector<int> index = findEmptyCell();
				if(index.size()<1)  // sudoku filled 
					return true; 

			// RECURSIVE CASE
				int i = index[0];
				int j = index[1]; 
				bool placed = false;
				// 1st CHOICE: 
				// digit [1-9]
				for(int digit=1; digit<=9; digit++){
					// 2nd CONTRAINT:
					// check digit does not appear in same coloumn & row
					if(doWePlace(i,j,digit)==true){
						board[i][j] = digit;							
						
						if(solve()==true)
							return true;
						else 
							board[i][j] = 0; // backtracking happen
					}						
				}				
				return false;
		}
		// 3rd GOAL: fill the entire board

		void printBoard(){
			pm(board);
		}
};


/*
// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

class RAT_IN_A_MAZE{

}


/*
https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

class KNIGHTS_TOUR{

}
*/