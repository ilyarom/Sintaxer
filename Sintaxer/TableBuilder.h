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
	void CheckEmpties(const Rule &rule);
	vector<Rule> m_rules;
	vector<TableRow> m_tableValues;
	unordered_map<string, vector<std::size_t>> m_tableReferences;
	unordered_map<string, vector<GrammarObject>> m_referencingSets;
	vector<pair<vector<GrammarObject>, std::size_t>> m_unresolvedNextIds;
};

