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

#ifndef _WINEVENTHEADER_H_
#define _WINEVENTHEADER_H_

#include "eventFile.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class winEventHeader {
	public:
		winEventHeader(char* pData);
		~winEventHeader();
		
		bool validate();
		
		u_int32_t getFirstEventOffset() { return m_eventFileHeader.dwFirstEventOffset; };
		u_int32_t getNextEventOffset() { return m_eventFileHeader.dwNextEventOffset; };
		u_int32_t getNextEventNumber() { return m_eventFileHeader.dwNextEventNumber; };
		u_int32_t getFirstEventNumber() { return m_eventFileHeader.dwFirstEventNumber; };
		u_int32_t getFileSize() { return m_eventFileHeader.dwFileSize; };
		u_int32_t getRetentionPeriod() { return m_eventFileHeader.dwRetentionPeriod; };
		
		bool getFileDirty() { return (m_eventFileHeader.dwFlags & EVENTLOG_DIRTY); };
		bool getFileWrapped() { return (m_eventFileHeader.dwFlags & EVENTLOG_WRAPPED); };
		bool getFileFull() { return (m_eventFileHeader.dwFlags & EVENTLOG_FULL); };
		bool getFilePrimary() { return (m_eventFileHeader.dwFlags & EVENTLOG_PRIMARY); };
	
	private:
		EVENTFILEHEADER m_eventFileHeader;
};

#endif //_WINEVENTHEADER_H_
