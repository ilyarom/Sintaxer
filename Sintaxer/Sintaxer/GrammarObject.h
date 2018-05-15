#pragma once
#include <string>
#include "GrammarObjectType.h"

using namespace std;

class GrammarObject
{
public:
	GrammarObject(string value, GrammarObjectType type);
	string GetValue() const;
	GrammarObjectType GetType() const;
	void SetType(GrammarObjectType type);
	void SetValue(string value);
	bool operator ==(const GrammarObject & rhs) const;
	size_t operator()(const GrammarObject & rhs) const;
private:
	string m_value;
	GrammarObjectType m_type;
};


