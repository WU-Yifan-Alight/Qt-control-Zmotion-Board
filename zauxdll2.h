/********************************** ZMCϵ�п�����  ************************************************
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**�ļ���: zauxdll2.h
**������: ֣Т��
**ʱ��: 20130621
**����: ZMCDLL ��������

**------------�޶���ʷ��¼----------------------------------------------------------------------------
** �޸���: 
** ��  ��: 
** �ա���: 
** �衡��: 
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/




#ifndef _ZMOTION_DLL_AUX_H
#define _ZMOTION_DLL_AUX_H


//ZAUX֧�ֵ����������
#define MAX_AXIS_AUX   64 
#define MAX_CARD_AUX   32


#ifdef __cplusplus  
extern "C" {
#endif 





/*********************************************************
�������Ͷ���
**********************************************************/

typedef unsigned __int64   uint64;  
typedef __int64   int64;  


//#define BYTE           INT8U
//#define WORD           INT16U
//#define DWORD          INT32U
typedef unsigned char  BYTE;
typedef unsigned short  WORD;
//typedef unsigned int  DWORD;
//#define __stdcall 
typedef unsigned char  uint8;                   /* defined for unsigned 8-bits integer variable     �޷���8λ���ͱ���  */
typedef signed   char  int8;                    /* defined for signed 8-bits integer variable        �з���8λ���ͱ���  */
typedef unsigned short uint16;                  /* defined for unsigned 16-bits integer variable     �޷���16λ���ͱ��� */
typedef signed   short int16;                   /* defined for signed 16-bits integer variable         �з���16λ���ͱ��� */
typedef unsigned int   uint32;                  /* defined for unsigned 32-bits integer variable     �޷���32λ���ͱ��� */
typedef signed   int   int32;                   /* defined for signed 32-bits integer variable         �з���32λ���ͱ��� */
typedef float          fp32;                    /* single precision floating point variable (32bits) �����ȸ�������32λ���ȣ� */
typedef double         fp64;                    /* double precision floating point variable (64bits) ˫���ȸ�������64λ���ȣ� */
typedef unsigned int   uint;                  /* defined for unsigned 32-bits integer variable     �޷���32λ���ͱ��� */

typedef  void* ZMC_HANDLE;
/************************************************/
//������ 
/************************************************/
#define ERR_OK  0
#define ERROR_OK 0
#define ERR_SUCCESS  0

#define ERR_AUX_OFFSET       30000

#define ERR_NOACK               ERR_AUX_OFFSET      //��Ӧ��
#define ERR_ACKERROR            (ERR_AUX_OFFSET+1)  //Ӧ�����
#define ERR_AUX_PARAERR         (ERR_AUX_OFFSET+2)  //��������
#define ERR_AUX_NOTSUPPORT      (ERR_AUX_OFFSET+3)  //��֧��

#define ERR_AUX_FILE_ERROR      (ERR_AUX_OFFSET+4)  //��������
#define ERR_AUX_OS_ERR      (ERR_AUX_OFFSET+5)  //

#if 0
    //�����������
#endif


//#define  ZAUX_DEBUG //����Ҫ���ʱע�͵�����
//#define  ZAUX_DEBUG_FILE "d:\\zauxout.txt"

#define ZAUX_COMMAND_SUM  100		//д������������ʱʹ��

#ifdef  ZAUX_DEBUG

#define ZAUX_TRACE(cText,a)     ZAux_TraceOut("%s,L:%u,"cText"\r\n",__FILE__,(unsigned int)__LINE__,a)
#define ZAUX_WARN(cText,a)      ZAux_TraceOut("%s,L:%u,"cText"\r\n",__FILE__,(unsigned int)__LINE__,a)
#define ZAUX_ERROR(cText,a)     ZAux_TraceOut("Error:%s,L:%u,"cText"\r\n",__FILE__,(unsigned int)__LINE__,a)
#define ZAUX_ERROR2(cText,a,b)     ZAux_TraceOut("Error:%s,L:%u,"cText"\r\n",__FILE__,(unsigned int)__LINE__,a,b)

#else

#define  ZAUX_TRACE(cText,a)
#define  ZAUX_WARN(cText,a)
#define  ZAUX_ERROR(cText,a)
#define  ZAUX_ERROR2(cText,a,b)

#endif

void  ZAux_TraceOut(const char * cText, ...);



/*********************************************************
��������
**********************************************************/


/*************************************************************
Description:    //��װ Excute ����, �Ա���մ���
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Execute(ZMC_HANDLE handle, const char* pszCommand, char* psResponse, uint32 uiResponseLength);


/*************************************************************
Description:    //��װ Excute ����, �Ա���մ���
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_DirectCommand(ZMC_HANDLE handle, const char* pszCommand, char* psResponse, uint32 uiResponseLength);

/*************************************************************
Description:    //�����������.
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_SetTraceFile(int bifTofile, const char *pFilePathName);






/*************************************************************
Description:    //��������������ӣ� ���ڷ�ʽ.
Input:          //���ں�COMId 
Output:         //������phandle
Return:         //������
*************************************************************/
int32 __stdcall ZAux_OpenCom(uint32 comid, ZMC_HANDLE * phandle);

/*************************************************************
Description:    //���ٿ�������������
Input:          //��С���ں�uimincomidfind
Input:          //��󴮿ں�uimaxcomidfind
Input:          //����ʱ��uims
Output:         //��ЧCOM pcomid
Output:         //������handle
Return:         //������
*************************************************************/
int32 __stdcall ZAux_SearchAndOpenCom(uint32 uimincomidfind, uint32 uimaxcomidfind,uint* pcomid, uint32 uims, ZMC_HANDLE * phandle);

