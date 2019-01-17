#ifndef _RPC_INTERNALS_H_
#define _RPC_INTERNALS_H_

#include <windows.h>
#include <Rpc.h>



#define RPC_CORE_DESCRIPTION					"Windows 7 SP1 64bits runtime core"
#define RPC_CORE_IS_WOW64						FALSE

#define ULONG_PTR_T ULONG_PTR
#define PTR_T *

#include "../RpcInternalsCommon.h"

#define RPC_ADDRESS_TYPE_DG		0x400000
#define RPC_ADDRESS_TYPE_LRPC	0x800000
#define RPC_ADDRESS_TYPE_OSF	0x800

#pragma pack(1)

typedef struct _RPC_SERVER_T {
	MUTEX_T						Mutex;
	ULONG						__bIslistening;
	BOOL						bIsListening;
	ULONG						MinimumCallThreads;
	BOOL						Wait;
	ULONG						OutCalls;
	ULONG						Unk1;
	ULONG						InCalls;
	ULONG						Unk2;
	SIMPLE_DICT_T				AddressDict;
	ULONG						lAvailableCalls;
	ULONG						Unk3;
	SIMPLE_DICT_T				_ProtSeqQueue;
	ULONG						Unk4[8];
	ULONG						OutPackets;
	ULONG						Unk5;
	MUTEX_T						Mutex2;
	ULONG						MaxCalls;
	ULONG						Unk6;
	VOID PTR_T					hEvent;
	ULONG						Unk7[4];
	SIMPLE_DICT_T				InterfaceDict;
	BOOL						_bIsListening;
	BOOL						bIsMaxCalls1234;
	ULONG						Unk8[6];
	ULONG						InPackets;
	ULONG						Unk9;
	RPC_FORWARD_FUNCTION PTR_T	pRpcForwardFunction;
	ULONG						Unk10[6];
	SIMPLE_DICT_T				AuthenInfoDict;
}RPC_SERVER_T, PTR_T PRPC_SERVER_T;


typedef struct _RPC_INTERFACE_T {
	PRPC_SERVER_T				pRpcServer;
	ULONG						Flags;
	ULONG						EpMapperFlags;
	RPC_MGR_EPV PTR_T			pMgrEpv;
	RPC_IF_CALLBACK_FN PTR_T	IfCallbackFn;
	RPC_SERVER_INTERFACE_T	RpcServerInterface;
	PMIDL_SYNTAX_INFO			pSyntaxInfo;
	VOID PTR_T				pTransfertSyntaxes;
	ULONG						TransfertSyntaxesCount;
	ULONG						__Field_C4;
	ULONG						NbTypeManager;
	ULONG						MaxRpcSize;
	UUID_VECTOR  PTR_T		pUuidVector;
	SIMPLE_DICT_T				RpcInterfaceManagerDict;
	UCHAR						Annotation[MAX_RPC_INTERFACE_ANNOTATION];
	ULONG						IsCallSizeLimitReached;
	ULONG						currentNullManagerCalls;
	ULONG						__Field_150;
	ULONG						__Field_154;
	ULONG						bRundownsBlocked;
	ULONG						SecurityCallbackInProgress;
	ULONG						SecurityCacheEntry;
	ULONG						field_164;
	VOID PTR_T				__SecurityCacheEntries;
	SIMPLE_DICT_T				FwEpDict;
	ULONG						__Field_218;
	ULONG						Unk1;
}RPC_INTERFACE_T, PTR_T PRPC_INTERFACE_T;


typedef struct _RPC_ADDRESS_T {
	VOID PTR_T				pVtable;
	ULONG					Magic;
	ULONG					TypeOfAddress;
	ULONG					ReferenceCounter;
	ULONG					Unk1[3];
	WCHAR PTR_T				Name;
	WCHAR PTR_T				Protocole;
	WCHAR PTR_T				Address;
	ULONG					bNamed;
	ULONG					EpAddAddressFlag;
	SIMPLE_DICT_T			__LRPCSassociationSimpleDict;
	ULONG					__Field_68;
	ULONG					Unk2;
	ULONG					EpAddOnFlag;
	ULONG					NbActiveCalls;
	ULONG					Unk3[6];
	MUTEX_T	Mutex;
}RPC_ADDRESS_T;

#pragma pack()

#endif // _RPC_INTERNALS_H_
