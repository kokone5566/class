#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
123
int main()
{
	srand(time(0));

	int opt = 1;
	while (opt == 1)
	{

		int num[4];
		int i = 0, j = 0;
		for (i = 0; i < 4; i++)
		{
			num[i] = rand() % 9 + 1;

			for (j = 0; j < i; j++)
			{
				if (num[i] == num[j])
				{
					i--;
					break;
				}
			}

		}


		int sysgena = 1000 * num[0] + 100 * num[1] + 10 * num[2] + num[3];
		int s1 = sysgena / 1000;
		int s2 = sysgena / 100 - s1 * 10;
		int s3 = sysgena / 10 - s1 * 100 - s2 * 10;
		int s4 = sysgena - s1 * 1000 - s2 * 100 - s3 * 10;

		cout << "\n\n\n" << sysgena << "\n\n\n";
		//	這ㄍ4答案不要秀出來

		cout << "\nThis is a number guessing program. \nPlease input a 4 digit number, each number cannot be the same. \n";
		cout << "Input: ";
		int guess;
		cin >> guess;                                //guess沒防呆
		
		int g1 = guess / 1000;
		int g2 = guess / 100 - g1 * 10;
		int g3 = guess / 10 - g1 * 100 - g2 * 10;
		int g4 = guess - g1 * 1000 - g2 * 100 - g3 * 10;

		while (guess != sysgena)
		{
			//剛剛在這

			while (g1 == g2 || g1 == g3 || g1 == g4 || g2 == g3 || g2 == g4 || g3 == g4)
			{
				cout << "\nInputing same numbers is not allowed.\nPlease input again.\n";
				cout << "Input: ";
				int reguess;
				cin >> reguess;
				guess = reguess;
				g1 = guess / 1000;
				g2 = guess / 100 - g1 * 10;
				g3 = guess / 10 - g1 * 100 - g2 * 10;
				g4 = guess - g1 * 1000 - g2 * 100 - g3 * 10;
			}

			int x = 0, y = 0; //現在在這

			if (sysgena != guess && g1 != g2 && g1 != g3 && g1 != g4 && g2 != g3 && g2 != g4 && g3 != g4)
			{
				if (s1 == g1)
					x++;
				if (s2 == g2)
					x++;
				if (s3 == g3)
					x++;
				if (s4 == g4)
					x++;

				if (s1 == g2 || s1 == g3 || s1 == g4 && s1 != g1)
					y++;
				if (s2 == g1 || s2 == g3 || s2 == g4 && s2 != g2)
					y++;
				if (s3 == g1 || s3 == g2 || s3 == g4 && s3 != g3)
					y++;
				if (s4 == g1 || s4 == g2 || s4 == g3 && s4 != g4)
					y++;
			}

			cout << "\n" << guess << "→" << x << "A" << y << "B";
			x = 0, y = 0;
			cout << "\n\nTry again.\n" << "Input:";
			int rereguess;
			cin >> rereguess;
			guess = rereguess;
			g1 = guess / 1000;
			g2 = guess / 100 - g1 * 10;
			g3 = guess / 10 - g1 * 100 - g2 * 10;
			g4 = guess - g1 * 1000 - g2 * 100 - g3 * 10;
		}


		if (sysgena == guess)
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!\n!!!!! YOU WIN !!!!!\n!!!!!!!!!!!!!!!!!!!\n" << "\nWould you like to play this game again?\nEnter 1 if you do, and 0 if you don't.\n";
			cout << "(1/0): ";
			cin >> opt;

		}
	}

	if (opt == 0)
	{
		cout << "\nHope to see you again, bye. \nWish you have a nice day!\n\n";
	}


	system("pause");
	return 0;

}
