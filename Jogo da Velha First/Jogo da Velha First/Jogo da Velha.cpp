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
			std::cout << "It's X's turn:" << std::endl; // Quebra de linha
		}
		else
		{
			turn = 'O';
			std::cout << "It's O's turn:" << std::endl;
		}
	}

	void Assign() // Impedir casa repetida = jogada inválida
	{
		std::cin >> input;
		--input;
		board[input / 3][input % 3] = turn;
	}

	void CheckWin()
	{
		if(turncount > 4)
		{
			for (int x = 0; x < 3; x++)
			{
				if (board[x][0] == board[x][1] && board[x][0] == board[x][2])
				{
					WinCond = true;
					std::cout << "The " << turn << " is the winner!" << std::endl;
					return;
				}
			}
			for (int y = 0; y < 3; y++)
			{
				if (board[0][y] == board[1][y] && board[0][y] == board[2][y])
				{
					WinCond = true;
					std::cout << "The " << turn << " is the winner!" << std::endl;
					return;
				}
			}
			if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
			{
				WinCond = true;
				std::cout << "The " << turn << " is the winner!" << std::endl;
				return;
			}
			if (turncount == 9)
			{
				WinCond = true;
				std::cout << "It's a draw!" << std::endl;
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
		char choice; // rever as possibilidades de resposta
		std::cout << "\nDo you want to play one more? Y/N" << std::endl; 
		std::cin >> choice;
		if (choice == 'N') { InitGame = false; } 
		else { std::cout << "Okay, let's play one more!" << std::endl; }
	}
	std::cout << "Thank you for playing! " << (char)0x03;
	std::cin.get();


}