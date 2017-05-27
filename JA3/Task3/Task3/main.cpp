#include <iostream>
#include <list>

int main() {
std::list<int> minerals;
int M, X, Y, N;
std::cin >> M >> X >> Y >> N;
for (int i = 0; i < N; i++) {
int tempX, tempY;
std::cin >> tempX >> tempY;
minerals.push_back((std::abs(X - tempX) + std::abs(Y - tempY)));
}
minerals.sort();
int totalTime = 0;
std::list<int>::iterator j = minerals.begin();
for (int i = 0; i < M; i++) {
totalTime += (*j * 2);
j++;
}
std::cout << totalTime << std::endl;
}