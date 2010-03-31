#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "guiIncludes.h"


class xmlAssociation
{
    public:
        xmlAssociation(guiBaseObject * objPtr, string xmlNameIn, int numParamsIn){
            guiObj      = objPtr;
            xmlName     = xmlNameIn;
            numParams   = numParamsIn;
        }

        guiBaseObject * guiObj;
        string xmlName;
        int numParams;
};

class ofxControlPanel: public guiBaseObject{

	public:
        static float borderWidth;
        static float topSpacing;
        static float tabWidth;
        static float tabHeight;

        ofxControlPanel();
        ~ofxControlPanel();

        void setup(string controlPanelName, float panelX, float panelY, float width, float height);
        void loadFont( string fontName, int fontsize );

        guiTypePanel * addPanel(string panelName, int numColumns, bool locked = false);
		
		int getSelectedPanel();
		void setSelectedPanel(int whichPanel);
		
        void setWhichPanel(int whichPanel);
        void setWhichPanel(string panelName);
        void setWhichColumn(int column);

		string getCurrentPanelName();

        void setSliderWidth(int width);

        guiTypeToggle * addToggle(string name, string xmlName, bool defaultValue);
        guiTypeMultiToggle * addMultiToggle(string name, string xmlName, int defaultBox, vector <string> boxNames);
        guiTypeSlider * addSlider(string sliderName, string xmlName, float value , float min, float max, bool isInt);
        guiType2DSlider * addSlider2D(string sliderName, string xmlName, float valueX, float valueY, float minX, float maxX, float minY, float maxY, bool isInt);
        guiTypeDrawable * addDrawableRect(string name, ofBaseDraws * drawablePtr, int drawW, int drawH);
		guiTypeVideo * addVideoRect(string name, ofVideoPlayer * drawablePtr, int drawW, int drawH);
        guiTypeCustom * addCustomRect(string name, guiCustomImpl * customPtr, int drawW, int drawH);
        guiTypeButtonSlider * addButtonSlider(string sliderName, string xmlName, float value , float min, float max, bool isInt);
        guiTypeTextDropDown * addTextDropDown(string name, string xmlName, int defaultBox, vector <string> boxNames);

		void setupEvents();
		void createEventGroup(string eventGroupName, vector <string> xmlNames);
		void enableEvents();
		void disableEvents();
		ofEvent <guiCallbackData> & getEventsForPanel(int panelNo);
		ofEvent <guiCallbackData> & getAllEvents();
		ofEvent <guiCallbackData> & getEventGroup(string eventGroupName);

        void setValueB(string xmlName, bool value,  int whichParam = 0);
        void setValueI(string xmlName, int value,  int whichParam = 0);
        void setValueF(string xmlName, float value,  int whichParam = 0);
        bool getValueB(string xmlName, int whichParam = 0);
        float getValueF(string xmlName, int whichParam = 0);
        int getValueI(string xmlName, int whichParam = 0);

        void setIncrementSave(string incrmentalFileBaseName);
        void disableIncrementSave();
        void loadSettings(string xmlFile);
        void reloadSettings();
        void saveSettings(string xmlFile);
        void saveSettings();
        void setXMLFilename(string xmlFile);

        void setDraggable(bool bDrag);
        void setMinimized(bool bMinimize);
        void show();
        void hide();

        void toggleView();
        void mousePressed(float x, float y, int button);
        void mouseDragged(float x, float y, int button);
        void mouseReleased();

        void updateBoundingBox();
        void update();
        void draw();


        ofTrueTypeFont guiTTFFont;

        vector <xmlAssociation> xmlObjects;
        vector <guiBaseObject *> guiObjects;
        vector <guiTypePanel *> panels;
        vector <ofRectangle> panelTabs;
		
		vector <guiCustomEvent *> customEvents;

		ofxXmlSettings settings;
		string currentXmlFile;
		string settingsDirectory;

		ofRectangle topBar;
		ofRectangle minimizeButton;
		ofRectangle saveButton;
		ofRectangle restoreButton;

        string incrementSaveName;

        bool hidden;
        bool usingXml;
        bool bUseTTFFont;
		bool minimize;
		bool saveDown;
		bool incrementSave;
		bool restoreDown;
		bool bDraggable;

		int selectedPanel;
        int currentPanel;

        ofPoint prevMouse;

		int sliderWidth;
		
		bool bEventsSetup;
		bool eventsEnabled;

		ofPoint mouseDownPoint;

		bool dragging;
		
		
		protected:
			void eventsIn(guiCallbackData & data);

		

};