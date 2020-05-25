#pragma once

#include <map>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

/////// ������

#include "Modules/Loader.h"

//////////////////////////////////////////////////////

// ���������� ������ �������
static std::map <std::string, SDL_Texture*> CRSC_Textures;

// ��������� �������� (id, ����)
void CRSC_LoadTexture(std::string id, const char* path);
// ������� �������� (id)
void CRSC_DestroyTexture(std::string id);
// ������� ��� ��������
void CRSC_DestroyAllTexture();
// �������� �������� (id)
SDL_Texture* CRSC_GetTexture(std::string id);

/////////////////////////////////////////////////////

// ���������� ������ �������
static std::map <std::string, TTF_Font*> CRSC_Fonts;

// ��������� ����� (id, ����)
void CRSC_LoadFont(std::string id, std::string path, int fontSize);
// ������� ����� (id)
void CRSC_DestroyFont(std::string id);
// ������� ��� ������
void CRSC_DestroyAllFonts();
// �������� ����� �� id (id)
TTF_Font* CRSC_GetFont(std::string id);


