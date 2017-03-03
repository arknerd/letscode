#include "Rifle.h"
#include <iomanip>


Rifle::Rifle() : m_manufacturer(), m_burstCap(), m_caliber(), m_roundsLeft() {}
Rifle::Rifle(string make, string caliber, string sn, bool mode, int fullMag) : m_manufacturer(make),
m_caliber(caliber), m_sn(sn), m_burstCap(mode), m_capacity(fullMag), m_roundsLeft(0) {}

Rifle::~Rifle()
{
}
int Rifle::getCapacity() { return m_capacity; }
string Rifle::getSerialNumber() { return m_sn; }
void Rifle::setManufacturer(string man) { m_manufacturer = man; }
void Rifle::setCaliber(string caliber) { m_caliber = caliber; }
void Rifle::setSerialNumber(string sn) { m_sn = sn; }
int Rifle::setCapacity(int fullMag) { return  m_capacity = fullMag; }


string Rifle::ToString()
{
	stringstream ss;
	ss << "This is a " << m_manufacturer << " " << m_caliber << " rifle, serial number: " << m_sn << endl;
	return ss.str();
}
int Rifle::setBurstCap(bool mode)
{
	if (mode == false)
	{
		m_burstCap = 0;
	}
	else
	{
		m_burstCap = 1;
	}
	return m_burstCap;
}
string Rifle::status()
{
	stringstream ss;
	if (m_burstCap == 1)
	{
		ss << m_manufacturer << " is firing " << m_burstRate << " round burst with " << m_roundsLeft << " rounds currently remaining\n";
	}
	else
	{
		ss << m_manufacturer << "is not capable of burst mode with " << m_roundsLeft << " rounds currently remaining\n";
	}
	return ss.str();
}



int Rifle::Automatic(int roundsPerBurst)
{
	if (m_burstCap == 1)
	{
		m_burstRate = roundsPerBurst;
		return m_burstRate;
	}

	return m_burstRate;
}

string Rifle::firing()
{
	stringstream ss;
	int rounds = 0, burst=m_burstRate;

	
	if (m_burstCap == 1)
	{
		while (m_roundsLeft > 0 && burst > 0)
		{
			ss << "bang ";
			--burst;
			--m_roundsLeft;
			
		}
		if (burst > 0)
		{
			ss << "click";
		}
	}
		else if (m_burstCap == 0)
		{
			if (m_roundsLeft > 0)
			{
				ss << "bang ";
				--m_roundsLeft;

			}
			else
			{
				ss <<"click";
			}
		}

	
	return ss.str();
}

int Rifle::Reload()
{
	int load;

	load = m_capacity - m_roundsLeft;
	m_roundsLeft = m_capacity;
	return load;
}

int Rifle::roundsRemaining()
{
	
	return m_roundsLeft;
}

string Rifle::getManufacturer() { return m_manufacturer; }

int Rifle::Unload()
{
	int unload;
	m_capacity = 0;
	unload = m_capacity;
	return unload;
	
}