// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

enum PersistenceType {
	File, Queue, Pathway
};

struct PersistenceAttribute {
	PersistenceType type;
	char value[30];
};

class DistrWorkPackage {
public:
	DistrWorkPackage(char *type) {
		sprintf(_desc, "Distributed Work Package for: %s", type);
	}

	void setFile(char *f, char *v) {
		sprintf(_tmp, "\n File(%s): %s", f, v);
		strcat(_desc, _tmp);
	}

	void setQueue(char *q, char *v) {
		sprintf(_tmp, "\n Queue(%s): %s", q, v);
		strcat(_desc, _tmp);
	}

	void setPathway(char *p, char *v) {
		sprintf(_tmp, "\n Pathway(%s): %s", p, v);
		strcat(_desc, _tmp);
	}

	const char * getState() {
		return _desc;
	}

private:
	char _desc[200], _tmp[80];
};

class Builder {
public:
	virtual void configureFile(char* ) = 0;
	virtual void configureQueue(char *) = 0;
	virtual void configurePathway(char *) = 0;
	DistrWorkPackage *getResult() {
		return _result;
	};

protected:
	DistrWorkPackage *_result;
};

class UnixBuilder : public Builder {
public:
	UnixBuilder() {
		_result = new DistrWorkPackage("Unix");
	}
	void configureFile(char *name) {
		_result->setFile("flatFile", name);
	}

	void configurePathway(char *name) {
		_result->setPathway("threah", name);
	}

	void configureQueue(char *name) {
		_result->setQueue("FIFO", name);
	}

};

class VmsBuilder : public Builder {
public:
	VmsBuilder() {
		_result = new DistrWorkPackage("Vms");
	}

	void configureFile(char *name) {
		_result->setFile("ISAM", name);
	}

	void configureQueue(char *name) {
		_result->setQueue("priority", name);
	}

	void configurePathway(char *name) {
		_result->setPathway("LWP", name);
	}

};

class Reader {
public:
	void setBuilder( Builder *b ) {
		_builder = b;
	}
	void construct(PersistenceAttribute[], int);

private:
	Builder *_builder;

};

void Reader::construct(PersistenceAttribute list[], int num) {
	for (int i = 0; i < num ; i++) {
		if (list[i].type == File) 
			_builder->configureFile(list[i].value);
		if (list[i].type == Queue)
			_builder->configureQueue(list[i].value);
		if (list[i].type == Pathway)
			_builder->configurePathway(list[i].value);
	}
}

const int NUM_ENTRIES = 6;
PersistenceAttribute input[NUM_ENTRIES] = {
	{
		File, "state.dat"
	}
	,
	{
		File, "config.sys"
	}
	,
	{
		Queue, "compute"
	}
	,
	{
		Queue, "log"
	}
	,
	{
		Pathway, "authentication"
	}
	,
	{
		Pathway, "error processing"
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	UnixBuilder unixbuilder;
	VmsBuilder vmsbuilder;
	Reader reader;

	reader.setBuilder(&unixbuilder);
	reader.construct(input, NUM_ENTRIES);
	cout << unixbuilder.getResult()->getState() << endl;

	reader.setBuilder(&vmsbuilder);
	reader.construct(input, NUM_ENTRIES);
	cout << vmsbuilder.getResult()->getState() << endl;
	return 0;
}

