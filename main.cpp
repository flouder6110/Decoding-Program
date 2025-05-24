#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


int main()
{

	char outputChar;
	enum modeType { UPPERCASE, LOWERCASE, PUNCTUATION };
	modeType mode = UPPERCASE;
	char digitChar;


	do
	{
		digitChar = cin.get();
		int num = (digitChar - '0');
		digitChar = cin.get();
		while ((digitChar != 10) && (digitChar != ','))
		{
			num = num * 10 + (digitChar - '0');
			digitChar = cin.get();
		}
		switch (mode)
		{
		case UPPERCASE:
			num = num % 27;
			outputChar = num + 'A' - 1;
			if (num == 0)
			{
				mode = LOWERCASE;
				continue;
			}
			break;
		case LOWERCASE:
			num = num % 27;
			outputChar = num + 'a' - 1;
			if (num == 0)
			{
				mode = PUNCTUATION;
				continue;
			}
			break;
		case PUNCTUATION:
			num = num % 9;
			switch (num) {
			case 1: outputChar = '!';
				break;
			case 2: outputChar = '?';
				break;
			case 3: outputChar = ',';
				break;
			case 4: outputChar = '.';
				break;
			case 5: outputChar = ' ';
				break;
			case 6: outputChar = ';';
				break;
			case 7: outputChar = '"';
				break;
			case 8: outputChar = '\'';
				break;
			}
			if (num == 0)
			{
				mode = UPPERCASE;
				continue;
			}
			break;
		}
		cout << outputChar;

	} while (digitChar != 10);
	cout << '\n';

	return 0;
}
