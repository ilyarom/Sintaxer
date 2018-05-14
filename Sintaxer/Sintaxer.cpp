// Sintaxer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TableBuilder.h"


int main()
{ 
	/*1*/
	vector<Rule> rules;
	GrammarObject terminal("S", GrammarObjectType::TERMINAL);
	vector<GrammarObject> rightPart = {
		GrammarObject("id", GrammarObjectType::NONTERMINAL),
		GrammarObject("=", GrammarObjectType::NONTERMINAL),
		GrammarObject("E", GrammarObjectType::TERMINAL),
		GrammarObject("#", GrammarObjectType::NONTERMINAL)
	};
	set<GrammarObject> guideSet = {
		GrammarObject("id", GrammarObjectType::NONTERMINAL)
	};
	/*end 1*/

	/*2*/
	vector<Rule> rules;
	GrammarObject terminal("S", GrammarObjectType::TERMINAL);
	vector<GrammarObject> rightPart = {
		GrammarObject("while", GrammarObjectType::NONTERMINAL),
		GrammarObject("E", GrammarObjectType::TERMINAL),
		GrammarObject("do", GrammarObjectType::NONTERMINAL),
		GrammarObject("S", GrammarObjectType::TERMINAL),
		GrammarObject("#", GrammarObjectType::NONTERMINAL),
	};
	set<GrammarObject> guideSet = {
		GrammarObject("while", GrammarObjectType::NONTERMINAL)
	};
	/*end 2*/



	/*3*/
	vector<Rule> rules;
	GrammarObject terminal("E", GrammarObjectType::TERMINAL);
	vector<GrammarObject> rightPart = {
		GrammarObject("id", GrammarObjectType::NONTERMINAL),
		GrammarObject("A", GrammarObjectType::TERMINAL)
	};
	set<GrammarObject> guideSet = {
		GrammarObject("id", GrammarObjectType::NONTERMINAL)
	};
	/*end 3*/
	

	/*4*/
	vector<Rule> rules;
	GrammarObject terminal("A", GrammarObjectType::TERMINAL);
	vector<GrammarObject> rightPart = {
		GrammarObject("e", GrammarObjectType::EMPTY),
	};
	set<GrammarObject> guideSet = {
		GrammarObject("#", GrammarObjectType::NONTERMINAL),
		GrammarObject("do", GrammarObjectType::NONTERMINAL)
	};
	/*end 4*/


	/*5*/
	vector<Rule> rules;
	GrammarObject terminal("A", GrammarObjectType::TERMINAL);
	vector<GrammarObject> rightPart = {
		GrammarObject("+", GrammarObjectType::NONTERMINAL),
		GrammarObject("E", GrammarObjectType::TERMINAL),
		GrammarObject("A", GrammarObjectType::TERMINAL)
	};
	set<GrammarObject> guideSet = {
		GrammarObject("+", GrammarObjectType::NONTERMINAL)
	};
	/*end 5*/


	Rule rule(terminal, rightPart, guideSet);
	rules.push_back(rule);
	TableBuilder builder(rules);
    return 0;
}

