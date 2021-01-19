#Do optymalizacji


#include <iostream>
#include<string>
#include<fstream>
#include<random>
#include<conio.h>
#include<cstdlib>
#include<windows.h>

using namespace std;
//funkcja losujaca slowka
int losujSlowko(int dlugoscPodanaPrzezUzytkownika);


int main()
{

	cout << endl << "   " << endl << "   *           *  * * * *  * * * *  * * *   *   *  *" << endl << "    *         *   *     *  *     *  *    *  *  *   *" << endl << "     *   *   *    *     *  * *  *   *    *  * *    *" << endl << "      * * * *     *     *  *   *    *    *  *  *   *" << endl << "       *   *      * * * *  *     *  * * *   *   *  *" << endl << endl;

	//tworzenie kluczowych zmiennych
	int losowyIndeks;
	int rozmiarNauki;
	string CwiczenieSlowek;

	Sleep(1500);

	//dynamiczne alokowanie pamieci przez uzytkownika + sprawdzenie czy uzytkownik zamiast liczby nie wpisal slowa		//TO-DO
	int dlugoscPodanaPrzezUzytkownika;
	cout << "I"; Sleep(10); cout << "l"; Sleep(10); cout << "e "; Sleep(10); cout << "s";  Sleep(10); cout << "l"; Sleep(10); cout << "o";  Sleep(10); cout << "w"; Sleep(10); cout << "e";  Sleep(10); cout << "k "; Sleep(10); cout << "c"; Sleep(10); cout << "h";  Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "z "; Sleep(10);  cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "e "; Sleep(10);  cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "u"; Sleep(10); cout << "c"; Sleep(10);  cout << "z"; Sleep(10); cout << "y"; Sleep(10); cout << "c"; Sleep(10); cout << "? " << endl;

	cin >> dlugoscPodanaPrzezUzytkownika;
	system("cls");

	//tablice stringow odpowiedzialne za przechowywanie slowek
	vector<string>TablicaPolskichSlowek{};
	vector<string>TablicaAngielskichSlowek{};
	vector<string>TablicaNauczyonychSlowek{};
	vector<string>TablicaPorownywaniaIndeksow{};
	TablicaPorownywaniaIndeksow.resize(1024);
	TablicaNauczyonychSlowek.resize(1024);
	TablicaAngielskichSlowek.resize(dlugoscPodanaPrzezUzytkownika);
	TablicaPolskichSlowek.resize(dlugoscPodanaPrzezUzytkownika);


	//zapisywanie przez uzytkownika slowek polskich i angielskich
	for (int i = 0; i < dlugoscPodanaPrzezUzytkownika; i++)
	{
		cout << endl << "   " << endl << "   *           *  * * * *  * * * *  * * *   *   *  *" << endl << "    *         *   *     *  *     *  *    *  *  *   *" << endl << "     *   *   *    *     *  * *  *   *    *  * *    *" << endl << "      * * * *     *     *  *   *    *    *  *  *   *" << endl << "       *   *      * * * *  *     *  * * *   *   *  *" << endl;
		cout << endl << "P"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "a"; Sleep(10); cout << "j "; Sleep(10); cout << i + 1; Sleep(10); cout << " p"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "s"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10);  cout << "e "; cout << "s"; Sleep(10); cout << "l"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "k"; Sleep(10); cout << "o "; cout << endl;
		cin >> TablicaPolskichSlowek[i];
		cout << "P"; Sleep(10); cout << "o"; Sleep(10); cout << "d"; Sleep(10); cout << "a"; Sleep(10);  cout << "j "; Sleep(10);          cout << "t"; Sleep(10); cout << "l"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10);  cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10);  cout << "i"; Sleep(10); cout << "e "; Sleep(10);                                  cout << "s"; Sleep(10); cout << "l"; Sleep(10); cout << "o"; Sleep(10);  cout << "w"; Sleep(10); cout << "a:"; cout << endl;
		cin >> TablicaAngielskichSlowek[i];
		system("cls");

		if (i == dlugoscPodanaPrzezUzytkownika - 1)
		{
			cout << endl << "   " << endl << "   *           *  * * * *  * * * *  * * *   *   *  *" << endl << "    *         *   *     *  *     *  *    *  *  *   *" << endl << "     *   *   *    *     *  * *  *   *    *  * *    *" << endl << "      * * * *     *     *  *   *    *    *  *  *   *" << endl << "       *   *      * * * *  *     *  * * *   *   *  *" << endl;
			cout << endl << "W"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10);  cout << "y"; Sleep(10);          cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10);  cout << "e "; Sleep(10); cout << "z"; Sleep(10); cout << "a"; Sleep(10); cout << "k"; Sleep(10); cout << "o"; Sleep(10);  cout << "n"; Sleep(10); cout << "c"; Sleep(10);                                  cout << "z"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10);  cout << "e"; Sleep(10); cout << endl;
			cout << "Z"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "z"; Sleep(10);  cout << "y"; Sleep(10);          cout << "n"; Sleep(10); cout << "a"; Sleep(10); cout << "m"; Sleep(10); cout << "y"; Sleep(10);  cout << " n"; Sleep(10); cout << "a"; Sleep(10); cout << "u"; Sleep(10); cout << "k"; Sleep(10); cout << "e"; Sleep(10);  cout << endl;
			Sleep(500); system("cls");
		}
	}

	//test pokazywania slowek
	rozmiarNauki = dlugoscPodanaPrzezUzytkownika;
	int drugiPrzebiegPetli = 0;
	int sprawdzCzyTenSam = 0;
	do
	{
		cout << endl << "   " << endl << "   *           *  * * * *  * * * *  * * *   *   *  *" << endl << "    *         *   *     *  *     *  *    *  *  *   *" << endl << "     *   *   *    *     *  * *  *   *    *  * *    *" << endl << "      * * * *     *     *  *   *    *    *  *  *   *" << endl << "       *   *      * * * *  *     *  * * *   *   *  *" << endl << endl;


		losowyIndeks = losujSlowko(dlugoscPodanaPrzezUzytkownika);
		sprawdzCzyTenSam = losowyIndeks;
		TablicaPorownywaniaIndeksow[drugiPrzebiegPetli] = losowyIndeks;

		//optymalizacja powtorzen

		for (int j = 0; j < dlugoscPodanaPrzezUzytkownika; j++)
		{
			if (TablicaNauczyonychSlowek[drugiPrzebiegPetli] == TablicaPorownywaniaIndeksow[j])
			{
				losowyIndeks = losujSlowko(dlugoscPodanaPrzezUzytkownika);
			}
		}

		Sleep(400); cout << endl;
		cout << TablicaPolskichSlowek[losowyIndeks] << endl;
		cout << "Podaj Angielski odpowiednik slowka: " << endl;
		cin >> CwiczenieSlowek;

		if (CwiczenieSlowek == TablicaAngielskichSlowek[losowyIndeks])
		{
			cout << "Dobra odpowiedz!" << endl;
			rozmiarNauki = rozmiarNauki - 1;
			TablicaNauczyonychSlowek[drugiPrzebiegPetli] = losowyIndeks;
			++drugiPrzebiegPetli;
			Sleep(1000);
		}
		else
		{
			cout << "Bledna odpowiedz! " << endl << "Poprawna odpowiedz to: '" << TablicaAngielskichSlowek[losowyIndeks] << "'" << endl;
			rozmiarNauki = rozmiarNauki + 1;
			Sleep(1250);
		}
		cout << endl << endl;
		system("cls");

	} while (rozmiarNauki != 0);

	cout << endl << "   " << endl << "   *           *  * * * *  * * * *  * * *   *   *  *" << endl << "    *         *   *     *  *     *  *    *  *  *   *" << endl << "     *   *   *    *     *  * *  *   *    *  * *    *" << endl << "      * * * *     *     *  *   *    *    *  *  *   *" << endl << "       *   *      * * * *  *     *  * * *   *   *  *" << endl << endl;

	cout << "Nauczyles/as sie wszsytkich slowek!" << endl;
	cout << "Gratulacje!" << endl << endl << endl;
	system("pause");

}
//funkcja losujaca indeks slowka, zwraca indeks
int losujSlowko(int dlugoscPodanaPrzezUzytkownika)
{
	int WylosowanaLiczba = 1;

	//generator losowania
	random_device ziarno;
	mt19937 generator(ziarno());
	uniform_int_distribution<int> distribution(0, dlugoscPodanaPrzezUzytkownika - 1);

	//generowanie liczby losowej
	WylosowanaLiczba = distribution(generator);

	return WylosowanaLiczba;
}
