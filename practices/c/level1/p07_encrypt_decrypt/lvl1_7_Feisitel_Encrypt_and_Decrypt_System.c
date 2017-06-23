// Feistel.cpp
//

/* code:	Feistel-construction Encrypt/Decrypt System
 * author:	Kyrios0
 * date:	2017.02.26
 * state:	finished
 * version:	1.1.1
 */

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<conio.h>

char* XOR(char *a, char *b);
unsigned int SDBMHash(char *str);
unsigned int RSHash(char *str);
int stringCopy(char *a, char *b, unsigned c);
char* HASH(char *str);
char* key_schedule(char *key);
int encrypt(char *data);
int decrypt(char *cipher);
int outputTrans(char *str);
int inputTrans(char *userPlain);
char* stringInput(char *buf);
int EncryptMode();
int DecryptMode();

char hstr[17], hstrsub[9], subKeys[16 * 16 + 1], cipher[33], plain[33];
char *userPlain = NULL, *userCipher = NULL;
//Just xor
char* XOR(char *a, char *b)
{
	for (int i = 0; i < 16; i++)
	{
		a[i] = a[i] ^ b[i];
	}

	a[16] = '\0';
	b[16] = '\0';

	return a;
}
//Hash1
unsigned int SDBMHash(char *str)
{
	unsigned int hash = 0;

	while (*str)
	{
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}

	return (hash & 0x7FFFFFFF);
}
//Hash2
unsigned int RSHash(char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}
//Instead strncopy, this won't stop at '0x00'
int stringCopy(char *a, char *b, unsigned c)
{
	for (int i = 0; i < c; i++)
	{
		a[i] = b[i];
	}

	return 0;
}
//Hash1 and hash2
char* HASH(char *str)
{
	unsigned hash, hashsub;

	hash = SDBMHash(str);
	hashsub = RSHash(str);
	_itoa_s(hash, hstr, 16);
	_itoa_s(hashsub, hstrsub, 16);
	strcat_s(hstr, hstrsub);

	if (strlen(hstr) < 16)
	{
		char subKey[] = { '0', 0x00 };

		for (int i = (16 - strlen(hstr)); i > 0; i--)
		{
			strcat_s(hstr, subKey);
		}

	}

	return hstr;
}
//Generate a key schedule
char* key_schedule(char *key)
{
	char *subKey = key;

	for (int i = 0; i < 16; i++)
	{
		subKey = HASH(subKey);
		strcat_s(subKeys, subKey);
	}

	return subKeys;
}
//Basic encrypt
int encrypt(char *data)
{
	*cipher = { 0x00 };
	char d1[17] = { 0x00 }, d2[17] = { 0x00 }, currentkey[17], temp[17];
	char done[17];
	done[16] = '\0'; 

	strncpy_s(d1, data, 16);
	strncpy_s(d2, data + 16, strlen(data) - 16);

	for (int i = 0; i < 16; i++)
	{
		strncpy_s(currentkey, subKeys + (16 * i), 16);
		stringCopy(done, XOR(XOR(HASH(d2), currentkey), d1), 16); 
		stringCopy(d1, done, 16);
		stringCopy(temp, d1, 16);
		stringCopy(d1, d2, 16);
		stringCopy(d2, temp, 16);
	}

	d2[16] = '\0';
	d1[16] = '\0';
	strcat_s(cipher, d2);
	strcat_s(cipher, d1);

	return 0;
}
//Basic decrypt
int decrypt(char *cipher)
{
	*plain = { 0x00 };
	char d1[17] = { 0x00 }, d2[17] = { 0x00 }, currentkey[17], temp[17];
	char done[17];
	done[16] = '\0';

	stringCopy(d2, cipher, 16);
	stringCopy(d1, cipher + 16, 16);

	for (int i = 0; i < 16; i++)
	{		
		strncpy_s(currentkey, subKeys + (16 * (15 - i)), 16);
		stringCopy(temp, d1, 16);
		stringCopy(d1, d2, 16);
		stringCopy(d2, temp, 16);
		stringCopy(done, XOR(XOR(HASH(d2), currentkey), d1), 16);
		stringCopy(d1, done, 16);	
	}

	strcat_s(plain, d1);
	strcat_s(plain, d2);

	return 0;
}
//Enhanced ascii to hex
int outputTrans(char *str)
{
	for (int i = 0; i < 32; i++)
	{
		if (((unsigned char)str[i] < 0x10) && ((unsigned char)str[i] > 0x00))
		{
			putchar('0');
		}
		printf("%x", (unsigned char)str[i]);
	}
	
	return 0;
}
//Enhanced hex to ascii
int inputTrans(char *userPlain)
{
	for (int i = 0; i < 64; i += 2)
	{
		if ((userPlain[i] >= '0') && (userPlain[i] <= '9'))
		{
			userPlain[i] -= '0';
		}
		else
		{
			userPlain[i] -= ('a' - 10);
		}
		if ((userPlain[i + 1] >= '0') && (userPlain[i + 1] <= '9'))
		{
			userPlain[i + 1] -= '0';
		}
		else
		{
			userPlain[i + 1] -= ('a' - 10);
		}
		cipher[i / 2] = userPlain[i] * 0x10 + userPlain[i + 1];
	}

	return 0;
}
//Arbitrary length
char* stringInput(char *buf)
{
	int len = 0;
	char *str = (char *)malloc(4 * sizeof(char));
	if (str == NULL)
	{
		exit(1);
	}

	while (1)
	{		
		fgets(str, 5, stdin);
		if (str[3] == '\n')
		{
			str[3] = '\0';
		}
		if (str[0] == '\n')
		{
			str[0] = '\0';
			break;
		}
		len += 4;
		char * buff = (char *)malloc(len * sizeof(char));
		*buff = { 0x00 };
		if (len != 4)
		{
			strcpy(buff, buf);
			*buf = { 0x00 };
		}
		strcat(buff, str);
		buf = buff;
		buff = NULL;
		if (strlen(str) != 4)
		{
			break;
		}
	}

	if (buf[strlen(buf) - 1] == '\n')
	{
		buf[strlen(buf) - 1] = '\0';
	}

	return buf;
}

