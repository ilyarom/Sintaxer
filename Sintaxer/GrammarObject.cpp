#include "stdafx.h"
#include "GrammarObject.h"


GrammarObject::GrammarObject(string value, GrammarObjectType type)
	:m_value(value), m_type(type)
{
}

string GrammarObject::GetValue() const
{
	return m_value;
}
GrammarObjectType GrammarObject::GetType() const
{
	return m_type;
}
void GrammarObject::SetType(GrammarObjectType type)
{
	m_type = type;
}
void GrammarObject::SetValue(string value)
{
	m_value = value;
}

bool GrammarObject::operator ==(const GrammarObject & rhs) const
{
	if (m_value == rhs.GetValue() && m_type == rhs.GetType())
		return true;
	else
		return false;
}

size_t GrammarObject::operator()(const GrammarObject & rhs) const
{
	return hash<string>()(rhs.GetValue());
}