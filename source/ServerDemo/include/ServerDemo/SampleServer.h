/*
 * SampleServer.h
 *
 * EchoServeConnection.h
 *
 * Author: Peter Maurer
 *
 * Beispiel fuer eine ServerApplication
 */

#ifndef SERVERDEMO_SOURCE_SAMPLESERVER_H_
#define SERVERDEMO_SOURCE_SAMPLESERVER_H_

#include "Poco/Util/OptionSet.h"
#include "Poco/Util/ServerApplication.h"

namespace ServerDemo
{

using Poco::Util::OptionSet;
using Poco::Util::ServerApplication;

using std::string;
using std::vector;

class SampleServer : public ServerApplication
{
public:
	SampleServer();

	virtual ~SampleServer();

	void initialize(Application &self);

	void uninitialize();

	void defineOptions(OptionSet& options);

	int main(const vector<string>& args);
};

} /* namespace ApplicationDemo */

#endif /* SERVERDEMO_SOURCE_SAMPLESERVER_H_ */
