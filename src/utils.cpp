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

/*
#include "utils.h"

#include <string>
#include <ctime>
#include <sstream>

string getDateString(unsigned long ulTime) {
	struct tm* time = gmtime((time_t*)&ulTime);

	char buffer[26];
	snprintf(buffer, 25, "%02d/%02d/%d", time->tm_mon + 1, time->tm_mday, time->tm_year + 1900);
	string strDate(buffer);
	return strDate;

	//ostringstream ostr;
	//ostr << time->tm_mon + 1 << "/" << time->tm_mday << "/" << time->tm_year + 1900;
	//return string(ostr.str());
}

//TODO Broken string getTimeString(unsigned long ulTime, int iTimeOffset, int iTimeDST) {
//string getTimeString(unsigned long ulTime) {
string getTimeString(unsigned long ulTime) {
	struct tm* time = gmtime((time_t*)&ulTime);

	char buffer[26];
	//TODO Broken swprintf(buffer, 25, L"%02d:%02d:%02d", time->tm_hour + iTimeOffset + iTimeDST, time->tm_min, time->tm_sec);
	snprintf(buffer, 25, "%02d:%02d:%02d", time->tm_hour, time->tm_min, time->tm_sec);
	string strTime(buffer);	
	return strTime;

	//wostringstream wostr;
	//wostr << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec;
	//return string(wostr.str());
}
*/
