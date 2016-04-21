/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PanoramaAudioProcessorEditor::PanoramaAudioProcessorEditor (PanoramaAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (panSld = new Slider ("Pan"));
    panSld->setRange (-100, 100, 1);
    panSld->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    panSld->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    panSld->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    panSld->setColour (Slider::thumbColourId, Colours::white);
    panSld->setColour (Slider::trackColourId, Colour (0x00ffffff));
    panSld->setColour (Slider::rotarySliderFillColourId, Colour (0x00c8c8c8));
    panSld->addListener (this);

    addAndMakeVisible (Title = new Label ("Title",
                                          TRANS("Panorama")));
    Title->setFont (Font ("Lucida Console", 36.60f, Font::plain));
    Title->setJustificationType (Justification::centred);
    Title->setEditable (false, false, false);
    Title->setColour (Label::textColourId, Colours::white);
    Title->setColour (TextEditor::textColourId, Colours::black);
    Title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (algorithmSelect = new ComboBox ("Algorithm"));
    algorithmSelect->setEditableText (false);
    algorithmSelect->setJustificationType (Justification::centredLeft);
    algorithmSelect->setTextWhenNothingSelected (String::empty);
    algorithmSelect->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    algorithmSelect->addItem (TRANS("Linear Crossfade"), 1);
    algorithmSelect->addItem (TRANS("Equal Power"), 2);
    algorithmSelect->addItem (TRANS("Speaker-to-Speaker"), 3);
    algorithmSelect->addListener (this);

    addAndMakeVisible (panLawSld = new Slider ("Pan Law"));
    panLawSld->setRange (0, 10, 0.1);
    panLawSld->setSliderStyle (Slider::LinearHorizontal);
    panLawSld->setTextBoxStyle (Slider::TextBoxRight, false, 40, 20);
    panLawSld->setColour (Slider::thumbColourId, Colour (0xff909090));
    panLawSld->addListener (this);

    addAndMakeVisible (panLawEnabledBtn = new ToggleButton ("Pan Law Enabled"));
    panLawEnabledBtn->addListener (this);
    panLawEnabledBtn->setToggleState (true, dontSendNotification);
    panLawEnabledBtn->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (bypassBtn = new ToggleButton ("Bypass"));
    bypassBtn->addListener (this);
    bypassBtn->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Pan Law\n")));
    label->setFont (Font (24.10f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Algorithm\n")));
    label2->setFont (Font (24.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("dB")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (296, 424);


    //[Constructor] You can add your own custom stuff here..
    startTimer(30);

    //Set double-click return values
    panSld->setDoubleClickReturnValue(true, 0);


    //Force a parameter reset upon re-opening.
    ownerFilter.requestUIUpdate();
    timerCallback();
    //[/Constructor]
}

PanoramaAudioProcessorEditor::~PanoramaAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    panSld = nullptr;
    Title = nullptr;
    algorithmSelect = nullptr;
    panLawSld = nullptr;
    panLawEnabledBtn = nullptr;
    bypassBtn = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PanoramaAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff6900cb));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PanoramaAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    panSld->setBounds (40, 80, 208, 136);
    Title->setBounds (40, 16, 216, 48);
    algorithmSelect->setBounds (40, 264, 208, 24);
    panLawSld->setBounds (40, 320, 184, 24);
    panLawEnabledBtn->setBounds (40, 352, 150, 24);
    bypassBtn->setBounds (40, 376, 150, 24);
    label->setBounds (40, 296, 96, 24);
    label2->setBounds (40, 232, 112, 24);
    label3->setBounds (224, 320, 31, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PanoramaAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    PanoramaAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == panSld)
    {
        //[UserSliderCode_panSld] -- add your slider handling code here..
        ourProcessor->setParameter(PanoramaAudioProcessor::pan, (float) panSld->getValue());
        //[/UserSliderCode_panSld]
    }
    else if (sliderThatWasMoved == panLawSld)
    {
        //[UserSliderCode_panLawSld] -- add your slider handling code here..
        ourProcessor->setParameter(PanoramaAudioProcessor::panLaw, (float) panLawSld->getValue());
        //[/UserSliderCode_panLawSld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PanoramaAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    PanoramaAudioProcessor* ourProcessor = getProcessor();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == algorithmSelect)
    {
        //[UserComboBoxCode_algorithmSelect] -- add your combo box handling code here..
        ourProcessor->setParameter(PanoramaAudioProcessor::algorithm, (float) algorithmSelect->getSelectedItemIndex());
        //[/UserComboBoxCode_algorithmSelect]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void PanoramaAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    PanoramaAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == panLawEnabledBtn)
    {
        //[UserButtonCode_panLawEnabledBtn] -- add your button handler code here..
        ourProcessor->setParameter(PanoramaAudioProcessor::panLawEnabled, (float) panLawEnabledBtn->getToggleState());
        //[/UserButtonCode_panLawEnabledBtn]
    }
    else if (buttonThatWasClicked == bypassBtn)
    {
        //[UserButtonCode_bypassBtn] -- add your button handler code here..
        ourProcessor->setParameter(PanoramaAudioProcessor::masterBypass, (float) bypassBtn->getToggleState());
        //[/UserButtonCode_bypassBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PanoramaAudioProcessorEditor::timerCallback() {
    PanoramaAudioProcessor* ourProcessor = getProcessor();

    //Perform necessary UI updates
    if(ourProcessor->needsUIUpdate()) {
        //Update panSld's state
        panSld->setValue(ourProcessor->getParameter(PanoramaAudioProcessor::pan), dontSendNotification);

        //Update panLawSld's state
        panLawSld->setValue(ourProcessor->getParameter(PanoramaAudioProcessor::panLaw), dontSendNotification);

        //Update panLawEnabledBtn's state
        panLawEnabledBtn->setToggleState(1.0f == ourProcessor->getParameter(PanoramaAudioProcessor::panLawEnabled), dontSendNotification);

        //Update bypassBtn's state
        bypassBtn->setToggleState(1.0f == ourProcessor->getParameter(PanoramaAudioProcessor::masterBypass), dontSendNotification);

        //update algorithmSelect's state
        algorithmSelect->setSelectedItemIndex((int) ourProcessor->getParameter(PanoramaAudioProcessor::algorithm), dontSendNotification);

        //We're done; clear the UI update flag
        ourProcessor->clearUIUpdateFlag();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PanoramaAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="PanoramaAudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="296" initialHeight="424">
  <BACKGROUND backgroundColour="ff6900cb">
    <RECT pos="-8 -8 296 424" fill="solid: e2ccd6" hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Pan" id="4078155c81af598b" memberName="panSld" virtualName=""
          explicitFocusOrder="0" pos="40 80 208 136" bkgcol="ffffff" thumbcol="ffffffff"
          trackcol="ffffff" rotarysliderfill="c8c8c8" min="-100" max="100"
          int="1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Title" id="e590c60e54b0ea8c" memberName="Title" virtualName=""
         explicitFocusOrder="0" pos="40 16 216 48" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Panorama" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Lucida Console"
         fontsize="36.600000000000001" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="Algorithm" id="f09b7b27668d5441" memberName="algorithmSelect"
            virtualName="" explicitFocusOrder="0" pos="40 264 208 24" editable="0"
            layout="33" items="Linear Crossfade&#10;Equal Power&#10;Speaker-to-Speaker"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="Pan Law" id="1c663294ce72c0ec" memberName="panLawSld" virtualName=""
          explicitFocusOrder="0" pos="40 320 184 24" thumbcol="ff909090"
          min="0" max="10" int="0.10000000000000001" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="Pan Law Enabled" id="f1a36e1844919f1d" memberName="panLawEnabledBtn"
                virtualName="" explicitFocusOrder="0" pos="40 352 150 24" txtcol="ffffffff"
                buttonText="Pan Law Enabled" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="Bypass" id="d9ca914f9b3df8eb" memberName="bypassBtn" virtualName=""
                explicitFocusOrder="0" pos="40 376 150 24" txtcol="ffffffff"
                buttonText="Bypass" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <LABEL name="new label" id="99d93ba3be76a485" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="40 296 96 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Pan Law&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="24.100000000000001" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8b07e0827979f5b8" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="40 232 112 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Algorithm&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="24" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="85ca32ba7f1f6679" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="224 320 31 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="dB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
