#include <iostream>
#include <string>
using namespace std;
void assignColors(string colors, int &red1, int &red2, int &green1, int &green2, int &blue1, int &blue2);
int calculateColor(char colorArr[]);
int main()
{
	string colors;
	getline(cin, colors);

	int red1, red2, green1, green2, blue1, blue2;

	assignColors(colors, red1, red2, green1, green2, blue1, blue2);
	
	int red = (red1 + red2) / 2;
	int green = (green1 + green2) / 2;
	int blue = (blue1 + blue2) / 2;

	cout << red << endl;
	cout << green << endl;
	cout << blue << endl;

}
void assignColors(string colors, int &red1, int &red2, int &green1, int &green2, int &blue1, int &blue2) {
	char colorArr[2];
	colorArr[0] = colors[1];
	colorArr[1] = colors[2];
	red1 = calculateColor(colorArr);

	colorArr[0] = colors[9];
	colorArr[1] = colors[10];
	red2 = calculateColor(colorArr);

	colorArr[0] = colors[3];
	colorArr[1] = colors[4];
	green1 = calculateColor(colorArr);

	colorArr[0] = colors[11];
	colorArr[1] = colors[12];
	green2 = calculateColor(colorArr);

	colorArr[0] = colors[5];
	colorArr[1] = colors[6];
	blue1 = calculateColor(colorArr);

	colorArr[0] = colors[13];
	colorArr[1] = colors[14];
	blue2 = calculateColor(colorArr);

}
int calculateColor(char colorArr[]) {
	int firstDigit, secondDigit;
	switch ((char)colorArr[0]) {
	case 'a':
		firstDigit = 10;
		break;
	case 'b':
		firstDigit = 11;
		break;
	case 'c':
		firstDigit = 12;
		break;
	case 'd':
		firstDigit = 13;
		break;
	case 'e':
		firstDigit = 14;
		break;
	case 'f':
		firstDigit = 15;
		break;
	case '0':
		firstDigit = 0;
		break;
	case '1':
		firstDigit = 1;
		break;
	case '2':
		firstDigit = 2;
		break;
	case '3':
		firstDigit = 3;
		break;
	case '4':
		firstDigit = 4;
		break;
	case '5':
		firstDigit = 5;
		break;
	case '6':
		firstDigit = 6;
		break;
	case '7':
		firstDigit = 7;
		break;
	case '8':
		firstDigit = 8;
		break;
	case '9':
		firstDigit = 9;
		break;
	}
	switch ((char)colorArr[1]) {
	case 'a':
		secondDigit = 10;
		break;
	case 'b':
		secondDigit = 11;
		break;
	case 'c':
		secondDigit = 12;
		break;
	case 'd':
		secondDigit = 13;
		break;
	case 'e':
		secondDigit = 14;
		break;
	case 'f':
		secondDigit = 15;
		break;
	case '0':
		secondDigit = 0;
		break;
	case '1':
		secondDigit = 1;
		break;
	case '2':
		secondDigit = 2;
		break;
	case '3':
		secondDigit = 3;
		break;
	case '4':
		secondDigit = 4;
		break;
	case '5':
		secondDigit = 5;
		break;
	case '6':
		secondDigit = 6;
		break;
	case '7':
		secondDigit = 7;
		break;
	case '8':
		secondDigit = 8;
		break;
	case '9':
		secondDigit = 9;
		break;
	}

	return (firstDigit * 16) + secondDigit;


}