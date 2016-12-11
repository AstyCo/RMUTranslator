#pragma once

#include "STRTError.h"

#include <string>

enum MorphSPos {
	MSNoun = 1,							///< • Существительное 
	MSAdjective,						///< • Прилагательное 
	MSVerb,								///< • Глагол
	MSAdverb,							///< • Наречие
	MSNumber,							///< • Числительное
	MSPreposition,						///< • Предлог 
	MSComposite,						///< • Композит
	MSConjunction,						///< • Союз
	MSParticle,							///< • Частица
	MSProposalWord,						///< • Слово-предложение
	MSInterjection,						///< • Междометие
	MSNID,								///< • Слово, представляющее собой иноязычное вкрапление в русский текст или несловесную формулу
	
	MSIndefinitePos,					///< • Морфологическая характеристика "Часть речи" имеет неопределенное значение
	MorphSPosCount = MSIndefinitePos	///< • Количество мофрологических категорий "Часть речи"
};

enum MorphSAnimacy {
	MSAnimate = 1,								///< • Одушевленное
	MSInanimate,								///< • Неодушевленное
	MSAnyAnimacy,								///< • Обобщенная одушевленность

	MSIndefiniteAnimacy,						///< • Морфологическая характеристика "Одушевленность" имеет неопределенное значение
	MorphSAnimacyCount = MSIndefiniteAnimacy	///< • Количество мофрологических категорий "Одушевленность"
};

enum MorphSGender {
	MSMale = 1,								///< • Мужской род
	MSFemale,								///< • Женский род
	MSNeuter,								///< • Средний род
	MSAnyGender,							///< • Обобщенный род

	MSIndefiniteGender,						///< • Морфологическая характеристика "Род" имеет неопределенное значение
	MorphSGenderCount = MSIndefiniteGender	///< • Количество мофрологических категорий "Род"
};

enum MorphSNumber {
	MSSingle = 1,							///< • Единственное
	MSPlural,								///< • Множественное

	MSIndefiniteNumber,						///< • Морфологическая характеристика "Число" имеет неопределенное значение
	MorphSNumberCount = MSIndefiniteNumber	///< • Количество мофрологических категорий "Число"
};

enum MorphSCase {
	MSNominative = 1,					///< • Именительный падеж
	MSGenitive,							///< • Родительный падеж
	MSPartitive,						///< • Партитивный (нет чаю)
	MSDative,							///< • Дательный падеж
	MSAccusative,						///< • Винительный падеж
	MSInstrumental,						///< • Творительный падеж
	MSPrepositional,					///< • Предложный падеж
	MSLocative,							///< • Местный (в лесу)

	MSIndefiniteCase,					///< • Морфологическая характеристика "Падеж" имеет неопределенное значение
	MorphSCaseCount = MSIndefiniteCase	///< • Количество мофрологических категорий "Падеж"
};

enum MorphSDegree {
	MSComparative = 1,						///< • Сравнительная степень сравнения
	MSSuperlative,							///< • Превосходная степень сравнения
	MSPositive,								///< • Положительная степень сравнения

	MSIndefiniteDegree,						///< • Морфологическая характеристика "Степень сравнения" имеет неопределенное значение
	MorphSDegreeCount = MSIndefiniteDegree	///< • Количество мофрологических категорий "Степень сравнения"
};

enum MorphSShort {
	MSShort = 1,							///< • Краткое
	MSShortNot,								///< • Не краткое

	MSIndefiniteShort,						///< • Морфологическая характеристика "Краткость" имеет неопределенное значение
	MorphSShortCount = MSIndefiniteShort	///< • Количество мофрологических категорий "Краткость"
};

enum MorphSRepresentation {
	MSInfinitive = 1,										///< • Инфинитив
	MSParticiple,											///< • Причастие
	MSParticipleDee,										///< • Деепричастие
	MSPersonal,												///< • Личная форма глагола 

	MSIndefiniteRepresentation,								///< • Морфологическая характеристика "Репрезентация" имеет неопределенное значение
	MorphSRepresentationCount = MSIndefiniteRepresentation	///< • Количество мофрологических категорий "Репрезентация"
};

enum MorphSMood {
	MSImperative = 1,						///< • Повелительное наклонение
	MSIndicative,							///< • Изъявительное наклонение
	//MSSubjunctive,						///< • Сослагательное наклонение в русском языке выражается только аналитически и не может приписываться никакой словоформе. Оно оформляется с помощью аналитического синтаксического отношения

