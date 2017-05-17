#include<iostream>
using namespace std;

void floodFillUtil(char **screen, int x, int y, char prevC, char newC, int M, int N)
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (screen[x][y] != prevC)
		return;

	screen[x][y] = newC;

	floodFillUtil(screen, x + 1, y, prevC, newC, M, N);
	floodFillUtil(screen, x - 1, y, prevC, newC, M, N);
	floodFillUtil(screen, x, y + 1, prevC, newC, M, N);
	floodFillUtil(screen, x, y - 1, prevC, newC, M, N);
	
}


void floodFill(char **screen, int x, int y, char newC, int M, int N)
{
	char prevC = screen[x][y];
	floodFillUtil(screen, x, y, prevC, newC, M, N);
}


int main()
{
	int M, N;
	cin >> M >> N;
	char **screen = new char*[M];
	for (int i = 0; i < M; i++) {
		screen[i] = new char[N];
		for (int j = 0; j < N; j++) {
			cin >> screen[i][j];
		}
	}
	int x, y;
	char newC;
	cin >> newC;
	cin >> x >> y;
	floodFill(screen, x, y, newC, M, N);


	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
			cout << screen[i][j];
		cout << endl;
	}
}