//#include "stdafx.h"
#include<stdio.h>
#include<string.h>

/* ��ʼ������ */
void rc4_init(unsigned char *key, unsigned long keylong);

/* �ӽ��� */
void rc4_Encrypt(unsigned char *plaintext, int textlong);

void rc4_Decrypt(unsigned char *ciphertext, int textlong);

void setRc4Key(unsigned char * key);

