#include <stdio.h>
#include "List.h"
/*todolist 
1. 在main函数中创建一个单向链表；
2. 遍历该链表，依次现实各节点的value；
3. 将该链表所有节点反序；
4. 在该链表中查找第一个值为5的节点，如果找到则返回该节点的序号，否则返回－1；
5. 查找下一个值为5的节点，返回值同上；
*/ 
void showdata(Item item);
Node *ReverseOrder(List *plist);//将链表所有节点反序
int FindValue(List * plist);//查找值
Node *head;
int main() {
	List data;
	Item temp;
	int i = 1;

	InitializeList(&data);
	if (ListIsFull(&data)) {
		printf("No memory available!\n");
		return 0;
	}
	puts("Enter the first digit:");
	while (scanf("%d", &temp.value) == 1) {
		temp.id = i++;
		if (AddItem(temp, &data) == false) {
			printf("Problem allocating memory!\n");
			break;
		}
		if (ListIsFull(&data)) {
			puts("The list is now full.\n");
			break;
		}
		puts("Enter the next value(empty 'q' to stop)");
	}
	
	Traverse(&data, showdata);
	printf("\n");
	
	Node *rehead = ReverseOrder(&data);
	Traverse(&rehead, showdata);

	int x = FindValue(&rehead);
	printf("%d\n", x);

	int y = FindValue(&head);
	printf("%d", y);


}

void showdata(Item item) {
	printf("%d  %d\n", item.id, item.value);
}

Node *ReverseOrder(List *plist) {
	Node * pre = *plist;
	Node * current = pre->next;
	Node * next = NULL;

	if (current) {
		next = current->next;
		(*plist)->next = NULL;
	}
	else
		return *plist;
	while (1) {
		current->next = pre;
		if (next) {
			pre = current;
			current = next;
			next = next->next;
		}
		else
			return current;
	}
}

int FindValue(List * plist) {
	Node * pnode = *plist;
	int k = 0;

	while (pnode != NULL) {
		if (pnode->item.value == 5) {
			head = pnode->next;
			k = 1;
			return (pnode->item).id;
		}
		pnode = pnode->next;
	}
	if (k == 0)
		return -1;
}



