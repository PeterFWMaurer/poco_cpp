/*
 * HelloPlugin.h
 *
 * Author: Peter Maurer
 *
 * Eine sehr einfache Basisklasse fuer ein Plugin
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef SHAREDDEMO_INCLUDE_SHAREDDEMO_HELLOPLUGIN_H_
#define SHAREDDEMO_INCLUDE_SHAREDDEMO_HELLOPLUGIN_H_

#include <string>

struct HelloPlugin
{
	HelloPlugin(){}
	virtual ~HelloPlugin(){}
	virtual std::string sayHello(const std::string& name)=0;
};



#endif /* SHAREDDEMO_INCLUDE_SHAREDDEMO_HELLOPLUGIN_H_ */
