#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Rifle
{
private:
	string m_manufacturer, m_caliber, m_sn;
	int m_burstRate, m_capacity, m_roundsLeft;
	bool m_burstCap;
public:

	Rifle();
	Rifle(string make, string caliber, string sn, bool mode, int capacity);

	~Rifle();
	string getManufacturer();
	int getCapacity();
	string getSerialNumber();
	string ToString();
	string status();
	string firing();

	void setManufacturer(string man);
	void setCaliber(string caliber);
	void setSerialNumber(string);
	int setCapacity(int full);
	int Automatic(int roundsPerBurst);

	int Unload();
	int setBurstCap(bool mode);
	int Reload();
	int roundsRemaining();
};

//int getCapacity();//?
//int roundsRemaining(); remaining ammo
