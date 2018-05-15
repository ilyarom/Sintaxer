#pragma once
#include "GrammarObject.h"

using namespace std;

class TableRow
{
public:
	TableRow(size_t id, vector<GrammarObject> references, int nextId = -1, bool shift = false, int pushToStack = -1, int popFromStack = -1, bool isError = true, bool isEnd = false);
	size_t GetId();
	vector<GrammarObject> GetReferences();
	int GetNextId() const;
	bool GetShift() const;
	int GetPushToStack() const;
	int GetPopFromStack() const;
	bool GetError() const;
	bool GetEnd() const;
	void SetNextId(int nextId);
	void SetShift(bool shift);
	void SetPushToStack(int pushToStack);
	void SetPopFromStack(int popFromStack);
	void SetError(bool isError);
	void SetEnd(bool isEnd);
private:
	size_t m_id;
	vector<GrammarObject> m_references;
	int m_nextId;
	bool m_shift;
	int m_pushToStack;
	int m_popFromStack;
	bool m_isError;
	bool m_isEnd;
};

