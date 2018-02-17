
#include "../Map.hpp"

int main(int argc, char** argv)
{

    Map broken;
    Map map1;
    Map map2;

    try
    {
        std::cout << "Importing map \"Map1.map\"... Should Fail." << std::endl;
        broken.importMap("TestData/InvalidSchema.map");
    }
    catch (std::exception& e)
    {
        std::cout << "Cannot parse \"InvalidSchema.map\": " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Importing map \"Map1.map\"... Should Succeed." << std::endl;
    std::cout << "Import " << (map1.importMap("TestData/2player.map") ? "SUCCEEDED" : "FAILED") << std::endl;
    std::cout << std::endl;

    std::cout << "Importing map \"Map2.map\"... Should Fail." << std::endl;
    std::cout << "Import " << (map2.importMap("TestData/2player_invalid.map") ? "SUCCEEDED" : "FAILED") << std::endl;
    std::cout << std::endl;

    return 0;
}
