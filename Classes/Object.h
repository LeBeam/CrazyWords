#ifndef Object_h
#define Object_h

#include <fstream>
#include <string>

class Object
{
protected:
	std::string text;
	//std::string getObject();
	
public:
	bool loadFile(std::ifstream& file);
	std::string getObject();
};

#endif