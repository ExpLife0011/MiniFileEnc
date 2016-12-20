#ifndef _LIB_H_
#define _LIB_H_

#include "common.h"
//#include "aes-demo.h"
//������
#define AES_INDEX_BIT 1
#define DES_INDEX_BIT 2
#define RC4_INDEX_BIT 3
#define RC6_INDEX_BIT 4
#define XOR_INDEX_BIT 5
#define CRYPT_FUNC_INDEX sizeof(UCHAR)
#define ENC_BUFF_KEY_BIT 0x77

VOID
Cc_ClearFileCache1 (
					__inout PFLT_CALLBACK_DATA Data,
					__in PCFLT_RELATED_OBJECTS FltObjects,
					__deref_out_opt PVOID *CompletionContext
					
					);



/**
 * ���ܻ�������
 *buffer:ָ�򻺴��ָ��
 *Length:���泤��
 *PassWord:���룬Ŀǰδʹ��
 *CryptIndex:���ܽ����㷨������
 */
NTSTATUS
File_EncryptBuffer(
    __in PVOID buffer,
    __in ULONG Length,
    __in PCHAR PassWord,
    __inout PUSHORT CryptIndex,
    __in ULONG ByteOffset
);

/**
 * ���ܻ�������
  *buffer:ָ�򻺴��ָ��
 *Length:���泤��
 *PassWord:���룬Ŀǰδʹ��
 *CryptIndex:���ܽ����㷨������
 */
NTSTATUS
File_DecryptBuffer(
    __in PVOID buffer,
    __in ULONG Length,
    __in PCHAR PassWord,
    __inout PUSHORT CryptIndex,
    __in ULONG ByteOffset
);




#endif