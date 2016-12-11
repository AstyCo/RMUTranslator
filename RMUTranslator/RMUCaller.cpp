#include "stdafx.h"
#include "RMUCaller.h"

#include <sstream>

RMUDLL & RMUDLL::instance()
{
	static RMUDLL instance;
	return instance;
}

string RMUDLL::Analyse(const string & word)
{
	RMUAnswer hAns;
	if (RMUGetAnswer(instance()._hRmu, word.c_str(), &hAns) != RMU_OK)
		RAISE_RMU_ERR("RMU.DLL analysis error");
	char Answer[1 << 14];
	if (RMUGetXML(hAns, Answer, sizeof(Answer), true) != RMU_OK) {
		RMUFreeAnswer(hAns);
		RAISE_RMU_ERR("RMU.DLL error getting xml");
	}
	RMUFreeAnswer(hAns);
	return string(Answer);
}

void RMUDLL::Analyse(const string & word, string & xml_answer, vector<RMUResult>& resultVec)
{
	RMUAnswer hAns;
	if (RMUGetAnswer(instance()._hRmu, word.c_str(), &hAns) != RMU_OK)
		RAISE_RMU_ERR("RMU.DLL analysis error");
	char Answer[1 << 14];
	if (RMUGetXML(hAns, Answer, sizeof Answer, true) != RMU_OK) {
		RMUFreeAnswer(hAns);
		RAISE_RMU_ERR("RMU.DLL error getting xml");
	}
	RMUFreeAnswer(hAns);
	string xml(Answer);
	xml_answer.swap(xml);
	RMUResultGet(xml_answer, resultVec);
}

RMUDLL::RMUDLL()
{
	int ret;
	if ((ret=RMUInit(&_hRmu)) != RMU_OK)
	{
		std::ostringstream sstream;
		sstream << "Error initialising RMU.DLL " << ret;
		std::string query = sstream.str();

		RAISE_RMU_ERR(query);
	}
}

RMUDLL::~RMUDLL()
{
	RMUFree(_hRmu);
}
