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

#ifndef _WINEVENTFILE_H_
#define _WINEVENTFILE_H_

#include "winEvent.h"
#include "winEventHeader.h"
#include "winEventCursor.h"
#include "libbinData/src/binDataFile.h"
#include <string>
using namespace std;

class winEventFile : public binDataFile {
	friend class winEvent;
	friend class winEventHeader;
	friend class winEventCursor;
	
	public:
		winEventFile(string strFilename);
		~winEventFile();
		
		WIN_EVENT_RV getHeader(winEventHeader** ppHeader);
		WIN_EVENT_RV getCursor(winEventCursor** ppCursor);		
		WIN_EVENT_RV getNextRecord(winEvent** ppEvent);
	
	private:
		long m_lNextRecordPos;
};

#endif //_WINEVENTFILE_H_
