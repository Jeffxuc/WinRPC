/*************************
======== Server ==========
**************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>

#include "..\\Interface_RPC\\myApp_h.h"
#include "..\\Interface_RPC\\myApp_s.c"

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

    const char* pszProtocolSequence = "ncalrpc";    //RPC协议需要与Client相同
    const char* pszSecurity = NULL;
    const char* pszEndpoint = "MyAppTestEndpoint";  //沟通端口，需要与Client相同
    unsigned int    minCalls = 1;
    unsigned int    dontWait = FALSE;

    //1. 告诉server端，沟通时所使用的协议序列,注意参数类型不能出错！！！
    status = RpcServerUseProtseqEpA(
        (unsigned char*)pszProtocolSequence,
        RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
        (unsigned char*)pszEndpoint,
        (void*)pszSecurity);

    if (status)
        exit(status);

    //2. Register the interface.
    status = RpcServerRegisterIf(
        MyApp_v1_0_s_ifspec,     // The MIDL compiler generates from the IDL file that defines the interface for server.
        NULL,                    // aUUID
        NULL);                   // entry-point vector

    if (status)
        exit(status);

    //3. Server端对客户端进行监听，以响应Client对Server的调用
    status = RpcServerListen(
        minCalls,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        dontWait);


    if (status)
        exit(status);

}

