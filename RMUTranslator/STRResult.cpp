#include "stdafx.h"
#include "STRResult.h"

std::wstring ToWStringMorphSPos(const MorphSPos & value, bool verbal){
	switch(value){
	case MSNoun			: return (verbal ? L"Noun"			: L"S"		);
	case MSAdjective	: return (verbal ? L"Adjective"		: L"A"		);
	case MSVerb			: return (verbal ? L"Verb"			: L"V"		);
	case MSAdverb		: return (verbal ? L"Adverb"		: L"ADV"	);
	case MSNumber		: return (verbal ? L"Number"		: L"NUM"	);
	case MSPreposition	: return (verbal ? L"Preposition"	: L"PR"		);
	case MSComposite	: return (verbal ? L"Composite"		: L"COM"	);
	case MSConjunction	: return (verbal ? L"Conjunction"	: L"CONJ"	);
	case MSParticle		: return (verbal ? L"Particle"		: L"PART"	);
	case MSProposalWord	: return (verbal ? L"ProposalWord"	: L"P"		);
	case MSInterjection	: return (verbal ? L"Interjection"	: L"INTJ"	);
	case MSNID			: return (verbal ? L"NID"			: L"NID"	);
	case MSIndefinitePos: return (verbal ? L"IndefinitePos"	: L""		);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSAnimacy(const MorphSAnimacy & value, bool verbal){
	switch(value){
	case MSAnimate:				return (verbal ? L"Animate"			: L"нд"	);
	case MSInanimate:			return (verbal ? L"Inanimate"		: L"менд");
	case MSAnyAnimacy:			return (verbal ? L"AnyAnimacy"		: L""	);
	case MSIndefiniteAnimacy:	return (verbal ? L"IndefiniteAnimacy": L""	);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSGender(const MorphSGender & value, bool verbal){
	switch(value){
	case MSMale:				return (verbal ? L"Male"			: L"лсф" );
	case MSFemale:				return (verbal ? L"Female"			: L"фем" );
	case MSNeuter:				return (verbal ? L"Neuter"			: L"япед");
	case MSAnyGender:			return (verbal ? L"AnyGender"		: L"лсф" ); // TODO: SynTagRus doesn't have feature AnyGender
	case MSIndefiniteGender:	return (verbal ? L"IndefiniteGender": L""    );
	default : RAISE_STRT_ERR("Unexpected default");							
	}
	return std::wstring();
};

std::wstring ToWStringMorphSNumber(const MorphSNumber & value, bool verbal){
	switch(value){
	case MSSingle:				return (verbal ? L"Single"			: L"ед"	);
	case MSPlural:				return (verbal ? L"Plural"			: L"лм"	);
	case MSIndefiniteNumber:	return (verbal ? L"IndefiniteNumber": L""	);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSCase(const MorphSCase & value, bool verbal){
	switch(value){
	case MSNominative:		return (verbal ? L"Nominative"		: L"хл"		);
	case MSGenitive:		return (verbal ? L"Genitive"		: L"пнд"	);
	case MSPartitive:		return (verbal ? L"Partitive"		: L"оюпр"	);
	case MSDative:			return (verbal ? L"Dative"			: L"дюр"	);
	case MSAccusative:		return (verbal ? L"Accusative"		: L"бхм"	);
	case MSInstrumental:	return (verbal ? L"Instrumental"	: L"рбнп"	);
	case MSPrepositional:	return (verbal ? L"Prepositional"	: L"оп"		);
	case MSLocative:		return (verbal ? L"Locative"		: L"леярм"	);
	case MSIndefiniteCase:	return (verbal ? L"IndefiniteCase"	: L""		);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSDegree(const MorphSDegree & value, bool verbal){
	switch(value){
	case MSComparative:			return (verbal ? L"Comparative"					: L"япюб");
	case MSSuperlative:			return (verbal ? L"Superlative"					: L"опеб");
	case MSPositive:			return (verbal ? L"Positive"					: L""	);
	case MSIndefiniteDegree:	return (verbal ? L"IndefiniteDegree(Positive)"	: L""	);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSShort(const MorphSShort & value, bool verbal){
	switch(value){
	case MSShort:				return (verbal ? L"Short"			: L"йп"	);
	case MSShortNot:			return (verbal ? L"not Short"		: L""	);
	case MSIndefiniteShort:		return (verbal ? L"IndefiniteShort"	: L""	);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSRepresentation(const MorphSRepresentation & value, bool verbal){
	switch(value){
	case MSInfinitive:					return (verbal ? L"Infinitive"				: L"хмт"	);
	case MSParticiple:					return (verbal ? L"Participle"				: L"опхв"	);
	case MSParticipleDee:				return (verbal ? L"ParticipleDee"			: L"дееоп"	);
	case MSPersonal:					return (verbal ? L"Personal"				: L""		);
	case MSIndefiniteRepresentation:	return (verbal ? L"IndefiniteRepresentation": L""		);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSMood(const MorphSMood & value, bool verbal){
	switch(value){
	case MSIndicative:		return (verbal ? L"Indicative"		: L"хгзъб"	);
	case MSImperative:		return (verbal ? L"Imperative"		: L"онб"	);
	case MSIndefiniteMood:	return (verbal ? L"IndefiniteMood"	: L""		);
	//case MSSubjunctive:		return "Subjunctive";
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSAspect(const MorphSAspect & value, bool verbal){
	switch(value){
	case MSPerfect:				return (verbal ? L"Perfect"			: L"янб"	);
	case MSImperfect:			return (verbal ? L"Imperfect"		: L"меянб"	);
	case MSIndefiniteAspect:	return (verbal ? L"IndefiniteAspect": L""		);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSTense(const MorphSTense & value, bool verbal){
	switch(value){
	case MSPastNot:				return (verbal ? L"PastNot"			: L"меопнь"	);
	case MSPast:				return (verbal ? L"Past"				: L"опнь"	);
	case MSPresent:				return (verbal ? L"Present"			: L"мюяр"	);
	case MSIndefiniteTense:		return (verbal ? L"IndefiniteTense"	: L""		);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSPerson(const MorphSPerson & value, bool verbal){
	switch(value){
	case MSFirst:				return (verbal ? L"First"			: L"1-к"	);
	case MSSecond:				return (verbal ? L"Second"			: L"2-к"	);
	case MSThird:				return (verbal ? L"Third"			: L"3-к"	);
	case MSIndefinitePerson:	return (verbal ? L"IndefinitePerson": L""		);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSVoice(const MorphSVoice & value, bool verbal){
	switch(value){
	case MSPassive:				return (verbal ? L"Passive"					: L"ярпюд");
	case MSActive:				return (verbal ? L"Active"					: L"");
	case MSIndefiniteVoice:		return (verbal ? L"IndefiniteVoice(Active)"	: L"");
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

std::wstring ToWStringMorphSExtra(const MorphSExtra & value, bool verbal){
	switch(value){
	case MSCompounding:				return (verbal ? L"Compounding"		: L"як"	);
	case MSSoftened:				return (verbal ? L"Softened"		: L"ялъц");
	case MSIndefiniteExtra:			return (verbal ? L"IndefiniteExtra"	: L""	);
	default : RAISE_STRT_ERR("Unexpected default");
	}
	return std::wstring();
};

static std::wstring addFeature(std::wstring feat){
	return (feat==L"" ? L"" : L" " + feat);
}

std::wstring STRResult::ToWString() const {
	std::wstring
		sAnimacy		=	ToWStringMorphSAnimacy(static_cast<MorphSAnimacy>(Animacy)),
		sGender			=	ToWStringMorphSGender(static_cast<MorphSGender>(Gender)),
		sNumber			=	ToWStringMorphSNumber(static_cast<MorphSNumber>(Number)),
		sCase			=	ToWStringMorphSCase(static_cast<MorphSCase>(Case)),
		sDegree			=	ToWStringMorphSDegree(static_cast<MorphSDegree>(Degree)),
		sShort			=	ToWStringMorphSShort(static_cast<MorphSShort>(Short)),
		sRepresentation =	ToWStringMorphSRepresentation(static_cast<MorphSRepresentation>(Representation)),
		sMood			=	ToWStringMorphSMood(static_cast<MorphSMood>(Mood)),
		sAspect			=	ToWStringMorphSAspect(static_cast<MorphSAspect>(Aspect)),
		sTense			=	ToWStringMorphSTense(static_cast<MorphSTense>(Tense)),
		sPerson			=	ToWStringMorphSPerson(static_cast<MorphSPerson>(Person)),
		sVoice			=	ToWStringMorphSVoice(static_cast<MorphSVoice>(Voice)),
		sExtra			=	ToWStringMorphSExtra(static_cast<MorphSExtra>(Extra));

	return ToWStringMorphSPos(static_cast<MorphSPos>(Pos))
		+ addFeature( sAspect		 )	
		+ addFeature( sMood			 )
		+ addFeature( sVoice		 )
		+ addFeature( sRepresentation) 
		+ addFeature( sTense		 )
		+ addFeature( sShort		 )	
		+ addFeature( sDegree		 )	
		+ addFeature( sNumber		 )	
		+ addFeature( sGender		 )	
		+ addFeature( sCase			 )
		
		
		+ addFeature( sPerson		 )	
		+ addFeature( sAnimacy		 )
		+ addFeature( sExtra		 );	
}

