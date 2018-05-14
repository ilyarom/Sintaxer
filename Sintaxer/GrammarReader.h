#pragma once
#include <vector>
#include "Rule.h"

using namespace std;

class GrammarReader
{
public:
	GrammarReader();
	~GrammarReader();
private:
	vector<Rule> m_rules;
};

