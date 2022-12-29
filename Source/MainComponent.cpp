#include "MainComponent.h"
using namespace juce;
//==============================================================================
MainComponent::MainComponent()
{
    dial1.setSliderStyle(Slider::Rotary);
    dial1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(dial1);

    dial2.setSliderStyle(Slider::Rotary);
    dial2.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(dial2);

    slider1.setSliderStyle(Slider::LinearHorizontal);
    slider1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(slider1);

    setSize (600, 400);
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll(Colours::aquamarine);
}

void MainComponent::resized()
{
    const int border = 20;

    Rectangle<int> totalArea = getLocalBounds();
    Rectangle<int> dialSection = totalArea.removeFromTop(totalArea.getHeight() / 2);

    dial1.setBounds(dialSection.removeFromLeft(totalArea.getWidth() / 2));
    dial2.setBounds(dialSection.removeFromRight(totalArea.getWidth() / 2).reduced(border));

    slider1.setBounds(totalArea);
}
