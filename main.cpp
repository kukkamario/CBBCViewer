#include "precomp.h"
#include <iostream>
#include "bytecodereader.h"
using namespace std;


int main(int argc, char *argv[]) {
	if (argc == 2) {
		ByteCodeReader reader;
		if (reader.readCBExecutable(QString(argv[1]))) {
			reader.byteCode().print();
		}
	}
	else {
		cerr << "Usage: CBBCViewer.exe <file>" << endl;
		return -1;
	}
	return 0;
}
