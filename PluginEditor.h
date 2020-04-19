#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
class OtherLookAndFeel : public LookAndFeel_V4
{
public:
	OtherLookAndFeel()
	{
		//Colour textColor = Colours::ghostwhite;
		//Colour textColor = Colour(0xffEDFCFF);
		Colour textColor = Colours::white;
		setColour(Label::textColourId, textColor);
		setColour(TextButton::textColourOffId, textColor);
	}

	void drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour,
		bool isMouseOverButton, bool isButtonDown) override
	{
		//g.setColour(Colours::cornflowerblue);
		//g.setColour(Colour(0xff5F5487));
		g.setColour(Colour(0xff5F5982));
		
		Rectangle <float> buttonRectangle(100, 30);
		g.fillRoundedRectangle(buttonRectangle, 5);
		
		button.setTriggeredOnMouseDown(true);

		//auto buttonArea = button.getLocalBounds();
		//g.fillRect(buttonArea);
	}

};

class HxpanderAudioProcessorEditor  : public AudioProcessorEditor,
	public DragAndDropContainer, public MouseListener									
{
public:
    HxpanderAudioProcessorEditor (HxpanderAudioProcessor&);
    ~HxpanderAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void callMidiFile(StringArray Files);

	
private:
	OtherLookAndFeel otherLookAndFeel;

	StringArray recFile, ovdFile, playFile, stopFile, onceFile, undoFile, 
		revFile, fwdFile, halfFile, fullFile,
		snap1File, snap2File, snap3File, snap4File, snap5File, snap6File, snap7File,snap8File;
	
	TextEditor debug;
	HxpanderAudioProcessor& processor;
	Label looperLable, snapshotsLable;
	TextButton recButton, ovdButton, playButton, stopButton, onceButton, undoButton,
		revButton, fwdButton, halfButton, fullButton,
		snap1,snap2,snap3,snap4,snap5,snap6,snap7,snap8;
	
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HxpanderAudioProcessorEditor)
};
