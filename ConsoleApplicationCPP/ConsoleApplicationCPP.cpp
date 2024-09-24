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

// Инициализирует и возвращает структуру, представляющую точку на координатах
Point initPoint(std::string pointName)
{
	Point point;

	cout << "Введите координаты точки " << pointName << ": ";
	cin >> point.x >> point.y;

	return point;
}

// Вычисляет расстояние между точками
double calсDistBetweenPoints(Point pA, Point pB)
{
	// Формула: 
	return sqrt(pow(pB.x - pA.x, 2) + pow(pB.y - pA.y, 2));
};

// Вычисляет расстояние от точки до начала координат
double calcDistFromPointToOrigin(Point p)
{
	return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

// Возвращает одну наиболее удалённую от начала координат точку из двух заданных
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

	cout << "1) Расстояние от точки A до начала координат: " << calcDistFromPointToOrigin(pointA) << "\n";
	cout << "Расстояние от точки B до начала координат: " << calcDistFromPointToOrigin(pointB) << "\n\n";

	Point farthestFromOriginPoint = calcFarthestFromOriginPoint(pointA, pointB);

	cout << "2) Координаты точки, наиболее удалённой от начала координат: " << farthestFromOriginPoint.x << ", " << farthestFromOriginPoint.y << "\n\n";

	cout << "3) Расстояние между точками: " << calсDistBetweenPoints(pointA, pointB) << "\n";
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

	cout << "Введите фамилию и год рождения: ";
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

	cout << "1) " << firstPerson.surname << ". Возраст - " << fPersonAge << ". ";
	cout << secondPerson.surname << ". Возраст - " << sPersonAge << "\n\n";

	cout << "2) Фамилия самого старшего человека - " << (fPersonAge > sPersonAge ? firstPerson.surname : sPersonAge > fPersonAge ? secondPerson.surname : "Оба человека имеют один возраст");
}



// Task3
struct Circle
{
	double radius;
	Point center;
};

// Инициализирует структуру, представляющую окружность
Circle initCircle()
{
	Circle circle;

	cout << "Введите радиус окружности: ";
	cin >> circle.radius;


	cout << "Определите координаты центра окружности. \n";
	circle.center = initPoint("");
	
	return circle;
}

// Вычисляет длину окружности (периметр)
double calcCircleLength(Circle circle)
{
	return 2 * M_PI * circle.radius;
}

// Вычисляет площадь окружности
double calcCircleArea(Circle circle)
{
	return M_PI * pow(circle.radius, 2);
}

// Определяет, пересекаются ли две окружности
bool doCirclesIntersect(Circle firstCircle, Circle secondCircle)
{
	double distBetweenCirclesCenters = calсDistBetweenPoints(firstCircle.center, secondCircle.center);

	return std::abs(firstCircle.radius - secondCircle.radius) < distBetweenCirclesCenters || firstCircle.radius + secondCircle.radius > distBetweenCirclesCenters;
}

void completeThirdTask()
{
	Circle firstCircle = initCircle();
	Circle secondCircle = initCircle();

	cout << "1) Длина первой окружности - " << calcCircleLength(firstCircle) << ", Второй - " << calcCircleLength(secondCircle) << "\n\n";
	cout << "2) Площадь первой окружности - " << calcCircleArea(firstCircle) << ", Второй - " << calcCircleArea(secondCircle) << "\n\n";
	cout << "3) " << (doCirclesIntersect(firstCircle, secondCircle) ? "Окружности пересекаются" : "Окружности не пересекаются");
}



// Task4
struct Ellipsee
{
	double r1;
	double r2;
	Point center;
};

// Инициализирует структуру, представяющую эллипс
Ellipsee initEllipse()
{
	Ellipsee ellipse;

	cout << "Введите 1-й радиус эллипса: ";
	cin >> ellipse.r1;

	cout << "Введите 2-й радиус эллипса: ";
	cin >> ellipse.r2;

	cout << "Определите координаты центра эллипса. \n";
	ellipse.center = initPoint("");

	return ellipse;
}

//double calcEllipseLength(Ellipsee ellipse)
//{
//	
//}

// Вычисляет площадь эллипса
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

	cout << "2) Площадь первого эллипса - " << ellipse1Area << " Второго - " << ellipse2Area << "\n\n";

	cout << "3) " << (ellipse1Area > ellipse2Area ? "Первый" : ellipse2Area > ellipse1Area ? "Второй" : "Площади эллипсов равны");
}



// Task5
void completeFifthTask()
{
	const int pointCount = 3;
	Point points[pointCount];

	cout << "Введите координаты точек\n";

	// Заполняет массив массив точек с координатами, задаваемыми пользователем
	for (int i = 0; i < pointCount; i++)
	{
		Point point;

		cout << "Точка " << i + 1 << " : ";
		cin >> point.x >> point.y;

		points[i] = point;
	}

	// индекс точки в массиве, наиболее удалённой от начала координат
	int pointIndex = 0;

	// наибольшее растояние от точки до начала координат
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

	cout << "Координаты наиболее удалённой от начала координат точки: " << points[pointIndex].x << " " << points[pointIndex].y;
}


// Task6
struct Train
{
	std::string destination;
	int n;
	int leavingtTime;
};


// Инициализирует структуру, представляющую поезд
Train initTrain()
{
	Train train;

	cout << "Номер поезда: ";
	cin >> train.n;
	cout << "Пункт назначения: ";
	cin >> train.destination;
	cout << "Время отправления: ";
	cin >> train.leavingtTime;

	return train;
}

// Служебная функция для сортировки массива поездов по назначению в алфавитном порядке
bool compareDestinations(const Train& a, const Train& b) {
	return a.destination < b.destination;
}

void completeSixthTask()
{
	const int trainCount = 4;
	Train trains[trainCount];

	// Инициализация массива поездов
	for (int i = 0; i < trainCount; i++)
	{
		trains[i] = initTrain();
	}

	// Сортировка по назначению
	std::sort(trains, trains + trainCount, compareDestinations);

	// Вывод отсортированного массива
	cout << "Заданные поезда по месту назначения в алфавитном порядке: \n";
	for (int i = 0; i < trainCount; i++)
	{
		cout << "Номер: " << trains[i].n << " ";
		cout << "Назначение: " << trains[i].destination << " ";
		cout << "Время отправления: " << trains[i].leavingtTime << "\n";
	}
	
	int guessedLeavingTime;

	cout << "Введите время отпраления, чтобы получить список поездов, отправляющихся после этого времени: ";

	cin >> guessedLeavingTime;

	// Флаг, показывающий, есть ли поезда, отправляющиеся после заданного времени
	bool hasLeavingFlag = false;
	
	cout << "Соответствующие поезда:\n";

	// Вывод поездов, отправляющихся после заданного времени
	for (int i = 0; i < trainCount; i++)
	{
		if (trains[i].leavingtTime > guessedLeavingTime)
		{
			if (!hasLeavingFlag)
			{
				hasLeavingFlag = true;
			}

			cout << "Назначение: " << trains[i].destination << " ";
			cout << "Номер: " << trains[i].n << " ";
			cout << "Время отправления: " << trains[i].leavingtTime << "\n";
		}
	}

	if (!hasLeavingFlag) 
	{
		cout << "Соответствующих поездов нет";
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