int EncryptMode()
{
	puts("Please enter plain text:");
	userPlain = stringInput(userPlain);

	unsigned int fill, block, length, exLength;
	char currentEncryptBlock[33];
	length = strlen(userPlain);
	block = (length - 1) / 32 + 1;
	fill = (32 - (length % 32)) % 32;
	exLength = block * 32;

	for (int i = fill; i > 0; i--)
	{
		userPlain[exLength - i] = ' ';
		userPlain[exLength - i + 1] = 0x00;
	}

	printf("cipher:\t");

	for (int i = 0; i < block; i++)
	{
		stringCopy(currentEncryptBlock, userPlain + (32 * i), 32);
		currentEncryptBlock[32] = '\0';
		encrypt(currentEncryptBlock);//Loop encryption
		outputTrans(cipher);
	}

	putchar('\n');
	
	return 0;
}

int DecryptMode()
{
	puts("Please enter cipher text:");
	unsigned int fill, block, length;
	userCipher = stringInput(userCipher);

	char currentDecryptBlock[65];
	length = strlen(userCipher);
	block = (length - 1) / 64 + 1;
	fill = (64 - (length % 64)) % 64;
	if ((length % 64) != 0)
	{
		puts("WARNING!");
		puts("INVAILD CIPHER!!!");
		return -1;
	}

	printf("plain:\t");

	for (int i = 0; i < block; i++)
	{
		stringCopy(currentDecryptBlock, userCipher + (64 * i), 64);
		currentDecryptBlock[64] = '\0';
		inputTrans(currentDecryptBlock);
		decrypt(cipher); //Loop encryption
		printf("%s", plain);
	}

	putchar('\n');
	
	return 0;
}

int main(int argc, char** argv)
{
	char key[] = "Kyrios0";//char Test_data[] = "hashtestmiaomiaomiaowhathappened"
	key_schedule(key);

	system("chcp 437");
	system("mode con cols=65 lines=32");

	while (1)
	{
		*hstr = { 0x00 }; *hstrsub = { 0x00 }; *cipher = { 0x00 }; *plain = { 0x00 };
		
		system("cls");
		printf("\n\n\n\n\n\n\n");
		puts("       Feistel Structure Encryption and Decryption System");
		printf("\n\n\n\n");
		puts("              Press E to enter the Encryption mode");
		printf("\n\n\n");
		puts("              Press D to enter the Decryption mode");
		printf("\n\n\n");
		puts("                         Press Q to Quit");

		switch (_getch())
		{
		case 'e':
			system("cls");
			puts("EncryptMode");
			EncryptMode();
			break;

		case 'd':
			system("cls");
			puts("DecryptMode");
			DecryptMode();
			break;

		case 'q':
			system("cls");
			puts("Kyrios hope that you will have a nice day");
			puts("Bye");
			system("pause");
			exit(0);
			break;

		default:
			continue;

		}

		system("pause");
	}

	return 0;
}

