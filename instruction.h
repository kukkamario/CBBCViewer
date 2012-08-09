#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <QtGlobal>
#include "precomp.h"
enum OpCode {
	OCUnknown = 0,
	OCPushInt,
	OCSetInt,
	OCSetFloat,
	OCCommand,
	OCData,
	OCPushSomething,
	OCJump,
	OCOperation,
	OCIncVar,
	OCIncGlobalVar,
	OCPushTypeMemberVariable,
	OCPushFuncPtr,
	OCPushVariable,
	OCFunction,
	OpCodeCount
};

void initCommandNames();
void initFunctionNames();

extern const char* OpCodeNames[OpCodeCount];

#define COMMAND_ARRAY_SIZE 800
extern char *commandNames[COMMAND_ARRAY_SIZE];

#define FUNCTION_ARRAY_SIZE 791
extern char *functionNames[FUNCTION_ARRAY_SIZE];

struct CBInstruction {
		CBInstruction() : mOpCode(OCUnknown), mData(0) {
		}
		CBInstruction(OpCode op, qint32 d) : mOpCode(op), mData(d) {}
		OpCode mOpCode;
		qint32 mData;
		QLinkedList<CBInstruction>::iterator mIterator;
};

inline ostream &operator << (ostream & s, const CBInstruction &i) {
	s << "<" << OpCodeNames[i.mOpCode] << ">";
	int len = 25 - strlen(OpCodeNames[i.mOpCode]);
	for (qint32 ii = 0; ii < len; ii++) {
		s << " ";
	}
	if (i.mOpCode == OCCommand) {
		if (commandNames[i.mData]) {
			s << commandNames[i.mData];
		}
		else {
			s << i.mData;
		}
	}
	else if (i.mOpCode == OCFunction) {
		if (functionNames[i.mData]) {
			s << functionNames[i.mData];
		}
		else {
			s << i.mData;
		}
	}
	else {
		s << i.mData;
	}
	return s;
}

#endif // INSTRUCTION_H
