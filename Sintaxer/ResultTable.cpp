#include "stdafx.h"
#include "ResultTable.h"


ResultTable::ResultTable()
{
}

vector<TableRow> ResultTable::GetValues() const
{
	return m_values;
}
void ResultTable::SetValues(vector<TableRow> values)
{
	m_values = values;
}
