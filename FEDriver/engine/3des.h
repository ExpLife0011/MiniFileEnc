#include <stdio.h>
#include<string.h>
void setDesKey(unsigned char *key);
int des3_Encrypt(unsigned char *plaintext,int textlong);
int des3_Decrypt(unsigned char *ciphertext, int textlong);

unsigned char desKey[128];
//�ֽ�ת���ɶ�����
unsigned char ByteToBit(unsigned char ch, unsigned char bit[8]);

// ������ת�����ֽ� 
unsigned char BitToByte(unsigned char bit[8],unsigned char *ch);

// ������Ϊ8���ַ���תΪ������λ�� 
unsigned char Char8ToBit64(unsigned char ch[8],unsigned char bit[64]);

// ��������λ��תΪ����Ϊ8���ַ���
unsigned char Bit64ToChar8(unsigned char bit[64],unsigned char ch[8]);

// ��Կ�û�1 
unsigned char DES_PC1_Transform(unsigned char key[64], unsigned char tempbts[56]);

//��Կ�û�2 
unsigned char DES_PC2_Transform(unsigned char key[56], unsigned char tempbts[48]);

//ѭ������ 
unsigned char DES_ROL(unsigned char data[56], unsigned char time);

//IP�û�
unsigned char DES_IP_Transform(unsigned char data[64]);

// IP���û� 
unsigned char DES_IP_1_Transform(unsigned char data[64]);

//��չ�û� 
unsigned char DES_E_Transform(unsigned char data[48]);

//P�û� 
unsigned char DES_P_Transform(unsigned char data[32]);

// ��� 
unsigned char DES_XOR(unsigned char R[48], unsigned char L[48] ,unsigned char count);

// S���û� 
unsigned char DES_SBOX(unsigned char data[48]);

//���� 
unsigned char DES_Swap(unsigned char left[32], unsigned char right[32]);

//��������Կ
unsigned char DES_MakeSubKeys(unsigned char key[64],unsigned char subKeys[16][48]);

//���ܵ������� 
unsigned char DES_EncryptBlock(unsigned char plainBlock[8], unsigned char subKeys[16][48], unsigned char cipherBlock[8]);

// ���ܵ�������
unsigned char DES_DecryptBlock(unsigned char cipherBlock[8], unsigned char subKeys[16][48],unsigned char plainBlock[8]);

//�����ļ�
unsigned char DES_Encrypt(unsigned char *keyStr,unsigned char *plainFile,unsigned char *cipherFile);

//�����ļ� 
unsigned char DES_Decrypt(unsigned char *keyStr,unsigned char *cipherFile,unsigned char *plainFile);

