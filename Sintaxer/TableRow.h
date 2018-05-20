#pragma once
#include "GrammarObject.h"
#include <utility>

using namespace std;

class TableRow
{
public:
	TableRow() = default;
	TableRow(std::size_t id, vector<GrammarObject> references, int nextId = -1, bool shift = false, int pushToStack = -1, int popFromStack = -1, bool isError = true, bool isEnd = false);
	std::size_t GetId();
	vector<GrammarObject> GetReferences();
	int GetNextId() const;
	bool GetShift() const;
	int GetPushToStack() const;
	int GetPopFromStack() const;
	bool GetError() const;
	bool GetEnd() const;
	void SetId(size_t id);
	void SetReferences(vector<GrammarObject> references);
	void SetNextId(int nextId);
	void SetShift(bool shift);
	void SetPushToStack(int pushToStack);
	void SetPopFromStack(int popFromStack);
	void SetError(bool isError);
	void SetEnd(bool isEnd);
	void Clear();
private:
	std::size_t m_id;
	vector<GrammarObject> m_references = {};
	int m_nextId = -1;
	bool m_shift = false;
	int m_pushToStack = -1;
	int m_popFromStack = -1;
	bool m_isError = true;
	bool m_isEnd = false;;
};

