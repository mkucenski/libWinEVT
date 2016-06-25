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

#ifndef _EVENTFILE_H_
#define _EVENTFILE_H_

#include "misc/windowsTypes.h"

#define EVENTLOGFILE_HEADER_ID 0x654c664c	//"LfLe"

typedef struct _EVENTFILEHEADER {
	DWORD	dwLength;			//Fixed at 0x30
	DWORD	dwHeaderID;
	DWORD	dwUnknown1;
	DWORD	dwUnknown2;
	DWORD	dwFirstEventOffset;
	DWORD	dwNextEventOffset;
	DWORD	dwNextEventNumber;	//??? Are these two backwards?
	DWORD	dwFirstEventNumber; //???
	DWORD	dwFileSize;
	DWORD	dwFlags;
	DWORD	dwRetentionPeriod;	//In Seconds
	DWORD	dwLength2;			//Fixed at 0x30
} __attribute__((packed)) EVENTFILEHEADER;
#define EVENTFILEHEADER_LENGTH 48

#define EVENTLOG_DIRTY					0x0001
#define EVENTLOG_WRAPPED				0x0002
#define EVENTLOG_FULL					0x0004
#define EVENTLOG_PRIMARY				0x0008

#define EVENTLOGFILE_CURSOR_ID0	0x11111111
#define EVENTLOGFILE_CURSOR_ID1	0x22222222
#define EVENTLOGFILE_CURSOR_ID2	0x33333333
#define EVENTLOGFILE_CURSOR_ID3	0x44444444

typedef struct _EVENTFILECURSOR {
	DWORD	dwLength;			//Fixed at 0x28
	DWORD	dwHeaderID[4];		//0x11111111 0x22222222 0x33333333 0x44444444
	DWORD	dwFirstEventOffset;
	DWORD	dwNextEventOffset;
	DWORD	dwNextEventNumber;	//??? Are these two backwards?
	DWORD	dwFirstEventNumber; //???
	DWORD	dwLength2;			//Fixed at 0x28
} __attribute__((packed)) EVENTFILECURSOR;
#define EVENTFILECURSOR_LENGTH 28

#endif //_EVENTFILE_H_
