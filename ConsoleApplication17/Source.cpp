#include <iostream>
#include <string>
using namespace std;

class Level1 
{
	friend class EnemyShip1;
protected:
	int ShieldEnergy;
	int ShieldPhysical;
	int DamageLasers;
	int DamageTorpedos;
public:
	int Health;
	int SEused;
	int SPused;
	bool SEon;
	bool SPon;
	//constructors
	Level1()
	{
		Health = 2000;
		ShieldEnergy = 400;
		SEon=0;
		ShieldPhysical = 400;
		SPon=0;
		SEused=0;
		SPused=0;
		DamageLasers = 400;
		DamageTorpedos = 400;
	}
	int getHealth()
	{
		return Health;
	}
	int getSE()
	{
		return SEused;
	}
	bool getSEon()
	{
		return SEon;
	}
	int getSP()
	{
		return SPused;
	}
	bool getSPon()
	{
		return SPon;
	}
	virtual void ShieldE()
	{
		SEon = 1;
		SEused = ShieldEnergy;
	}
	virtual void ShieldP()
	{
		SPon=1;
		SPused = ShieldPhysical;
	}
	virtual void Lasers(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon)
		{
			if ((ESE -= DamageLasers*2/3)<=0)
			{
				EHealth = EHealth + ESE - DamageLasers;
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= DamageLasers/3;
				ESE -= DamageLasers*2/3;
			}
		}
		else EHealth -= DamageLasers;
	}
	virtual void Torpedos (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon)
		{
			if ((ESP -= DamageTorpedos*2/3)<=0)
			{
				EHealth = EHealth + ESP - DamageTorpedos;
				ESPon=0;
				ESP = 0;
			}
			else
			{
				EHealth -= DamageTorpedos/3;
				ESP -= DamageTorpedos*2/3;
			}
		}
		else EHealth -= DamageTorpedos;
	}
	virtual void LightTurrets(bool&, int&, int&){};
	virtual void PoloronCanon(bool&, int&, int&){};
	virtual void KiloprotonTorpedoes(bool&, int&, int&){};
	virtual void IonBlaster(bool&, int&, int&){};
}; 
class Level2 : public Level1
{
	friend class EnemyShip2;
protected:
	int ShieldEnergyUP;
	int ShieldPhysicalUP;
	int DamageLasersUP;
	int DamageTorpedosUP;
	int DamageLightTurrets;
	int DamagePoloronCanon;
public:
	//constructors
	Level2()
	{
		Health = 3000;
		ShieldEnergyUP = 300;
		SEon=0;
		ShieldPhysicalUP = 300;
		SPon=0;
		SEused=0;
		SPused=0;
		DamageLasersUP = 200;
		DamageTorpedosUP = 200;
		DamageLightTurrets = 700;
		DamagePoloronCanon = 750;
	}
	int getHealth()
	{
		return Health;
	}
	void setHealth(int a)
	{
		Health = a;
	}
	int getSE()
	{
		return SEused;
	}
	bool getSEon()
	{
		return SEon;
	}
	int getSP()
	{
		return SPused;
	}
	bool getSPon()
	{
		return SPon;
	}
	virtual void ShieldE()
	{
		Level1::ShieldE();
		SEused += ShieldEnergyUP;
	}
	virtual void ShieldP()
	{
		Level1::ShieldP();
		SPused += ShieldPhysicalUP;
	}
	virtual void Lasers(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= (DamageLasers+DamageLasersUP)*2/3)<=0)
			{
				EHealth = EHealth + ESE - (DamageLasers+DamageLasersUP);
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= (DamageLasers+DamageLasersUP)/3;
				ESE -= (DamageLasers+DamageLasersUP)*2/3;
			}
		}
		else EHealth -= (DamageLasers+DamageLasersUP);
	}
	virtual void Torpedos (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= (DamageTorpedos+DamageTorpedosUP)*2/3)<=0)
			{
				EHealth = EHealth + ESP - (DamageTorpedos+DamageTorpedosUP);
				ESPon=0;
				ESP = 0;
			}
			else
			{
			EHealth -= (DamageTorpedos+DamageTorpedosUP)/3;
			ESP -= (DamageTorpedos+DamageTorpedosUP)*2/3;
			}
		}
		else EHealth -= (DamageTorpedos+DamageTorpedosUP);
	}
	virtual void LightTurrets(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= DamageLightTurrets*2/3)<=0)
			{
				EHealth = EHealth + ESE - DamageLightTurrets;
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= DamageLightTurrets/3;
				ESE -= DamageLightTurrets*2/3;
			}
		}
		else EHealth -= DamageLightTurrets;
	}
	virtual void PoloronCanon (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= DamagePoloronCanon*2/3)<=0)
			{
				EHealth = EHealth + ESP - DamagePoloronCanon;
				ESPon=0;
				ESP = 0;
			}
			else
			{
				EHealth -= DamagePoloronCanon/3;
				ESP -= DamagePoloronCanon*2/3;
			}
		}
		else EHealth -= DamagePoloronCanon;
	}
	virtual void KiloprotonTorpedoes(bool&, int&, int&){};
	virtual void IonBlaster(bool&, int&, int&){}; 
};
class Level3 : public Level2
{
	friend class MotherShip;
protected:
	int ShieldEnergyUPUP;
	int ShieldPhysicalUPUP;
	int DamageLasersUPUP;
	int DamageTorpedosUPUP;
	int DamageLightTurretsUP;
	int DamagePoloronCanonUP;
	int DamageKiloprotonTorpedoes;
	int DamageIonBlaster;
public:
	Level3() 
	{
		Health = 4500;
		ShieldEnergyUPUP = 500;
		SEon=0;
		ShieldPhysicalUPUP = 500;
		SPon=0;
		SEused=0;
		SPused=0;
		DamageLasersUPUP = 250;
		DamageTorpedosUPUP = 250;
		DamageLightTurretsUP = 350;
		DamagePoloronCanonUP = 400;
		DamageKiloprotonTorpedoes = 1300;
		DamageIonBlaster = 1300;
	}
	int getHealth()
	{
		return Health;
	}
	void setHealth(int a)
	{
		Health = a;
	}
	int getSE()
	{
		return SEused;
	}
	bool getSEon()
	{
		return SEon;
	}
	int getSP()
	{
		return SPused;
	}
	virtual void ShieldE()
	{
		Level2::ShieldE();
		SEused += ShieldEnergyUPUP;
	}
	virtual void ShieldP()
	{
		Level2::ShieldP();
		SPused += ShieldPhysicalUPUP;
	}
	virtual void Lasers(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= (DamageLasers+DamageLasersUP+DamageLasersUPUP)*2/3)<=0)
			{
				EHealth = EHealth + ESE - (DamageLasers+DamageLasersUP+DamageLasersUPUP);
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= (DamageLasers+DamageLasersUP+DamageLasersUPUP)/3;
				ESE -= (DamageLasers+DamageLasersUP+DamageLasersUPUP)*2/3;
			}
		}
		else EHealth -= (DamageLasers+DamageLasersUP+DamageLasersUPUP);
	}
	virtual void Torpedos (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= (DamageTorpedos+DamageTorpedosUP+DamageTorpedosUPUP)*2/3)<=0)
			{
				EHealth = EHealth + ESP - (DamageTorpedos+DamageTorpedosUP+DamageTorpedosUPUP);
				ESPon=0;
				ESP = 0;
			}
			else
			{
			EHealth -= (DamageTorpedos+DamageTorpedosUP+DamageTorpedosUPUP)/3;
			ESP -= (DamageTorpedos+DamageTorpedosUP+DamageTorpedosUPUP)*2/3;
			}
		}
		else EHealth -= (DamageTorpedos+DamageTorpedosUP+DamageTorpedosUPUP);
	}
	virtual void LightTurrets(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= (DamageLightTurrets+DamageLightTurretsUP)*2/3)<=0)
			{
				EHealth = EHealth + ESE - (DamageLightTurrets+DamageLightTurretsUP);
				ESEon=0;
				ESE = 0;
			}
			else
			{
			EHealth -= (DamageLightTurrets+DamageLightTurretsUP)/3;
			ESE -= (DamageLightTurrets+DamageLightTurretsUP)*2/3;
			}
		}
		else EHealth -= (DamageLightTurrets+DamageLightTurretsUP);
	}
	virtual void PoloronCanon (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= (DamagePoloronCanon+DamagePoloronCanonUP)*2/3)<=0)
			{
				EHealth = EHealth + ESP - (DamagePoloronCanon+DamagePoloronCanonUP);
				ESPon=0;
				ESP = 0;
			}
			else
			{
			EHealth -= (DamagePoloronCanon+DamagePoloronCanonUP)/3;
			ESP -= (DamagePoloronCanon+DamagePoloronCanonUP)*2/3;
			}
		}
		else EHealth -= (DamagePoloronCanon+DamagePoloronCanonUP);
	}
	virtual void KiloprotonTorpedoes(bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= DamageKiloprotonTorpedoes*2/3)<=0)
			{
				EHealth = EHealth + ESP - DamageKiloprotonTorpedoes;
				ESPon=0;
				ESP = 0;
			}
			else
			{
				EHealth -= DamageKiloprotonTorpedoes/3;
				ESP -= DamageKiloprotonTorpedoes*2/3;
			}
		}
		else EHealth -= DamageKiloprotonTorpedoes;
	}
	virtual void IonBlaster(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= DamageIonBlaster*2/3)<=0)
			{
				EHealth = EHealth + ESE - DamageIonBlaster;
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= DamageIonBlaster/3;
				ESE -= DamageIonBlaster*2/3;
			}
		}
		else EHealth -= DamageIonBlaster;
	}
};

