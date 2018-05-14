#include "stdafx.h"
#include "TableRow.h"


TableRow::TableRow(size_t id, set<GrammarObject> references, int nextId = -1, bool shift = false, int pushToStack = -1, int popFromStack = -1, bool isError = true, bool isEnd = false)
	:m_id(id), m_references(references), m_nextId(nextId), m_shift(shift), m_pushToStack(pushToStack), m_popFromStack(popFromStack), m_isError(isError), m_isEnd(isEnd)
{
}


TableRow::~TableRow()
{
}
