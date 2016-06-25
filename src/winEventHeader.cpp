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

#include "winEventHeader.h"

#include "misc/debugMsgs.h"

winEventHeader::winEventHeader(char* pData)	{
	memset(&m_eventFileHeader, 0, EVENTFILEHEADER_LENGTH);	
	memcpy(&m_eventFileHeader, pData, EVENTFILEHEADER_LENGTH);
	
	//TODO Endian fixes of the member structure
}

winEventHeader::~winEventHeader() {
}

bool winEventHeader::validate() {
	bool rv = false;
	
	if (m_eventFileHeader.dwHeaderID == EVENTLOGFILE_HEADER_ID) {
		rv = true;
	}
	
	return rv;
}
