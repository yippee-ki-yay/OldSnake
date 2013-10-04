#include"Singelton.h"

Singleton Singleton::mInstance;

Singleton::~Singleton()
{
delete app;
delete event;
}
