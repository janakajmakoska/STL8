#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Vraboten {
public:
    Vraboten(std::string i, int b) : ime(i), bodovi(b) {}
    std::string ime;
    int bodovi;
};

int main() {
    int vkupno_bodovi = 0;
    int vrednost_na_bod = 5;
    std::vector<Vraboten> vraboteni {
        {"Ana", 10},
        {"Bojan", 15},
        {"Cvetko", 5},
        {"Damjan", 8}
    };

    // Presmetka na vkupnata suma
    int vkupno_plata = std::accumulate(vraboteni.begin(), vraboteni.end(), 0,
        [vrednost_na_bod](int sum, const Vraboten& v) { return sum + v.bodovi * vrednost_na_bod; });

    // Sortiranje na listata spored brojot na bodovi
    std::sort(vraboteni.begin(), vraboteni.end(),
        [](const Vraboten& v1, const Vraboten& v2) { return v1.bodovi < v2.bodovi; });

    // Prikaz na vkupnata suma i listata na vrabotenite
    std::cout << "Vkupna plata: " << vkupno_plata << std::endl;
    std::cout << "Lista na vrabotenite (spored brojot na bodovi):" << std::endl;
    for (const auto& v : vraboteni) {
        std::cout << v.ime << " - " << v.bodovi * vrednost_na_bod << " denari" << std::endl;
    }

    return 0;
}
