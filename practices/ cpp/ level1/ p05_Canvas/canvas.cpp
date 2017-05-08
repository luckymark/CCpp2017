#include<iostream>
using namespace std;

class Canvas {
private:
	struct Circle {
		int center_x,center_y,radii;	//圆形参数：名称、中心位置、半径
		struct Circle *next;
	}circle;
	struct Rectangle {
		int center_x, center_y, length, width;		//矩形参数：名称、中心位置、长宽、宽度
		struct Rectangle *next;
	}rectangle;
	struct Circle *head1, *p1, *p_new1;
	struct Rectangle *head2, *p2, *p_new2;
public:
	Canvas();
	void if_add();
	void add_circle();
	void add_rectangle();
	void show_figure();
}canvas;

Canvas::Canvas()
{
	head1 = NULL;
	head2 = NULL;
}
void Canvas::if_add()
{
	while (1) {
		system("cls");
		cout << "add or exit?" << endl;
		cout << "1.add a circle" << endl;	//添加圆的信息
		cout << "2.add a rectangle" << endl;	//添加矩形的信息
		cout << "3.stop adding and see information" << endl;	//停止添加，查看已有信息
		int n;
		cin >> n;
		system("cls");
		if (1 == n) {
			add_circle();	//添加圆信息
		}
		else if (2 == n) {
			add_rectangle();	//添加矩形信息
		}
		else {
			break;		//停止添加
		}
	}
}
void Canvas::add_circle()
{
	p_new1 = new(struct Circle);
	cout << "please input the center_x" << endl;
	cin >> p_new1->center_x;
	cout << endl << "please input the center_y" << endl;
	cin >> p_new1->center_y;
	cout << endl << "please input the length" << endl;
	cin >> p_new1->radii;
	p_new1->next = head1;
	head1 = p_new1;
}
void Canvas::add_rectangle()
{
	p_new2 = new(struct Rectangle);
	cout << "please input the center_x" << endl;
	cin >> p_new2->center_x;
	cout << endl << "please input the center_y" << endl;
	cin >> p_new2->center_y;
	cout << endl << "please input the length" << endl;
	cin >> p_new2->length;
	cout << endl << "please input the width" << endl;
	cin >> p_new2->width;
	p_new2->next = head2;
	head2 = p_new2;
}
void Canvas::show_figure()
{
	int i = 1, j = 1;
	p1 = head1;
	cout << "circle no."<<"\t\t"<<"center_x"<<"\t\t"<<"center_y"<<"\t\t"<<"radii" << endl;
	while (p1 != NULL) {
		cout << i <<"\t\t\t"<< p1->center_x <<"\t\t\t"<< p1->center_y <<"\t\t\t"<< p1->radii << endl;
		p1 =
			p1->next;
		i++;
	}
	p2 = head2;
	cout << "rectangle no."<<"\t\t"<<"center_x"<<"\t\t"<<"center_y"<<"\t\t"<<"length"<<"\t\t"<<"width"<< endl;
	while (p2 != NULL) {
		cout << j <<"\t\t\t"<<p2->center_x <<"\t\t\t"<< p2->center_y <<"\t\t\t" <<p2->length <<"\t\t"<< p2->width << endl;
		p2 =
			p2->next;
		j++;
	}
}

void main()
{
	canvas.if_add();
	canvas.show_figure();
	system("pause");
}
