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

#ifndef _WINEVENTCURSOR_H_
#define _WINEVENTCURSOR_H_

#include "eventFile.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class winEventCursor {
	public:
		winEventCursor(char* pData);
		~winEventCursor();
		
		bool validate();
		
		u_int32_t getFirstEventOffset() { return m_eventFileCursor.dwFirstEventOffset; };
		u_int32_t getNextEventOffset() { return m_eventFileCursor.dwNextEventOffset; };
		u_int32_t getNextEventNumber() { return m_eventFileCursor.dwNextEventNumber; };
		u_int32_t getFirstEventNumber() { return m_eventFileCursor.dwFirstEventNumber; };
	
	private:
		EVENTFILECURSOR m_eventFileCursor;
};

#endif //_WINEVENTCURSOR_H_
