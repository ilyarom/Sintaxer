#pragma once
#include "GrammarObject.h"
#include <vector>

using namespace std;

class Rule
{
public:
	Rule(GrammarObject terminal, vector<GrammarObject> rightPart, vector<GrammarObject> guideSet);
	GrammarObject GetTerminal() const;
	vector<GrammarObject> GetRightPart() const;
	vector<GrammarObject> GetGuideSet() const;
	void SetTerminal(GrammarObject terminal);
	void SetRightPart(vector<GrammarObject> rightPart);
	void SetGuideSet(vector<GrammarObject> guideSet);
private:
	GrammarObject m_terminal;
	vector<GrammarObject> m_rightPart;
	vector<GrammarObject> m_guideSet;
};

