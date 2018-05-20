#include "stdafx.h"
#include "TableRow.h"


TableRow::TableRow(std::size_t id, vector<GrammarObject> references, int nextId, bool shift, int pushToStack, int popFromStack, bool isError, bool isEnd)
	:m_id(id), m_references(references), m_nextId(nextId), m_shift(shift), m_pushToStack(pushToStack), m_popFromStack(popFromStack), m_isError(isError), m_isEnd(isEnd)
{
}


int TableRow::GetNextId() const
{
	return m_nextId;
}
bool TableRow::GetShift() const
{
	return m_shift;
}
int TableRow::GetPushToStack() const
{
	return m_pushToStack;
}
int TableRow::GetPopFromStack() const
{
	return m_popFromStack;
}
bool TableRow::GetError() const
{
	return m_isError;
}
bool TableRow::GetEnd() const
{
	return m_isEnd;
}
void TableRow::SetNextId(int nextId)
{
	m_nextId = nextId;
}
void TableRow::SetShift(bool shift)
{
	m_shift = shift;
}
void TableRow::SetPushToStack(int pushToStack)
{
	m_pushToStack = pushToStack;
}
void TableRow::SetPopFromStack(int popFromStack)
{
	m_popFromStack = popFromStack;
}
void TableRow::SetError(bool isError)
{
	m_isError = isError;
}
void TableRow::SetEnd(bool isEnd)
{
	m_isEnd = isEnd;
}

void TableRow::SetId(size_t id)
{
	m_id = id;
}

void TableRow::SetReferences(vector<GrammarObject> references)
{
	m_references.assign(references.begin(), references.end());
}

void TableRow::Clear() {
	TableRow row;
	swap(*this, row);
}
