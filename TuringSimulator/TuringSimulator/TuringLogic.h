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
	//��������� ������, ���������� ����������
	//������� ������ ���������� ����� ���������, ���������� - ������, ������� ������� �������
	vector<vector<string>> instructions;
	// ������� ������� �� �������� �������� ������������ ����� 
	// ����� ���� ����� �� ����� ��������� ��������� ���������
	map<char, int> symbols;
	bool isRunning; //���������� �������� �� �������� (true - ���)
	string tape; //�����
	int state; //����� �������� ��������� �����
	int index; //������ ������ ��� ������� ��������� �������
public:
	//����������� 
	TuringMachine() {
		index = 0;
		state = 0;
		tape = "B";
		isRunning = 0;
	}
	TuringMachine(int a, int b, int s = 0, int in = 0) : state(s), index(in), isRunning(true) {
		//��������� �����
		string t(a, '1');
		t += 'B' + string(b, '1');
		tape = t;
		//���� � ������������
		/*
		�������
		���-�� ���������
		��������� � ����� �������: [��������� ������][����������� �������� R/L/H(halt)][��������� ���������]
		*/
		//����� �������� �� ����� ������ ���������� ������ ������� � � ����� ������� ���������
		ifstream ifs("instructions.txt");
		string alph;
		ifs >> alph; // ��������� �������
		int amountOfSymbols = alph.size();
		int i = 0;
		for (char c : alph) {
			symbols.insert(pair<char, int>(c, i)); //������� ������� � ������������� ������
			i++;
		}
		int amountOfStates;
		string str;
		ifs >> amountOfStates;
		//������� � ������ �������
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
	//������� ��� ���������� ����
	int move() {
		char symbol = tape[index]; //��������� ������
		int i = symbols.at(symbol); //���������� ����� ������� 
		string instruction = instructions[state][i]; //���������� � ������� �������
		tape[index] = instructions[state][i][0]; //���������� ����� ������ � ������� ������ 

		//���������� ������� � ������ �����������
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
		//���� ������� ������� �� ������� �������������� �����, ��������� ������ ������ � ������ �������
		if (index < 0) {
			index++;
			tape = 'B' + tape;
		}
		if (index == tape.size()) {
			tape += 'B';
		}
		state = atoi(instruction.substr(2).c_str()); // ���������� �������� ���������
		//���������� ����������� � ������� �������� ������
		return step;
	}
	int result() {
		return count(tape.begin(), tape.end(), '1');
	}
	int getNumberOfSymbol() {
		char symbol = tape[index]; //��������� ������
		int i = symbols.at(symbol); //���������� ����� �������
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



