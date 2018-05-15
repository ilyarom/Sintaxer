#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include "Rule.h"
#include "TableRow.h"

using namespace std;

class TableBuilder
{
public:
	TableBuilder(vector<Rule> rules);
private:
	void CreateTable();
	void ReadRules();
	void ComputeNextIds();
	vector<Rule> m_rules;
	vector<TableRow> m_tableValues;
	unordered_map<GrammarObject, vector<size_t>> m_tableReferences;
	unordered_map<GrammarObject, vector<GrammarObject>> m_referencingSets;
	vector<pair<vector<GrammarObject>, size_t>> m_unresolvedNextIds;
};

