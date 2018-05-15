#include "stdafx.h"
#include "GrammarReader.h"


GrammarReader::GrammarReader()
{
}


vector<Rule> GrammarReader::GetRules() const
{
	return m_rules;
}
void GrammarReader::SetTules(vector<Rule> rules)
{
	m_rules = rules;
}
