#include<iostream>
#include<string>
using namespace std;
 
class Device {
private:
	string name;
	string model;
	string version;
 
public:
	Device(string nameArg, string modelArg,string versionArg) : name{nameArg} ,model{modelArg},version{versionArg}{
		cout << "Device constructor called" << endl;
	}
	~Device() {
		cout << "Device Destructed" << endl;
	}
};

class Printer:virtual public Device{
public:
	Printer() :Device{"","",""}{
		cout << "Printer constructor called"<<endl;
	}
	~Printer() {
		cout << "Printer Destructed" << endl;
	}
	void print(string content) {
		cout << "Print " << content << endl;
	}
};

class Scanner:virtual public Device{
public:
	Scanner() : Device{"","",""}{
		cout << "Scanner constructor called" << endl;
	}
	~Scanner() {
		cout << "Scanner Destructed" << endl;
	}
	void scan(string content) {
		cout << "Scan " << content << endl;
	}
};

class PrintScanner :public Printer, public Scanner {  //never do this as it is a crime which cpp supports./..
public:
	PrintScanner(string n, string m,string v) : Device{n,m,v} {
		cout << "PrintScanner constructor called" << endl;
	}
	~PrintScanner() {
		cout << "PrintScanner Destructed" << endl;
	}
};

class TaskManager {
public:
	void invokePrintTask(Printer* printerPtr, string content) {
		printerPtr->print(content);
	}
	void invokeScanTask(Scanner* scannerPtr, string content) {
		scannerPtr->scan(content);
	}
};

int main() {
	/*Printer hpPrinter;
	Scanner hpScanner;*/
	PrintScanner hpPrintScanner("","","");
	TaskManager taskMgr;
	/*taskMgr.invokePrintTask(&hpPrinter, "doc.pdf");
	taskMgr.invokeScanTask(&hpScanner, "doc.pdf");*/
	taskMgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
	taskMgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
}