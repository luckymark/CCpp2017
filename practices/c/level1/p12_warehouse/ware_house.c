#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_COL 80
#define MAX_ROW 25
#define BREAK_COL 62
#define BREAK_COL_C 12

int c_row, c_col;
FILE *in, *out;
char *data = NULL;

void print_table(void);
void in_store(void);
void out_store(void);
void disp_store(void);
void clear_disp(void);

int main(void)
{
	char command[4];
	
	c_row = 4, c_col = 2;
	print_table();
	for (;;){
		if (c_row == MAX_ROW){
			c_row = 4;
			print_table();
		}
		gotoxy(c_col, c_row);
		textcolor(YELLOW);
		cprintf("Input: ");
		for (int i = 0; i < 3; i++){
			command[i] = getch();
			textcolor(RED);
			gotoxy(9 + i, c_row);
			cprintf("%c", command[i]);
			if (command[i] == '\r'){
				command[i] = '\0';
				break;
			}
		}
		command[3] = '\0';
		if (strcmp(command, "i") == 0){
			c_row++;
			disp_store();
			continue;
		}
		else if (strcmp(command, "ii") == 0){
			c_row++;
			in_store();
			continue;
		}
		else if (strcmp(command, "iii") == 0){
			c_row++;
			out_store();
			continue;
		}
		else if (strcmp(command, "iv") == 0)
			return 0;
		if (strcmp(command, "vi") == 0){
			c_row++;
			clear_disp();
			continue;
		}
		else{
			gotoxy(BREAK_COL_C + 4, c_row);
			printf("Illegal command, try again.\n");
			c_row++;
			continue;
		}
	}
}

void print_table(void)
{
	clrscr();
	for (int i = 0; i < MAX_ROW; i++){
		for (int j = 0; j < MAX_COL; j++){
			if (i == 0 || i == MAX_ROW - 1 ||
			(i == 2 && j != BREAK_COL - 1 && j != MAX_COL - 1 && j != 0))
				printf("-");
			else if (j == 0 || j == BREAK_COL - 1 || j == MAX_COL - 1 ||
				(j == BREAK_COL_C && i != 0 && i != 2 && i != MAX_ROW - 1))
				printf("|");
			else
				printf(" ");
		}
	}
	gotoxy(BREAK_COL / 2 - 10, 2);
	printf("Wareouse\tAuthor: HolmesQiao");
	gotoxy(BREAK_COL + 7, 2);
	printf("Command");
	gotoxy(BREAK_COL + 10, 4);
	printf("i");
	gotoxy(BREAK_COL + 2, 5);
	printf("Display the data");
	gotoxy(BREAK_COL + 9, 7);
	printf("ii");
	gotoxy(BREAK_COL + 4, 8);
	printf("Store goods");
	gotoxy(BREAK_COL + 8, 10);
	printf("iii");
	gotoxy(BREAK_COL + 2, 11);
	printf("Take out goods");
	gotoxy(BREAK_COL + 9, 13);
	printf("iv");
	gotoxy(BREAK_COL + 8, 14);
	printf("Quit");
	gotoxy(BREAK_COL + 9, 16);
	printf("vi");
	gotoxy(BREAK_COL + 4, 17);
	printf("clean screen");
}

void in_store(void)
{
	if ((in = fopen("store_data.txt", "w")) == NULL){
		printf("File cannot be opened");
		exit(0);
	}
	char new_data[100];
	gotoxy(BREAK_COL_C + 2, --c_row);
	printf("Enter the goods to store: (modle num price)");
	gotoxy(BREAK_COL_C + 2, (++c_row)++);
	gets(new_data);
	if (data == NULL){
		data = (char *)malloc(sizeof(char));
		strcpy(data ,new_data);
	}
	else
		strcat(data, new_data);
	fprintf(in, "%s", data);
	fclose(in);
}

void out_store(void)
{
	int value = 0;
	if ((in = fopen("store_data.txt", "w")) == NULL){
		printf("File cannot be opened\n");
		exit(0);
	}
	char out_data[100];
	gotoxy(BREAK_COL_C + 2, --c_row);
	printf("Enter the goods to out: (modle remine_num)");
	gotoxy(BREAK_COL_C + 2, (++c_row)++);
	gets(out_data);
	int data_len = strlen(data), out_len = strlen(out_data);
	for (int i = 0 ; i < data_len - out_len + 1; i++){
		if (data[i] == out_data[0]){
			for (int j = i; j < i + out_len; i++){
				if (data[j] == out_data[j - i])
					value = 1;
				else{
					value = 0;
					break;
				}
			}
			if (value){
				value = 0;
				for (int k = i; k < i + out_len; k++){
					if(data[i] == ' '){
						i++;
						value = 1;
					}
					if (value){
						data[i] = out_data[k - i];
					}
				}
			}
		}		
	}
	fprintf(in, "%s", data);
	fclose(in);
}

void disp_store(void)
{
	char ch;
	
	clear_disp();
	gotoxy(BREAK_COL_C + 2, c_row++);
	printf("Model\tNUM\tPrice");
	if ((out = fopen("store_data.txt", "r")) == NULL){
		printf("File cannot be opened");
		exit(0);
	}
	gotoxy(BREAK_COL_C + 2, c_row);
	int i = 0;
	while ((ch = getc(out)) != EOF){
		if (ch == ' '){
			printf("\t");
			i++;
		}
		else
			printf("%c", ch);
		if (i == 3){
			c_row++;
			i = 0;
			gotoxy(BREAK_COL_C + 2, c_row);
		}	
	}
	fclose(out);
}

void clear_disp(void)
{
	for (int i = 4; i < MAX_ROW - 1; i++)
		for (int j = BREAK_COL_C + 2; j < BREAK_COL - 1; j++){
			gotoxy(j, i);
			printf(" ");
		}
	c_col = 2;
}
