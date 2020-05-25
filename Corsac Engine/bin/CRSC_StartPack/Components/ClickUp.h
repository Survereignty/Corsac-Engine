#pragma once

#include "../ECS/ECS.h"

class ClickUp : public Component
{
public:
	ClickUp(){};
	~ClickUp(){};

	void setEvent(bool value)
	{
		click = value;
	}

	bool getEvent()
	{
		return click;
	}

	void Update() override
	{

	}

private:



	bool click = false;
};