#include "stdafx.h"
#include "TableBuilder.h"


TableBuilder::TableBuilder(vector<Rule> rules)
	:m_rules(rules)
{
	CreateTable();
}

void TableBuilder::ReadRules() 
{
	size_t counter = 0;
	for (const Rule &rule : m_rules) 
	{
		m_unresolvedNextIds.push_back(pair<vector<GrammarObject>, size_t>(rule.GetRightPart(), counter));
		if (m_tableReferences.find(rule.GetTerminal()) == m_tableReferences.end())
		{
			m_tableReferences.insert(m_tableReferences.begin(), pair<GrammarObject, vector<size_t>>(rule.GetTerminal(), { counter }));
			m_referencingSets.insert(m_referencingSets.begin(), pair<GrammarObject, vector<GrammarObject>>(rule.GetTerminal(), rule.GetGuideSet()));
		}
		else {
			vector<size_t> &references = m_tableReferences.at(rule.GetTerminal());
			for (vector<size_t>::iterator iterator = references.begin(); iterator != references.end(); ++iterator)
			{
				m_tableValues[*iterator].SetError(false);
			}
			references.push_back(counter);
			m_referencingSets.at(rule.GetTerminal()).insert(m_referencingSets.at(rule.GetTerminal()).begin(), rule.GetGuideSet().begin(), rule.GetGuideSet().end());
		}
		
		m_tableValues.push_back(TableRow(m_tableValues.size(), rule.GetGuideSet()));
		++counter;
	}
}


void TableBuilder::ComputeNextIds() 
{
	for (const pair<vector<GrammarObject>, size_t> &referencingSet : m_referencingSets)
	{

	}
}

void TableBuilder::CreateTable() 
{
	ReadRules();
	ComputeNextIds();
}

