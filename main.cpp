#include <iostream>
#include <Eigen/Dense>
#include <stdlib.h>
#include <string>

using Eigen::MatrixXd;
using Eigen::VectorXd;

// This shit is for setting the sigma board like a gigachad. Returns error if:
// 1. Invalid element
// 2. The element is not 0 (empty)
void setBoard(MatrixXd& board, int row, int column, bool isPlayer){
	if(row < 0 || row > 2) throw "Ya fucked up row, cunt";
	if(column < 0 || column > 2) throw "Ya fucked up column, cunt";
	if(board(row, column) != 0 ) throw "You bitch";
	board(row, column) = (isPlayer) ? -1 : 1;
}

// This function basically asks the sigma for what input is the bitchass n***a gonna put.
// Needs the moveRow and moveCol on the higher level function to actually store the input otherwise ur a bitch.
void playerMove(int& moveRow, int& moveCol){
	std::string inputRow, inputCol;
	std::cin >> inputRow;
	std::cin >> inputCol;
	try {
		moveRow = std::stoi(inputRow);
		moveCol = std::stoi(inputCol);
	}catch(...) {
		std::cout << "Wrong input, bitch.\n";
		throw "Wrong Input";
	}
}

void AIMove(){
	throw "Not yet implemented lmao";
}

// Didn't know what to name on this one but it's basically returning what the fuck is that element represents
// if 1 then AI, if -1 then Player
// Notice I don't have 0 which is empty
// Because I'm so retarded that I expected myself to only use this function when the game ends, potentionally a drawback function who knows
// and I am such a sigma
std::string otenShit(int boardValue){
	return ((boardValue == 1) ? "AI" : "Player");
}

// This one checks if the board is boarding the board board
// Throws some shi if "
void checkBoard(MatrixXd &board){
	bool draw = true;
	for(int i = 0; i < 3; i++){
		// Since 0 means empty and empty means 0, then cock can suck my asscrack and my asscrack suck my cock
		// if the product of this bushit is 0, that means there exist an element which is 0, so the game is not yet ending
		if(draw) if(board(0,i) * board(1,i) * board(2,i)) draw = false;
		if(board(i,1) != 0) if (board(i,0) == board(i, 1) && board(i, 1) == board(i, 2)) throw otenShit(board(i,1));
		if(board(1,i) != 0) if (board(0,i) == board(1,i) && board(1,i) == board(2,i)) throw otenShit(board(1,i));
		if(board(1,1) != 0) if (board(0,i) == board(1,1) && board(1,1) == board(2, 2-i)) throw otenShit(board(1,1));
	}

	// Assuming there was no aligned oten, since otherwise the loop would throw otenShit, if the flag didnt false, that means there is no 0 element
	// Therefore the game ends a draw. HA! Logic bweeeee :3
	if(draw) throw "Draw";
}

int main(){
	MatrixXd board = MatrixXd::Zero(3,3);
	
	int moveRow, moveCol;
	bool turnFlag = false;	
	//Game loop
	while(true){
		std::cout << board << '\n';
		
		turnFlag = !turnFlag;
		try {
			//Player Input
			if(turnFlag) playerMove(moveRow, moveCol);
			//AI Input
			else AIMove();
		} catch (...) { //When player is fucking with the input or AI somehow fucked up
			continue;
		}

		//Change the board state
		try {
			setBoard(board, moveRow, moveCol, turnFlag);
		} catch (...) { // When both of these bitches tries to make an illegal move
			std::cout << "hoy";
		}

		try {
			checkBoard(board);
		} catch (...) {
			//put the reward shit here
			break; // just break it for now like a good little boy :3
		}

		system("clear");
	}
}