/*************************************************************
Description:    //�����޸�ȱʡ�Ĳ����ʵ�����
uint32 dwByteSize = 8, uint32 dwParity = NOPARITY, uint32 dwStopBits = ONESTOPBIT
windows:
#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
ע��: ONESTOPBIT ����1
#define ONESTOPBIT          0
#define ONE5STOPBITS        1
#define TWOSTOPBITS         2
linux:
dwParity:0/1/2
dwStopBits
1:1��ֹͣλ
2:2��ֹͣλ
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_SetComDefaultBaud(uint32 dwBaudRate, uint32 dwByteSize, uint32 dwParity, uint32 dwStopBits);

/*************************************************************
Description:    //�޸Ŀ�����IP��ַ
Input:          //������handle 
Input:          //IP��ַ  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_SetIp(ZMC_HANDLE handle, char * ipaddress);

/*************************************************************
Description:    //���������������
Input:          //IP��ַ���ַ����ķ�ʽ����
Output:         //������handle
Return:         //������
*************************************************************/
int32  __stdcall ZAux_OpenEth(char *ipaddr, ZMC_HANDLE * phandle);


/*************************************************************
Description:    //���ټ���IP�б�
Input:          //uims ��Ӧʱ��
Input:          //addrbufflength		��󳤶�
output:			//ipaddrlist		��ǰ���IP�б�
Return:         //������, ERR_OK��ʾ��������.
*************************************************************/
int32 __stdcall ZAux_SearchEthlist(char *ipaddrlist, uint32 addrbufflength, uint32 uims);


/*************************************************************
Description:    //���ټ���������
Input:          //������IP��ַ
Input:          //��Ӧʱ��
Output:         //
Return:         //������, ERR_OK��ʾ��������.
*************************************************************/
int32 __stdcall ZAux_SearchEth(const char *ipaddress,  uint32 uims);

/*************************************************************
Description:    //�رտ���������
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Close(ZMC_HANDLE  handle);

/*************************************************************
Description:    //��ͣ��������BAS��Ŀ
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Resume(ZMC_HANDLE handle);

/*************************************************************
Description:    //��ͣ
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Pause(ZMC_HANDLE handle);

/*************************************************************
Description:    //����BAS�ļ�����ZAR�������ص�����������
Input:          //������handle
Input:          //Filename BAS�ļ�·��
Input:          //RAM-ROM  0-RAM  1-ROM
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_BasDown(ZMC_HANDLE handle,const char *Filename,uint32 run_mode);




#if 0
    //IOָ��
    // ����ʹ�� ZMC_GetIn ZMC_GetOutput ��
#endif
/*************************************************************
Description:    //��ȡ�����ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetIn(ZMC_HANDLE handle, int ionum , uint32 *piValue);


/*************************************************************
Description:    //������ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetOp(ZMC_HANDLE handle, int ionum, uint32 iValue);

/*************************************************************
Description:    //��ȡ�����״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetOp(ZMC_HANDLE handle, int ionum, uint32 *piValue);


/*************************************************************
Description:    //��ȡģ���������ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAD(ZMC_HANDLE handle, int ionum , float *pfValue);

/*************************************************************
Description:    //��ģ��������ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetDA(ZMC_HANDLE handle, int ionum, float fValue);


/*************************************************************
Description:    //��ȡģ�������״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetDA(ZMC_HANDLE handle, int ionum, float *pfValue);

/*************************************************************
Description:    //��������ڷ�ת
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetInvertIn(ZMC_HANDLE handle, int ionum, int bifInvert);

/*************************************************************
Description:    //��ȡ����ڷ�ת״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetInvertIn(ZMC_HANDLE handle, int ionum, int *piValue);

/*************************************************************
Description:    //����pwmƵ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetPwmFreq(ZMC_HANDLE handle, int ionum, float fValue);

/*************************************************************
Description:    //��ȡpwmƵ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetPwmFreq(ZMC_HANDLE handle, int ionum, float *pfValue);

/*************************************************************
Description:    //����pwmռ�ձ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetPwmDuty(ZMC_HANDLE handle, int ionum, float fValue);

/*************************************************************
Description:    //��ȡpwmռ�ձ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetPwmDuty(ZMC_HANDLE handle, int ionum, float *pfValue);

#if 0
    //ͨ��modbus���ٶ�ȡ����Ĵ���
#endif

/*************************************************************
Description:    //���� ���ٶ�ȡ�������
Input:          //������handle  
Output:         //��λ�洢
Return:         //������
*************************************************************/
int32 __stdcall ZAux_GetModbusIn(ZMC_HANDLE handle, int ionumfirst, int ionumend, uint8 *pValueList);


/*************************************************************
Description:    //���� ���ٶ�ȡ�����ǰ�����״̬
Input:          //������handle  
Output:         //��λ�洢
Return:         //������
*************************************************************/
int32 __stdcall ZAux_GetModbusOut(ZMC_HANDLE handle, int ionumfirst, int ionumend, uint8 *pValueList);


/*************************************************************
Description:    //���� ���ٶ�ȡ�����ǰ��DPOS
Input:          //������handle  
Output:         //���洢
Return:         //������
*************************************************************/
int32 __stdcall ZAux_GetModbusDpos(ZMC_HANDLE handle, int imaxaxises, float *pValueList);


/*************************************************************
Description:    //���� ���ٶ�ȡ�����ǰ��MPOS
Input:          //������handle  
Output:         //���洢
Return:         //������
*************************************************************/
int32 __stdcall ZAux_GetModbusMpos(ZMC_HANDLE handle, int imaxaxises, float *pValueList);


/*************************************************************
Description:    //���� ���ٶ�ȡ�����ǰ���ٶ�
Input:          //������handle  
Output:         //���洢
Return:         //������
*************************************************************/
int32 __stdcall ZAux_GetModbusCurSpeed(ZMC_HANDLE handle, int imaxaxises, float *pValueList);



