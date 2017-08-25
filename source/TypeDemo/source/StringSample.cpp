/*
 * StringSample.cpp
 *
 *  Created on: Aug 25, 2017
 *      Author: peter
 */

#ifndef TYPEDEMO_SOURCE_STRINGSAMPLE_CPP_
#define TYPEDEMO_SOURCE_STRINGSAMPLE_CPP_

#include "TypeDemo/StringSample.h"

#include "Poco/String.h"
#include "Poco/Types.h"
#include "Poco/UTF8String.h"
#include "Poco/TextConverter.h"
#include "Poco/ASCIIEncoding.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/Latin1Encoding.h"


namespace TypeDemo
{
	void StringSample::run(std::ostream& os, std::istream& is)
	{
		std::string myWords="                In the beginning was the word     ";
		std::cout<<Poco::trimLeft(myWords)<<"."<<std::endl;
		std::cout<<Poco::trimRight(myWords)<<"."<<std::endl;
		std::cout<<Poco::trimInPlace(myWords)<<"."<<std::endl;

		std::string russianString="был вначале словом";
		std::cout<<russianString<<std::endl;
		std::cout<<Poco::UTF8::toUpper(russianString)<<std::endl;

		russianString = Poco::cat(russianString,std::string(","),std::string("и Слово было у Бога"));
		std::cout<<russianString<<std::endl;

		Poco::UTF8Encoding utf8enc;
		Poco::ASCIIEncoding asciiEnc;
		Poco::TextConverter myConverter(utf8enc,asciiEnc);

		std::string asciiResult;
		myConverter.convert(russianString,asciiResult);

		std::cout<<"ASCII: "<<asciiResult<<std::endl;

		// Clean the string in ASCII-Result
		asciiResult.erase();

		std::string germanWords="Übel wäre es, wenn der Bär den Würger fräße.";
		myConverter.convert(germanWords,asciiResult);

		std::cout<<"UTF8:  "<<germanWords<<std::endl;
		std::cout<<"ASCII: "<<asciiResult<<std::endl;


	}
}



#endif /* TYPEDEMO_SOURCE_STRINGSAMPLE_CPP_ */
