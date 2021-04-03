#include <iostream>
#include <string>

class Game
{
private:
	unsigned int turncount = 1;
	char turn = 'X';
	bool WinCond = false;

	char board[3][3] =      { { '_','_','_' },
							  { '_','_','_' },
							  { '_','_','_' } };


public:
	std::string nboard = R"(
 1 | 2 | 3 
___|___|___
 4 | 5 | 6 
___|___|___
 7 | 8 | 9 
   |   |   )";
	int input = -1;


	void PrintT() // Limpagem de tela e reprintar o preview, e sepa o design e add quebra de linha do texto anterior
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				std::cout << "|" << board[x][y] << "|";
			}
			std::cout << std::endl;
		}

	}

	void Next()
	{
		turncount++;
		if (turncount % 2 != 0)
		{
			turn = 'X';
			std::cout << "\nIt's X's turn:" << std::endl;
		}
		else
		{
			turn = 'O';
			std::cout << "\nIt's O's turn:" << std::endl;		
		}
	}

	void Assign()
	{
		bool validplay = false;
		while (validplay == false)
		{
			std::cin >> input;
			--input;
			if (board[input / 3][input % 3] == '_')
			{
				board[input / 3][input % 3] = turn;
				validplay = true;
			}
			else { std::cout << "This play has already been done. Choose a new space.\n" << std::endl; }
		}
	}

	void CheckWin() // Verificar por quê em formato de L tá dando vitória ex. 0,1 ; 1,0 e 1,1
	{
		if(turncount > 4)
		{
			for (int x = 0; x < 3; x++)
			{
				if (board[x][0] == board[x][1] && board[x][0] == board[x][2])
				{
					WinCond = true;
					std::cout << "The " << turn << " is the winner!\n" << std::endl;
					return;
				}
			}
			for (int y = 0; y < 3; y++)
			{
				if (board[0][y] == board[1][y] && board[0][y] == board[2][y])
				{
					WinCond = true;
					std::cout << "The " << turn << " is the winner!\n" << std::endl;
					return;
				}
			}
			if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
			{
				WinCond = true;
				std::cout << "The " << turn << " is the winner!\n" << std::endl;
				return;
			}
			if (turncount == 9)
			{
				WinCond = true;
				std::cout << "It's a draw!\n" << std::endl;
				return;
			}
		}
	}

	void Play()
	{
		while (WinCond == false)
		{
			Assign();
			PrintT();
			CheckWin();
			if (WinCond == false) { Next(); }
		}
	}

};

int main()
{
	std::cout << "Press Enter to start the game" << std::endl;
	std::cin.get();
	bool InitGame = true;
	while (InitGame)
	{
		Game g;
		std::cout << "This is the board:\n" << std::endl;
		std::cout << g.nboard << std::endl;
		std::cout << "\nYou can choose where to assign your symbol by pressing the respective number on your keyboard." << std::endl;
		std::cout << "Now, X goes first. Type in the respective number for your intended play:" << std::endl;
		g.Play();
		char choice = 'b';
		std::cout << "Do you want to play one more? Y/N\n" << std::endl; 
		while (choice !='N' && choice !='n' && choice !='Y' && choice !='y')
		{
			std::cin >> choice;
			if (choice == 'N' || choice == 'n') 
			{ 
				std::cout << "Thank you for playing! " << (char)0x03 << "\n";
				InitGame = false;				
			}
			else if (choice == 'Y' || choice == 'y')
			{
				std::cout << "\Okay, let's play one more!\n" << std::endl;
			}
			else
			std::cout << "Please, type one of the valid responses:\n Do you want to play again? Y/N" << std::endl;
		}
	}
	
	std::cin.get();


}