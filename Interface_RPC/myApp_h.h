

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for myApp.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __myApp_h_h__
#define __myApp_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __MyApp_INTERFACE_DEFINED__
#define __MyApp_INTERFACE_DEFINED__

/* interface MyApp */
/* [implicit_handle][version][uuid] */ 

void HelloProc( 
    /* [string][in] */ const unsigned char *pszString);

void Shutdown( void);

int GetAddRes( 
    /* [in] */ int num1,
    /* [in] */ int num2);

int GetCondition( 
    /* [string][in] */ const unsigned char *pState,
    /* [out] */ wchar_t pRet[ 20 ]);

void GetMyAppVersion( 
    /* [out] */ wchar_t versionNum[ 10 ]);

void GetArrCharStr( 
    /* [out] */ unsigned char arrChar[ 100 ]);

void GetPointerCharStr( 
    /* [out] */ unsigned char *pChar);

int GetFanSpeed( void);


extern handle_t MyApp_UsedHandle;


extern RPC_IF_HANDLE MyApp_v1_0_c_ifspec;
extern RPC_IF_HANDLE MyApp_v1_0_s_ifspec;
#endif /* __MyApp_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


