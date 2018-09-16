#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


//Function that prints a regular board with hits and misses

void printnormalboard(vector <vector<char> > board){
	static string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int row = 0;
	cout << "  ";

	//Print Letters on top of first row
	cout << " ";
	for (int i = 0; i < board[0].size(); i++){
		cout << alphabet[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < board.size(); i++)
		{
		//Print numbers before each row
		if(row < 9){
			cout << " " << row+1 << " ";
		}
		else {
			cout << row+1 << " ";
		}
		row++;

		//Printing the board
		for (int j = 0; j < board[i].size(); j++)
		    {
		        if(board[i][j] == 'o' || board[i][j] == 'c' || board[i][j] == 'b' || board[i][j] == 'f' || board[i][j] == 's' || board[i][j] == 'm'){
		        	cout << "." << " ";

		        }
		        else{
		        	cout << board[i][j] << " ";
		        }

		    }

		    cout << endl;
		}
}

//Function that prints a board with only the ship points(used for the cheat and end of game)

void printexposedboard(vector <vector<char> > board){
	static string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int row = 0;
	cout << "  ";

	//Print Letters on top of first row
	cout << " ";
	for (int i = 0; i < board[0].size(); i++){
		cout << alphabet[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < board.size(); i++)
		{
		//Print numbers before each row
		if(row < 9){
			cout << " " << row+1 << " ";
		}
		else {
			cout << row+1 << " ";
		}
		row++;

		//Printing the board
		for (int j = 0; j < board[i].size(); j++)
		    {
		        if(board[i][j] == 'o' || board[i][j] == 'X'){
		        	cout << "." << " ";

		        }
		        else{
		        	//Print Carrier
		        	if(board[i][j] == 'c' || board[i][j] == 'C'){
		        	cout << "C" << " ";
		        	}
		        	//Print Battleship
		        	else if(board[i][j] == 'b' || board[i][j] == 'B'){
			        	cout << "B" << " ";
		        	}
		        	//Print Frigate
			        else if(board[i][j] == 'f' || board[i][j] == 'F'){
				        cout << "F" << " ";
			        }
		        	//Print Submarine
			        else if(board[i][j] == 's' || board[i][j] == 'S'){
			        	cout << "S" << " ";
			        }
		        	//Print Minesweeper
			        else {
			        	cout << "M" << " ";
			        }
		        }

		    }

		    cout << endl;
		}
}


//Function that handles ship placement logic

vector< vector<char> > placeships(vector <vector<char> > boardplaceholder, int shipsize, char letter, int rows, int columns){
	bool placedships = false;
		while (placedships == false){

			int randomdirection = rand() % 4 + 1;
			int x = rand() % rows;
			int y = rand() % columns;

			//1= horizontal
			if (randomdirection == 1){
				bool canbeplaced = false;
			    if( ( y + (shipsize-1) ) <= (columns-1)){
			    	for(int i = 0; i < shipsize; i++){
			    		if(boardplaceholder[x][y+i] != 'o'){
			    			i = shipsize;
			    			canbeplaced = false;
			            }
			            else{
			            canbeplaced = true;}
			        }
			    if(canbeplaced == true){
			    	for(int i = 0; i < shipsize; i++){
			        	boardplaceholder[x][y+i] = letter;
			            }
			       	placedships = true;
			        }
			     }
			 }


			//2  = vertical
			if (randomdirection == 2){
				bool canbeplaced = false;
			    if( (x + (shipsize-1)) <= (rows -1 )){
			    	for(int i = 0; i < shipsize; i++){
			    		if(boardplaceholder[x+i][y] != 'o'){
			             	i = shipsize;
			                canbeplaced = false;
			    		}
			            else{
			            	canbeplaced = true;}
			        }
			    	if(canbeplaced == true){
			        	for(int i = 0; i < shipsize; i++){
			            	boardplaceholder[x+i][y] = letter;
			                }
			        	placedships = true;
			        }
			     }
			 }


			//3 = upward diagonal
			if (randomdirection == 3){
				bool canbeplaced = false;

				if((x - (shipsize-1) >= 0 ) && (y +(shipsize-1) <= (columns -1))){

				for(int i = 0; i < shipsize; i++){
					if ((i == 0) && (boardplaceholder[x-i][y+i] != 'o')){
						i = shipsize;
						canbeplaced = false;}
					else if ((i == 0) && (boardplaceholder[x-i][y+i] == 'o')){
						canbeplaced = true;}
					else if ((i != 0) && (boardplaceholder[x-i][y+i] == 'o')){
						if (((boardplaceholder[x-i][(y+i)-1] != 'o') && (boardplaceholder[(x-i)+1][y+i] == 'o')) || ((boardplaceholder[x-i][(y+i)-1] == 'o') && (boardplaceholder[(x-i)+1][y+i] != 'o'))){
							canbeplaced = true;}
						else if ((boardplaceholder[x-i][(y+i)-1] != 'o') && (boardplaceholder[(x-i)+1][y+i] != 'o')){
							i = shipsize;
							canbeplaced = false;}
						else if ((boardplaceholder[x-i][(y+i)-1] == 'o') && (boardplaceholder[(x-i)+1][y+i] == 'o')){
							canbeplaced = true;}
					}
					else{
						i = shipsize;
						canbeplaced = false;}
				}
				}

				if(canbeplaced == true){
					for(int i = 0; i < shipsize; i++){
						boardplaceholder[x-i][y+i] = letter;

					}
					placedships = true;
				}

				}


			//4 = downward diagonal
			if (randomdirection == 4){
				bool canbeplaced = false;

				if((x + (shipsize-1) <= (rows - 1)) && (y + (shipsize-1) <= (columns - 1))){

					for(int i = 0; i < shipsize; i++){
						if ((i == 0) && (boardplaceholder[x+i][y+i] != 'o')){
							i = shipsize;
							canbeplaced = false;}
						else if ((i == 0) && (boardplaceholder[x+i][y+i] == 'o')){
							canbeplaced = true;}
						else if ((i != 0) && (boardplaceholder[x+i][y+i] == 'o')){
							if (((boardplaceholder[x+i][(y+i)-1] != 'o') && (boardplaceholder[(x+i)-1][y+i] == 'o')) || ((boardplaceholder[x+i][(y+i)-1] == 'o') && (boardplaceholder[(x+i)-1][y+i] != 'o'))){
								canbeplaced = true;}
							else if ((boardplaceholder[x+i][(y+i)-1] != 'o') && (boardplaceholder[(x+i)-1][y+i] != 'o')){
								i = shipsize;
								canbeplaced = false;}
							else if ((boardplaceholder[x+i][(y+i)-1] == 'o') && (boardplaceholder[(x+i)-1][y+i] == 'o')){
								canbeplaced = true;}
						}
						else{
							i = shipsize;
							canbeplaced = false;}
					}
				}

				if(canbeplaced == true){
					for(int i = 0; i < shipsize; i++){
						boardplaceholder[x+i][y+i] = letter;

					}
					placedships = true;
				}

				}


		}
		return boardplaceholder;
}


int main(){

	//Seeding random generator function with time to prevent same random number of sequences after each run
	srand ( time(NULL) );

	//Loop that checks if user enters correct dimensions for the board
	int rows,columns;
	bool properdimensions = false;
	cout << "Minimum size: product of row x col must be greater than or equal to 30." << endl;
	while(properdimensions == false){
		cout << "Enter rows: ";
		cin >> rows;
		cout << "Enter columns: ";
		cin >> columns;
		if((rows*columns) >= 30){
			properdimensions = true;
			cout << "Welcome to Battleship" << endl;
		}
		else{
			properdimensions = false;
			cout << "Minimum size: product of row x col must be greater than or equal to 30." << endl;
		}
	}

	//Declaring the maximum amount of guesses the player will have for the game
	int guesses = 0;
	int product = rows*columns;
	if (product % 2 != 0){
		product++;
	}
	int maxguesses = ((product)/2) + 5;

	cout << "You have " << maxguesses << " guesses to find" << endl;
	cout << "\tOne Carrier of length 5" << endl;
	cout << "\tOne Battleship of length 5" << endl;
	cout << "\tOne Frigate of length 3" << endl;
	cout << "\tOne Submarine of length 3" << endl;
	cout << "\tOne Minesweeper of length 2" << endl;

	//Creating the empty board
	vector<vector<char> > board;
	for ( int x = 0 ; x < rows ; x++ ){
		vector<char> row;
		for ( int y = 0 ; y < columns ; y++ ){
			row.push_back('o');
		}
		board.push_back(row);
	}

	//Placing all ships on the board
	board = placeships(board, 5 , 'c', rows, columns);
	board = placeships(board, 5 , 'b', rows, columns);
	board = placeships(board, 3 , 'f', rows, columns);
	board = placeships(board, 3 , 's', rows, columns);
	board = placeships(board, 2 , 'm', rows, columns);

	printnormalboard(board);

	//Declaring variables and booleans that will be needed for game-play
	bool gameover = false;
	char col;
	int row;
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int carrier = 0;
	int battleship = 0;
	int submarine = 0;
	int frigate = 0;
	int minesweeper = 0;

	bool carrierbombed = false;
	bool battleshipbombed = false;
	bool submarinebombed = false;
	bool frigatebombed = false;
	bool minesweeperbombed = false;

	//Create vector that will save the bombed point locations
	vector<string> bombedpoints;

	//String that will save user bombed point location which will be compared to vector strings
	string bombedpoint;

	vector<int> possiblerows;
	int possiblerow = 0;

	for(int i = 0; i < rows; i++){
		possiblerow++;
		possiblerows.push_back(possiblerow);
	}

	vector<char> possiblecolumns;
	for(int i = 0; i < columns; i++){
		possiblecolumns.push_back(alphabet[i]);
	}

	//Loop that checks if the game is over
	while(gameover == false){

		//Loop that checks if user point is valid(not bombing the same point and cheat system)
		bool repeatedbomb = false;
		bool properbomb = false;
		while(properbomb == false){

			//Dropping bomb coordinates

			//Loop that checks for proper column input

			bool columncheck = false;
			bool propercolinput = false;
			while (columncheck == false){
				cout << "Enter col(A-" << alphabet[columns-1] << "): ";
				cin >> col;
				for(int i = 0; i < columns; i++){
					if(col == possiblecolumns[i]){
						propercolinput = true;
					}
				}
				//Checks if cheat is activated
				if(col == '?'){
					printexposedboard(board);
					columncheck = false;
				}
				else if(propercolinput == false){
					columncheck = false;
				}
				else{
					columncheck = true;
				}
			}


			//Loop that checks proper row input
			bool properrow = false;
			while(properrow == false){
				cout << "Enter row(1-" << rows << "): ";
				cin >> row;
				for(int i = 0; i< rows;i++){
					if(row == possiblerows[i]){
						properrow = true;
					}
				}
			}



			//Converts column character and row integer to separate strings that are concatenated
			string savedcol;
			savedcol+=col;
			string savedrow = to_string(row);
			bombedpoint = savedcol + savedrow;

			//Check if input location has already been bombed
			for(int i = 0; i < bombedpoints.size(); i++){
				if(bombedpoint == bombedpoints[i]){
					repeatedbomb = true;
				}
			}

			//If input location has not already been bombed, save the location in the bombed points vector
			if(repeatedbomb == false){
				properbomb = true;
				bombedpoints.push_back(bombedpoint);
			}

			else {
				cout << bombedpoint << " has already been bombed" << endl;
				properbomb = false;
			}

			repeatedbomb = false;

		}

		guesses++;

		//Convert column Letter to index number
		int convertedcol;
		for(int i = 0; i < alphabet.size(); i++){
			if(alphabet[i] == col){
				convertedcol = i;
			}
		}


		//Check if dropped bomb is a hit or miss and add amount of hits for each ship until they are destroyed
		if(board[row-1][convertedcol] == 'o'){
			board[row-1][convertedcol] = 'X';
		}
		else if(board[row-1][convertedcol] == 'c'){
			board[row-1][convertedcol] = 'C';
			carrier++;
			if(carrier == 5){
				carrierbombed = true;
				cout << "You have sunk the Carrier" << endl;
			}
		}
		else if(board[row-1][convertedcol] == 'b'){
			board[row-1][convertedcol] = 'B';
			battleship++;
			if(battleship == 5){
				battleshipbombed = true;
				cout << "You have sunk the Battleship"<< endl;
			}
		}
		else if(board[row-1][convertedcol] == 's'){
			board[row-1][convertedcol] = 'S';
			submarine++;
			if(submarine == 3){
				submarinebombed = true;
				cout << "You have sunk the Submarine" << endl;
			}
		}
		else if(board[row-1][convertedcol] == 'f'){
			board[row-1][convertedcol] = 'F';
			frigate++;
			if(frigate == 3){
				frigatebombed = true;
				cout << "You have sunk the Frigate" << endl;
			}
		}
		else {
			board[row-1][convertedcol] = 'M';
			minesweeper++;
			if(minesweeper == 2){
				minesweeperbombed = true;
				cout << "You have sunk the Minesweeper" << endl;
			}
		}

		cout << "guess="<< guesses << endl;
		printnormalboard(board);


		//Checks if player exceeded amount of guesses
		if(guesses < maxguesses){
			//Checks if all ships are bombed
			if(carrierbombed == true && battleshipbombed == true && submarinebombed == true && frigatebombed == true && minesweeperbombed == true){
				gameover = true;
				cout << "You have sunk all the ships" << endl;
			}
			else {
				gameover = false;
			}
		}

		//When player uses all guesses
		else{
			//Checks if all ships are bombed
			if(carrierbombed == true && battleshipbombed == true && submarinebombed == true && frigatebombed == true && minesweeperbombed == true){
				gameover = true;
				cout << "You have sunk all the ships" << endl;
			}
			else {
				gameover = true;
				cout << "You used up all your guesses" << endl;
				cout << "Here is where all of the ships were deployed:" << endl;
				printexposedboard(board);
			}
		}

	}
	return 0;

}

