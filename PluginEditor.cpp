#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <string>
#include <iostream>

//==============================================================================
HxpanderAudioProcessorEditor::HxpanderAudioProcessorEditor(HxpanderAudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p)
{

	addAndMakeVisible(debug);
	LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName("Helvetica");
	setSize(675, 320);
	//setSize(675, 420);
	setLookAndFeel(&otherLookAndFeel);
	Font labelFont("Times New Roman", 30.f, Font::bold);

	addAndMakeVisible(looperLable);
	looperLable.setFont(30.f);
	looperLable.setText("LOOPER", dontSendNotification);

	addAndMakeVisible(snapshotsLable);
	snapshotsLable.setFont(30.f);
	snapshotsLable.setText("SNAPSHOTS", dontSendNotification);
	
	//recFile = { "C:/Program Files/Common Files/VST3/MidiFiles/RECORD.mid" };
	String midiFilesPath =
		File::getSpecialLocation(File::currentApplicationFile).getFullPathName().dropLastCharacters(13);
	recFile = {  midiFilesPath + "MidiFiles/RECORD.mid" };
	ovdFile = { midiFilesPath + "MidiFiles/OVERDUB.mid" };
	playFile = { midiFilesPath + "MidiFiles/PLAY.mid" };
	stopFile = { midiFilesPath + "MidiFiles/STOP.mid" };
	onceFile = { midiFilesPath + "MidiFiles/ONCE.mid" };
	undoFile = { midiFilesPath + "MidiFiles/UNDO.mid" };
	revFile = { midiFilesPath + "MidiFiles/REVERSE.mid" };
	fwdFile = { midiFilesPath + "MidiFiles/FORWARD.mid" };
	halfFile = { midiFilesPath + "MidiFiles/HALF SPEED.mid" };
	fullFile = { midiFilesPath + "MidiFiles/FULL SPEED.mid" };

	snap1File = { midiFilesPath + "MidiFiles/SNAP 1.mid" };
	snap2File = { midiFilesPath + "MidiFiles/SNAP 2.mid" };
	snap3File = { midiFilesPath + "MidiFiles/SNAP 3.mid" };
	snap4File = { midiFilesPath + "MidiFiles/SNAP 4.mid" };
	snap5File = { midiFilesPath + "MidiFiles/SNAP 5.mid" };
	snap6File = { midiFilesPath + "MidiFiles/SNAP 6.mid" };
	snap7File = { midiFilesPath + "MidiFiles/SNAP 7.mid" };
	snap8File = { midiFilesPath + "MidiFiles/SNAP 8.mid" };

	addAndMakeVisible(recButton);
	recButton.setButtonText("RECORD");
	recButton.onClick = [this] {callMidiFile(recFile);};
	
	addAndMakeVisible(ovdButton);
	ovdButton.setButtonText("OVERDUB");
	ovdButton.onClick = [this] {callMidiFile(ovdFile);};

	addAndMakeVisible(playButton);
	playButton.setButtonText("PLAY");
	playButton.onClick = [this] {callMidiFile(playFile);};

	addAndMakeVisible(stopButton);
	stopButton.setButtonText("STOP");
	stopButton.onClick = [this] {callMidiFile(stopFile);};
	
	addAndMakeVisible(onceButton);
	onceButton.setButtonText("ONCE");
	onceButton.onClick = [this] {callMidiFile(onceFile);};
	
	addAndMakeVisible(undoButton);
	undoButton.setButtonText("UNDO");
	undoButton.onClick = [this] {callMidiFile(undoFile);};

	addAndMakeVisible(revButton);
	revButton.setButtonText("REVERSE");
	revButton.onClick = [this] {callMidiFile(revFile);};

	addAndMakeVisible(fwdButton);
	fwdButton.setButtonText("FORWARD");
	fwdButton.onClick = [this] {callMidiFile(fwdFile);};

	addAndMakeVisible(halfButton);
	halfButton.setButtonText("HALF SPEED");
	halfButton.onClick = [this] {callMidiFile(halfFile);};

	addAndMakeVisible(fullButton);
	fullButton.setButtonText("FULL SPEED");
	fullButton.onClick = [this] {callMidiFile(fullFile);};

	addAndMakeVisible(snap1);
	snap1.setButtonText("SNAPSHOT 1");
	snap1.onClick = [this] {callMidiFile(snap1File);};

	addAndMakeVisible(snap2);
	snap2.setButtonText("SNAPSHOT 2");
	snap2.onClick = [this] {callMidiFile(snap2File);};

	addAndMakeVisible(snap3);
	snap3.setButtonText("SNAPSHOT 3");
	snap3.onClick = [this] {callMidiFile(snap3File);};

	addAndMakeVisible(snap4);
	snap4.setButtonText("SNAPSHOT 4");
	snap4.onClick = [this] {callMidiFile(snap4File);};

	addAndMakeVisible(snap5);
	snap5.setButtonText("SNAPSHOT 5");
	snap5.onClick = [this] {callMidiFile(snap5File);};

	addAndMakeVisible(snap6);
	snap6.setButtonText("SNAPSHOT 6");
	snap6.onClick = [this] {callMidiFile(snap6File);};

	addAndMakeVisible(snap7);
	snap7.setButtonText("SNAPSHOT 7");
	snap7.onClick = [this] {callMidiFile(snap7File);};

	addAndMakeVisible(snap8);
	snap8.setButtonText("SNAPSHOT 8");
	snap8.onClick = [this] {callMidiFile(snap8File);};
}

