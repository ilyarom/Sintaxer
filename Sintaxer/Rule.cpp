#include "stdafx.h"
#include "Rule.h"

Rule::Rule(GrammarObject terminal, vector<GrammarObject> rightPart, vector<GrammarObject> guideSet)
	:m_terminal(terminal), m_rightPart(rightPart), m_guideSet(guideSet)
{
}

GrammarObject Rule::GetTerminal() const
{
	return m_terminal;
}
vector<GrammarObject> Rule::GetRightPart() const
{
	return m_rightPart;
}
vector<GrammarObject> Rule::GetGuideSet() const
{
	return m_guideSet;
}
void Rule::SetTerminal(GrammarObject terminal)
{
	m_terminal = terminal;
}
void Rule::SetRightPart(vector<GrammarObject> rightPart)
{
	m_rightPart = rightPart;
}
void Rule::SetGuideSet(vector<GrammarObject> guideSet)
{
	m_guideSet = guideSet;
}