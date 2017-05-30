//
// OPCServer.cpp
//
// $Id$
//
// This sample demonstrates an OPC server.
//
// Copyright (c) 2010-2015, Günter Obiltschnig.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/OPC/Server.h"
#include "Poco/Dynamic/Var.h"
#include <iostream>

using namespace Poco;
using namespace Poco::Dynamic;
using namespace Poco::OPC;
using namespace open62541;

int main(int argc, char** argv)
{
	try
	{
		Server srv;

		int nsIndex = 1;
		Var id = "the.int.answer";
		std::string name = "the int answer";
		srv.addVariableNode(nsIndex, id, 42, UA_TYPES_INT32, name, name, name);
		std::cout << "Added variable node \"" << name << "\", to namespace " << nsIndex << std::endl; 

		nsIndex = srv.addNamespace("ns2");
		id = "the.double.answer";
		name = "the double answer";
		srv.addVariableNode(nsIndex, id, 4.2, UA_TYPES_DOUBLE, name, name, name);
		std::cout << "Added variable node \"" << name << "\", to namespace " << nsIndex << std::endl;

		id = 3;
		name = "the double answer by ID in ns2";
		srv.addVariableNode(nsIndex, id, 2.4, UA_TYPES_DOUBLE, name, name, name);
		std::cout << "Added double variable node \"" << name << "\", to namespace " << nsIndex << std::endl;

		id = 4;
		name = "the string answer by ID in ns2";
		srv.addVariableNode(nsIndex, id, std::string("abc123"), UA_TYPES_STRING, name, name, name);
		std::cout << "Added string variable node \"" << name << "\", to namespace " << nsIndex << std::endl;

		id = 5;
		name = "the DateTime answer by ID in ns2";
		Poco::Int64 ts = OPC::DateTime::now();
		srv.addVariableNode(nsIndex, id, ts, UA_TYPES_DATETIME, name, name, name);
		std::cout << "Added DateTime (" << OPC::DateTime(ts).toString() << ") variable node \"" << name << "\", to namespace " << nsIndex << std::endl;

		srv.run();
	}
	catch(Poco::Exception& ex)
	{
		std::cout << ex.displayText() << std::endl;
		return -1;
	}
	return 0;
}