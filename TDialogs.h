#ifndef __TDIALOGS__
#define __TDIALOGS__

#include "TSettings.h"
#include "TTFTexture.h"

extern TSettings mGlobalSettings;

class Dialog{
	public:
		SDL_Color mTextColor = mGlobalSettings.DefaultTextColor;
		std::string mDialogTextMain;		
		std::string mDialogTextTitle;				
		void setColorScheme(int nScheme);
		int mDialogWidth = 400;
		int mDialogHeight = 200;		
		bool bDialogIsWatingForText = false;
		bool bInputIsAccept = false;
		bool bInputIsCancel = false;
		virtual void recieveInput(int mKey);		
		virtual void dropLastInputChar();
		virtual int render(int xpos, int ypos);
		virtual int render();		
		virtual void init();
		virtual void update();
		virtual void cancel();
};

class TIDialog: public Dialog{
	public:
		int mCursorTime = 0;
		bool bShowCursor=false;
		bool bIsInputActive=false;
		bool bInputIsAccepted=true;
		bool bIsNumeric=false;
		bool bAutoComplete=false;
		int mCompleteIndex=0;				
		static int MyCallback(ImGuiInputTextCallbackData* data);
		std::string mCompleteText;		
		std::vector<int> mAllowedValues;
		int mMaxLength=0;
		int mMaxRange=0;
		int mMinRange=0;
		bool bMustExist=false;
		bool bMustBeFile=false;
		bool bMustBeFolder=false;
		bool bMustNotBeFile=false;
		bool bMustNotExist=false;
		int checkCurrentText();
		void autoComplete();
		virtual void dropLastInputChar();
		virtual void init();		
		virtual int render();		
		std::string mInputLabel = "Filename";
		bool bIsActive=false;
};


class SDialog: public Dialog{
	public:
		virtual void init();
		std::string mDialogButtonAccept;
		std::string mDialogButtonCancel;
		virtual void recieveInput(int mKey);				
		virtual int render();
};

class RTDialog: public SDialog{
	public:
		virtual void init();
		virtual void recieveInput(int mKey);
};

class SADialog: public SDialog{
	public:
		virtual void init();
		virtual void cancel();		
		virtual void recieveInput(int mKey);		
		virtual void dropLastInputChar();
		virtual int render();
		bool bSubDialogActive = false;	
		SDialog *mSubDialog;
		TIDialog mTextInput;		
};

class ITDialog: public SADialog{
	public:
		virtual void init();
		virtual void cancel();
		virtual int render();
		virtual void recieveInput(int mKey);		
};

class RNDialog: public ITDialog{
	public:
		int mNumber = 0;
		bool show_another_window = false;
		bool show_demo_window = false;
		float f = 0;
    	int counter = 0;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
		virtual void init();
		virtual void cancel();
		virtual void dropLastInputChar();
		virtual int render(int xpos, int ypos);
		virtual void recieveInput(int mKey);
		bool isShown = true;
		float wx,wy;
		ImVec2 wpos;
		ImVec2 wsize;
		ImVec2 elmin;
		ImVec2 elmax;
		ImVec2 esize;		
};

class OPDialog: public ITDialog{
	public:
		virtual void init();
		virtual int render();
};

class CPDialog: public Dialog{
	public:		
		TIDialog mReadPath;
		TIDialog mReadPal;		
		TIDialog *mActiveInput;
		bool bInputIsAccepted = false;
		virtual void init();		
		virtual void dropLastInputChar();		
		virtual void recieveInput(int mKey);				
		virtual int render();
		int tmapx=32;
		int tmapy=32;
		int tilex=16;
		int tiley=16;
		bool bHasPalette = false;
};


class OCDialog: public Dialog{
	public:
		virtual void init();		
		bool bSubDialogActive = false;
		bool bSubDialogIsOpen = false;	
		bool bSubDialogIsCreate = false;			
		OPDialog mOpenProject;
		CPDialog mCreateProject;
		virtual void dropLastInputChar();		
		virtual void recieveInput(int mKey);				
		virtual int render();
};

class HDialog: public SDialog{
	public:
		std::string	mCurModeHead;
		std::vector<std::string> mCurModeText;		
		virtual void init();
		virtual void recieveInput(int mKey);		
		virtual int render(int xpos, int ypos);
};

class PIDialog: public Dialog{
	public:
		TEditor* mEditor;
		virtual void init();
		virtual void update();
		int fliph,flipv,tilenum,curtile;
		std::string TileMap;
		std::string cMapWidth;
		std::string cMapHeight;
		std::string TileSizeX;
		std::string TileSizeY;
		std::string Flip;		
		std::string CurrentTile;
		std::string TilesInSet;
		std::string SelectedTile;
		std::string cTileSizeX;
		std::string cTileSizeY;
		virtual int render(int xpos, int ypos);
};

class TBDialog: public Dialog{
	public:
		std::string mDialogTextActions;
		std::string mDialogTextWindow;		
		std::string mDialogTextProject;		
		TEditor* mEditor;
		virtual void init();
		virtual int render();
};


class MEDialog: public HDialog{
	public:
		virtual void init();
		virtual void setColorScheme(int nScheme);
		virtual void update();		
		virtual int render();
};

class QDialog: public Dialog{
	public:
		virtual int render();
		virtual void recieveInput(int mKey);
};


#endif