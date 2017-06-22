#include <iostream>
#include <ctime>

int main()
{
  int s,m,h,d,mh,yr;
  char znak;
  std::cout << "Podaj date w formacie: godzina minuta sekunda dzien miesiac rok np: \"17:00:00 25.7.2017\"\n__ __ __ __ __ ____\r";
  std::cin >> h >> znak >> m >> znak >> s >> d >> znak >> mh >> znak >> yr;

  struct std::tm a = {s,m,h-1,d,mh-1,yr-1900}; // format do wczytania daty: sekunda minuta godzina dzień miesiąc rok 
  std::time_t x = std::mktime(&a);
  std::time_t y = std::time(nullptr);      // Dziś 
  double differenceDays = std::difftime(x, y) / (60 * 60 * 24);
  int weeks = int(differenceDays/7);
  int hours = int(differenceDays * 24)%24;
  int minutes = int(differenceDays * 24 * 60)%60;
  int seconds = int(differenceDays * 24 * 60 * 60)%60;
  std::cout << "Data docelowa to: " << std::ctime(&x);
  std::cout << "Data obecna to: " << std::ctime(&y);

  if (differenceDays <= 0)
  {
    differenceDays = -differenceDays;
    weeks = -weeks;
    hours = -hours;
    minutes = -minutes;
    seconds = -seconds;
  }
  std::cout << "Różnica = ";
  if (weeks<5)
  {
    std::cout << weeks << " tygodni " << int(differenceDays)%7 << " dni ";
  }
  else
  {
    std::cout << int(differenceDays) << " dni ";
  }
  std::cout << hours << " godzin " << minutes << " minut "<< seconds << " sekund" << std::endl;
  return 0;
}
