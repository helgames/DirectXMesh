//
//  Compat.h
//  UVAtlas
//
//  Created by Paul Schulze on 25.02.2018.
//  Copyright © 2018 Hel Games. All rights reserved.
//

#pragma once

#include "math.h"
#include "stdint.h"
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

// SAL declaration
#include "sal.h"

// Return values
#define HRESULT int32_t
#define S_OK 0
#define S_FALSE 0
#define E_FAIL 1
#define E_POINTER 2
#define E_OUTOFMEMORY 3
#define E_INVALIDARG 4
#define E_UNEXPECTED 5
#define E_ABORT 6
#define E_BOUNDS 7
#define HRESULT_FROM_WIN32(x) x
#define ERROR_INVALID_DATA 4
#define ERROR_NOT_SUPPORTED 4
#define ERROR_ARITHMETIC_OVERFLOW 3
#define ERROR_INVALID_NAME 4
#define FAILED(cond) ((cond) != S_OK)
#define SUCCEEDED(cond) ((cond) == S_OK)

// Win API declaration
#define __cdecl
#define __declspec(x)
#define WINAPI
#define STDMETHOD(name) virtual HRESULT name
#define STDMETHODIMP HRESULT
#define PURE = 0
#define PVOID void*
#define UNREFERENCED_PARAMETER(x)
float __min(float lhs, float rhs) { return fmin(lhs, rhs); }
#define _Analysis_assume_(x)
#define _finite(x) x
#define swprintf_s(buf, fmt, ...) swprintf(buf, 1024, fmt, __VA_ARGS__)
#define _stricmp strcasecmp
// DirectX
#define DWORD int
#include <dxgiformat.h>

#define _XM_NO_INTRINSICS_
#include <DirectXMath.h>

namespace DirectX
{
	XMVECTOR operator +(XMVECTOR lhs, XMVECTOR rhs)
	{
		return XMVectorAdd(lhs, rhs);
	}
	
	XMVECTOR operator -(XMVECTOR lhs, XMVECTOR rhs)
	{
		return XMVectorSubtract(lhs, rhs);
	}
	
	XMVECTOR operator *(XMVECTOR lhs, float rhs)
	{
		return XMVectorScale(lhs, rhs);
	}
	
	XMVECTOR operator /(XMVECTOR lhs, float rhs)
	{
		return XMVectorScale(lhs, 1.0f/rhs);
	}
	
	XMVECTOR& operator +=(XMVECTOR& lhs, XMVECTOR rhs)
	{
		lhs = XMVectorAdd(lhs, rhs);
		return lhs;
	}
	
	XMVECTOR& operator -=(XMVECTOR& lhs, XMVECTOR rhs)
	{
		lhs = XMVectorSubtract(lhs, rhs);
		return lhs;
	}
	
	XMVECTOR& operator *=(XMVECTOR& lhs, float rhs)
	{
		lhs = XMVectorScale(lhs, rhs);
		return lhs;
	}
	
	XMVECTOR& operator /=(XMVECTOR& lhs, float rhs)
	{
		lhs = XMVectorScale(lhs, 1.0f / rhs);
		return lhs;
	}
}

// Mutex compat
struct MutexHandle
{
    // TODO: Stub, should contain the actual handle
};

#define CREATE_MUTEX_INITIAL_OWNER 1
#define SYNCHRONIZE 2
#define WAIT_OBJECT_0 0
#define BOOL int32_t
#define FALSE 0
#define TRUE 1
#define INVALID_HANDLE_VALUE nullptr
#define _aligned_malloc(size, align) malloc(size)
#define _aligned_free(x) free(x)
typedef MutexHandle* HANDLE;

HANDLE CreateMutexEx(int* dontCare1, int* dontCare2, int someParam1, int someParam2)
{
    // TODO: Stub
    return nullptr;
}

void CloseHandle(HANDLE handle)
{
    // TODO: Stub
}

HRESULT WaitForSingleObjectEx(HANDLE handle, int someParam1, bool someParam2)
{
    // TODO: Stub
    return WAIT_OBJECT_0;
}

HRESULT ReleaseMutex(HANDLE handle)
{
    // TODO: Stub
    return S_OK;
}

void SwitchToThread()
{
    // TODO: Stub
}

HRESULT GetLastError()
{
    // TODO: Stub
    return S_OK;
}
