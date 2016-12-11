#pragma once

#include "RMUDLL.h"
#include "RMUResult.h"
#include "RMUError.hpp"

#include "STRResult.h"

#include <vector>

using namespace std;

class RMUTranslator
{
public:
	static RMUTranslator &instance();
private:
	RMUTranslator() {}
	virtual ~RMUTranslator() {}

	RMUTranslator(const RMUTranslator&);
	RMUTranslator& operator=(const RMUTranslator&);

public:
	static STRResult toSynTagRusFeature(const RMUResult &result);

	///////
	// functions translating RMU structure to SynTagRus 2012 structures
	///////
	static MorphSPos			Pos(const RMUResult &result);				
	static MorphSAnimacy		Animacy(const RMUResult &result);
	static MorphSGender			Gender(const RMUResult &result);
	static MorphSNumber			Number(const RMUResult &result);
	static MorphSCase			Case(const RMUResult &result);
	static MorphSDegree			Degree(const RMUResult &result);
	static MorphSShort			Short(const RMUResult &result);
	static MorphSRepresentation Representation(const RMUResult &result);
	static MorphSMood			Mood(const RMUResult &result);
	static MorphSAspect			Aspect(const RMUResult &result);
	static MorphSTense			Tense(const RMUResult &result);
	static MorphSPerson			Person(const RMUResult &result);
	static MorphSVoice			Voice(const RMUResult &result);
	static MorphSExtra			Extra(const RMUResult &result);
	
};
