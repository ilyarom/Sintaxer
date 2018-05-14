#pragma once
#include <vector>
#include <map>
#include "Rule.h"
#include "TableRow.h"

using namespace std;

class TableBuilder
{
public:
	TableBuilder(vector<Rule> rules);
	~TableBuilder();
private:
	void CreateTable();
	vector<Rule> m_rules;
	vector<TableRow> m_tableValues;
	map<GrammarObject, size_t> tableReferences;
	map<GrammarObject, set<GrammarObject>> referencingSets;
	vector<pair<vector<GrammarObject>, size_t>> unresolvedNextIds;
};

