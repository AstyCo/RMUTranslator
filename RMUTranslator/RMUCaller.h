#pragma once

#include "RMUDLL.h"
#include "RMUResult.h"
#include "RMUError.hpp"
using namespace std;

class RMUDLL
{
	RMUHandle _hRmu;
public:
	static RMUDLL &instance();
	static string Analyse(const string& word);
	static void Analyse(const string& word, string& xml_answer, vector<RMUResult>& resultVec);
private:
	RMUDLL();
	~RMUDLL();

	RMUDLL(const RMUDLL&) {}
	RMUDLL& operator=(const RMUDLL&) {}
};