class EnemyShip1
{
	friend class Level1;
protected:
	int ShieldEnergy;
	int ShieldPhysical;
	int DamageBlasters;
	int DamageCanons;
public:
	int Health;
	int SEused;
	int SPused;
	bool SPon;
	bool SEon;
	//constructors
	EnemyShip1()
	{
		Health = 3000;
		ShieldEnergy = 500;
		SEon=0;
		ShieldPhysical = 200;
		SPon=0;
		SEused=0;
		SPused=0;
		DamageBlasters = 500;
		DamageCanons = 250;
	}
	int getHealth()
	{
		return Health;
	}
	void setHealth(int a)
	{
		Health = a;
	}
	int getSE()
	{
		return SEused;
	}
	void setSE(int a)
	{
		SEused = a;
	}
	bool getSEon()
	{
		return SEon;
	}
	int getSP()
	{
		return SPused;
	}
	bool getSPon()
	{
		return SPon;
	}
	virtual void ShieldE()
	{
		SEon = 1;
		SEused = ShieldEnergy;
	}
	virtual void ShieldP()
	{
		SPon=1;
		SPused = ShieldPhysical;
	}
	virtual void Blasters(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= DamageBlasters*2/3)<=0)
			{
				EHealth = EHealth + ESE - DamageBlasters;
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= DamageBlasters/3;
				ESE -= DamageBlasters*2/3;
			}
		}
		else EHealth -= DamageBlasters;
	}
	virtual void Canons (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= DamageCanons*2/3)<=0)
			{
				EHealth = EHealth + ESP - DamageCanons;
				ESPon=0;
				ESP = 0;
			}
			else
			{
				EHealth -= DamageCanons/3;
				ESP -= DamageCanons*2/3;
			}
		}
		else EHealth -= DamageCanons;
	}
	virtual void PlasmaBeam(bool&, int&, int&){};
	virtual void QuantumRailgun(bool&, int&, int&){};
	virtual void NovaCanon(bool&, int&, int&){};
	virtual void WaveMotionBlaster(bool&, int&, int&){};
};
class EnemyShip2 : public EnemyShip1
{
	friend class Level2;
protected:
	int ShieldEnergyUP;
	int ShieldPhysicalUP;
	int DamageBlastersUP;
	int DamageCanonsUP;
	int DamagePlasmaBeam;
	int DamageQuantumRailgun;
public:
	//constructors
	EnemyShip2()
	{
		Health = 4000;
		ShieldEnergyUP = -100;
		SEon=0;
		ShieldPhysicalUP = 400;
		SPon=0;
		SEused=0;
		SPused=0;
		DamageBlastersUP = -100;
		DamageCanonsUP = 200;
		DamagePlasmaBeam = 500;
		DamageQuantumRailgun = 750;
	}
	int getHealth()
	{
		return Health;
	}
	void setHealth(int a)
	{
		Health = a;
	}
	int getSE()
	{
		return SEused;
	}
	bool getSEon()
	{
		return SEon;
	}
	int getSP()
	{
		return SPused;
	}
	bool getSPon()
	{
		return SPon;
	}
	virtual void ShieldE()
	{
		EnemyShip1::ShieldE();
		SEused += ShieldEnergyUP;
	}
	virtual void ShieldP()
	{
		EnemyShip1::ShieldP();
		SPused += ShieldPhysicalUP;
	}
	virtual void Blasters(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= (DamageBlasters+DamageBlastersUP)*2/3)<=0)
			{
				EHealth = EHealth + ESE - (DamageBlasters+DamageBlastersUP);
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= (DamageBlasters+DamageBlastersUP)/3;
				ESE -= (DamageBlasters+DamageBlastersUP)*2/3;
			}
		}
		else EHealth -= (DamageBlasters+DamageBlastersUP);
	}
	virtual void Canons (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= (DamageCanons+DamageCanonsUP)*2/3)<=0)
			{
				EHealth = EHealth + ESP - (DamageCanons+DamageCanonsUP);
				ESPon=0;
				ESP = 0;
			}
			else
			{
			EHealth -= (DamageCanons+DamageCanonsUP)/3;
			ESP -= (DamageCanons+DamageCanonsUP)*2/3;
			}
		}
		else EHealth -= (DamageCanons+DamageCanonsUP);
	}
	virtual void PlasmaBeam(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= DamagePlasmaBeam*2/3)<=0)
			{
				EHealth = EHealth + ESE - DamagePlasmaBeam;
				ESE=0;
				ESE = 0;
			}
			else
			{
				EHealth -= DamagePlasmaBeam/3;
				ESE -= DamagePlasmaBeam*2/3;
			}
		}
		else EHealth -= DamagePlasmaBeam;
	}
	virtual void QuantumRailgun (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= DamageQuantumRailgun*2/3)<=0)
			{
				EHealth = EHealth + ESP - DamageQuantumRailgun;
				ESP=0;
				ESP = 0;
			}
			else
			{
				EHealth -= DamageQuantumRailgun/3;
				ESP -= DamageQuantumRailgun*2/3;
			}
		}
		else EHealth -= DamageQuantumRailgun;
	}
	virtual void NovaCanon(bool&, int&, int&){};
	virtual void WaveMotionBlaster(bool&, int&, int&){};
};
class MotherShip : public EnemyShip2
{
	friend class Level3;
protected:
	int ShieldEnergyUPUP;
	int ShieldPhysicalUPUP;
	int DamageBlastersUPUP;
	int DamageCanonsUPUP;
	int DamagePlasmaBeamUP;
	int DamageQuantumRailgunUP;
	int DamageNovaCanon;
	int DamageWaveMotionBlaster;
public:
	MotherShip() 
	{
		Health = 5500;
		ShieldEnergyUPUP = 200;
		SEon=0;
		ShieldPhysicalUPUP = 100;
		SPon=0;
		SEused=0;
		SPused=0;
		DamageBlastersUPUP = 250;
		DamageCanonsUPUP = 250;
		DamagePlasmaBeamUP = 350;
		DamageQuantumRailgunUP = 150;
		DamageNovaCanon = 1300;
		DamageWaveMotionBlaster = 1300;
	}
	int getHealth()
	{
		return Health;
	}
	void setHealth(int a)
	{
		Health = a;
	}
	int getSE()
	{
		return SEused;
	}
	int getSP()
	{
		return SPused;
	}
	virtual void ShieldE()
	{
		EnemyShip2::ShieldE();
		SEused += ShieldEnergyUPUP;
	}
	virtual void ShieldP()
	{
		EnemyShip2::ShieldP();
		SPused += ShieldPhysicalUPUP;
	}
	virtual void Blasters(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= (DamageBlasters+DamageBlastersUP+DamageBlastersUPUP)*2/3)<=0)
			{
				EHealth = EHealth + ESE - (DamageBlasters+DamageBlastersUP+DamageBlastersUPUP);
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= (DamageBlasters+DamageBlastersUP+DamageBlastersUPUP)/3;
				ESE -= (DamageBlasters+DamageBlastersUP+DamageBlastersUPUP)*2/3;
			}
		}
		else EHealth -= (DamageBlasters+DamageBlastersUP+DamageBlastersUPUP);
	}
	virtual void Canons (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= (DamageCanons+DamageCanonsUP+DamageCanonsUPUP)*2/3)<=0)
			{
				EHealth = EHealth + ESP - (DamageCanons+DamageCanonsUP+DamageCanonsUPUP);
				ESPon=0;
				ESP = 0;
			}
			else
			{
			EHealth -= (DamageCanons+DamageCanonsUP+DamageCanonsUPUP)/3;
			ESP -= (DamageCanons+DamageCanonsUP+DamageCanonsUPUP)*2/3;
			}
		}
		else EHealth -= (DamageCanons+DamageCanonsUP+DamageCanonsUPUP);
	}
	virtual void PlasmaBeam(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= (DamagePlasmaBeam+DamagePlasmaBeamUP)*2/3)<=0)
			{
				EHealth = EHealth + ESE - (DamagePlasmaBeam+DamagePlasmaBeamUP);
				ESEon=0;
				ESE = 0;
			}
			else
			{
			EHealth -= (DamagePlasmaBeam+DamagePlasmaBeamUP)/3;
			ESE -= (DamagePlasmaBeam+DamagePlasmaBeamUP)*2/3;
			}
		}
		else EHealth -= (DamagePlasmaBeam+DamagePlasmaBeamUP);
	}
	virtual void QuantumRailgun (bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= (DamageQuantumRailgun+DamageQuantumRailgunUP)*2/3)<=0)
			{
				EHealth = EHealth + ESP - (DamageQuantumRailgun+DamageQuantumRailgunUP);
				ESPon=0;
				ESP = 0;
			}
			else
			{
			EHealth -= (DamageQuantumRailgun+DamageQuantumRailgunUP)/3;
			ESP -= (DamageQuantumRailgun+DamageQuantumRailgunUP)*2/3;
			}
		}
		else EHealth -= (DamageQuantumRailgun+DamageQuantumRailgunUP);
	}
	virtual void NovaCanon(bool& ESPon, int& EHealth, int& ESP)
	{
		if (ESPon == 1)
		{
			if ((ESP -= DamageNovaCanon*2/3)<=0)
			{
				EHealth = EHealth + ESP - DamageNovaCanon;
				ESPon=0;
				ESP = 0;
			}
			else
			{
				EHealth -= DamageNovaCanon/3;
				ESP -= DamageNovaCanon*2/3;
			}
		}
		else EHealth -= DamageNovaCanon;
	}
	virtual void WaveMotionBlaster(bool& ESEon, int& EHealth, int& ESE)
	{
		if (ESEon == 1)
		{
			if ((ESE -= DamageWaveMotionBlaster*2/3)<=0)
			{
				EHealth = EHealth + ESE - DamageWaveMotionBlaster;
				ESEon=0;
				ESE = 0;
			}
			else
			{
				EHealth -= DamageWaveMotionBlaster/3;
				ESE -= DamageWaveMotionBlaster*2/3;
			}
		}
		else EHealth -= DamageWaveMotionBlaster;
	}
};


