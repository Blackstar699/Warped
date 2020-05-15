#include "fonctions.h"

///charge une texture a partir d'une image et la return
sf::Texture loadTexture(const std::string& filename){
    sf::Image image;
    sf::Texture texture;

    if(!image.loadFromFile(filename)){
        cerr << "Error, load image failed (" << filename << ")" << endl;
    } else{
        if(!texture.loadFromImage(image)){
            cerr << "Error, load texture failed (" << filename << ")" << endl;
        } else{
            texture.setSmooth(true);
        }
    }

    return texture;
}


///récupère un fichier .csv et le retourne sous forme de std::map<std::pair<int, int>, int>
std::map<std::pair<int, int>, int> getMap(const string& fileName){
    cout << "rebuilding map... " << std::flush;
    std::map<std::pair<int, int>, int> map;
    CSVReader reader(fileName);
    std::vector<std::vector<string>> data = reader.getData();
    for(auto line : data)
    {
        int x = stoi(line[0]);
        int z = stoi(line[1]);
        int value = stoi(line[2]);

        map[std::make_pair(x,z)] = value;
    }
    cout << "OK" << endl;
    return map;
}
