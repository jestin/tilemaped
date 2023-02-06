#pragma once

#include <SDL2/SDL.h> 
#include <vector>
#include <iostream>

class TSettings{
	public:
		SDL_Renderer *TRenderer;
		SDL_Window *TWindow;			
		int WindowWidth=1900;
		int WindowHeight=1000;
		int TopBarHeight = 50;
		int TileSetWidth=200;
		int TileSetDefaultScale=10;
		int TileMapScale=3;
		int TileMapHeight=128;
		int TileMapWidth=128;		
		int TileSize=16;
		int PaletteScale=2;
		std::string ProjectPath;
		std::string ProjectPalettePath = "";
		std::vector<unsigned char> ProjectPalette;
		bool bProjectHasPalette = false;
		int mProjectSaveState = 0;
		int mOpenTileState = 0;
		int mDeleteUnusedTilesState = 0;
		std::string mNewTilePath = "";				
		bool bShowTypeSelection = false;
		bool bShowPixelGrip = true;
		bool bShowPixelType = false;
		bool bShowSelectedTile = true;
		bool bShowProjectInfo = false;
		int mSelectedTile = 0;
		int mTileEdScale = 4;
		TTF_Font *TFont;
		TTF_Font *LFont;
		SDL_Color DefaultBGColor = {0xc0,0xc0,0xc0,0xff};
		SDL_Color DefaultDarkBGColor = {0xb0,0xb0,0xb0,0xff};
		SDL_Color DefaultTextColor = {0x20,0x20,0x20,0xff};
		SDL_Color DefaultBorderColor = {0x00,0x00,0xff,0xff};
		SDL_Color DefaultButtonColor = {0x90,0x90,0x90,0xff};
		SDL_Color DefaultButtonBorderColor = {0x20,0x20,0x20,0xff};
		SDL_Color DefaultGUIBorderColor = {0x20,0x20,0x20,0xff};
		SDL_Color DefaultHighlightColor = {0xff,0xff,0xff,0xff};
		SDL_Color AltHighlightColor = {0x00,0xff,0xff,0xff};
		SDL_Color ErrorTextColor = {0xff,0x00,0x00,0xff};
		SDL_Color ErrorBorderColor = {0xc0,0x00,0x00,0xff};
		SDL_Color PixelGridColor = {0x20,0x20,0x20,0xff};
		std::vector<std::string> mHelpText;
		std::vector<std::string> mHelpTextMap;
		std::vector<std::string> mHelpTextTile;
		int mLastTick = 0;
		int mCurrentTick = 0;
		int initSettings();
		void initHelpText();
		void printHelpText();		
		int initTicks();
		int updateTicks();
		int getTicks();
};

static TSettings mGlobalSettings;
