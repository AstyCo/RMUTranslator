#pragma once

#include <exception>
#include <string>
#include <sstream>

#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class STRTError : public std::runtime_error
{
typedef std::runtime_error _mybase;
#if defined(WIN32)
	static const char PATH_SEPARATOR = '\\';
#else
	static const char PATH_SEPARATOR = '/';
#endif
public:
	explicit STRTError(const std::string& message) : _mybase(message) {}
	explicit STRTError(const char * message) : _mybase(message) {}
	static void Raise(const std::string& message,const char * fileName, int lineNo)
	{
		if (!fileName)
			fileName = "";
		const char * pFileName = strrchr(fileName, PATH_SEPARATOR);
		std::stringstream s; 
		s << "STRTError in file " << (pFileName == NULL ? fileName : pFileName+1)  << ", line " << lineNo << ": " << message;
		throw STRTError(s.str());
	}
	static void Raise(const char * message,const char * fileName, int lineNo)
	{
		Raise(std::string(message), fileName, lineNo);
	}
};

#define RAISE_STRT_ERR(msg) (STRTError::Raise((msg), __FILE__, __LINE__))

