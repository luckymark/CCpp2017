#include <iostream>
#include <vector>
#include "canvas.h"
using namespace std;

Point::Point(double nx, double ny)
{
	this->x = nx;
	this->y = ny;
}

Circle::Circle(double r, double x, double y)
{
	Point p(x, y);
	this->radius = r;
	this->center = p;
}

Circle::Circle(double r, Point &p)
{
	this->radius = r;
	this->center = p;
}

Rectan::Rectan(double l, double h, double x, double y, double the)
{
	Point p(x, y);
	this->len = l;
	this->hei = h;
	this->theta = the;
	this->center = p;
}

Rectan::Rectan(double l, double h, Point &p, double the)
{
	this->len = l;
	this->hei = h;
	this->theta = the;
	this->center = p;
}

void Canvas::paint()
{
	puts("\nCircles:");
	if (circles.size() == 0)
	{
		puts("None");
	}
	for (int i = 0; i < circles.size(); i++)
	{
		if (circles[i].radius != 0)
		{
			printf("%d.Circle: center:(%.2lf, %.2lf), radius: %.2lf\n", i+1, circles[i].center.x, circles[i].center.y, circles[i].radius);
		}
	}

	puts("\nRectangles:");
	if (rectans.size() == 0)
	{
		puts("None");
	}
	for (int i = 0; i < rectans.size(); i++)
	{
		if (rectans[i].len != 0)
		{
			printf("%d.Rectanle: center:(%.2lf, %.2lf), length: %.2lf, height: %.2lf, theta: %.2lf\n", i+1, rectans[i].center.x, rectans[i].center.y, rectans[i].len, rectans[i].hei, rectans[i].theta);
		}
	}
	puts("");
}

void Canvas::add()
{
	int mod = 0;
	Circle newCir;
	Rectan newRec;
	printf("Please confirm the type of item you will add\n1.Circle\n2.Rectangle\n:");
	cin >> mod;
	getchar();
	switch (mod)
	{
	case 1:
		printf("Please enter radius: ");
		std::cin >> newCir.radius;
		printf("Please enter x and y of center point: ");
		std::cin >> newCir.center.x >> newCir.center.y;
		getchar();
		circles.push_back(newCir);
		puts("Add success!");
		break;
	case 2:
		printf("Please enter length and height: ");
		std::cin >> newRec.len >> newRec.hei;
		printf("Please enter x and y of center point: ");
		std::cin >> newRec.center.x >> newRec.center.y;
		printf("Please enter theta: ");
		std::cin >> newRec.theta;
		getchar();
		rectans.push_back(newRec);
		puts("Add success!");
		break;
	default:
		puts("Error: Invalid mode!");
	}
	
}

void Canvas::del()
{
	int mod = 0, serial = 0;
	vector<Circle>::iterator itc;
	vector<Rectan>::iterator itr;
	printf("Please confirm the type of item you will delete\n1.Circle\n2.Rectangle\n:");
	cin >> mod;
	getchar();
	switch (mod)
	{
	case 1:
		if (circles.size() == 0)
		{
			puts("Error: no circle!");
			break;
		}
		puts("\nLists: ");
		for (int i = 0; i < circles.size(); i++)
		{
			if (circles[i].radius != 0)
			{
				printf("%d.Circle: center:(%.2lf, %.2lf), radius: %.2lf\n", i + 1, circles[i].center.x, circles[i].center.y, circles[i].radius);
			}
		}
		puts("\nWhich one do you want to remove?");
		cin >> serial;
		getchar();
		if (serial < 1 || serial > circles.size())
		{
			puts("Error: Wrong serial number!");
			break;
		}
		itc = circles.begin() + serial - 1;
		itc = circles.erase(itc);
		puts("Delete success!");
		break;
	case 2:
		if (rectans.size() == 0)
		{
			puts("Error: no rectangle!");
			break;
		}
		puts("\nLists: ");
		for (int i = 0; i < rectans.size(); i++)
		{
			if (rectans[i].len != 0)
			{
				printf("%d.Rectanle: center:(%.2lf, %.2lf), length: %.2lf, height: %.2lf, theta: %.2lf\n", i + 1, rectans[i].center.x, rectans[i].center.y, rectans[i].len, rectans[i].hei, rectans[i].theta);
			}
		}
		puts("\nWhich one do you want to remove?");
		cin >> serial;
		getchar();
		if (serial < 1 || serial > rectans.size())
		{
			puts("Error: Wrong serial number!");
			break;
		}
		itr = rectans.begin() + serial - 1;
		itr = rectans.erase(itr);
		puts("Delete success!");
		break;
	default:
		puts("Error: Invalid mode!");
	}
}