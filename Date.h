#pragma once


class Date
{


private :
	int jour;
	int mois;
	int annee;

public :

	Date();
	Date(int,int,int);
	bool estValide(int , int , int );
	bool estBissextile(int);
	void Consulter() const;
	~Date();
	bool operator==(Date);
	bool operator<(Date);

};