void HxpanderAudioProcessorEditor::callMidiFile(StringArray Files)
{
	//String path = Files;
	//debug.setText(path);
	bool dragRes = DragAndDropContainer::performExternalDragDropOfFiles(Files, true);
}


HxpanderAudioProcessorEditor::~HxpanderAudioProcessorEditor()
{
	setLookAndFeel(nullptr);
}

//==============================================================================
void HxpanderAudioProcessorEditor::paint (Graphics& g)
{
	//g.fillAll(Colours::lightgrey);
	g.fillAll(Colours::black);
	int cornerSize = 5;
	Rectangle<float> insideWindow(675,320);
	//g.setColour(Colours::grey);
	g.setColour(Colour(0xFF1B1915));
	g.fillRoundedRectangle(insideWindow.reduced(10), cornerSize);

	Rectangle<float> line1 (23,55,625,40);
	Rectangle<float> line2(23,105,625,40);
	Rectangle<float> line3(23, 205, 625, 40);
	Rectangle<float> line4(23, 255, 625, 40);
	//g.setColour(Colours::darkgrey);
	g.setColour(Colours::black);
	g.fillRoundedRectangle(line1, cornerSize);
	g.fillRoundedRectangle(line2, cornerSize);
	g.fillRoundedRectangle(line3, cornerSize);
	g.fillRoundedRectangle(line4, cornerSize);
}

void HxpanderAudioProcessorEditor::resized()
{
	auto width = getWidth();
	int column1 = 35, column2 = 160, column3 = 285, column4 = 410, column5 = 535,
		row1 = 10, row2 = 60, row3 = 110, row4 = 160, row5 = 210, row6 = 260,
		buttonWidth = 100, buttonHeight = 30, middle = getWidth() / 2;

	//debug.setBounds(0, 320, getWidth(), 100);

	looperLable.setBounds(column1-10, row1, width, 50);
	
	recButton.setBounds(column1, row2, buttonWidth, buttonHeight);
	ovdButton.setBounds(column2, row2, buttonWidth, buttonHeight);
	playButton.setBounds(column3, row2, buttonWidth, buttonHeight);
	stopButton.setBounds(column4, row2, buttonWidth, buttonHeight);
	onceButton.setBounds(column5, row2, buttonWidth, buttonHeight);
	undoButton.setBounds(column1, row3, buttonWidth, buttonHeight);
	revButton.setBounds(column2, row3, buttonWidth, buttonHeight);
	fwdButton.setBounds(column3, row3, buttonWidth, buttonHeight);
	halfButton.setBounds(column4, row3, buttonWidth, buttonHeight);
	fullButton.setBounds(column5, row3, buttonWidth, buttonHeight);

	snapshotsLable.setBounds(column1 - 10, row4, width, 50);

	snap1.setBounds(column1, row5, buttonWidth, buttonHeight);
	snap2.setBounds(column2, row5, buttonWidth, buttonHeight);
	snap3.setBounds(column3, row5, buttonWidth, buttonHeight);
	snap4.setBounds(column4, row5, buttonWidth, buttonHeight);
	snap5.setBounds(column5, row5, buttonWidth, buttonHeight);
	snap6.setBounds(column1, row6, buttonWidth, buttonHeight);
	snap7.setBounds(column2, row6, buttonWidth, buttonHeight);
	snap8.setBounds(column3, row6, buttonWidth, buttonHeight);
}