	MSIndefiniteMood,						///< • Морфологическая характеристика "Наклонение" имеет неопределенное значение
	MorphSMoodCount = MSIndefiniteMood		///< • Количество мофрологических категорий "Наклонение"
};

enum MorphSAspect {
	MSPerfect = 1,							///< • Несовершенный вид
	MSImperfect,							///< • Совершенный вид

	MSIndefiniteAspect,						///< • Морфологическая характеристика "Вид" имеет неопределенное значение
	MorphSAspectCount = MSIndefiniteAspect	///< • Количество мофрологических категорий "Вид"
};

enum MorphSTense {
	MSPastNot = 1,							///< • Непрошедшее (настоящее-будущее)  время
	MSPast,									///< • Прошедшее время
	MSPresent,								///< • Настоящее время (прим. Настоящее время приписывается только глаголу быть в личной форме)

	MSIndefiniteTense,						///< • Морфологическая характеристика "Время" имеет неопределенное значение
	MorphSTenseCount = MSIndefiniteTense	///< • Количество мофрологических категорий "Время"
};

enum MorphSPerson {
	MSFirst = 1,							///< • Первое лицо
	MSSecond,								///< • Второе лицо
	MSThird,								///< • Третье лицо

	MSIndefinitePerson,						///< • Морфологическая характеристика "Лицо" имеет неопределенное значение
	MorphSPersonCount = MSIndefinitePerson	///< • Количество мофрологических категорий "Лицо"
};

enum MorphSVoice {
	MSPassive = 1,							///< • Страдательный залог
	MSActive,								///< • Действительный залог 

	MSIndefiniteVoice,						///< • Морфологическая характеристика "Лицо" имеет неопределенное значение
	MorphSVoiceCount = MSIndefiniteVoice	///< • Количество мофрологических категорий "Лицо"
};

enum MorphSExtra {
	MSCompounding = 1,						///< • Форма, используемая в словосложении 
	MSSoftened,								///< • Смягченная сравнительная степень

	MSIndefiniteExtra,						///< • Морфологическая характеристика "Дополнительные характеристики" имеет неопределенное значение
	MorphSExtraCount = MSIndefiniteExtra	///< • Количество мофрологических категорий "Дополнительные характеристики"
};

std::wstring ToWStringMorphSPos				(const MorphSPos & value			, bool verbal = false);
std::wstring ToWStringMorphSAnimacy			(const MorphSAnimacy & value		, bool verbal = false);
std::wstring ToWStringMorphSGender			(const MorphSGender & value			, bool verbal = false);
std::wstring ToWStringMorphSNumber			(const MorphSNumber & value			, bool verbal = false);
std::wstring ToWStringMorphSCase			(const MorphSCase & value			, bool verbal = false);
std::wstring ToWStringMorphSDegree			(const MorphSDegree & value			, bool verbal = false);
std::wstring ToWStringMorphSShort			(const MorphSShort & value			, bool verbal = false);
std::wstring ToWStringMorphSRepresentation	(const MorphSRepresentation & value	, bool verbal = false);
std::wstring ToWStringMorphSMood			(const MorphSMood & value			, bool verbal = false);
std::wstring ToWStringMorphSAspect			(const MorphSAspect & value			, bool verbal = false);
std::wstring ToWStringMorphSTense			(const MorphSTense & value			, bool verbal = false);
std::wstring ToWStringMorphSPerson			(const MorphSPerson & value			, bool verbal = false);
std::wstring ToWStringMorphSVoice			(const MorphSVoice & value			, bool verbal = false);
std::wstring ToWStringMorphSExtra			(const MorphSExtra & value			, bool verbal = false);


struct STRResult
{
	int Pos;
	int Animacy;
	int Gender;
	int Number;
	int Case;
	int Degree;
	int Short;
	int Representation;
	int Mood;
	int Aspect;
	int Tense;
	int Person;
	int Voice;
	int Extra;

	STRResult(void){
		Pos				= MSIndefinitePos;
		Animacy			= MSIndefiniteAnimacy;
		Gender			= MSIndefiniteGender;
		Number			= MSIndefiniteNumber;
		Case			= MSIndefiniteCase;
		Degree			= MSIndefiniteDegree;
		Short			= MSIndefiniteShort;
		Representation	= MSIndefiniteRepresentation;
		Mood			= MSIndefiniteMood;
		Aspect			= MSIndefiniteAspect;
		Tense			= MSIndefiniteTense;
		Person			= MSIndefinitePerson;
		Voice			= MSIndefiniteVoice;
		Extra			= MSIndefiniteExtra;
	}
	virtual ~STRResult(void) {}

	std::wstring ToWString() const;
};

