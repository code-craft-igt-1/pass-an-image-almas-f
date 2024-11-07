#include "brightener.h"
#include <bits/stdc++.h>
using namespace std;
ImageBrightener::ImageBrightener(Image& inputImage) : m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;
    
    for (int x = 0; x < m_inputImage.rows; x++) {
        for (int y = 0; y < m_inputImage.columns; y++) {
            int pixelIndex = x * m_inputImage.columns + y;
            
            if (m_inputImage.pixels[pixelIndex] > (255 - 25)) {
                ++attenuatedPixelCount;
                m_inputImage.pixels[pixelIndex] = 255;
            } else {
                m_inputImage.pixels[pixelIndex] = min(m_inputImage.pixels[pixelIndex] + 25, 255);
            }
        }
    }
    
    return attenuatedPixelCount;
}


Image ImageBrightener::GetImage() {
	return m_inputImage;
}
