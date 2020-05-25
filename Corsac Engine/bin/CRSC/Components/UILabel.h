#pragma once

#include "ECS.h"
#include "../CRSC_App.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "../CRSC_Asset.h"

class UILabel : public Component
{
public:
	UILabel(int xpos, int ypos, std::string text, std::string font, SDL_Color& color) :
		labelText(text), labelFont(font), textColor(color)
	{
		position.x = xpos;
		position.y = ypos;

		SetLabelText(labelText, labelFont);
	}
	~UILabel()
	{

	}

	void SetLabelText(std::string text, std::string font)
	{
		SDL_Surface* surf = TTF_RenderText_Blended(CRSC_Scene::assets->GetFont(font), text.c_str(), textColor);
		labelTexture = SDL_CreateTextureFromSurface(CRSC_App::Renderer, surf);
		SDL_FreeSurface(surf);

		SDL_QueryTexture(labelTexture, nullptr, nullptr, &position.w, &position.h);
	}

	void Render() override
	{
		SDL_RenderCopy(CRSC_App::Renderer, labelTexture, nullptr, &position);
	}

private:
	SDL_Rect position;
	std::string labelText;
	std::string labelFont;

	SDL_Color textColor;
	SDL_Texture* labelTexture;
};

