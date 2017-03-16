//丑陋的加密算法
//只考虑了大小写字母与数字
//加密只能通过改变Hash值改变
//总之这个算法特别蠢就是了

#include <stdio.h>
#include <string.h>
#define Hash 10007
#define N 100

char numToChar(int x);
char enToDe(char c);
char deToEn(char c);
void encrypt();
void decrypt();
void init();

int enIntoDe[62];
int deIntoEn[62];
char ch[N];

int main() {
	init();
	while (1) {
		int k;
		printf("输入要进行的操作序号，1:加密，2:解密，3:退出 : ");
		scanf("%d",&k);
		if (k == 1) {
			encrypt();
			continue;
		}
		if (k == 2) {
			decrypt();
			continue;
		}
		if (k == 3) {
			break;
		}
	}
	return 0;
}

char numToChar(int x) {
    if (x < 10) return (char)(48+x);
    if (x < 36) return (char)(55+x);
    return (char)(61+x);
}

char enToDe(char c) {
    if ((int)(c) > 47 && (int)(c) < 58) {
        return numToChar(enIntoDe[(int)(c) - 48]);
    }
    if ((int)(c) > 64 && (int)(c) < 91) {
        return numToChar(enIntoDe[(int)(c) - 55]);
    }
    return numToChar(enIntoDe[(int)(c) - 61]);
}

char deToEn(char c) {
    if ((int)(c) > 47 && (int)(c) < 58) {
        return numToChar(deIntoEn[(int)(c) - 48]);
    }
    if ((int)(c) > 64 && (int)(c) < 91) {
        return numToChar(deIntoEn[(int)(c) - 55]);
    }
    return numToChar(deIntoEn[(int)(c) - 61]);
}

void encrypt() {
    printf("输入需要加密的字符串:\n");
    scanf("%s",&ch);
    for (int i = 0; i < strlen(ch); i++) {
        ch[i] = enToDe(ch[i]);
    }
    printf("加密后的字符串为:%s\n",ch);
}

void decrypt() {
    printf("输入需要解密的字符串:\n");
    scanf("%s",&ch);
    for (int i = 0; i < strlen(ch); i++) {
        ch[i] = deToEn(ch[i]);
    }
    printf("解密后的字符串为:%s\n",ch);
}

void init() {
    memset(enIntoDe,-1,sizeof(enIntoDe));
    memset(deIntoEn,-1,sizeof(deIntoEn));
    for (int i = 0; i < 62; i++) {
        int x = (i * Hash) % 62;
        if (deIntoEn[x] == -1) {
            enIntoDe[i] = x;
            deIntoEn[x] = i;
        }
    }
    for (int i = 0; i < 62; i++) {
        if (enIntoDe[i] == -1) {
            for (int j = 0; j < 62; j++) {
                if (deIntoEn[j] == -1) {
                    enIntoDe[i] = j;
                    deIntoEn[j] = i;
                    break;
                }
            }
        }
    }
}
