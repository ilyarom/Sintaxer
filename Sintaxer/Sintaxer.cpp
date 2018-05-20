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
	vector<GrammarObject> guideSet = {
		GrammarObject("id", GrammarObjectType::NONTERMINAL)
	};
	/*end 1*/
	Rule rule(terminal, rightPart, guideSet);
	rules.push_back(rule);


	/*2*/
	terminal = GrammarObject("S", GrammarObjectType::TERMINAL);
	rightPart = {
		GrammarObject("while", GrammarObjectType::NONTERMINAL),
		GrammarObject("E", GrammarObjectType::TERMINAL),
		GrammarObject("do", GrammarObjectType::NONTERMINAL),
		GrammarObject("S", GrammarObjectType::TERMINAL),
		GrammarObject("#", GrammarObjectType::NONTERMINAL),
	};
	guideSet = {
		GrammarObject("while", GrammarObjectType::NONTERMINAL)
	};
	/*end 2*/

	rule = Rule(terminal, rightPart, guideSet);
	rules.push_back(rule);



	/*3*/
	terminal = GrammarObject("E", GrammarObjectType::TERMINAL);
	rightPart = {
		GrammarObject("id", GrammarObjectType::NONTERMINAL),
		GrammarObject("A", GrammarObjectType::TERMINAL)
	};
	guideSet = {
		GrammarObject("id", GrammarObjectType::NONTERMINAL)
	};
	/*end 3*/

	rule = Rule(terminal, rightPart, guideSet);
	rules.push_back(rule);
	

	/*4*/
	terminal = GrammarObject("A", GrammarObjectType::TERMINAL);
	rightPart = {
		GrammarObject("e", GrammarObjectType::EMPTY),
	};
	guideSet = {
		GrammarObject("#", GrammarObjectType::NONTERMINAL),
		GrammarObject("do", GrammarObjectType::NONTERMINAL)
	};
	/*end 4*/

	rule = Rule(terminal, rightPart, guideSet);
	rules.push_back(rule);


	/*5*/
	terminal = GrammarObject("A", GrammarObjectType::TERMINAL);
	rightPart = {
		GrammarObject("+", GrammarObjectType::NONTERMINAL),
		GrammarObject("E", GrammarObjectType::TERMINAL),
		GrammarObject("A", GrammarObjectType::TERMINAL)
	};
	guideSet = {
		GrammarObject("+", GrammarObjectType::NONTERMINAL)
	};
	/*end 5*/

	rule = Rule(terminal, rightPart, guideSet);
	rules.push_back(rule);


	
	TableBuilder builder(rules);
    return 0;
}

