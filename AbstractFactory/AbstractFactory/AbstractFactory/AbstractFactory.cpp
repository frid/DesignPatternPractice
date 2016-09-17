// AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Widget {
public:
	virtual void Draw() = 0;
};

class MotifButton : public Widget {
public:
	void Draw() { cout << "Motif Button Draw" << endl; }
};

class MotifMenu : public Widget {
public:
	void Draw() { cout << "Motif Menu Draw" << endl; }
};

class WindowButton : public Widget {
public:
	void Draw() { cout << "Window Button Draw" << endl; }
};

class WindowMenu : public Widget {
public:
	void Draw() { cout << "Window Menu Draw" << endl; }
};

class Factory {
public:
	virtual Widget * createButton() = 0;
	virtual Widget * createMenu() = 0;
};

class MotifFactory : public Factory {
public:
	Widget * createButton() { return new MotifButton; }
	Widget * createMenu() { return new MotifMenu; }
};

class WindowFactory : public Factory {
public:
	Widget * createButton() { return new WindowButton; }
	Widget * createMenu() { return new WindowMenu; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Factory *factory = new MotifFactory;

	Widget *w = factory->createButton();
	w->Draw();

	return 0;
}

