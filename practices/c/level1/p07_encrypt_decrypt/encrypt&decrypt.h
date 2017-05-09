//
// Created by plusls on 17-3-4.
//

#ifndef P07_ENCRYPT_DECRYPT_ENCRYPT_DECRYPT_H
#define P07_ENCRYPT_DECRYPT_ENCRYPT_DECRYPT_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *encrypt(const unsigned char *data, int l);
unsigned char *decrypt(char *str);
void add_pointer(char *p);
void free_memory();
int to_num(char c);
#endif //P07_ENCRYPT_DECRYPT_ENCRYPT_DECRYPT_H
