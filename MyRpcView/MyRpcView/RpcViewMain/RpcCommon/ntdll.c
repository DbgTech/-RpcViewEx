#include "ntdll.h"

NtQueryInformationProcessFn_T	NtQueryInformationProcessFn	= NULL;


//-----------------------------------------------------------------------------
NTSTATUS NTAPI NtQueryInformationProcess(
	IN	HANDLE				ProcessHandle,
	IN	PROCESSINFOCLASS	ProcessInformationClass,
	OUT	PVOID				ProcessInformation,
	IN	ULONG				ProcessInformationLength,
	OUT	PULONG				ReturnLength OPTIONAL
	)
{
	if (NtQueryInformationProcessFn == NULL)
	{
		HMODULE handle=LoadLibrary(L"ntdll.dll");
		NtQueryInformationProcessFn = (NtQueryInformationProcessFn_T)GetProcAddress(handle, "NtQueryInformationProcess");

	}
	return NtQueryInformationProcessFn(
		ProcessHandle,
		ProcessInformationClass,
		ProcessInformation,
		ProcessInformationLength,
		ReturnLength);
}