#if 0
    //����ZMC_DirectCommand �����ٻ�ȡһЩ״̬, ZMC_DirectCommand��ִ�б�ZMC_ExecuteҪ��
	// ֻ�в���������������Ԫ�ص���ʹ��ZMC_DirectCommand
	// 20130901�Ժ�İ汾��һЩ�˶�����Ҳ���Ե���ZMC_DirectCommand�����˶������������ʱ�򣬻����̷���ʧ�ܡ�
	// ZMC_DirectCommand�����˶�����ʱ�����������Ǿ������ֵ�������Ǳ������ʽ��
#endif

/*************************************************************
Description:    //ͨ�õĲ����޸ĺ��� sParam: ��д��������
Input:          //������handle 
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetParam(ZMC_HANDLE handle,const char *sParam,int iaxis, float fset);

/*************************************************************
Description:    //���� ͨ�õĲ�����ȡ����, sParam:��д��������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetParam(ZMC_HANDLE handle,const char *sParam, int iaxis, float *pfValue);

/*************************************************************
Description:    //���ü��ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetAccel(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAccel(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAddax(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //������澯�ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetAlmIn(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ�澯�ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAlmIn(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //����������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetAtype(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAtype(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��ȡ��״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAxisStatus(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //�������ַ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetAxisAddress(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ���ַ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAxisAddress(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //������ʹ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetAxisEnable(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ��ʹ��״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetAxisEnable(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //������������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetClutchRate(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ��������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetClutchRate(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //�������津���Ľ������귶Χ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetCloseWin(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���津���Ľ������귶Χ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetCloseWin(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���ùսǼ���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetCornerMode(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ�սǼ���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetCornerMode(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���û��������ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetCreep(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���������ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetCreep(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //����ԭ���ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetDatumIn(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡԭ���ź�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetDatumIn(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���ü��ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetDecel(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetDecel(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���ùսǼ��ٽǶȣ���ʼ���ٽǶȣ���λΪ����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetDecelAngle(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ�սǿ�ʼ���ٽǶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetDecelAngle(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //������λ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetDpos(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ��λ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetDpos(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ�ڲ�������ֵ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetEncoder(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ��ǰ�˶�������λ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetEndMove(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ��ǰ�ͻ������˶�������λ�ã�����������Ծ���ת��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetEndMoveBuffer(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //����SP�˶��Ľ����ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetEndMoveSpeed(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡSP�˶��Ľ����ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetEndMoveSpeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���ô����ǣ���AXISSTATUS����������������Щ������Ҫ�ر�WDOG��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetErrormask(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ�����ǣ���AXISSTATUS����������������Щ������Ҫ�ر�WDOG��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetErrormask(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���ÿ���JOG����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFastJog(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ����JOG����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFastJog(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���ÿ��ټ��ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFastDec(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���ټ��ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFastDec(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ�涯���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFe(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //�������������涯���ֵ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFeLimit(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���������涯���ֵ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFeLimit(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���ñ���ʱ�涯���ֵ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFRange(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ����ʱ���涯���ֵ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFeRange(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���ñ�������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFholdIn(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ��������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFholdIn(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //�����ᱣ���ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFhspeed(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ�ᱣ���ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFhspeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //����SP�˶��������ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetForceSpeed(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡSP�˶��������ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetForceSpeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //������������λ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFsLimit(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ��������λ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFsLimit(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //����СԲ������С�뾶
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFullSpRadius(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡСԲ������С�뾶
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFullSpRadius(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��������Ӳ��λ����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFwdIn(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ����Ӳ��λ����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFwdIn(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��������JOG����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetFwdJog(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ����JOG����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetFwdJog(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��ȡ���Ƿ��˶�����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetIfIdle(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //�����������ģʽ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetInvertStep(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ�������ģʽ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetInvertStep(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���ò岹ʱ���Ƿ�����ٶȼ��㣬ȱʡ���루1�����˲���ֻ��ֱ�ߺ������ĵ�������������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetInterpFactor(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ�岹ʱ���Ƿ�����ٶȼ��㣬ȱʡ���루1�����˲���ֻ��ֱ�ߺ������ĵ�������������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetInterpFactor(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //����JOGʱ�ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetJogSpeed(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡJOGʱ�ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetJogSpeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ��ǰ�����˶��Ĳο����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetLinkax(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��ȡ��ǰ���˵�ǰ�˶��Ƿ��л���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetLoaded(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��������ʼ�ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetLspeed(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ����ʼ�ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetLspeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���û��㷴�ҵȴ�ʱ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetHomeWait(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���㷴�ҵȴ�ʱ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetHomeWait(ZMC_HANDLE handle, int iaxis, float *pfValue);


/*************************************************************
Description:    //��ȡ����������ʾ�̷���״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMark(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��ȡ����������ʾ�̷���״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMarkB(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��������������Ƶ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetMaxSpeed(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ����������Ƶ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMaxSpeed(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���������岹
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetMerge(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ�����岹״̬
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMerge(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��ȡ��ǰ�������������˶�����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMovesBuffered(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��ȡ��ǰ�����˶�ָ���MOVE_MARK���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMoveCurmark(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //�����˶�ָ���MOVE_MARK���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetMovemark(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //���÷���λ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetMpos(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ����λ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMpos(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ�����ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMspeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ��ǰ�����˶�ָ������
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetMtype(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //�����޸�ƫ��λ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetOffpos(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ�޸�ƫ��λ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetOffpos(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //�������津���Ľ������귶Χ�㡣
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetOpenWin(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���津���Ľ������귶Χ�㡣
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetOpenWin(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ��������Ĳ�������λ��(MPOS)
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRegPos(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ��������Ĳ�������λ��(MPOS)
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRegPosB(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ�����ᵱǰ�˶���δ��ɵľ���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRemain(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //����  ��ʣ��Ļ���, ��ֱ�߶�������
				  REMAIN_BUFFERΪΨһһ�����Լ�AXIS����ZAux_DirectCommand��ȡ��.
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRemain_LineBuffer(ZMC_HANDLE handle, int iaxis,int * piValue);

/*************************************************************
Description:    //����  ��ʣ��Ļ���, ����ӵĿռ�Բ��������
				  REMAIN_BUFFERΪΨһһ�����Լ�AXIS����ZAux_DirectCommand��ȡ��.
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRemain_Buffer(ZMC_HANDLE handle, int iaxis, int *piValue);


/*************************************************************
Description:    //���ø���REP_OPTION�������Զ�ѭ����DPOS��MPOS���ꡣ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetRepDist(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ����REP_OPTION�������Զ�ѭ����DPOS��MPOS���ꡣ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetOpenRepDist(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���������ظ�����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetRepOption(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ�����ظ�����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRepOption(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //��ȡ����REP_OPTION�������Զ�ѭ����DPOS��MPOS���ꡣ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRepDist(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���ø���Ӳ����λ���ض�Ӧ��������ţ�-1��Ч��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetRevIn(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ����Ӳ����λ���ض�Ӧ��������ţ�-1��Ч��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRevIn(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���ø���JOG�����Ӧ��������ţ�-1��Ч��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetRevJog(ZMC_HANDLE handle, int iaxis, int iValue);

/*************************************************************
Description:    //��ȡ����JOG�����Ӧ��������ţ�-1��Ч��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRevJog(ZMC_HANDLE handle, int iaxis, int *piValue);

/*************************************************************
Description:    //���ø�������λλ�á�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetRsLimit(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ��������λλ�á�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetRsLimit(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //�������ٶȣ���λΪunits/s���������˶�ʱ����Ϊ�岹�˶����ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetSpeed(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���ٶȣ���λΪunits/s���������˶�ʱ����Ϊ�岹�˶����ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetSpeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���� S�������á�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetSramp(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ S�������á�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetSramp(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���� �Զ����ٶȵ�SP�˶�����ʼ�ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetStartMoveSpeed(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ�Զ����ٶȵ�SP�˶�����ʼ�ٶ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetStartMoveSpeed(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���� ���ٵ���͵���С�ս�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetStopAngle(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���ٵ���͵���С�ս�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetStopAngle(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���� ���ٵ���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetZsmooth(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���ǰ뾶
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetZsmooth(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //���� ���嵱��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetUnits(ZMC_HANDLE handle, int iaxis, float fValue);

/*************************************************************
Description:    //��ȡ���嵱��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetUnits(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //��ȡ�����ᵱǰ��ǰ�˶��ͻ����˶���δ��ɵľ���
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetVectorBuffered(ZMC_HANDLE handle, int iaxis, float *pfValue);

/*************************************************************
Description:    //����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetVpSpeed(ZMC_HANDLE handle, int iaxis, float *pfValue);




/*************************************************************
Description:    //ȫ�ֱ�����ȡ, Ҳ�����ǲ����ȵ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetVariablef(ZMC_HANDLE handle, const char *pname, float *pfValue);


/*************************************************************
Description:    //ȫ�ֱ�����ȡ, Ҳ�����ǲ����ȵ�
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetVariableInt(ZMC_HANDLE handle, const char *pname, int *piValue);

///////////////////////  ֻ��������˶�����֧��ֱ�ӵ��ã����������е�ָ�֧��
///////////////////////  ���� 20130901 �Ժ�Ŀ������汾֧��

/*************************************************************
Description:    //BASEָ�����

�����޸����������BASE�б����Կ����������������BASE�����޸�.
�޸ĺ󣬺���������MOVE��ָ��������BASEΪ����

Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Base(ZMC_HANDLE handle, int imaxaxises, int *piAxislist);

/*************************************************************
Description:    //����DPOS
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Defpos(ZMC_HANDLE handle, int imaxaxises, float *pfDposlist);

/*************************************************************
Description:    //��Բ岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Move(ZMC_HANDLE handle, int imaxaxises, float *pfDisancelist);


/*************************************************************
Description:    //��Բ岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveSp(ZMC_HANDLE handle, int imaxaxises, float *pfDisancelist);



/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveAbs(ZMC_HANDLE handle, int imaxaxises, float *pfDisancelist);

/*************************************************************
Description:    //�岹 BASE�����̵����˶�����.
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_BaseAndMoveAbs(ZMC_HANDLE handle, int imaxaxises, int *piAxislist, float *pfDisancelist);

/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveAbsSp(ZMC_HANDLE handle, int imaxaxises, float *pfDisancelist);



/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveModify(ZMC_HANDLE handle, int imaxaxises, float *pfDisancelist);



/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

end1              ��һ�����˶�����
end2              �ڶ������˶�����
centre1    ��һ�����˶�Բ�ģ��������ʼ�㡣
centre2    �ڶ������˶�Բ�ģ��������ʼ�㡣
direction  0-��ʱ�룬1-˳ʱ��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCirc(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection);


/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

end1              ��һ�����˶�����
end2              �ڶ������˶�����
centre1    ��һ�����˶�Բ�ģ��������ʼ�㡣
centre2    �ڶ������˶�Բ�ģ��������ʼ�㡣
direction  0-��ʱ�룬1-˳ʱ��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCircSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection);



/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

end1              ��һ�����˶����꣬����λ��
end2              �ڶ������˶����꣬����λ��
centre1    ��һ�����˶�Բ�ģ�����λ��
centre2    �ڶ������˶�Բ�ģ�����λ��
direction  0-��ʱ�룬1-˳ʱ��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCircAbs(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection);


/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

end1              ��һ�����˶����꣬����λ��
end2              �ڶ������˶����꣬����λ��
centre1    ��һ�����˶�Բ�ģ�����λ��
centre2    �ڶ������˶�Բ�ģ�����λ��
direction  0-��ʱ�룬1-˳ʱ��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCircAbsSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection);




/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

mid1       ��һ�����м�㣬�����ʼ�����
mid2       �ڶ������м�㣬�����ʼ�����
end1              ��һ��������㣬�����ʼ�����
end2              �ڶ���������㣬�����ʼ�����

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCirc2(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2);



/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

mid1       ��һ�����м�㣬����λ��
mid2       �ڶ������м�㣬����λ��
end1              ��һ��������㣬����λ��
end2              �ڶ���������㣬����λ��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCirc2Abs(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2);


/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

mid1       ��һ�����м�㣬�����ʼ�����
mid2       �ڶ������м�㣬�����ʼ�����
end1              ��һ��������㣬�����ʼ�����
end2              �ڶ���������㣬�����ʼ�����

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCirc2Sp(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2);



/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle

mid1       ��һ�����м�㣬����λ��
mid2       �ڶ������м�㣬����λ��
end1              ��һ��������㣬����λ��
end2              �ڶ���������㣬����λ��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveCirc2AbsSp(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2);




/*************************************************************
Description:    //�岹
Input:          //������handle

end1              ��һ�����˶�����

end2              �ڶ������˶�����

centre1    ��һ�����˶�Բ�ģ��������ʼ��

centre2    �ڶ������˶�Բ�ģ��������ʼ��

direction  0-��ʱ�룬1-˳ʱ��

distance3���������˶����롣

mode      ��������ٶȼ���:
0(ȱʡ)
 ����������ٶȼ��㡣
1
 �����᲻�����ٶȼ��㡣
 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelical(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fDistance3, int imode);


/*************************************************************
Description:    //�岹
Input:          //������handle

end1              ��һ�����˶�����

end2              �ڶ������˶�����

centre1    ��һ�����˶�Բ�ģ��������ʼ��

centre2    �ڶ������˶�Բ�ģ��������ʼ��

direction  0-��ʱ�룬1-˳ʱ��

distance3���������˶����롣

mode      ��������ٶȼ���:
0(ȱʡ)
 ����������ٶȼ��㡣
1
 �����᲻�����ٶȼ��㡣
 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelicalAbs(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fDistance3, int imode);


/*************************************************************
Description:    //�岹
Input:          //������handle

end1              ��һ�����˶�����

end2              �ڶ������˶�����

centre1    ��һ�����˶�Բ�ģ��������ʼ��

centre2    �ڶ������˶�Բ�ģ��������ʼ��

direction  0-��ʱ�룬1-˳ʱ��

distance3���������˶����롣

mode      ��������ٶȼ���:
0(ȱʡ)
 ����������ٶȼ��㡣
1
 �����᲻�����ٶȼ��㡣
 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelicalSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fDistance3, int imode);


/*************************************************************
Description:    //�岹
Input:          //������handle

end1              ��һ�����˶�����

end2              �ڶ������˶�����

centre1    ��һ�����˶�Բ�ģ��������ʼ��

centre2    �ڶ������˶�Բ�ģ��������ʼ��

direction  0-��ʱ�룬1-˳ʱ��

distance3���������˶����롣

mode      ��������ٶȼ���:
0(ȱʡ)
 ����������ٶȼ��㡣
1
 �����᲻�����ٶȼ��㡣
 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelicalAbsSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fDistance3, int imode);



/*************************************************************
Description:    //�岹
Input:          //������handle

mid1       ��һ�����м��

mid2       �ڶ������м��

end1              ��һ���������

end2              �ڶ����������

distance3���������˶�����

mode      ��������ٶȼ���:

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelical2(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2, float fDistance3, int imode);


/*************************************************************
Description:    //�岹
Input:          //������handle

mid1       ��һ�����м��

mid2       �ڶ������м��

end1              ��һ���������

end2              �ڶ����������

distance3   ���������˶�������

mode      ��������ٶȼ���:

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelical2Abs(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2, float fDistance3, int imode);


/*************************************************************
Description:    //�岹
Input:          //������handle

mid1       ��һ�����м��

mid2       �ڶ������м��

end1              ��һ���������

end2              �ڶ����������

distance3���������˶�����

mode      ��������ٶȼ���:

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelical2Sp(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2, float fDistance3, int imode);


/*************************************************************
Description:    //�岹
Input:          //������handle

mid1       ��һ�����м��

mid2       �ڶ������м��

end1              ��һ���������

end2              �ڶ����������

distance3   ���������˶�������

mode      ��������ٶȼ���:

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MHelical2AbsSp(ZMC_HANDLE handle, float fmid1, float fmid2, float fend1, float fend2, float fDistance3, int imode);




/*************************************************************
Description:    //�岹
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipse(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis);


/*************************************************************
Description:    //�岹
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipseAbs(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis);


/*************************************************************
Description:    //�岹
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipseSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis);


/*************************************************************
Description:    //�岹
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipseAbsSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis);



/*************************************************************
Description:    //�岹 ��Բ + ����
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipseHelical(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis, float fDistance3);


/*************************************************************
Description:    //�岹  ��Բ + ����
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipseHelicalAbs(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis,float fDistance3);


/*************************************************************
Description:    //�岹 ��Բ + ����
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipseHelicalSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis, float fDistance3);


/*************************************************************
Description:    //�岹  ��Բ + ����
Input:          //������handle

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MEclipseHelicalAbsSp(ZMC_HANDLE handle, float fend1, float fend2, float fcenter1, float fcenter2, int idirection, float fADis, float fBDis,float fDistance3);



/*************************************************************
Description:    //�岹  �ռ�Բ��
Input:          //������handle
end1              ��1�����˶��������1

end2              ��2�����˶��������1

end3              ��3�����˶��������1

centre1    ��1�����˶��������2

centre2    ��2�����˶��������2

centre3    ��3�����˶��������2

mode      ָ��ǰ�����������
0 ��ǰ�㣬�м�㣬�յ����㶨Բ�����������1Ϊ�յ���룬�������2Ϊ�м����롣
1 ����С��Բ�����������1Ϊ�յ���룬�������2ΪԲ�ĵľ��롣
2 ��ǰ�㣬�м�㣬�յ����㶨Բ���������1Ϊ�յ���룬�������2Ϊ�м����롣
3 ������С��Բ�����ټ���������Բ���������1Ϊ�յ���룬�������2ΪԲ�ĵľ��롣
 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MSpherical(ZMC_HANDLE handle, float fend1, float fend2, float fend3, float fcenter1, float fcenter2, float fcenter3, int imode,float fcenter4, float fcenter5);


/*************************************************************
Description:    //�岹  �ռ�Բ��
Input:          //������handle
end1              ��1�����˶��������1

end2              ��2�����˶��������1

end3              ��3�����˶��������1

centre1    ��1�����˶��������2

centre2    ��2�����˶��������2

centre3    ��3�����˶��������2

mode      ָ��ǰ�����������
0 ��ǰ�㣬�м�㣬�յ����㶨Բ�����������1Ϊ�յ���룬�������2Ϊ�м����롣
1 ����С��Բ�����������1Ϊ�յ���룬�������2ΪԲ�ĵľ��롣
2 ��ǰ�㣬�м�㣬�յ����㶨Բ���������1Ϊ�յ���룬�������2Ϊ�м����롣
3 ������С��Բ�����ټ���������Բ���������1Ϊ�յ���룬�������2ΪԲ�ĵľ��롣
 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MSphericalSp(ZMC_HANDLE handle, float fend1, float fend2, float fend3, float fcenter1, float fcenter2, float fcenter3, int imode,float fcenter4, float fcenter5);



/*************************************************************
Description:    //������Բ���岹�˶�������ƶ���ʽ������ʼ�뾶0ֱ����ɢʱ��0�Ƕȿ�ʼ
Input:          //������handle

              centre1: ��1��Բ�ĵ���Ծ���

              centre2: ��2��Բ�ĵ���Ծ���

              circles:  Ҫ��ת��Ȧ��������ΪС��Ȧ��������ʾ˳ʱ��.

              pitch:   ÿȦ����ɢ���룬����Ϊ����

distance3        ��3�������Ĺ��ܣ�ָ����3�����Ծ��룬���᲻�����ٶȼ��㡣

distance4        ��4�������Ĺ��ܣ�ָ����4�����Ծ��룬���᲻�����ٶȼ��㡣
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveSpiral(ZMC_HANDLE handle, float centre1, float centre2, float circles, float pitch, float distance3, float distance4);

/*************************************************************
Description:    //������Բ���岹�˶�������ƶ���ʽ������ʼ�뾶0ֱ����ɢʱ��0�Ƕȿ�ʼ
Input:          //������handle

              centre1: ��1��Բ�ĵ���Ծ���

              centre2: ��2��Բ�ĵ���Ծ���

              circles:  Ҫ��ת��Ȧ��������ΪС��Ȧ��������ʾ˳ʱ��.

              pitch:   ÿȦ����ɢ���룬����Ϊ����

distance3        ��3�������Ĺ��ܣ�ָ����3�����Ծ��룬���᲻�����ٶȼ��㡣

distance4        ��4�������Ĺ��ܣ�ָ����4�����Ծ��룬���᲻�����ٶȼ��㡣

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveSpiralSp(ZMC_HANDLE handle, float centre1, float centre2, float circles, float pitch, float distance3, float distance4);

/*************************************************************
Description:    //�ռ�ֱ���˶���������һ��ֱ���˶��ľ��������ڹս��Զ�����Բ��������Բ�����ʹ���˶����յ���ֱ�ߵ��յ㲻һ�£��սǹ���ʱ�������Բ���������벻��ʱ���Զ���С�뾶
Input:          //������handle
end1              ��1�����˶���������
end2              ��2�����˶���������
end3              ��3�����˶���������
next1      ��1������һ��ֱ���˶���������
next2      ��2������һ��ֱ���˶���������
next3      ��3������һ��ֱ���˶���������
radius      ����Բ���İ뾶���������ʱ���Զ���С��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveSmooth(ZMC_HANDLE handle, float end1, float end2, float end3, float next1, float next2, float next3, float radius);

/*************************************************************
Description:    //�ռ�ֱ���˶���������һ��ֱ���˶��ľ��������ڹս��Զ�����Բ��������Բ�����ʹ���˶����յ���ֱ�ߵ��յ㲻һ�£��սǹ���ʱ�������Բ���������벻��ʱ���Զ���С�뾶
Input:          //������handle
end1              ��1�����˶���������
end2              ��2�����˶���������
end3              ��3�����˶���������
next1      ��1������һ��ֱ���˶���������
next2      ��2������һ��ֱ���˶���������
next3      ��3������һ��ֱ���˶���������
radius      ����Բ���İ뾶���������ʱ���Զ���С��

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveSmoothSp(ZMC_HANDLE handle, float end1, float end2, float end3, float next1, float next2, float next3, float radius);




/*************************************************************
Description:    //�˶���ͣ
Input:          //������handle  

0��ȱʡ�� ��ͣ��ǰ�˶��� 
1 �ڵ�ǰ�˶���ɺ���׼��ִ����һ���˶�ָ��ʱ��ͣ�� 
2 �ڵ�ǰ�˶���ɺ���׼��ִ����һ���˶�ָ��ʱ����������ָ���MARK��ʶ��һ��ʱ��ͣ�����ģʽ��������һ�������ɶ��ָ����ʵ��ʱ��������һ����������ɺ���ͣ�� 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MovePause(ZMC_HANDLE handle, int imode);


/*************************************************************
Description:    //�˶���ͣ
Input:          //������handle  

0��ȱʡ�� ��ͣ��ǰ�˶��� 
1 �ڵ�ǰ�˶���ɺ���׼��ִ����һ���˶�ָ��ʱ��ͣ�� 
2 �ڵ�ǰ�˶���ɺ���׼��ִ����һ���˶�ָ��ʱ����������ָ���MARK��ʶ��һ��ʱ��ͣ�����ģʽ��������һ�������ɶ��ָ����ʵ��ʱ��������һ����������ɺ���ͣ�� 

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveResume(ZMC_HANDLE handle);

/*************************************************************
Description:    //�ڵ�ǰ���˶�ĩβλ�������ٶ����ƣ�����ǿ�ƹսǼ���
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveLimit(ZMC_HANDLE handle, float limitspeed);

/*************************************************************
Description:    //���˶������м������ָ��
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveOp(ZMC_HANDLE handle, int ioutnum, int ivalue);

/*************************************************************
Description:    //���˶������м������ָ��
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveOpMulti(ZMC_HANDLE handle, int ioutnumfirst, int ioutnumend, int ivalue);

/*************************************************************
Description:    //���˶������м������ָ��
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveOp2(ZMC_HANDLE handle, int ioutnum, int ivalue, int iofftimems);

/*************************************************************
Description:    //���˶������м���AOUT���ָ��
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveAout(ZMC_HANDLE handle, int ioutnum, float fvalue);

/*************************************************************
Description:    //���˶������м�����ʱָ��
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveDelay(ZMC_HANDLE handle, int itimems);


/*************************************************************
Description:    //�岹 ��ת�Ĳ岹�˶�
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_MoveTurnabs(ZMC_HANDLE handle, int tablenum ,int imaxaxises, float *pfDisancelist);

/*************************************************************
Description:    //�岹 ֱ�ӵ����˶����� 20130901 �Ժ�Ŀ������汾֧��
Input:          //������handle
				tablenum       �洢��ת������table���
refpos1    ��һ����ο��㣬����λ��
refpos2    �ڶ�����ο��㣬����λ��
mode      1-�ο����ǵ�ǰ��ǰ�棬2-�ο����ǽ�������棬3-�ο������м䣬�������㶨Բ�ķ�ʽ��
end1              ��һ��������㣬����λ��
end2              �ڶ���������㣬����λ��
imaxaxises        ���������
pfDisancelist	����������б�
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_McircTurnabs(ZMC_HANDLE handle, int tablenum ,float refpos1,float refpos2,int mode,float end1,float end2,int imaxaxises, float *pfDisancelist);

/*************************************************************
Description:    //����͹��
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Cam(ZMC_HANDLE handle, int istartpoint, int iendpoint, float ftablemulti, float fDistance);

/*************************************************************
Description:    //����͹��
Input:          //������handle  

Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Cambox(ZMC_HANDLE handle, int istartpoint, int iendpoint, float ftablemulti, float fDistance, int ilinkaxis, int ioption, float flinkstartpos);



/*************************************************************
Description:    //���� ����͹��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Movelink(ZMC_HANDLE handle, float fDistance, float fLinkDis, float fLinkAcc, float fLinkDec,int iLinkaxis, int ioption, float flinkstartpos);

/*************************************************************
Description:    //���� ����͹��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Moveslink(ZMC_HANDLE handle, float fDistance, float fLinkDis, float startsp, float endsp,int iLinkaxis, int ioption, float flinkstartpos);

/*************************************************************
Description:    //���� ͬ���˶�ָ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Connect(ZMC_HANDLE handle, float ratio, int link_axis, int move_axis);

/*************************************************************
Description:    //���� ͬ���˶�ָ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Connpath(ZMC_HANDLE handle, float ratio, int link_axis, int move_axis);


/*************************************************************
Description:    //λ������ָ��
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Regist(ZMC_HANDLE handle, int imode);

/*************************************************************
Description:    //������������ֱȣ�ȱʡ(1,1)
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_EncoderRatio(ZMC_HANDLE handle,int mpos_count,int input_count);

/*************************************************************
Description:    //���ò���������ֱȣ�ȱʡ(1,1)
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_StepRatio(ZMC_HANDLE handle,int mpos_count,int input_count);


/*************************************************************
Description:    //����������ֹͣ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Rapidstop(ZMC_HANDLE handle, int imode);

/*************************************************************
Description:    //������˶�ֹͣ
Input:          //������handle  ��ţ� ����
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_CancelAxisList(ZMC_HANDLE handle, int imaxaxises, int *piAxislist, int imode);

/*************************************************************
Description:    //CONNFRAME��е��ָ��

Input:          //������handle
					frame��е������
					tablenum  ��ز���TABLE���
					imaxaxises �������������
					piAxislist �������б�
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Connframe(ZMC_HANDLE handle, int frame, int tablenum , int imaxaxises , int *piAxislist);

/*************************************************************
Description:    //CONNREFRAME��е��ָ��

Input:          //������handle
					frame��е������
					tablenum  ��ز���TABLE���
					imaxaxises �����ؽ������
					piAxislist �ؽ����б�
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Connreframe(ZMC_HANDLE handle, int frame, int tablenum , int imaxaxises , int *piAxislist);


#if 0
    //���ắ��
#endif

/*************************************************************
Description:    //����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Singl_Addax(ZMC_HANDLE handle, int iaxis, int iaddaxis);

/*************************************************************
Description:    //�����˶�ֹͣ
Input:          //������handle  ��ţ� ģʽ
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Singl_Cancel(ZMC_HANDLE handle, int iaxis, int imode);


/*************************************************************
Description:    //�����˶�
Input:          //������handle  ��ţ� ����
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Singl_Vmove(ZMC_HANDLE handle, int iaxis, int idir);

/*************************************************************
Description:    //����
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Singl_Datum(ZMC_HANDLE handle, int iaxis, int imode);


/*************************************************************
Description:    //�����˶�
Input:          //������handle  ��ţ� ����
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Singl_Move(ZMC_HANDLE handle, int iaxis, float fdistance);


/*************************************************************
Description:    //�����˶�
Input:          //������handle  ��ţ� ����
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_Singl_MoveAbs(ZMC_HANDLE handle, int iaxis, float fdistance);




#if 0
    //��������
#endif

//*********************�ڴ����

//*********************�ڴ����
/*************************************************************
Description:    //дVR, 
Input:          //������handle  ��ţ� ����
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetVrf(ZMC_HANDLE handle,int vrstartnum, int numes, float *pfValue);

/*************************************************************
Description:    //VR��ȡ, ����һ�ζ�ȡ���
Input:          //������handle  
Output:         //pfValue  ���ʱ�������ռ�.
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetVrf(ZMC_HANDLE handle, int vrstartnum, int numes, float *pfValue);


/*************************************************************
Description:    //VRINT��ȡ�� ����150401���ϰ汾��֧��VRINT��DIRECTCOMMAND��ȡ
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetVrInt(ZMC_HANDLE handle, int vrstartnum, int numes, int *piValue);

/*************************************************************
Description:    //дtable 
Input:          //������handle  ��ţ� ����
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_SetTable(ZMC_HANDLE handle,int tabstart, int numes, float *pfValue);

/*************************************************************
Description:    //table��ȡ, ����һ�ζ�ȡ���
Input:          //������handle  
Output:         //pfValue  ���ʱ�������ռ�.
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Direct_GetTable(ZMC_HANDLE handle, int tabstart, int numes, float *pfValue);

/*************************************************************
Description:    //�ַ���תΪfloat
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_TransStringtoFloat(const char* pstringin, int inumes,  float* pfvlaue);


/*************************************************************
Description:    //�ַ���תΪint
Input:          //������handle  
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_TransStringtoInt(const char* pstringin, int inumes,  int* pivlaue);

/*************************************************************
Description:    //��float��ʽ�ı����б�洢���ļ��� ���������U���ļ���ʽһ��.
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_WriteUFile(const char *sFilename, float *pVarlist, int inum);

/*************************************************************
Description:    //��ȡfloat��ʽ�ı����б� ���������U���ļ���ʽһ��.
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_ReadUFile(const char *sFilename, float *pVarlist, int* pinum);


/*************************************************************
Description:    //modbus�Ĵ�������
Input:          //������handle �Ĵ�����ַ
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Set0x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint8* pdata);

/*************************************************************
Description:    //modbus�Ĵ�������
Input:          //������handle �Ĵ�����ַ
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Get0x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint8* pdata);

/*************************************************************
Description:    //modbus�Ĵ�������
Input:          //������handle �Ĵ�����ַ
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Set4x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint16* pdata);

/*************************************************************
Description:    //modbus�Ĵ�������
Input:          //������handle �Ĵ�����ַ
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Get4x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint16* pdata);

/*************************************************************
Description:    //modbus_ieee
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Get4x_Float(ZMC_HANDLE handle, uint16 start, uint16 inum, float* pfdata);

/*************************************************************
Description:    //modbus_ieee
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Set4x_Float(ZMC_HANDLE handle, uint16 start, uint16 inum, float* pfdata);

/*************************************************************
Description:    //modbus_long
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Get4x_Long(ZMC_HANDLE handle, uint16 start, uint16 inum, int32* pidata);

/*************************************************************
Description:    //modbus_long
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Set4x_Long(ZMC_HANDLE handle, uint16 start, uint16 inum, int32* pidata);

/*************************************************************
Description:    //modbus_string
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Get4x_String(ZMC_HANDLE handle, uint16 start, uint16 inum, char * pidata);

/*************************************************************
Description:    //modbus_string
Input:          //
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_Modbus_Set4x_String(ZMC_HANDLE handle, uint16 start, uint16 inum, char * pidata);

/*************************************************************
Description:    //д�û�flash��, float����
Input:          //������handle
					uiflashid 	flash���
					uinumes		��������
Output:         //
Return:         //������
*************************************************************/
int32 __stdcall ZAux_FlashWritef(ZMC_HANDLE handle, uint16 uiflashid, uint32 uinumes, float *pfvlue);

/*************************************************************
Description:    //��ȡ�û�flash��, float����
Input:          //������handle
					uiflashid 	flash���
					uibuffnum	�����������
Output:         //
					puinumesread ��ȡ���ı�������
Return:         //������
*************************************************************/
int32 __stdcall ZAux_FlashReadf(ZMC_HANDLE handle, uint16 uiflashid, uint32 uibuffnum, float *pfvlue, uint32* puinumesread);

/*************************************************************
Description:    //ZAux_WriteLog ����, ����ַ������̶����ı���
Input:          //������			handle
Input:          //�ַ�������		pszErro
Input:          //�ַ�������,����ļ���ַ		pfilename
Return:         //������
*************************************************************/
int32 __stdcall ZAux_WriteLog( const char* pszErro,const char* pfilename);

/*************************************************************
Description:    //ZAux_WriteCommandLog ����, �����ǰ100��ָ��log
Input:          //������			handle
Input:          //�ַ����������ļ���ַ		pfilename
Return:         //������
*************************************************************/
int32 __stdcall ZAux_WriteCommandLog(const char* pfilename);



#ifdef __cplusplus  
}  
#endif 


#endif











