#include"ResourceManager.h"
#include<iostream>

np::ResourceManager np::ResourceManager::m_Instance;

np::ResourceManager::ResourceManager():nImages(0), found(false)
{

}

np::ResourceManager::~ResourceManager()
{

}

 void np::ResourceManager::Load(int progress)
{
  int curr_size = ImgStorage.size();
  progress += 100/curr_size;

}

 void np::ResourceManager::addImage(std::string path)
{
	//Iter = ImgStorage.find(path);
    
	Iter i = ImgStorage.find(path);

	if(i == ImgStorage.end())
		 {
			 sf::Image img;
          img.LoadFromFile(path);
          ImgStorage[path] = img;
          nImages++;
	     }

	   else
	    {

	    }


	
}


void np::ResourceManager::delImage(std::string name)
{

}

sf::Image& np::ResourceManager::getImage(std::string path)
{
  Iter i = ImgStorage.find(path);

  return i->second;
}
 void np::ResourceManager::addSound(std::string path)
{

}

