#include"employ.h"
int main()
{
	employ list1;
	list1.insert("charlie", 4, 18);
	list1.show("charlie");
	sales sale;
	sale.insert("hash", 5, 25);
	sale.pushSaleNum(5000);
	sale.show("hash");
}