#pragma once

/////////////////////////////////////////////////////
//
//	helper functions for converting russian language to/from win1251tdos866/UTF8(console)
//
/////////////////////////////////////////////////////

string TranslateToConsole(const string& message);
string TranslateFromConsole(const string& message);