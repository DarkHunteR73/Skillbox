#pragma once

#include <cpr/cpr.h>
#include <iostream>

class Request
{
	cpr::Url url;
	cpr::Response response;

public:

	Request(const char* inUrl) :url(inUrl) {};
	void get();
	void post();
	void put();
	void patch();
	void _delete();
};