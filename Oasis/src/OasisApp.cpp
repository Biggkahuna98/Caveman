#include <Caveman.h>

class Oasis : public Caveman::Application
{
public:
	Oasis()
	{
		
	}

	~Oasis()
	{
		
	}
};

Caveman::Application* Caveman::CreateApplication()
{
	return new Oasis();
}