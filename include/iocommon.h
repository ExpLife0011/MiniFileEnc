#ifndef _IOCOMMON_H_
#define _IOCOMMON_H_

//#include <fltKernel.h>
//maximum path length
#ifndef 	MAX_PATH
#define 	MAX_PATH					260
#endif

// max user name length
#define  MAX_USER_NAME_LENGTH			128

//password length limitation(in bytes)
#define  MAX_PASSWORD_LENGTH			20
#define  MIN_PASSWORD_LENGTH			4

//maximum key length
#define MAX_KEY_LENGTH  32

//password question length limitation(in bytes)
#define  MAX_SECRETQUESTION_LENGTH		64
#define  MAX_SECRETANSWER_LENGTH		32
#define  MAX_PASSWORDHINT_LENGTH		32

#define  HASH_SIZE  20
#define  SECTION_SIZE 512

typedef void* HANDLE ;

typedef enum {OFF, ON}STATE ;

#pragma pack(1)

//
typedef struct MyFileHeader_
{
	char szName[12];	// ������"�ļ�������\06"
	int isTwiceEncript;	//�Ƿ��������
	int iTwiceEncriptType;	//�������ܷ�ʽ,0��ʾ����,1��ʾ�Ź������
	int iTwiceEncriptLength;//�������ܺ����ĵĳ���

	int iType;		//���ܷ�ʽ,1-4�ֱ��Ӧ��ͬ�ļ����㷨
	char szUserName[17];	//�����ߵ��û���
	char szTmpBuf[32];		//�������ܻ���

	char szMD5Twice[33];	//�������ܿ��õ�ʱ����������
	char szMD5Header[33];	//����ͷ�ļ�(��szMD5Twice��һ�ֶε�У��)

	char szKeyBuf[1024];	//�����ں�Ӧ�ò㴫����Կ
	int iKeyLength;		//���ݵ���Կ����
	int isWriteBack;	//�Ƿ�д���ļ�
	int isCancel;		//�Ƿ�ȡ������

	char szPath[256];	// �ļ�·��
	int isEnc; //1 ���ܣ�0 ����
}FileHeader,*PFileHeader;

typedef enum _NPMINI_COMMAND { 
	ENUM_PASS = 0, 
	ENUM_BLOCK 
} NPMINI_COMMAND; 

typedef struct _COMMAND_MESSAGE {
	NPMINI_COMMAND     Command;  
	FileHeader filehead;
} COMMAND_MESSAGE, *PCOMMAND_MESSAGE;


typedef struct _USERCOMMAND_MESSAGE {
	FILTER_MESSAGE_HEADER messageHeader;
	COMMAND_MESSAGE cmdMessage;
}USERCOMMAND_MESSAGE, *PUSERCOMMAND_MESSAGE;

typedef struct _USERCOMMAND_MESSAGE_REPLAY
{
	FILTER_REPLY_HEADER  replayHeader;
	COMMAND_MESSAGE cmdMessage;
}USERCOMMAND_MESSAGE_REPLAY,*PUSERCOMMAND_MESSAGE_REPLAY;

//typedef struct{
//	CHAR    uName[17] ;
//	CHAR uAesKey[32] ;
//	CHAR uAesKey[32] ;
//	CHAR uAesKey[32] ;
//	CHAR uAesKey[32] ;
//}USER_INFO_LIST,*PUSER_INFO_LIST; 

typedef struct _PROCESS_INFO{
	CHAR    szProcessName[16] ;
	BOOLEAN bMonitor ;
	FileHeader filehead;
}PROCESS_INFO,*PPROCESS_INFO; 

/**
 * password
 */
typedef struct _PASSWORD_INFO
{
	UCHAR	password[MAX_PASSWORD_LENGTH + 1];
}PASSWORD_INFO, *PPASSWORD_INFO;

/**
 * file path name info
 */
typedef struct _FILE_PATH_INFO
{
	TCHAR	FileName[MAX_PATH];
}FILE_PATH_INFO, *PFILE_PATH_INFO;

/**
 * password question
 */
typedef struct _PASSWORD_HINT_QUESTION
{
	UCHAR 	HintQuestion[MAX_SECRETQUESTION_LENGTH + 1];
}PASSWORD_HINT_QUESTION, *PPASSWORD_HINT_QUESTION;

/**
 * password answer
 */
typedef struct _PASSWORD_HINT_ANSWER
{
	UCHAR 	HintAnswer[MAX_SECRETANSWER_LENGTH + 1];
}PASSWORD_HINT_ANSWER, *PPASSWORD_HINT_ANSWER;

/**
 * password hint
 */
typedef struct _PASSWORD_HINT
{
	UCHAR 	Hint[MAX_PASSWORDHINT_LENGTH + 1];
}PASSWORD_HINT, *PPASSWORD_HINT;

/**
 * password hint info
 */
typedef struct _HINT_INFO
{
	PASSWORD_HINT_QUESTION PwdHintQue;
	PASSWORD_HINT_ANSWER   PwdHintAns;
	PASSWORD_HINT		  pwdHint;
}HINT_INFO, *PHINT_INFO;

#pragma pack()

typedef void (*GETRESULTCALLBACK)(PVOID pUserParam, TCHAR* pszProcessPathName) ;

#endif