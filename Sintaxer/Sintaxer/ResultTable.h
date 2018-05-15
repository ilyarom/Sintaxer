#pragma once
#include <vector>
#include "TableRow.h"

using namespace std;

class ResultTable
{
public:
	ResultTable();
	vector<TableRow> GetValues() const;
	void SetValues(vector<TableRow> values);
private:
	vector<TableRow> m_values;
};

