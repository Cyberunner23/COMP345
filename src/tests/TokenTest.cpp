
#include <iostream>
#include <map>

#include "../GameDeck.hpp"

int main(int argc, char** argv)
{

    GameDeck provider;

    std::cout << "There are " << provider.getCoinsTokenListSize() << " coins in the deck." << std::endl;
    std::cout << "There are " << provider.getMapTokensTokenListSize() << " map tokens in the deck." << std::endl;
    std::cout << "There are " << provider.getRaceBannersTokenListSize() << " race banners in the deck." << std::endl;
    std::cout << "There are " << provider.getRaceTokensTokenListSize() << " race tokens in the deck." << std::endl;
    std::cout << "There are " << provider.getSpecialPowersTokenListSize() << " badges/special powers in the deck." << std::endl;


    return 0;
}


