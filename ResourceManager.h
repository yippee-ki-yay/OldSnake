#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<map>
//#include <unordered_map>

//TO DO: add sound support, loading mesurment,

namespace np
{

 class ResourceManager
 {
  public:

   ResourceManager();

   ~ResourceManager();

   void Load(int progress = 0);

   void addImage(std::string path);

   void delImage(std::string name);

   void addSound(std::string path);

   sf::Image& getImage(std::string path);

   static ResourceManager m_Instance;

   static ResourceManager* getInstance(){return &m_Instance;}

  protected:

   std::map<std::string,sf::Image>ImgStorage;

  typedef std::map<std::string,sf::Image>::iterator Iter;


   int nImages;

   bool found;


 };

}

#endif
