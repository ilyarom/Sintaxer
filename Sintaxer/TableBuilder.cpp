#include "stdafx.h"
#include "TableBuilder.h"
#include <iterator>

TableBuilder::TableBuilder(vector<Rule> rules)
	:m_rules(rules)
{
	CreateTable();
}

void TableBuilder::CheckEmpties(const Rule &rule)
{
	for (const GrammarObject &element : rule.GetRightPart())
	{
		if (element.GetType() == GrammarObjectType::EMPTY)
		{
			pair<string, vector<GrammarObject>> referencingSet(element.GetValue(), rule.GetGuideSet());
			m_referencingSets.insert(m_referencingSets.end(), referencingSet);
		}
	}
}

void TableBuilder::ReadRules() 
{
	std::size_t counter = 0;
	for (const Rule &rule : m_rules) 
	{
		m_unresolvedNextIds.push_back(pair<vector<GrammarObject>, std::size_t>(rule.GetRightPart(), counter));
		if (m_tableReferences.find(rule.GetTerminal().GetValue()) == m_tableReferences.end())
		{
			m_tableReferences.insert(m_tableReferences.begin(), pair<string, vector<std::size_t>>(rule.GetTerminal().GetValue(), { counter }));
			m_referencingSets.insert(m_referencingSets.begin(), pair<string, vector<GrammarObject>>(rule.GetTerminal().GetValue(), rule.GetGuideSet()));
		}
		else {
			vector<std::size_t> &references = m_tableReferences.at(rule.GetTerminal().GetValue());
			for (vector<std::size_t>::iterator &iterator = references.begin(); iterator != references.end(); ++iterator)
			{
				m_tableValues[*iterator].SetError(false);
			}
			references.push_back(counter);
			vector <GrammarObject> &destination = m_referencingSets.at(rule.GetTerminal().GetValue());
			vector <GrammarObject> source = rule.GetGuideSet();
			std::copy(source.begin(), source.end(), std::back_inserter(destination));
		}
		CheckEmpties(rule);
		m_tableValues.push_back(TableRow(m_tableValues.size(), rule.GetGuideSet()));
		++counter;
	}
}


void TableBuilder::ComputeNextIds() 
{
	std::size_t nextId = m_tableValues.size();
	vector<GrammarObject> elementsSet;
	TableRow row;
	for (const pair<vector<GrammarObject>, std::size_t> &ruleNextIds : m_unresolvedNextIds)
	{
		nextId = m_tableValues.size();
		m_tableValues[ruleNextIds.second].SetNextId(nextId);
		std::size_t counter = 0;
		for (const GrammarObject &object : ruleNextIds.first)
		{
			++nextId;
			row.SetId(m_tableValues.size());
			switch (object.GetType())
			{
				case GrammarObjectType::NONTERMINAL:
				{
					elementsSet.push_back(object);
					if (counter != (ruleNextIds.first.size() - 1))
					{
						row.SetShift(true);
						row.SetNextId(nextId);
					}
					else
					{
						row.SetEnd(true);
					}
					break;
				}	
				case GrammarObjectType::TERMINAL:
				{
					elementsSet = m_referencingSets.at(object.GetValue());
					row.SetNextId(m_tableReferences.at(object.GetValue()).front());
					row.SetPushToStack(nextId);
					break;
				}
				case GrammarObjectType::EMPTY:
				{
					elementsSet = m_referencingSets.at(object.GetValue());
					//row.SetPopFromStack(true);
					break;
				}
			};
			if (row.GetNextId() == -1)
			{
				row.SetPopFromStack(true);
			}
			row.SetReferences(elementsSet);
			m_tableValues.push_back(row);
			row.Clear();
			elementsSet.clear();
			++counter;
		}
	}
}

void TableBuilder::CreateTable() 
{
	ReadRules();
	ComputeNextIds();
	cout << "D";
}

