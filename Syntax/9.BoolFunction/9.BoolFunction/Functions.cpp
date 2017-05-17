int reverseNumber(int n)
{
	int reverse = 0;
	int reminder;
	while (n != 0)
	{
		reminder = n % 10;
		reverse = reverse * 10 + reminder;
		n /= 10;
	}

	return reverse;
}

bool check() {
	int check1 = 12;
	int checkRev1 = 21;
	int check2 = 123;
	int checkRev2 = 321;
	int check3 = 1234;
	int checkRev3 = 4321;
	int check4 = 1234;
	int checkRev4 = 4321;
	int check5 = 12345;
	int checkRev5 = 54321;
	int check6 = 123456;
	int checkRev6 = 654321;
	int check7 = 1234567;
	int checkRev7 = 7654321;
	int check8 = 12345678;
	int checkRev8 = 87654321;
	int check9 = 123456789;
	int checkRev9 = 987654321;
	int check10 = 1234567891;
	int checkRev10 = 1987654321;
	if (reverseNumber(check1) != checkRev1
		|| reverseNumber(check2) != checkRev2
		|| reverseNumber(check3) != checkRev3
		|| reverseNumber(check4) != checkRev4
		|| reverseNumber(check5) != checkRev5
		|| reverseNumber(check6) != checkRev6
		|| reverseNumber(check7) != checkRev7
		|| reverseNumber(check8) != checkRev8
		|| reverseNumber(check9) != checkRev9
		|| reverseNumber(check10) != checkRev10)
	{
		return false;
	}
	return true;
}