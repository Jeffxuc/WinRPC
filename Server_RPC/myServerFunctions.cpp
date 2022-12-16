/*************************
* Server Function Implement
* Used to implement declared functions
* in interface IDL  file
**************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>

#include "..\\Interface_RPC\\myApp_h.h"

/// <summary>
/// Stop listening the client
/// </summary>
/// <param name=""></param>
void Shutdown(void)
{
    RPC_STATUS status;

    status = RpcMgmtStopServerListening(NULL);

    if (status)
    {
        printf("RpcMgmtStopServerListening Failed, ErrorCode = %ld\n", status);
        exit(status);
    }




    status = RpcServerUnregisterIf(NULL, NULL, FALSE);

    if (status)
    {
        printf("RpcServerUnregisterIf Failed, ErrorCode = %ld\n", status);
        exit(status);
    }

}


/// <summary>
/// A simple hello procedure for test the RPC function.
/// </summary>
/// <param name="pszString"></param>
void HelloProc(/*[in, string]*/ const unsigned char* pszString)
{
    printf("%s\n", pszString);
}


int GetAddRes(/*[in]*/ int num1, /*[in]*/ int num2)
{
    return num1 + num2;
}

int GetCondition(
    /* [string][in] */ const unsigned char* pState,
    /* [out] */ wchar_t pRet[20])
{
    if (pState == NULL)
        return 1;
    
    switch (pState[1])
    {
    case 'A':
        swprintf(pRet, 20, L"Case A!");
        break;
    case 'B':
        swprintf(pRet, 20, L"Case B!");
        break;
    default:
        swprintf(pRet, 20, L"Default Case!");
        break;
    }

    printf("pRet Condition is: %S\n", pRet);

    return 0;
}

void GetMyAppVersion(
    /* [out] */ wchar_t versionNum[10])
{
    //swprintf(versionNum, 10, L"ver=1.0");

    //���ƿ��ַ�����
    wcscpy_s(versionNum, 10, L"ver:2.0");
}


/// <summary>
/// ��ʱClient�˿���������Server�˻�ȡ�ַ�������������
/// </summary>
/// <param name="arrChar"></param>
void GetArrCharStr(
    /* [out] */ unsigned char arrChar[100])
{
    strcpy_s((char*)arrChar, 100, "Out String by Array.");
    printf("Astr = : %s\n", arrChar);
}


/// <summary>
/// ��ʱClient��ֻ�ܴ�Server�˵õ���Ԫ�ر���ֵ���ַ������ַ���ʣ�µ����ݶ��޷���ȡ��
/// ��MIDL�н� unsigned char* pChar ��Ϊһ���ַ��������ַ�����
/// </summary>
/// <param name="pChar"></param>
void GetPointerCharStr(
    /* [out] */ unsigned char* pChar)
{
    strcpy_s((char*)pChar, 100, "Pointer style string.");
    printf("Pstr = : %s\n", pChar);
}


int GetFanSpeed()
{
    return 20000;
}


