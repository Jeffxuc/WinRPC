/*************************
======== Client ==========
**************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>

#include "..\Interface_RPC\myApp_h.h"
#include "..\Interface_RPC\myApp_c.c"

#pragma comment( lib, "Rpcrt4.lib" ) //For RPC function.


/******************************************************/
/*         MIDL allocate and free                     */
/******************************************************/

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
    free(ptr);
}


int main()
{
    RPC_STATUS status;

    const char* pszUuid = NULL;
    const char* pszProtocolSequence = "ncalrpc";    //local RPC protocol sequence.
    const char* pszNetworkAddress = NULL;
    const char* pszEndpoint = "MyAppTestEndpoint";   //Corresponding to the ProtocolSequence
    const char* pszOptions = NULL;
    unsigned char* pszStringBinding = NULL;
    
    const char* pszString = "hello, world";
    unsigned long ulCode = 0;

    //1. Initial and Set the RPC composition content.
    status = RpcStringBindingComposeA(
        (unsigned char*)pszUuid,              // UUID
        (unsigned char*)pszProtocolSequence,  // Protocol sequence to use
        (unsigned char*)pszNetworkAddress,    // The network address or the name of the server host computer
        (unsigned char*)pszEndpoint,
        (unsigned char*)pszOptions,
        &pszStringBinding);                   // Create a string binding handle.

    //Error checking, If no error(status=0), we proceed below, otherwise exit.
    if (status)
        exit(status);

    //2. Set the RPC Binding handle.
    status = RpcBindingFromStringBindingA(
        pszStringBinding,
        &MyApp_UsedHandle);   // implicit_handle

    if (status)
        exit(status);

    //3. Excute the Remote Procedure Call in RpcTryExcept.
    RpcTryExcept
    {

    HelloProc((const unsigned char*)pszString);
        
    int resNum = GetAddRes(10, 70);

    wchar_t pRet01[20];
    GetCondition((const unsigned char*)"ABB", pRet01);
    printf("The condition is = %S\n", pRet01);

    wchar_t pVer[10];
    GetMyAppVersion(pVer);
    printf("The version is %S\n", pVer);

    unsigned char arrChar[100];
    GetArrCharStr(arrChar);
    printf("Array string = : %s\n", arrChar);

    unsigned char pChar[100];
    GetPointerCharStr(pChar);
    printf("Pointer char = : %s\n", pChar);


    int fanSpeed = GetFanSpeed();
    printf("The Fan speed : %d", fanSpeed);

    // Shutdown and exit the server.
    Shutdown();

    }
    RpcExcept(1)
    {
        ulCode = RpcExceptionCode();
        printf("Runtime reported exception 0x%lx = %ld\n", ulCode, ulCode);
    }
    RpcEndExcept


    // free string regardless of errors from RpcBindingFromStringBinding.
    status = RpcStringFreeA(&pszStringBinding);

    if (status)
    {
        printf("RpcStringFree Error = %ld\n", status);
        exit(status);
    }

    status = RpcBindingFree(&MyApp_UsedHandle);

    if (status)
        exit(status);

    exit(0);


}



