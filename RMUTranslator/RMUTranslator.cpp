#include "stdafx.h"
#include "RMUTranslator.h"
#include "convert.h"
#include "STRTError.h"
#include "STRResult.h"

#include <iostream>

using namespace std;

RMUTranslator & RMUTranslator::instance() {
	char warning[] = "Загрузка файлов морфологии. Ждите...";
	cout << TranslateToConsole(warning)<< endl;

	static RMUTranslator instance;
	return instance;
}

STRResult RMUTranslator::toSynTagRusFeature(const RMUResult &result){
	STRResult syntagrusResult;

	syntagrusResult.Pos				= Pos(result);
	syntagrusResult.Animacy			= Animacy(result);
	syntagrusResult.Gender			= Gender(result);
	syntagrusResult.Number			= Number(result);
	syntagrusResult.Case			= Case(result);
	syntagrusResult.Degree			= Degree(result);
	syntagrusResult.Short			= Short(result);
	syntagrusResult.Representation	= Representation(result);
	syntagrusResult.Mood			= Mood(result);
	syntagrusResult.Aspect			= Aspect(result);
	syntagrusResult.Tense			= Tense(result);
	syntagrusResult.Person			= Person(result);
	syntagrusResult.Voice			= Voice(result);
	syntagrusResult.Extra			= Extra(result);
	return syntagrusResult;
}

MorphSPos RMUTranslator::Pos(const RMUResult &result){
	switch(result.S_cl){
	case noun:
	case personalpronoun:
	case reflexivepronoun:
	case pronoun:
	case name:
		return MSNoun;
	case adjective:
	case possesiveadjective:
	case pronounadjective:
	case shortadjective:
		return MSAdjective;
	case verb:
	case unpersonalverb:
	case frequentativeverb:
	case predicative:
	case participle:
	case shortparticiple:
		return MSVerb;
	case adverb:
		return MSAdverb;
	case numberordinal:
	case numberone:
	case numbertwo:
	case numberthree:
	case number:
	case numberbiform:
		return MSNumber;
	case preposition:
		return MSPreposition;
	case conjunction:
		return MSConjunction;
	case particle:
		return MSParticle;
	case interjection:
		return MSInterjection;
	case 0:
		break;
	default:
		RAISE_RMU_ERR(SSTR(result.S_cl));
		break;
	}
	return MSIndefinitePos;
}
MorphSAnimacy RMUTranslator::Animacy(const RMUResult &result){
	switch(result.Animate){
	case animate:
		return MSAnimate;
	case unanimate:
		return MSInanimate;
	case animateAny:
	case 0:
		break;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}

	return MSIndefiniteAnimacy;
}
MorphSGender RMUTranslator::Gender(const RMUResult &result){
	switch(result.Gender){
	case male:
		return MSMale;
	case female:
		return MSFemale;
	case neuter:
		return MSNeuter;
	case malefemale:
	case maleorfemale:
		return MSAnyGender;
	case genderAny:
	case 0:
		break;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}
	return MSIndefiniteGender;
}
MorphSNumber RMUTranslator::Number(const RMUResult &result){
	switch(result.Number){
	case single:
		return MSSingle;
	case plural:
		return MSPlural;
	case numberAny:
	case 0:
		break;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}
	return MSIndefiniteNumber;
}
MorphSCase RMUTranslator::Case(const RMUResult &result){
	switch(result.Case){
	case nominative:
		return MSNominative;
	case genitive:
		return MSGenitive;
	case dative:
		return MSDative;
	case accusative:
		return MSAccusative;
	case instrumental:
		return MSInstrumental;
	case prepositional:
		return MSPrepositional;
	case caseAny:
	case 0:
		break;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}
	// TODO: Partitive/Locative cases

	return MSIndefiniteCase;
}
MorphSDegree RMUTranslator::Degree(const RMUResult &result){
	switch(result.Degree){
	case strong:
		return MSSuperlative;
	case weak:
		return MSComparative;
	case degreeAny:
	case 0:
		break;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}
	return MSPositive;
}

MorphSShort RMUTranslator::Short(const RMUResult &result){
	switch(result.S_cl){
	case shortadjective:
	case shortparticiple:
		return MSShort;
	default:
		break;
	}
	return MSShortNot;
}

MorphSRepresentation RMUTranslator::Representation(const RMUResult &result){
	switch(result.Tense){
	case infinitive:
		return MSInfinitive;
	default:
		break;
	}
	switch(result.S_cl){
	case participle:
	case shortparticiple:
		return MSParticiple;
	default:
		break;
	}
	return MSPersonal;
}
MorphSMood RMUTranslator::Mood(const RMUResult &result){
	switch(result.Tense){
	case imperative:
		return MSImperative;
	default:
		break;
	}
	if(result.S_cl != verb){	/// TODO: predicative -> Verb, does it have Mood?
		return MSIndefiniteMood;
	}	
	return MSIndicative;
}
MorphSAspect RMUTranslator::Aspect(const RMUResult &result){
	switch(result.Perfective){
	case perfective:
		return MSPerfect;
	case unperfective:
		return MSImperfect;
	case perfectiveAny:
	case 0:
		break;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}
	return MSIndefiniteAspect;
}
MorphSTense RMUTranslator::Tense(const RMUResult &result){
	switch(result.Tense){
	case present:
	case infinitive:
		return MSPastNot;
	case imperative:
	case tenseAny:
	case 0:
		break;
	case past:
		return MSPast;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}
	/// TODO: 	MSPresent,	///< • Настоящее время (прим. Настоящее время приписывается только глаголу быть в личной форме)
	return MSIndefiniteTense;
	
}
MorphSPerson RMUTranslator::Person(const RMUResult &result){
	//switch(result.Person){
	//default:
	//	break;
	//}
	/// TODO: --
	return MSIndefinitePerson;
}
MorphSVoice RMUTranslator::Voice(const RMUResult &result){
	switch(result.Voice){
	case active:
		return MSActive;
	case passive:
		return MSPassive;
	case voiceAny:
	case 0:
		break;
	default:
		RAISE_RMU_ERR("Unexpected default value");
		break;
	}
	return MSIndefiniteVoice;
}
MorphSExtra RMUTranslator::Extra(const RMUResult &result){
	//switch(result.Degree){
	//case strong:
	//	return MSSuperlative;
	//case weak:
	//	return MSComparative;
	//case degreeAny:
	//case 0:
	//	break;
	//default:
	//	RAISE_RMU_ERR("Unexpected default value");
	//	break;
	//}
	// TODO: --
	return MSIndefiniteExtra;
}