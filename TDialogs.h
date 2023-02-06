#ifndef __TDIALOGS__
#define __TDIALOGS__

#include "TSettings.h"
#include "TTFTexture.h"

extern TSettings mGlobalSettings;

class Dialog{
	public:
	
		SDL_Color mDialogColor = mGlobalSettings.DefaultDarkBGColor;
		SDL_Color mDialogBorderColor = mGlobalSettings.DefaultBorderColor;
		SDL_Color mTextColor = mGlobalSettings.DefaultTextColor;
		void setColorScheme(int nScheme);
		int mDialogWidth=200;
		int mDialogHeight=100;
		int mDialogBorder=10;
		bool bDialogIsWatingForText=false;
		bool bInputIsAccept=false;
		bool bInputIsCancel=false;
		virtual void recieveInput(int mKey);
		virtual void recieveInput(std::string mTextInput);		
		virtual int recieveInput(int mx, int my);		
		virtual void dropLastInputChar();
		virtual SDL_Rect render(int xpos, int ypos);		
		virtual void init();
		virtual void update();
		virtual void cancel();
};

class BDialog: public Dialog{
	public:
		std::string mDialogTextMain;
		TTFTexture mTexDialogTextMain;
		SDL_Rect mButtonRect;
		int mMinDialogWidth=100;
		virtual void init();
		virtual void setColorScheme(int nScheme);
		virtual int recieveInput(int mx, int my);		
		virtual SDL_Rect render(int xpos, int ypos);
};

class TIDialog: public BDialog{
	public:
		int mCursorTime = 0;
		bool bShowCursor=false;
		bool bIsInputActive=false;
		bool bInputIsAccepted=true;
		bool bIsNumeric=false;
		int mMaxLength=0;
		int mMaxRange=0;
		int mMinRange=0;
		bool bMustExist=false;
		bool bMustBeFolder=false;
		bool bMustNotExist=false;
		int checkCurrentText();
		virtual void dropLastInputChar();
		virtual void init();
		virtual int recieveInput(int mx, int my);		
		virtual SDL_Rect render(int xpos, int ypos);
		virtual void recieveInput(std::string mTextInput);
};


class SDialog: public Dialog{
	public:
		virtual void init();
		std::string mDialogTextMain;
		std::string mDialogTextInput;
		TTFTexture mTexDialogTextMain;
		TTFTexture mTexDialogTextInput;		
		BDialog mAcceptButton;
		BDialog mCancelButton;
		virtual void recieveInput(int mKey);		
		virtual int recieveInput(int mx, int my);
		virtual SDL_Rect render(int xpos, int ypos);
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
		virtual void recieveInput(std::string mTextInput);
		virtual void recieveInput(int mKey);
		virtual int recieveInput(int mx, int my);
		virtual void dropLastInputChar();
		virtual SDL_Rect render(int xpos, int ypos);
		bool bSubDialogActive = false;	
		SDialog *mSubDialog;
		TIDialog mTextInput;
		virtual void resize();
};

class ITDialog: public SADialog{
	public:
		virtual void init();
		virtual void cancel();
		virtual SDL_Rect render(int xpos, int ypos);
		virtual void recieveInput(int mKey);
		virtual int recieveInput(int mx, int my);
};

class RNDialog: public ITDialog{
	public:
		int mNumber = 0;
		virtual void init();
		virtual void cancel();
		virtual void dropLastInputChar();
		virtual SDL_Rect render(int xpos, int ypos);
		virtual void recieveInput(int mKey);
		virtual void recieveInput(std::string mTextInput);		
};

class HDialog: public SDialog{
	public:

		std::vector<TTFTexture*> mHelpText;
		std::string	mCurModeHead;
		std::vector<std::string> mCurModeText;
		BDialog mCloseButton;
		virtual void init();
		virtual void recieveInput(int mKey);
		virtual int recieveInput(int mx, int my);				
		virtual SDL_Rect render(int xpos, int ypos);
};

class PIDialog: public HDialog{
	public:
		TEditor* mEditor;
		virtual void init();
		virtual void update();
		int fliph,flipv,tilenum,curtile;
		virtual SDL_Rect render(int xpos, int ypos);
};

class TBDialog: public Dialog{
	public:
		std::string mDialogTextActions;
		std::string mDialogTextWindow;		
		std::string mDialogTextProject;
		TTFTexture mTexDialogTextActions;
		TTFTexture mTexDialogTextWindow;		
		TTFTexture mTexDialogTextProject;
		TEditor* mEditor;
		virtual void init();
		virtual SDL_Rect render(int xpos, int ypos);
};


class MEDialog: public HDialog{
	public:
		virtual void init();
		virtual void setColorScheme(int nScheme);
		virtual void update();		
		virtual SDL_Rect render(int xpos, int ypos);
};


#endif