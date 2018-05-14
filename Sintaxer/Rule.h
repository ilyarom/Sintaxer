#pragma once
#include "GrammarObject.h"
#include <vector>
#include <set>

using namespace std;

class Rule
{
public:
	Rule(GrammarObject terminal, vector<GrammarObject> rightPart, set<GrammarObject> guideSet);
	~Rule();
private:
	GrammarObject m_terminal;
	vector<GrammarObject> m_rightPart;
	set<GrammarObject> m_guideSet;
};

