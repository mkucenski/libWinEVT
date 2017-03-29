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

#include "winEventFile.h"

#include "eventRecord.h"
#include "misc/debugMsgs.h"
#include "misc/endianSwitch.h"

winEventFile::winEventFile(string strFilename)	:	binDataFile(strFilename),
													m_lNextRecordPos(0) {
	DEBUG_INFO("winEventFile::winEventFile()");
}

winEventFile::~winEventFile() {
	DEBUG_INFO("winEventFile::~winEventFile()");
}

WIN_EVENT_RV winEventFile::getHeader(winEventHeader** ppHeader) {
	WIN_EVENT_RV rv = WIN_EVENT_ERROR;

	
	return rv;
}

WIN_EVENT_RV winEventFile::getCursor(winEventCursor** ppCursor) {
	WIN_EVENT_RV rv = WIN_EVENT_ERROR;
		
	
	return rv;
}
		
WIN_EVENT_RV winEventFile::getNextRecord(winEvent** ppEvent) {
	WIN_EVENT_RV rv = WIN_EVENT_ERROR;
		
	if (ppEvent && *ppEvent == NULL) {
		DWORD dwLength = 0;
		DWORD dwHeaderID = 0;
		if (getData(&dwLength, sizeof(DWORD), m_lNextRecordPos, NULL) >= 0 && 
			 getData(&dwHeaderID, sizeof(DWORD), NULL) >= 0) {
			LITTLETOHOST32(dwLength);
			LITTLETOHOST32(dwHeaderID);
			
			bool bFound = false;
			
			if (dwHeaderID == EVENTLOGRECORD_HEADER_ID) {
				bFound = true;
			} else {
				DEBUG_INFO("winEventFile::getNextRecord() Next record was not found in the expected location.  Searching...");
				while (!bFound) {
					if (getData(&dwHeaderID, sizeof(DWORD), NULL) >= 0) {
						LITTLETOHOST32(dwHeaderID);
						
						if (dwHeaderID == EVENTLOGRECORD_HEADER_ID) {
							DEBUG_INFO("winEventFile::getNextRecord() Next record found at offset: " << offset() - 8 << " (diff = " << ((offset() - 8) - m_lNextRecordPos) << ")");
							bFound = true;
							m_lNextRecordPos = currPos() - 8;
						} else {
							dwLength = dwHeaderID;
						}
					} else {
						DEBUG_ERROR("winEventFile::getNextRecord() Failure reading data while trying to find record header.");
						break;
					}
				}
			}
			
			if (bFound) {
 				char* buffer = (char*)calloc(EVENTLOGRECORD_LENGTH, 1);
				if (buffer) {
					if (getData(buffer, EVENTLOGRECORD_LENGTH, m_lNextRecordPos, NULL) >= 0) {
						*ppEvent = new winEvent(this, buffer, m_lNextRecordPos, dwLength);
						m_lNextRecordPos += dwLength;
						rv = WIN_EVENT_SUCCESS;
					} else {
						DEBUG_ERROR("winEventFile::getNextRecord() Failure reading next record.");
					}
					free(buffer);
					buffer = NULL;
				} else {
					DEBUG_ERROR("winEventFile::getNextRecord() Unable to allocate buffer for record storage.");
				}
			} else {
				DEBUG_ERROR("winEventFile::getNextRecord() Unable to find next record.");
			}
		} else {
			DEBUG_ERROR("winEventFile::getNextRecord() Failed reading length/header.");
		}
	} else {
		DEBUG_ERROR("winEventFile::getNextRecord() Invalid destination pointer.");
	}
	
	return rv;
}
