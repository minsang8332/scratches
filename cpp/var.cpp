#include <iostream>
using namespace std;

/* �������� > ���α׷��� ����� �� ���� */
int varLifeTime1;

/* const > ���� �ٲ��� �ʰڴٴ� Ű����*/
double getCircleWidth (double radius = 0) {
	const double PI{ 3.14159 };
	double area = radius * radius * PI;
	cout << "���� ���� = " << area << endl;
	return area;
}

/* constexpr > ���� ������ �� �� ���ϴ� Ű���� */
void studyConstexpr(int a) {
	const int b = 20;
	const int c1 = a;
	/// constexpr int c2 = a + 10;
	constexpr int c3 = b + 100;
	// constexpr int c4 = c1 * 2;
}

void studyVarLifeTime (int num) {
	/* �������� > �Լ��� ���� ������ */
	int varLifeTime2;
	/* ���� �������� > ���α׷��� ���� �� �� ����, �̰�� �Լ��� ����� �� �� ���� ����� */
	static int varLifeTime3;
}


int main() {
	getCircleWidth(10);
	studyConstexpr(10);
	
	return 0;
}