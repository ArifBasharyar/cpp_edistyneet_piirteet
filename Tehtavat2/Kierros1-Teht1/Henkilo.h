#pragma once
#include <iostream>
#include <string>

class Henkilo {
private:
	std::string nimi{};
	unsigned int ika{};

public:
	Henkilo(std::string _nimi, unsigned int _ika): nimi(_nimi), ika(_ika) {};
	Henkilo() {};
	~Henkilo() {};

	void setNimi(const std::string _nimi);
	void setIka(const unsigned int _ika);
	std::string getNimi();
	unsigned int getIka();
	void tulostaHenkilonTiedot();
};
