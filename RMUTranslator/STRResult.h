#pragma once

#include "STRTError.h"

#include <string>

enum MorphSPos {
	MSNoun = 1,							///< � ��������������� 
	MSAdjective,						///< � �������������� 
	MSVerb,								///< � ������
	MSAdverb,							///< � �������
	MSNumber,							///< � ������������
	MSPreposition,						///< � ������� 
	MSComposite,						///< � ��������
	MSConjunction,						///< � ����
	MSParticle,							///< � �������
	MSProposalWord,						///< � �����-�����������
	MSInterjection,						///< � ����������
	MSNID,								///< � �����, �������������� ����� ���������� ���������� � ������� ����� ��� ����������� �������
	
	MSIndefinitePos,					///< � ��������������� �������������� "����� ����" ����� �������������� ��������
	MorphSPosCount = MSIndefinitePos	///< � ���������� ��������������� ��������� "����� ����"
};

enum MorphSAnimacy {
	MSAnimate = 1,								///< � ������������
	MSInanimate,								///< � ��������������
	MSAnyAnimacy,								///< � ���������� ��������������

	MSIndefiniteAnimacy,						///< � ��������������� �������������� "��������������" ����� �������������� ��������
	MorphSAnimacyCount = MSIndefiniteAnimacy	///< � ���������� ��������������� ��������� "��������������"
};

enum MorphSGender {
	MSMale = 1,								///< � ������� ���
	MSFemale,								///< � ������� ���
	MSNeuter,								///< � ������� ���
	MSAnyGender,							///< � ���������� ���

	MSIndefiniteGender,						///< � ��������������� �������������� "���" ����� �������������� ��������
	MorphSGenderCount = MSIndefiniteGender	///< � ���������� ��������������� ��������� "���"
};

enum MorphSNumber {
	MSSingle = 1,							///< � ������������
	MSPlural,								///< � �������������

	MSIndefiniteNumber,						///< � ��������������� �������������� "�����" ����� �������������� ��������
	MorphSNumberCount = MSIndefiniteNumber	///< � ���������� ��������������� ��������� "�����"
};

enum MorphSCase {
	MSNominative = 1,					///< � ������������ �����
	MSGenitive,							///< � ����������� �����
	MSPartitive,						///< � ����������� (��� ���)
	MSDative,							///< � ��������� �����
	MSAccusative,						///< � ����������� �����
	MSInstrumental,						///< � ������������ �����
	MSPrepositional,					///< � ���������� �����
	MSLocative,							///< � ������� (� ����)

	MSIndefiniteCase,					///< � ��������������� �������������� "�����" ����� �������������� ��������
	MorphSCaseCount = MSIndefiniteCase	///< � ���������� ��������������� ��������� "�����"
};

enum MorphSDegree {
	MSComparative = 1,						///< � ������������� ������� ���������
	MSSuperlative,							///< � ������������ ������� ���������
	MSPositive,								///< � ������������� ������� ���������

	MSIndefiniteDegree,						///< � ��������������� �������������� "������� ���������" ����� �������������� ��������
	MorphSDegreeCount = MSIndefiniteDegree	///< � ���������� ��������������� ��������� "������� ���������"
};

enum MorphSShort {
	MSShort = 1,							///< � �������
	MSShortNot,								///< � �� �������

	MSIndefiniteShort,						///< � ��������������� �������������� "���������" ����� �������������� ��������
	MorphSShortCount = MSIndefiniteShort	///< � ���������� ��������������� ��������� "���������"
};

enum MorphSRepresentation {
	MSInfinitive = 1,										///< � ���������
	MSParticiple,											///< � ���������
	MSParticipleDee,										///< � ������������
	MSPersonal,												///< � ������ ����� ������� 

	MSIndefiniteRepresentation,								///< � ��������������� �������������� "�������������" ����� �������������� ��������
	MorphSRepresentationCount = MSIndefiniteRepresentation	///< � ���������� ��������������� ��������� "�������������"
};

enum MorphSMood {
	MSImperative = 1,						///< � ������������� ����������
	MSIndicative,							///< � ������������� ����������
	//MSSubjunctive,						///< � �������������� ���������� � ������� ����� ���������� ������ ������������ � �� ����� ������������� ������� ����������. ��� ����������� � ������� �������������� ��������������� ���������

	MSIndefiniteMood,						///< � ��������������� �������������� "����������" ����� �������������� ��������
	MorphSMoodCount = MSIndefiniteMood		///< � ���������� ��������������� ��������� "����������"
};

enum MorphSAspect {
	MSPerfect = 1,							///< � ������������� ���
	MSImperfect,							///< � ����������� ���

	MSIndefiniteAspect,						///< � ��������������� �������������� "���" ����� �������������� ��������
	MorphSAspectCount = MSIndefiniteAspect	///< � ���������� ��������������� ��������� "���"
};

enum MorphSTense {
	MSPastNot = 1,							///< � ����������� (���������-�������)  �����
	MSPast,									///< � ��������� �����
	MSPresent,								///< � ��������� ����� (����. ��������� ����� ������������� ������ ������� ���� � ������ �����)

	MSIndefiniteTense,						///< � ��������������� �������������� "�����" ����� �������������� ��������
	MorphSTenseCount = MSIndefiniteTense	///< � ���������� ��������������� ��������� "�����"
};

enum MorphSPerson {
	MSFirst = 1,							///< � ������ ����
	MSSecond,								///< � ������ ����
	MSThird,								///< � ������ ����

	MSIndefinitePerson,						///< � ��������������� �������������� "����" ����� �������������� ��������
	MorphSPersonCount = MSIndefinitePerson	///< � ���������� ��������������� ��������� "����"
};

enum MorphSVoice {
	MSPassive = 1,							///< � ������������� �����
	MSActive,								///< � �������������� ����� 

	MSIndefiniteVoice,						///< � ��������������� �������������� "����" ����� �������������� ��������
	MorphSVoiceCount = MSIndefiniteVoice	///< � ���������� ��������������� ��������� "����"
};

enum MorphSExtra {
	MSCompounding = 1,						///< � �����, ������������ � ������������� 
	MSSoftened,								///< � ���������� ������������� �������

	MSIndefiniteExtra,						///< � ��������������� �������������� "�������������� ��������������" ����� �������������� ��������
	MorphSExtraCount = MSIndefiniteExtra	///< � ���������� ��������������� ��������� "�������������� ��������������"
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

