#pragma once
#include <vector>
#include "TableRow.h"

using namespace std;

class ResultTable
{
public:
	ResultTable();
private:
	vector<TableRow> m_values;
};

