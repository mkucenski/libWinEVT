// Copyright 2003 Matthew A. Kucenski
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

#include "winEventCursor.h"
#include "misc/debugMsgs.h"

winEventCursor::winEventCursor(char* pData)	{
	memset(&m_eventFileCursor, 0, EVENTFILECURSOR_LENGTH);	
	memcpy(&m_eventFileCursor, pData, EVENTFILECURSOR_LENGTH);
	
	//TODO Endian fixes of the member structure
}

winEventCursor::~winEventCursor() {
}

bool winEventCursor::validate() {
	bool rv = false;
	
	if (m_eventFileCursor.dwHeaderID[0] == EVENTLOGFILE_CURSOR_ID0 &&
		m_eventFileCursor.dwHeaderID[1] == EVENTLOGFILE_CURSOR_ID1 &&
		m_eventFileCursor.dwHeaderID[2] == EVENTLOGFILE_CURSOR_ID2 &&
		m_eventFileCursor.dwHeaderID[3] == EVENTLOGFILE_CURSOR_ID3) {
		rv = true;
	}
	
	return rv;
}
