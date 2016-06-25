// Copyright 2007 Matthew A. Kucenski
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _EVENTRECORD_H_
#define _EVENTRECORD_H_

#include "misc/windowsTypes.h"

#define EVENTLOGRECORD_HEADER_ID 0x654c664c	//"LfLe"

typedef struct _EVENTLOGRECORD {
	DWORD	dwLength;
	DWORD	dwHeaderID;
	DWORD	dwRecordNumber;
	DWORD	dwTimeGenerated;
	DWORD	dwTimeWritten;
	DWORD	dwEventID;
	WORD	wEventType;
	WORD	wNumStrings;
	WORD	wEventCategory;
	WORD	wReservedFlags;
	DWORD	dwClosingRecordNumber;
	DWORD	dwStringOffset;
	DWORD	dwUserSidLength;
	DWORD	dwUserSidOffset;
	DWORD	dwDataLength;
	DWORD	dwDataOffset;
    //WCHAR	SourceName[]
    //WCHAR	Computername[]
    //SID	UserSid
    //WCHAR	Strings[]
    //BYTE	Data[]
    //CHAR	Pad[]
    //DWORD	Length;
} __attribute__((packed)) EVENTLOGRECORD;
#define EVENTLOGRECORD_LENGTH 56

#define SID_MAX_SUB_AUTHORITIES 15

typedef struct _SID_IDENTIFIER_AUTHORITY {
    BYTE  bValue[6];
} __attribute__((packed)) SID_IDENTIFIER_AUTHORITY;
#define SID_IDENTIFIER_AUTHORITY_LENGTH 6

typedef struct _SID {
   BYTE  bRevision;
   BYTE  bSubAuthorityCount;
   SID_IDENTIFIER_AUTHORITY identifierAuthority;
   DWORD dwSubAuthority[SID_MAX_SUB_AUTHORITIES];
} __attribute__((packed)) SID;
#define SID_LENGTH 68

#define EVENTID_CODE_MASK				0x0000ffff
#define EVENTID_FACILITY_MASK			0x0fff0000
#define EVENTID_CUSTOMER_MASK			0x20000000
#define EVENTID_SEVERITY_MASK			0xC0000000

#define ERROR_SEVERITY_SUCCESS			0x00000000
#define ERROR_SEVERITY_INFORMATION		0x40000000
#define ERROR_SEVERITY_WARNING			0x80000000
#define ERROR_SEVERITY_ERROR			0xC0000000

#define EVENTLOG_SUCCESS				0x0000
#define EVENTLOG_ERROR					0x0001
#define EVENTLOG_WARNING				0x0002
#define EVENTLOG_INFORMATION			0x0004
#define EVENTLOG_AUDIT_SUCCESS			0x0008
#define EVENTLOG_AUDIT_FAILURE			0x0010

#define EVENTLOG_SYSTEM					0x00000000
#define EVENTLOG_CUSTOMER				0x20000000

#endif //_EVENTRECORD_H_
