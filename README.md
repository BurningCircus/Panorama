# Panorama

A 32-bit, stereo VST plugin implemented using the JUCE interface.

The Panorama plugin is an exercise in taking a basic process, in this case gain, and creating something useful and not trivially obvious out of it. Panorama is designed to be more robust than the typical pan controls found in a DAW; it offers the user a choice between three different panning algorithms and a user-adjustable pan law, as well as a finer degree of panning precision than many DAWs.

Panning, conceptually, is a technique used in multi-channel audio mixing to “place” different sources at separate virtual locations in the sound field. Panning is used most often in a stereo configuration to place a sound source right or left of the perceived center point of the stereo image. This is accomplished by varying the amount of gain that is sent to each stereo channel. For instance, to pan a sound source to the left, one would decrease the gain of the sound source being sent to the right channel. This causes the source to be perceived as coming more strongly from the left side of the stereo image.

Panorama.h, Panorama.cpp: The DSP source code.

PluginProcessor.h, PluginProcessor.cpp: The JUCE wrapper for the DSP source.

PluginEditor.h, PluginEditor.cpp: The JUCE wrapper for GUI elements.
