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

#ifndef _WINEVENT_H_
#define _WINEVENT_H_

#include "eventRecord.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef enum { WIN_EVENT_ERROR, WIN_EVENT_SUCCESS } WIN_EVENT_RV;

class winEventFile;

class winEvent {
	public:
		winEvent(winEventFile* pEventFile, char* pData, long lOffset, DWORD dwLength);
		~winEvent();
		
		long getRecordOffset() { return m_lOffset; };
		unsigned long getRecordLength() { return m_eventLogRecord.dwLength; };
		unsigned long getRecordNumber() { return m_eventLogRecord.dwRecordNumber; };
		unsigned long getTimeGenerated() { return m_eventLogRecord.dwTimeGenerated; };
		unsigned long getTimeWritten() { return m_eventLogRecord.dwTimeWritten; };
		unsigned long getEventSeverity() { return m_eventLogRecord.dwEventID & EVENTID_SEVERITY_MASK; };
		unsigned long getEventCustomer() { return m_eventLogRecord.dwEventID & EVENTID_CUSTOMER_MASK; };
		unsigned long getEventFacility() { return m_eventLogRecord.dwEventID & EVENTID_FACILITY_MASK; };
		unsigned long getEventCode() { return m_eventLogRecord.dwEventID & EVENTID_CODE_MASK; };
		unsigned short getEventType() { return m_eventLogRecord.wEventType; };
		unsigned short getEventCategory() { return m_eventLogRecord.wEventCategory; };

		string getSourceName();
		string getComputerName();
		WIN_EVENT_RV getStrings(vector<string>* pvStrings);

		WIN_EVENT_RV getSID(SID* pSID);
		string getSIDString();

		unsigned long getStringsOffset() { return m_eventLogRecord.dwStringOffset; };
		unsigned short getNumStrings() { return m_eventLogRecord.wNumStrings; };

		WIN_EVENT_RV getData(char** ppData);
		unsigned long getDataOffset() { return m_eventLogRecord.dwDataOffset; };
		unsigned long getDataLength() { return m_eventLogRecord.dwDataLength; };
	
	private:
		winEventFile* m_pEventFile;
		long m_lOffset;
		EVENTLOGRECORD m_eventLogRecord;

		string m_strSource;
		string m_strComputer;
};

#endif //_WINEVENT_H_
