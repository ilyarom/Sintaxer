#pragma once
#include <string>
#include "GrammarObjectType.h"

using namespace std;

class GrammarObject
{
public:
	GrammarObject(string value, GrammarObjectType type);
private:
	string m_value;
	GrammarObjectType m_type;
};

