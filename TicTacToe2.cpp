

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int NUM_SQUARES = 9;
const char EMPTY = 's';
char Player_Pawn = 'X';
char PC_Pawn = 'O';
int GotWinner = 0;

vector<char> Board (NUM_SQUARES, EMPTY);



//блок ввода данных от пользователя. По-хорошему, сделать защиту от дурака(через массив или цикл). Но я не стал, тк впритык успеваю(
int Cin(int move) {
	

	cin >> move;
	
	if (Board[move] != EMPTY/*если ячейка занята*/)
	{
		while (Board[move] != EMPTY)
		{
			cin.clear();
			cout << "wrong int\n";
			cin >> move;
		}
		return move;
	}
	else
	{
		cout << "right int\n";
		return move;
	}

}

void ShowMeTheBoard(vector <char>& board)
{		
//для удобства игрока, я хотел сделать так, чтобы он видел, на какую цифру-куда нажимать
	cout << endl;
	cout << "\t " << (board[0] == EMPTY ? '0' : board[0]) << " | " << (board[1] == EMPTY ? '1' : board[1]) << " | " << (board[2] == EMPTY ? '2' : board[2]) << endl;
	cout << "\t" << "-----------" << endl;
	cout << "\t " << (board[3] == EMPTY ? '3' : board[3]) << " | " << (board[4] == EMPTY ? '4' : board[4]) << " | " << (board[5] == EMPTY ? '5' : board[5]) << endl;
	cout << "\t" << "-----------" << endl;
	cout << "\t " << (board[6] == EMPTY ? '6' : board[6]) << " | " << (board[7] == EMPTY ? '7' : board[7]) << " | " << (board[8] == EMPTY ? '8' : board[8]) << endl << endl;
}
char fBoard(vector <char>& board,int move,char pawn)
{
	//очень громоздкий код, я знаю. Делал изначально через матрицу. Сам же постоянно путался. Решил так. Чтобы нагляднее
	board[move] = pawn;
	
	if ((board[0] == board[1] && board[1] == board[2] && board[0] == Player_Pawn) ||
		(board[3] == board[4] && board[4] == board[5] && board[4] == Player_Pawn) ||
		(board[6] == board[7] && board[7] == board[8] && board[8] == Player_Pawn) ||

		(board[0] == board[3] && board[3] == board[6] && board[6] == Player_Pawn) ||
		(board[1] == board[4] && board[4] == board[7] && board[4] == Player_Pawn) ||
		(board[2] == board[5] && board[5] == board[8] && board[8] == Player_Pawn) ||

		(board[0] == board[4] && board[4] == board[8] && board[4] == Player_Pawn) ||
		(board[6] == board[4] && board[4] == board[2] && board[4] == Player_Pawn))

	{
		GotWinner = 1;
		return Player_Pawn;

	}
	else if (
		(board[0] == board[1] && board[1] == board[2] && board[2] == PC_Pawn) ||
		(board[3] == board[4] && board[4] == board[5] && board[3] == PC_Pawn) ||
		(board[6] == board[7] && board[7] == board[8] && board[8] == PC_Pawn) ||

		(board[0] == board[3] && board[3] == board[6] && board[6] == PC_Pawn) ||
		(board[1] == board[4] && board[4] == board[7] && board[4] == PC_Pawn) ||
		(board[2] == board[5] && board[5] == board[8] && board[8] == PC_Pawn) ||

		(board[0] == board[4] && board[4] == board[8] && board[4] == PC_Pawn) ||
		(board[6] == board[4] && board[4] == board[2] && board[4] == PC_Pawn))
	{
		GotWinner = 2;
		return PC_Pawn;
	}
	else
	{
		GotWinner=0;
		return 'U';
	}
}

//2 дня мучился, как реализовать только этот блок. Моя гордость)) наверно, десятый вариант, который оказался работоспособным 
int PC(vector <char> board)
{	
	for (size_t i = 0; i < NUM_SQUARES; i++)
	{
		if (board[i]==EMPTY)
		{
			if (fBoard(board, i, Player_Pawn) == Player_Pawn)
			{
				return i;
			}
			else 
			{
				fBoard(board, i, EMPTY);
			}
				if (fBoard(board, i, PC_Pawn) == PC_Pawn)
			{
				return i;
			}
			else 
			{
				fBoard(board, i, EMPTY);
			}
		}
		else {
		}
	}
	for (size_t i = 0; i < NUM_SQUARES; i++)
	{
		if (board[i] == EMPTY) {
			return i;
		}
	}
	cout << "round draw\n";
	return 9;
//я понимаю как можно улучшить скрипт и оптимизировать, но чет ссыкотно ввязываться)
}
void Intro()
//декор)
{
		cout << endl;
		cout << "   _______  ___   _______    _______  _______  _______    _______  _______  _______" << endl;
		cout << "  |       ||   | |       |  |       ||   _   ||       |  |       ||       ||       |" << endl;
		cout << "  |_     _||   | |       |  |_     _||  |_|  ||       |  |_     _||   _   ||    ___|" << endl;
		cout << "    |   |  |   | |       |    |   |  |       ||       |    |   |  |  | |  ||   |___ " << endl;
		cout << "    |   |  |   | |      _|    |   |  |       ||      _|    |   |  |  |_|  ||    ___|" << endl;
		cout << "    |   |  |   | |     |_     |   |  |   _   ||     |_     |   |  |       ||   |___ " << endl;
		cout << "    |___|  |___| |_______|    |___|  |__| |__||_______|    |___|  |_______||_______|" << endl<<endl;
		system("pause");
		system("cls");
		cout << "\nHi There. This is a TicTacToe. You should Won your opponent.\n\n"<<endl;				
}

//устанавливаем очередность
char SetPawn() 
{
	char question;
	do
	{
		cout << "Do you want to be First? (y/n)";
		cin >> question;
	} while (question!='y'&& question!='n');
	if (question=='y')
	{
		return Player_Pawn;
	}
	else
	{
		return PC_Pawn;
	}
	
}

int main()
{
	//покажет правила
	Intro();

	int move=0;
	int PC_Move;
	//Если первым ходит игрок
	if (SetPawn()==Player_Pawn)
	{
		ShowMeTheBoard(Board);
		while (GotWinner == 0)
		{
			cout << "Your Turn : \n";
			fBoard(Board, Cin(move), Player_Pawn);

			system("cls");

			PC_Move = PC(Board);
			//Определяем ничью
			if (PC_Move == NUM_SQUARES)
			{
				break;
				cout << "Round Draw\n";
			}
			fBoard(Board, PC_Move, 'O');
			ShowMeTheBoard(Board);
		}


	}
	//Если Игрок не хочет идти первым
	else
	{
		while (GotWinner == 0)
		{
			PC_Move = PC(Board);
			//Определяем ничью
			if (PC_Move == NUM_SQUARES)
			{
				break;
				cout << "Round Draw\n";
			}
			fBoard(Board, PC_Move, 'O');
			ShowMeTheBoard(Board);
			cout << "Your Turn : \n";
			fBoard(Board, Cin(move), Player_Pawn);

			system("cls");
		//цикл до тех пор, пока ничья
		} 
	}
			
	//поставил, чтобы комп всегда выпендривался, если человек не выиграл
	
	cout << "Game Over\n";
	GotWinner==1 ? cout << "This time you win. Conratulations\n" : cout << "You lose! HAHAHA Stupid human\n";

	return 0;
}

