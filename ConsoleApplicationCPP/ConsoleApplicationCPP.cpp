#include <iostream>
#include <Windows.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <algorithm>

using std::cout;
using std::cin;

// Task 1
struct Point
{
	int x;
	int y;
};

// �������������� � ���������� ���������, �������������� ����� �� �����������
Point initPoint(std::string pointName)
{
	Point point;

	cout << "������� ���������� ����� " << pointName << ": ";
	cin >> point.x >> point.y;

	return point;
}

// ��������� ���������� ����� �������
double cal�DistBetweenPoints(Point pA, Point pB)
{
	// �������: 
	return sqrt(pow(pB.x - pA.x, 2) + pow(pB.y - pA.y, 2));
};

// ��������� ���������� �� ����� �� ������ ���������
double calcDistFromPointToOrigin(Point p)
{
	return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

// ���������� ���� �������� �������� �� ������ ��������� ����� �� ���� ��������
Point calcFarthestFromOriginPoint(Point pA, Point pB)
{
	double distanceToOriginA = calcDistFromPointToOrigin(pA);
	double distanceToOriginB = calcDistFromPointToOrigin(pB);

	return distanceToOriginA > distanceToOriginB ? pA : pB;
}

void completeFirstTask()
{
	Point pointA = initPoint("A");
	Point pointB = initPoint("B");

	cout << "1) ���������� �� ����� A �� ������ ���������: " << calcDistFromPointToOrigin(pointA) << "\n";
	cout << "���������� �� ����� B �� ������ ���������: " << calcDistFromPointToOrigin(pointB) << "\n\n";

	Point farthestFromOriginPoint = calcFarthestFromOriginPoint(pointA, pointB);

	cout << "2) ���������� �����, �������� �������� �� ������ ���������: " << farthestFromOriginPoint.x << ", " << farthestFromOriginPoint.y << "\n\n";

	cout << "3) ���������� ����� �������: " << cal�DistBetweenPoints(pointA, pointB) << "\n";
}



// Task 2
struct Person
{
	std::string surname;
	int birthYear;
};

Person initPerson()
{
	Person person;

	cout << "������� ������� � ��� ��������: ";
	cin >> person.surname >> person.birthYear;

	return person;
}

const int currentYear = 2024;

int calcAge(int birthYear)
{
	return currentYear - birthYear;
}

void completeSecondTask()
{
	Person firstPerson = initPerson();
	Person secondPerson = initPerson();

	int fPersonAge = calcAge(firstPerson.birthYear);
	int sPersonAge = calcAge(secondPerson.birthYear);

	cout << "1) " << firstPerson.surname << ". ������� - " << fPersonAge << ". ";
	cout << secondPerson.surname << ". ������� - " << sPersonAge << "\n\n";

	cout << "2) ������� ������ �������� �������� - " << (fPersonAge > sPersonAge ? firstPerson.surname : sPersonAge > fPersonAge ? secondPerson.surname : "��� �������� ����� ���� �������");
}



// Task3
struct Circle
{
	double radius;
	Point center;
};

// �������������� ���������, �������������� ����������
Circle initCircle()
{
	Circle circle;

	cout << "������� ������ ����������: ";
	cin >> circle.radius;


	cout << "���������� ���������� ������ ����������. \n";
	circle.center = initPoint("");
	
	return circle;
}

// ��������� ����� ���������� (��������)
double calcCircleLength(Circle circle)
{
	return 2 * M_PI * circle.radius;
}

// ��������� ������� ����������
double calcCircleArea(Circle circle)
{
	return M_PI * pow(circle.radius, 2);
}

// ����������, ������������ �� ��� ����������
bool doCirclesIntersect(Circle firstCircle, Circle secondCircle)
{
	double distBetweenCirclesCenters = cal�DistBetweenPoints(firstCircle.center, secondCircle.center);

	return std::abs(firstCircle.radius - secondCircle.radius) < distBetweenCirclesCenters || firstCircle.radius + secondCircle.radius > distBetweenCirclesCenters;
}

void completeThirdTask()
{
	Circle firstCircle = initCircle();
	Circle secondCircle = initCircle();

	cout << "1) ����� ������ ���������� - " << calcCircleLength(firstCircle) << ", ������ - " << calcCircleLength(secondCircle) << "\n\n";
	cout << "2) ������� ������ ���������� - " << calcCircleArea(firstCircle) << ", ������ - " << calcCircleArea(secondCircle) << "\n\n";
	cout << "3) " << (doCirclesIntersect(firstCircle, secondCircle) ? "���������� ������������" : "���������� �� ������������");
}



// Task4
struct Ellipsee
{
	double r1;
	double r2;
	Point center;
};

// �������������� ���������, ������������� ������
Ellipsee initEllipse()
{
	Ellipsee ellipse;

	cout << "������� 1-� ������ �������: ";
	cin >> ellipse.r1;

	cout << "������� 2-� ������ �������: ";
	cin >> ellipse.r2;

	cout << "���������� ���������� ������ �������. \n";
	ellipse.center = initPoint("");

	return ellipse;
}

//double calcEllipseLength(Ellipsee ellipse)
//{
//	
//}

// ��������� ������� �������
double calcEllipseArea(Ellipsee ellipse)
{
	return M_PI * (ellipse.r1 + ellipse.r2);
}

void completeFourthTask()
{
	Ellipsee ellipse1 = initEllipse();
	Ellipsee ellipse2 = initEllipse();

	double ellipse1Area = calcEllipseArea(ellipse1);
	double ellipse2Area = calcEllipseArea(ellipse2);

	cout << "2) ������� ������� ������� - " << ellipse1Area << " ������� - " << ellipse2Area << "\n\n";

	cout << "3) " << (ellipse1Area > ellipse2Area ? "������" : ellipse2Area > ellipse1Area ? "������" : "������� �������� �����");
}



// Task5
void completeFifthTask()
{
	const int pointCount = 3;
	Point points[pointCount];

	cout << "������� ���������� �����\n";

	// ��������� ������ ������ ����� � ������������, ����������� �������������
	for (int i = 0; i < pointCount; i++)
	{
		Point point;

		cout << "����� " << i + 1 << " : ";
		cin >> point.x >> point.y;

		points[i] = point;
	}

	// ������ ����� � �������, �������� �������� �� ������ ���������
	int pointIndex = 0;

	// ���������� ��������� �� ����� �� ������ ���������
	double largestDistance = 0;

	for (int i = 0; i < pointCount; i++)
	{
		double distance = calcDistFromPointToOrigin(points[i]);

		if ( distance > largestDistance)
		{
			largestDistance = distance;
			pointIndex = i;
		}
	}

	cout << "���������� �������� �������� �� ������ ��������� �����: " << points[pointIndex].x << " " << points[pointIndex].y;
}


// Task6
struct Train
{
	std::string destination;
	int n;
	int leavingtTime;
};


// �������������� ���������, �������������� �����
Train initTrain()
{
	Train train;

	cout << "����� ������: ";
	cin >> train.n;
	cout << "����� ����������: ";
	cin >> train.destination;
	cout << "����� �����������: ";
	cin >> train.leavingtTime;

	return train;
}

// ��������� ������� ��� ���������� ������� ������� �� ���������� � ���������� �������
bool compareDestinations(const Train& a, const Train& b) {
	return a.destination < b.destination;
}

void completeSixthTask()
{
	const int trainCount = 4;
	Train trains[trainCount];

	// ������������� ������� �������
	for (int i = 0; i < trainCount; i++)
	{
		trains[i] = initTrain();
	}

	// ���������� �� ����������
	std::sort(trains, trains + trainCount, compareDestinations);

	// ����� ���������������� �������
	cout << "�������� ������ �� ����� ���������� � ���������� �������: \n";
	for (int i = 0; i < trainCount; i++)
	{
		cout << "�����: " << trains[i].n << " ";
		cout << "����������: " << trains[i].destination << " ";
		cout << "����� �����������: " << trains[i].leavingtTime << "\n";
	}
	
	int guessedLeavingTime;

	cout << "������� ����� ����������, ����� �������� ������ �������, �������������� ����� ����� �������: ";

	cin >> guessedLeavingTime;

	// ����, ������������, ���� �� ������, �������������� ����� ��������� �������
	bool hasLeavingFlag = false;
	
	cout << "��������������� ������:\n";

	// ����� �������, �������������� ����� ��������� �������
	for (int i = 0; i < trainCount; i++)
	{
		if (trains[i].leavingtTime > guessedLeavingTime)
		{
			if (!hasLeavingFlag)
			{
				hasLeavingFlag = true;
			}

			cout << "����������: " << trains[i].destination << " ";
			cout << "�����: " << trains[i].n << " ";
			cout << "����� �����������: " << trains[i].leavingtTime << "\n";
		}
	}

	if (!hasLeavingFlag) 
	{
		cout << "��������������� ������� ���";
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	//completeFirstTask();
	//completeSecondTask();
	//completeThirdTask();
	//completeFourthTask();
	//completeFifthTask();
	//completeSixthTask();

	return 0;
}