int main ()
{
	cout<<"\n\n			WELCOME TO \"VORTEX ESCAPE\"\n\n\n";
	cout<<"Choose a name for your spaceship!\n";
	string nm;
	cin>>nm;
	cout<<"\n\nThe story so far\n";
	cout<<nm<<" was on a mission to search for an inhabitable planet in the galaxy Zirius."<<endl;
	cout<<"While traveling in hiperspace the ship passed right next to a black hole."<<endl;
	cout<<"The gravitation got the spaceship out of course and towards a vortex leading to another dimension."<<endl;
	cout<<"Not knowing about the threat, the ship's crew got stranded on the other side of the vortex."<<endl;
	cout<<"However, passing through the wormhole damaged severely the spaceship. By the time the mechanics"<<endl;
	cout<<"fixed the damage, the ship was already drifted far away into the other dimension's galaxy."<<endl;
	cout<<"Now the ship is on its way to the vortex but a race called the Sclitex had detected the foreign"<<endl;
	cout<<"ship and watnts to get a hold on the technology on "<<nm<<endl<<endl;
	cout<<"			Now you have to defeat the enemy ships that "<<endl;
	cout<<"				are blocking the way to the vortex!"<<endl;
	//collection of objects for the different levels
	Level1 *a[] = {new Level1, new Level2, new Level3};
	EnemyShip1 *b[] = {new EnemyShip1, new EnemyShip2, new MotherShip};
	cout<<"\n				STAGE 1"<<endl;
	cout<<"\n\n		INFORMATION TECHNOLOGY"<<endl;
	cout<<"The enemy ship's total health is 3000\n"<<endl;
	cout<<"The energy weapons as well as the energy shield are with higher priority\n"<<endl;
	cout<<"Energy Shield absorbs 500 damage, energy weapons(1) inflict 500 damage"<<endl;
	cout<<"Physical Shield absorbs 200 damage, physical weapons(1) inflict 250 damage"<<endl;
	//energy and physical attacks
	int EA = 0;
	int PA = 0;
	//stage 1
	do
	{
		cout<<"\n\nACTION"<<endl;
		cout<<"\nDefence:"<<endl;
		cout<<"	1.Activate Energy Shield (400)"<<endl;
		cout<<"	2.Activate Physical Shield (400)"<<endl;
		cout<<"Offence:"<<endl;
		cout<<"	3.Lasers(400)"<<endl;
		cout<<"	4.Torpedoes(400)"<<endl;
		int i;
		do
		{
		cin>>i;
		switch (i)
			{
			case 1: 
				a[0]->ShieldE();
				break;
			case 2: 
				a[0]->ShieldP();
				break;
			case 3:
				a[0]->Lasers(b[0]->SEon,b[0]->Health,b[0]->SEused);
				EA++;
				break;
			case 4: 
				a[0]->Torpedos(b[0]->SPon,b[0]->Health,b[0]->SPused);
				PA++;
				break;
			default:
				cout <<endl<< "Invalid action!" << endl;
			}
		cout<<nm<<" health:           "<<a[0]->getHealth()<<endl;
		cout<<nm<<" energy shields:   "<<a[0]->getSE()<<endl;
		cout<<nm<<" physical shields: "<<a[0]->getSP()<<endl;
		cout<<"Enemy's health:           "<<b[0]->getHealth()<<endl;
		cout<<"Enemy's energy shields:   "<<b[0]->getSE()<<endl;
		cout<<"Enemy's physical shields: "<<b[0]->getSP()<<endl;
		break;
		}
		while ((i!=1)||(i!=2)||(i!=3)||(i!=4));
		if (b[0]->getHealth()>0)
		{
			if (EA==2)
			{
				b[0]->ShieldE();
				cout<<endl<<"\nThe enemy just activated their Energy Shield"<<endl;
				EA=0;
			}
			else 
				if (PA==2)
				{
					b[0]->ShieldP();
					cout<<endl<<"\nThe enemy just activated their Physical Shield"<<endl;
					PA=0;  
				}
				else 
					if (a[0]->getSEon())
					{
						b[0]->Canons(a[0]->SPon,a[0]->Health,a[0]->SPused);
						cout<<endl<<"You were just attacked with Cannons"<<endl;
					}	
					else 
					{
						b[0]->Blasters(a[0]->SEon,a[0]->Health,a[0]->SEused);
						cout<<endl<<"You were just attacked with Blasters"<<endl;
					}
		}
		cout<<nm<<" health:           "<<a[0]->getHealth()<<endl;
		cout<<nm<<" energy shields:   "<<a[0]->getSE()<<endl;
		cout<<nm<<" physical shields: "<<a[0]->getSP()<<endl;
		cout<<"Enemy's health:           "<<b[0]->getHealth()<<endl;
		cout<<"Enemy's energy shields:   "<<b[0]->getSE()<<endl;
		cout<<"Enemy's physical shields: "<<b[0]->getSP()<<endl;
	}
	while ((a[0]->getHealth() > 0)&&(b[0]->getHealth() > 0));

	if (a[0]->getHealth() <= 0) cout<<"\n\n\n			YOUR SHIP WAS DESTROYED!\n\n\n";
	else cout<<"			COOD JOB!"<<endl<<"You defeated the first enemy spaceship."<<
		endl<<"Your mechanics got good ideas for improving the ship"<<endl<<
		"from the parts left from the enemy spaceship."<<endl<<endl<<"Your weapons and shields are now improved"<<endl
		<<"and you have 2 new weapons"<<endl<<endl<<"		STAGE 2\n\n";

	do
	{
		if (a[0]->getHealth() <= 0) break;
		cout<<"\n\nACTION"<<endl;
		cout<<"\nDefence:"<<endl;
		cout<<"	1.Activate Energy Shield (700)"<<endl;
		cout<<"	2.Activate Physical Shield (700)"<<endl;
		cout<<"Offence:"<<endl;
		cout<<"	3.Lasers(600)"<<endl;
		cout<<"	4.Torpedoes(600)"<<endl;
		cout<<"	5.Light Turrets(700)"<<endl;
		cout<<"	6.Poloron Cannon(750)"<<endl;
		int i;
		do
		{
		cin>>i;
		switch (i)
			{
			case 1: 
				a[1]->ShieldE();
				break;
			case 2: 
				a[1]->ShieldP();
				break;
			case 3:
				a[1]->Lasers(b[1]->SEon,b[1]->Health,b[1]->SEused);
				EA++;
				break;
			case 4: 
				a[1]->Torpedos(b[1]->SPon,b[1]->Health,b[1]->SPused);
				PA++;
				break;
			case 5:
				a[1]->LightTurrets(b[1]->SEon,b[1]->Health,b[1]->SEused);
				EA++;
				break;
			case 6:
				a[1]->PoloronCanon(b[1]->SPon,b[1]->Health,b[1]->SPused);
				PA++;
				break;
			default:
				cout <<endl<< "Invalid action!" << endl;
			}
		cout<<nm<<" health:           "<<a[1]->getHealth()<<endl;
		cout<<nm<<" energy shields:   "<<a[1]->getSE()<<endl;
		cout<<nm<<" physical shields: "<<a[1]->getSP()<<endl;
		cout<<"Enemy's health:           "<<b[1]->getHealth()<<endl;
		cout<<"Enemy's energy shields:   "<<b[1]->getSE()<<endl;
		cout<<"Enemy's physical shields: "<<b[1]->getSP()<<endl;
		break;
		}
		while ((i!=1)||(i!=2)||(i!=3)||(i!=4)||(i!=5)||(i!=6));
		if (b[1]->getHealth()>0)
		{
			if (EA==2)
			{
				b[1]->ShieldE();
				cout<<endl<<"\nThe enemy just activated their Energy Shield"<<endl;
				EA=0;
			}
			else 
				if (PA==2)
				{
					b[1]->ShieldP();
					cout<<endl<<"\nThe enemy just activated their Physical Shield"<<endl;
					PA=0;  
				}
				else 
					if (a[1]->getSEon())
					{
						b[1]->PlasmaBeam(a[1]->SPon,a[1]->Health,a[1]->SPused);
						cout<<endl<<"You were just attacked with Plasma Beam"<<endl;
					}	
					else 
					{
						b[1]->QuantumRailgun(a[1]->SEon,a[1]->Health,a[1]->SEused);
						cout<<endl<<"You were just attacked with Quantum Railgun"<<endl;
					}
		}
		cout<<nm<<" health:           "<<a[1]->getHealth()<<endl;
		cout<<nm<<" energy shields:   "<<a[1]->getSE()<<endl;
		cout<<nm<<" physical shields: "<<a[1]->getSP()<<endl;
		cout<<"Enemy's health:           "<<b[1]->getHealth()<<endl;
		cout<<"Enemy's energy shields:   "<<b[1]->getSE()<<endl;
		cout<<"Enemy's physical shields: "<<b[1]->getSP()<<endl;
	}
	while ((a[1]->getHealth() > 0)||(b[1]->getHealth() > 0));

	if ((a[1]->getHealth() <= 0)&&(a[0]->getHealth()>0)) cout<<"\n\n\n			YOUR SHIP WAS DESTROYED!\n\n\n";
	if ((a[1]->getHealth() > 0)&&(a[0]->getHealth()>0))
		cout<<"			COOD JOB!"<<endl<<"You defeated the second enemy spaceship."<<
		endl<<"Your weapons and shields are now improved"<<endl
		<<"and you have 2 new weapons"<<"\n\n GET READY FOR THE MOTHER SHIP"<<endl<<endl<<"		STAGE 3\n\n";

		do
	{
		if ((a[0]->getHealth() <=0)||(a[1]->getHealth() <= 0)) break;
		cout<<"\n\nACTION"<<endl;
		cout<<"\nDefence:"<<endl;
		cout<<"	1.Activate Energy Shield (1300)"<<endl;
		cout<<"	2.Activate Physical Shield (1300)"<<endl;
		cout<<"Offence:"<<endl;
		cout<<"	3.Lasers(850)"<<endl;
		cout<<"	4.Torpedoes(850)"<<endl;
		cout<<"	5.Light Turrets(1100)"<<endl;
		cout<<"	6.Poloron Cannon(1100)"<<endl;
		cout<<"	7.Kiloproton Torpedoes(1300)"<<endl;
		cout<<"	8.Ion Blaster(1300)"<<endl;
		int i;
		do
		{
		cin>>i;
		switch (i)
			{
			case 1: 
				a[2]->ShieldE();
				break;
			case 2: 
				a[2]->ShieldP();
				break;
			case 3:
				a[2]->Lasers(b[2]->SEon,b[2]->Health,b[2]->SEused);
				EA++;
				break;
			case 4: 
				a[2]->Torpedos(b[2]->SPon,b[2]->Health,b[2]->SPused);
				PA++;
				break;
			case 5:
				a[2]->LightTurrets(b[2]->SEon,b[2]->Health,b[2]->SEused);
				EA++;
				break;
			case 6:
				a[2]->PoloronCanon(b[2]->SPon,b[2]->Health,b[2]->SPused);
				PA++;
				break;
			case 7:
				a[2]->KiloprotonTorpedoes(b[2]->SPon,b[2]->Health,b[2]->SPused);
				EA++;
				break;
			case 8:
				a[2]->IonBlaster(b[2]->SEon,b[2]->Health,b[2]->SEused);
				PA++;
				break;
			default:
				cout <<endl<< "Invalid action!" << endl;
			}
		cout<<nm<<" health:           "<<a[2]->getHealth()<<endl;
		cout<<nm<<" energy shields:   "<<a[2]->getSE()<<endl;
		cout<<nm<<" physical shields: "<<a[2]->getSP()<<endl;
		cout<<"Enemy's health:           "<<b[2]->getHealth()<<endl;
		cout<<"Enemy's energy shields:   "<<b[2]->getSE()<<endl;
		cout<<"Enemy's physical shields: "<<b[2]->getSP()<<endl;
		break;
		}
		while ((i!=1)||(i!=2)||(i!=3)||(i!=4)||(i!=5)||(i!=6)||(i!=7)||(i!=8));
		if (b[2]->getHealth()>0)
		{
			if (EA==2)
			{
				b[2]->ShieldE();
				cout<<endl<<"\nThe enemy just activated their Energy Shield"<<endl;
				EA=0;
			}
			else 
				if (PA==2)
				{
					b[2]->ShieldP();
					cout<<endl<<"\nThe enemy just activated their Physical Shield"<<endl;
					PA=0;  
				}
				else 
					if (a[2]->getSEon())
					{
						b[2]->PlasmaBeam(a[2]->SPon,a[2]->Health,a[2]->SPused);
						cout<<endl<<"You were just attacked with Plasma Beam"<<endl;
					}	
					else 
					{
						b[2]->QuantumRailgun(a[2]->SEon,a[2]->Health,a[2]->SEused);
						cout<<endl<<"You were just attacked with Quantum Railgun"<<endl;
					}
		}
		cout<<nm<<" health:           "<<a[2]->getHealth()<<endl;
		cout<<nm<<" energy shields:   "<<a[2]->getSE()<<endl;
		cout<<nm<<" physical shields: "<<a[2]->getSP()<<endl;
		cout<<"Enemy's health:           "<<b[2]->getHealth()<<endl;
		cout<<"Enemy's energy shields:   "<<b[2]->getSE()<<endl;
		cout<<"Enemy's physical shields: "<<b[2]->getSP()<<endl;
	}
	while ((a[2]->getHealth() < 0)||(b[2]->getHealth() < 0));
	if ((a[0]->getHealth() > 0)&&(a[1]->getHealth() > 0)&&(a[2]->getHealth() <= 0))
	cout<<"\n\n\n			YOUR SHIP WAS DESTROYED!\n\n\n";
	if ((a[0]->getHealth() > 0)&&(a[1]->getHealth() > 0)&&(a[2]->getHealth() >0))
		cout<<"			CONGRATULATIONS!"<<endl<<"You defeated the Mothership."<<endl
		<<"You are now safely traveling to your dimension through the vortex"<<endl;
	system ("pause");
	return 0;
}