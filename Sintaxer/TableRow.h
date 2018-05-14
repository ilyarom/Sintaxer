#pragma once
#include <set>
#include "GrammarObject.h"

using namespace std;

class TableRow
{
public:
	TableRow(size_t id, set<GrammarObject> references, int nextId = -1, bool shift = false, int pushToStack = -1, int popFromStack = -1, bool isError = true, bool isEnd = false);
private:
	size_t m_id;
	set<GrammarObject> m_references;
	int m_nextId = -1;
	bool m_shift = false;
	int m_pushToStack = -1;
	int m_popFromStack = -1;
	bool m_isError = true;
	bool m_isEnd = false;
};

