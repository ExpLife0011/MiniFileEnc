#ifndef _RC6_H
#define _RC6_H

#include <stdio.h>
#include<string.h>
#include "windef.h"
//��������
// #define w 32    /* wordΪ32bits */
// #define r 20    //��������
// #define P32 0xB7E15163
// #define Q32 0x9E3779B9
// 
// #define bytes   (w / 8)                        /* �����ֽ�*/
// #define c       ((b + bytes - 1) / bytes)      /* ��Կ���� */
// #define R24     (2 * r + 4)
// #define lgw     5                           /* log2(w)  */
// /* �����߼���λ�������� */
// #define ROTL(x,y) (((x)<<(y&(w-1))) | ((x)>>(w-(y&(w-1)))))
// #define ROTR(x,y) (((x)>>(y&(w-1))) | ((x)<<(w-(y&(w-1)))))
// 
// UINT S[R24 - 1];                    /* ����Կ�� */

void setRc6Key(PUCHAR K);
INT rc6_Encrypt(PUCHAR  plaintext, INT textlong);
INT rc6_Decrypt(PUCHAR  plaintext, INT textlong);


void rc6_Encrypt16(PUCHAR  plaintext);
void rc6_Decrypt16(PUCHAR  ciphertext);
UINT rc6Key[43];                    /* ����Կ�� */
UINT ROTL(UINT x, UINT y);
UINT ROTR(UINT x, UINT y);

#endif