// Unit-test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "RMUTranslator.h"
#include "RMUCaller.h"
#include "STRTError.h"

#include "convert.h"

#include <iostream>
#include <algorithm>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <string>
#include <fstream>

using namespace std;

static void print_answer(const RMUResult& answer)
{
	cout << TranslateToConsole(answer.GetTranslatedAnswer()) << endl;
}

void myPrint(const RMUResult& answer)
{
	wcerr << L"SynTagRus [" << RMUTranslator::instance().toSynTagRusFeature(answer).ToWString() << L']' << endl;
	print_answer(answer);
}



int _tmain(int argc, _TCHAR* argv[])
{
	_setmode(_fileno(stderr), _O_U16TEXT);

	//std::ofstream out("out.txt");
	//wcout.rdbuf(stderr.rdbuf());

	try {
		char word[1024];
		for(;;) {
			try {
				cout << TranslateToConsole(string("Введите словоформу или quit>")) << endl;
				cin.getline(word, sizeof word);
				if (strcmp(word,"quit") == 0) break;
				string result;
				if (word[0] != '<')
				{
					vector<RMUResult> ans_vector;
					RMUDLL::instance().Analyse(TranslateFromConsole(word), result, ans_vector);
					if (ans_vector.size() == 0)
						cout << TranslateToConsole(string("Словоформа отсутствует в словаре")) << endl;
					else
						cout << TranslateToConsole(string("Варианты анализа:")) << endl;

					for_each(ans_vector.begin(), ans_vector.end(), myPrint);
					//for_each(ans_vector.begin(), ans_vector.end(), RMUTranslator::instance().toSynTagRusFeature);
				}
				cout << TranslateToConsole(result) << endl;
			} catch(const char * msg){
				cout << TranslateToConsole(string("Ошибка обработки: ") + string(msg)) << endl;
			}
		}
	} catch (const char * msg) {
		cout << TranslateToConsole(string("Ошибка инициализации: ") + string(msg)) << endl;
		std::cin.ignore();
		return 1;
	}
	catch (const std::exception &exc)
	{
		cout << "Damn, exception, again.." << endl;
		// catch anything thrown within try block that derives from std::exception
		std::cout << exc.what();
		std::cin.ignore();
		return 2;
	}
	catch(...){
		cout << "Damn, exception, again.." << endl;
		std::cin.ignore();
		return 3;
	}


	//vector<RMUResult> ans_vector;
	//string result;
	//RMUDLL::instance().Analyse(TranslateFromConsole(string("анализ")),result, ans_vector);	
	//
	//if (ans_vector.size() == 0)
	//	cout << TranslateToConsole(string("Словоформа отсутствует в словаре")) << endl;
	//else{
	//	cout << TranslateToConsole(string("Варианты анализа:")) << endl;

	//	for_each(ans_vector.begin(), ans_vector.end(), RMUTranslator::instance().toSynTagRusFeature);

	//	//RMUTranslator::instance().toSyntagRusFeatures(ans_vector[0]);
	//}

	return 0;
}

