#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class TuringMachine {
private:
	//двумерный массив, содержащий инструкции
	//внешний вектор определ€ет номер состо€ни€, внутренний - символ, который считала каретка
	vector<vector<string>> instructions;
	// каждому символу из входного алфавита соответсвует число 
	// чтобы было легче по букве вычисл€ть следующее состо€ние
	map<char, int> symbols;
	bool isRunning; //определ€ет завершен ли алгоритм (true - нет)
	string tape; //лента
	int state; //номер текущего состо€ни€ машин
	int index; //индекс €чейки над которой находитс€ каретка
public:
	//конструктор 
	TuringMachine() {
		index = 0;
		state = 0;
		tape = "B";
		isRunning = 0;
	}
	TuringMachine(int a, int b, int s = 0, int in = 0) : state(s), index(in), isRunning(true) {
		//заполн€ет ленту
		string t(a, '1');
		t += 'B' + string(b, '1');
		tape = t;
		//файл с инструкци€ми
		/*
		алфавит
		кол-во состо€ний
		состо€ни€ в таком формате: [считанный символ][направлени€ движени€ R/L/H(halt)][следующее состо€ние]
		*/
		//можно заменить на любые другие инструкции любого размера и с любым входным алфавитом
		ifstream ifs("instructions.txt");
		string alph;
		ifs >> alph; // считывает алфавит
		int amountOfSymbols = alph.size();
		int i = 0;
		for (char c : alph) {
			symbols.insert(pair<char, int>(c, i)); //заносит символы в ассоциативный массив
			i++;
		}
		int amountOfStates;
		string str;
		ifs >> amountOfStates;
		//заносит в массив правила
		for (int i = 0; i < amountOfStates; i++) {
			vector<string> instruction;
			for (int j = 0; j < amountOfSymbols; j++) {
				ifs >> str;
				instruction.push_back(str);
			}
			instructions.push_back(instruction);
		}
		ifs.close();
	};
	//функци€ дл€ совершени€ шага
	int move() {
		char symbol = tape[index]; //считываем символ
		int i = symbols.at(symbol); //определ€ем номер символа 
		string instruction = instructions[state][i]; //обращаемс€ к нужному правилу
		tape[index] = instructions[state][i][0]; //записываем новый символ в текущую €чейку 

		//перемещаем каретку в нужном направлении
		int step = 0;
		switch (instructions[state][i][1]) {
		case 'R': step = 1;
			break;
		case 'L': step = -1;
			break;
		case 'H': isRunning = false;
			break;
		default:
			break;
		}
		index += step;
		//если каретка выходит за пределы сформированной ленты, добавл€ем пустую €чейку с нужной стороны
		if (index < 0) {
			index++;
			tape = 'B' + tape;
		}
		if (index == tape.size()) {
			tape += 'B';
		}
		state = atoi(instruction.substr(2).c_str()); // определ€ем следущее состо€ние
		//возвращаем направление в которую сдвинули €чейку
		return step;
	}
	int result() {
		return count(tape.begin(), tape.end(), '1');
	}
	int getNumberOfSymbol() {
		char symbol = tape[index]; //считываем символ
		int i = symbols.at(symbol); //определ€ем номер символа
		return i;
	}
	char getSymbolAt(int i) {
		return tape[i];
	}
	int getState() { return state; }
	int getIndex() { return index; }
	string getTape() { return tape; }
	bool running() { return isRunning; }
	vector<vector<string>>& getinstructions() { return instructions; }
};



