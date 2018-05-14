#include "stdafx.h"
#include "Rule.h"

Rule::Rule(GrammarObject terminal, vector<GrammarObject> rightPart, set<GrammarObject> guideSet) 
	:m_terminal(terminal), m_rightPart(rightPart), m_guideSet(guideSet)
{
}