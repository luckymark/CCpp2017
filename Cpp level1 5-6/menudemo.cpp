#include <windows.h>  
#include <iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "resource.h"
#include <boost/serialization/export.hpp>
#include <vector>

using namespace std;
HDC hdc;
const class Point 
{
public:
	int x;
	int y;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(x);
		ar & BOOST_SERIALIZATION_NVP(y);
	};
};
class Index 
{
public:
	int index;
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(index);
	};
};
  class Shape {
	public :	
		virtual void LButtonDown() = 0;
		virtual void LButtonUp() = 0;
		virtual void MouseMove() = 0;
		virtual void Paint() = 0;
		virtual void Begin() = 0;
		virtual void End() = 0;		
		virtual void GetHwnd(HWND hwnd)=0;
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version) 
		{};				
  };
   BOOST_SERIALIZATION_ASSUME_ABSTRACT(Shape)
  class Line :public Shape
  {
  protected:
		int mark;
		Point pt[100];
		int *ptrx, *ptry;
		HWND hwnd;
		PAINTSTRUCT ps;
		int flag = 0;
  public:
	  Line() {};
	
	 
	   Line(static int &x,static int &y,HWND hwnd)
	  {		 
		  ptrx = &x;
		  ptry = &y;
		  this->hwnd= hwnd;
		  mark = 0;
	  }
	 void LButtonDown()
	 {
		 pt[mark].x = *ptrx;
		 pt[mark].y = *ptry;
	 }
	 void MouseMove()
	 {
		 if (flag == 0)
		 {
			 pt[mark].x = *ptrx;
			 pt[mark].y = *ptry;
		 }
	 }
	 void LButtonUp()
	 {
		 if(flag==0)
		 mark++;
	 }
	 void Paint()
	 {		
		 
		 HPEN hPen;
		 RECT  rect;
		 GetClientRect(hwnd, &rect);
		 hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		 SelectObject(hdc, hPen);
		 if (flag == 0)
		 {
			 for (int i = 0; i < mark; i++)
			 {

				 MoveToEx(hdc, pt[i].x, pt[i].y, 0);
				 LineTo(hdc, pt[i + 1].x, pt[i + 1].y);
			 }
		 }
		 if (mark >= 2 && (pt[mark-1].x - pt[0].x)*(pt[mark-1].x - pt[0].x) + (pt[mark-1].y - pt[0].y)*(pt[mark-1].y - pt[0].y)<145)
		 {
			 flag = 1;
			 Polygon(hdc, (const POINT*)pt, mark);
		 }
	 }
	 void Begin()
	 {
		 hdc = BeginPaint(hwnd, &ps);
	 }
	 void End()
	 {
		 EndPaint(hwnd, &ps);
	 }
	 void GetHwnd(HWND hwnd)
	 {
		 this->hwnd = hwnd;
	 }
	 friend class boost::serialization::access;
	 template<class Archive>
	 void serialize(Archive & ar, const unsigned int version)
	 {
		 ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Shape);
		 ar & BOOST_SERIALIZATION_NVP(pt);
		 ar & BOOST_SERIALIZATION_NVP(mark);
	 }
	 virtual ~Line(){};
  };
 BOOST_CLASS_EXPORT(Line)

  class Tri :public Shape
  {
  protected:
	  int mark;
	  Point pt[3];
	  int *ptrx, *ptry;
	  HWND hwnd;
	  PAINTSTRUCT ps;
  public:
	  Tri() {};
	  Tri(static int &x, static int &y, HWND hwnd)
	  {
		  ptrx = &x;
		  ptry = &y;
		  this->hwnd = hwnd;
		  mark = 0;
	  }
	  void LButtonDown()
	  {
		  if (mark <= 2)
		  {
			  pt[mark].x = *ptrx;
			  pt[mark].y = *ptry;
		  }
	  }
	  void MouseMove()
	  {
		  if (mark <= 2)
		  {
			  pt[mark].x = *ptrx;
			  pt[mark].y = *ptry;
		  }
	  }
	  void LButtonUp()
	  {
		  if(mark<=2)
		  mark++;
	  }
	  void Paint()
	  {
		
		  HPEN hPen;
		  hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		  SelectObject(hdc, hPen);
		  for (int i = 0; i < mark&&mark<3; i++)
		  {
			  MoveToEx(hdc, pt[i].x, pt[i].y, 0);
			  LineTo(hdc, pt[i + 1].x, pt[i + 1].y);
			  
		  }
		  if (mark == 3)
		  {
			  Polygon(hdc, (const POINT*)pt, 3);
		  }
		 
	  }
	  void Begin()
	  {
		  hdc = BeginPaint(hwnd, &ps);
	  }
	  void End()
	  {
		  EndPaint(hwnd, &ps);
	  }
	  void GetHwnd(HWND hwnd)
	  {
		  this->hwnd = hwnd;
	  }
	  friend class boost::serialization::access;
	  template<class Archive>
	  void serialize(Archive & ar, const unsigned int version)
	  {
		  ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Shape);
		  ar & BOOST_SERIALIZATION_NVP(pt);
		  ar & BOOST_SERIALIZATION_NVP(mark);
	  }
	  virtual ~Tri() {};
  };
	BOOST_CLASS_EXPORT(Tri)
		
  class Round :public Shape
  {
  protected:
	  int mark;
	  int flag = 0;
	  Point pt[2];
	  int *ptrx, *ptry;
	  HWND hwnd;
	  PAINTSTRUCT ps;
	  int tempX = 0;
	  int tempY = 0;
  public:
	  Round() {};
	  Round(static int &x, static int &y, HWND hwnd)
	  {
		  ptrx = &x;
		  ptry = &y;
		  this->hwnd = hwnd;
		  mark = 0;
	  }
	  void LButtonDown()
	  {
		  if (mark <=1)
		  {
			  pt[mark].x = *ptrx;
			  pt[mark].y = *ptry;
		  }
		  if (mark == 2&&(*ptrx>pt[0].x)&&(*ptrx<pt[1].x)&&(*ptry>pt[0].y)&&(*ptry<pt[1].y))
		  {
			  if (flag == 1)
				  flag = 0;
			  else if (flag == 0)
				  flag = 1;
		  }
	  }
	  void MouseMove()
	  {
		  if (mark == 1)
		  {
			  pt[mark].x = *ptrx;
			  pt[mark].y = *ptry;
		  }
		  if (flag == 1)
		  {
			  if (tempX == 0 && tempY == 0)
			  {
				  tempX = pt[1].x - pt[0].x;
				  tempY = pt[1].y - pt[0].y;
			  }
			  pt[0].x = *ptrx - tempX/2;
			  pt[0].y = *ptry -	tempY/2;
			  pt[1].x = *ptrx +	tempX/2;
			  pt[1].y = *ptry +	tempY/2;
		  }
	  }
	  void LButtonUp()
	  {
		  if (mark <= 1)
			  mark++;
		 
	  }
	  void Paint()
	  {
		  HPEN hPen;
		  hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		  SelectObject(hdc, hPen);
		  Ellipse(hdc, pt[0].x, pt[0].y, pt[1].x, pt[1].y);
	  }
	  void Begin()
	  {
		  hdc = BeginPaint(hwnd, &ps);
	  }
	  void End()
	  {
		  EndPaint(hwnd, &ps);
	  }
	  void GetHwnd(HWND hwnd)
	  {
		  this->hwnd = hwnd;
	  }
	  friend class boost::serialization::access;
	  template<class Archive>
	  void serialize(Archive & ar, const unsigned int version)
	  {
		  ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Shape);
		  ar & BOOST_SERIALIZATION_NVP(pt);
		  ar & BOOST_SERIALIZATION_NVP(mark);
	  }
	  virtual ~Round() {};
  };
	BOOST_CLASS_EXPORT(Round)

		class Rect :public Shape
	{
	protected:
		int mark;
		Point pt[2];
		int *ptrx, *ptry;
		HWND hwnd;
		PAINTSTRUCT ps;
	public:
		Rect() {};
		Rect(static int &x, static int &y, HWND hwnd)
		{
			ptrx = &x;
			ptry = &y;
			this->hwnd = hwnd;
			mark = 0;

		}
		void LButtonDown()
		{
			if (mark <= 1)
			{
				pt[mark].x = *ptrx;
				pt[mark].y = *ptry;
			}
		}
		void MouseMove()
		{
			if (mark == 1)
			{
				pt[mark].x = *ptrx;
				pt[mark].y = *ptry;
			}
		}
		void LButtonUp()
		{
			if (mark <= 1)
				mark++;
		}
		void Paint()
		{
			HPEN hPen;
			hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
			SelectObject(hdc, hPen);
			Rectangle(hdc, pt[0].x, pt[0].y, pt[1].x, pt[1].y);
		}
		void Begin()
		{
			hdc = BeginPaint(hwnd, &ps);
		}
		void End()
		{
			EndPaint(hwnd, &ps);
		}
		void GetHwnd(HWND hwnd)
		{
			this->hwnd = hwnd;
		}
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{
			ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Shape);
			ar & BOOST_SERIALIZATION_NVP(pt);
			ar & BOOST_SERIALIZATION_NVP(mark);
		}
		virtual ~Rect() {};
  };
	BOOST_CLASS_EXPORT(Rect)

  class Creator {
  public:
	  virtual Shape* factory() = 0;
  };

  class LineCreator :public Creator
  {
  protected:	
		int *ptrx, *ptry;
		HWND hwnd;
  public:
		LineCreator( int &x, int &y,HWND hwnd) {		
			ptrx = &x;
			ptry = &y;
			this->hwnd = hwnd;
			
	  }
	  Shape* factory()
	  {
		  return new Line(*ptrx,*ptry,hwnd);
	  }
  };
   
  class TriCreator :public Creator
  {
  protected:
	  int *ptrx, *ptry;
	  HWND hwnd;
	
  public:
	  TriCreator(int &x, int &y, HWND hwnd) {
		  ptrx = &x;
		  ptry = &y;
		  this->hwnd = hwnd;
	  }
	  Shape* factory()
	  {
		  return new Tri(*ptrx, *ptry, hwnd);
	  }
  };

  class RectCreator :public Creator
  {
  protected:
	  int *ptrx, *ptry;
	  HWND hwnd;
  public:
	  RectCreator(int &x, int &y, HWND hwnd) {
		  ptrx = &x;
		  ptry = &y;
		  this->hwnd = hwnd;
	  }
	  Shape* factory()
	  {
		  return new Rect(*ptrx, *ptry, hwnd);
	  }
  };

  class RoundCreator :public Creator
  {
  protected:
	  int *ptrx, *ptry;
	  HWND hwnd;
  public:
	  RoundCreator(int &x, int &y, HWND hwnd) {
		  ptrx = &x;
		  ptry = &y;
		  this->hwnd = hwnd;
	  }
	  Shape* factory()
	  {
		  return new Round(*ptrx, *ptry, hwnd);
	  }
  };


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
	TCHAR SoftName[] = TEXT("»­°å");      
	HWND     hwnd;      
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;     
	wndclass.cbClsExtra = 0;      
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, SoftName);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = "MenuDemo";
	wndclass.lpszClassName = SoftName;
	if (!RegisterClass(&wndclass)) {
		MessageBox(NULL, TEXT("This program requires Windows NT!"), SoftName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(SoftName, SoftName,WS_OVERLAPPEDWINDOW,GetSystemMetrics(SM_CXSCREEN) / 4, GetSystemMetrics(SM_CYSCREEN) / 4, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);      
	UpdateWindow(hwnd);

		MSG   msg;
		while (GetMessage(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);                
			DispatchMessage(&msg);
		}
		return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int mark = 0,flag=0;
	static int x=100, y=100;
	HMENU hMenu;
	static int index = 0;
	static vector <Creator*> creator(2);
	static vector <Shape*> shape(2);
	static bool judge = true;
	switch(message)        
	{   
	case WM_LBUTTONDOWN: 
	{		
		if (shape[0] != NULL)
		{
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			shape[index-1]->LButtonDown();
		}
		
		break;
	}

	case WM_MOUSEMOVE: 	
	{
		if (shape[0] != NULL)
		{
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			shape[index-1]->MouseMove();
			InvalidateRect(hwnd, NULL, TRUE);

		}
		break;
	}
	case WM_PAINT: 
	{
		for (int i = index - 1; i >= 0; i--)
		{
			if (i == index - 1)
				shape[i]->Begin();

			shape[i]->Paint();

			if (i == 0)
				shape[i]->End();
		}
	}
		break;
	case WM_LBUTTONUP:
		
		if (shape[0] != NULL)
		{
			shape[index-1]->LButtonUp();
			
		}
		break;

	case WM_COMMAND:
		{
		hMenu = GetMenu(hwnd);
		switch (LOWORD(wParam)) {

			case DRAW_LINE:
				{	
					creator.push_back(NULL);
					shape.push_back(NULL);
					creator[index] = new LineCreator(x, y, hwnd);
					shape[index] = creator[index]->factory();
					index++;
					
					break;
				}
			case DRAW_ROUND:
				{
					creator.push_back(NULL);
					shape.push_back(NULL);
					creator[index] = new RoundCreator(x, y, hwnd);
					shape[index] = creator[index]->factory();
					index++;
					break;
				}
				
			case DRAW_TRI:
				{
					creator.push_back(NULL);
					shape.push_back(NULL);
					creator[index] = new TriCreator(x, y, hwnd);
					shape[index] = creator[index]->factory();
					index++;
					break;
				}
				
			case DRAW_RECT:
				{
					creator.push_back(NULL);
					shape.push_back(NULL);
					creator[index] = new RectCreator(x, y, hwnd);
					shape[index] = creator[index]->factory();
					index++;
					break;
				}
			case OPEN:
			{
				Index in;
				std::ifstream ifs("d:\\paint", std::ios::binary);
				boost::archive::text_iarchive ia(ifs);
				ia >> BOOST_SERIALIZATION_NVP(in);
				creator.resize(in.index);
				shape.resize(in.index);
				while (index < in.index)
				{
					ia >> BOOST_SERIALIZATION_NVP(shape[index++]);
					
				}
				shape[index - 1]->GetHwnd(hwnd);
				break;
			}
			case SAVE:
			{
				Index in;
				in.index = index;
				std::ofstream ofs("d:\\paint", std::ios::binary);
				boost::archive::text_oarchive oa(ofs);
				oa << BOOST_SERIALIZATION_NVP(in);
				for(int i=0;i<index;i++)
				oa << BOOST_SERIALIZATION_NVP(shape[i]);					
				break;
			}
				
			}
			break;
		}
		case WM_CLOSE:
			if (IDYES == MessageBox(hwnd, "want to finish?", "message", MB_YESNO))
			{
				DestroyWindow(hwnd);
			}			
			break;
			
		case WM_DESTROY:        
		
			PostQuitMessage(0);
			break;
		
			
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
