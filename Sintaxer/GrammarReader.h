#pragma once
#include <vector>
#include "Rule.h"

using namespace std;

class GrammarReader
{
public:
	GrammarReader();
	~GrammarReader();
	vector<Rule> GetRules() const;
	void SetTules(vector<Rule> rules);
private:
	vector<Rule> m_rules;
};

