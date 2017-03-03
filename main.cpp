#include "Rifle.h"

void buildRifle(Rifle &blank);



void main()

{
	Rifle blank;
	Rifle colt("Colt", "5.56mm", "RCOLT-0001", 1, 20);
	Rifle rugar("Rugar", ".22", "R22-0001", 0, 10);
	string manufacturer;
	/*int rounds, burst, shotsToBeFires;*/
	/*int capacity;*/

	/*This is a rifle...*/
	cout << blank.ToString();
	cout << colt.ToString();
	cout << rugar.ToString();
	cin.get();
	/*end*/


	/*SN, [roundsPerBurst]*/

	colt.Automatic(1);
	cout << colt.status();
	cout << rugar.status();
	cin.get(), cin.get();
	cout << "Loading weapons....\n";
	/*end*/
	cin.get();


	/*loading*/
	cout << colt.getSerialNumber() << ": " << colt.Reload() << " rounds loaded\n";
	cout << rugar.getSerialNumber() << ": " << rugar.Reload() << " rounds loaded\n";
	cin.get();
	/*end*/


	/*fire colt*/
	cout << "Fire " << colt.getSerialNumber() << " in automatic mode.....\n";
	colt.Automatic(3);
	colt.Reload();
	while (colt.roundsRemaining() > 0)
	{
		cout << colt.firing() << endl;
	}
	cin.get(); cin.get();
	/*end*/

	/*fire Rugar*/
	cout << "Fire " << rugar.getSerialNumber() << " in automatic mode.....\n";
	rugar.Automatic(1);
	rugar.Reload();
	cout << rugar.firing() << endl;
	cout << rugar.firing();
	cin.get(), cin.get();
	/*end*/

	/*Status*/
	cout << colt.status();
	cout << rugar.status();
	cin.get(), cin.get();
	/*end*/

	buildRifle(blank);
	cout << blank.ToString();
	cin.get(), cin.get();

}
void buildRifle(Rifle &blank)
{
	string newRifle;
	int newInfo;

	cout << "Enter the manufacturer : ";
	cin >> newRifle;
	blank.setManufacturer(newRifle);
	cin.get();

	cout << "Enter caliber: ";
	cin >> newRifle;
	blank.setCaliber(newRifle);

	cout << "Can this rifle fire in burst mode (y/n)";
	cin >> newRifle;
	if (newRifle == "y" || newRifle =="Y")
	{
		blank.setBurstCap(true);
	}
	else
	{
		blank.setBurstCap(false);
	}
	

	cout << "What is the magazine capacity? ";
	cin >> newInfo;
	blank.setCapacity(newInfo);
	
	cout << "Enter ssn: ";
	cin >> newRifle;
	blank.setSerialNumber(newRifle);




}