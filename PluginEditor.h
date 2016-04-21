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

#ifndef __JUCE_HEADER_2080A0FFE421A366__
#define __JUCE_HEADER_2080A0FFE421A366__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PanoramaAudioProcessorEditor  : public AudioProcessorEditor,
                                      public Timer,
                                      public SliderListener,
                                      public ComboBoxListener,
                                      public ButtonListener
{
public:
    //==============================================================================
    PanoramaAudioProcessorEditor (PanoramaAudioProcessor& ownerFilter);
    ~PanoramaAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();

    PanoramaAudioProcessor* getProcessor() const {
		return static_cast <PanoramaAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> panSld;
    ScopedPointer<Label> Title;
    ScopedPointer<ComboBox> algorithmSelect;
    ScopedPointer<Slider> panLawSld;
    ScopedPointer<ToggleButton> panLawEnabledBtn;
    ScopedPointer<ToggleButton> bypassBtn;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PanoramaAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_2080A0FFE421A366__
