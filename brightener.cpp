#include "brightener.h"
#include <algorithm>    
using namespace std;
ImageBrightener::ImageBrightener(Image& inputImage) : m_inputImage(inputImage) {
}

 // Brightens the whole image and returns the number of attenuated pixels
int ImageBrightener::BrightenWholeImage() {        
	int attenuatedCount = 0;

        for (int i = 0; i < m_inputImage.rows; ++i) {
            for (int j = 0; j < m_inputImage.columns; ++j) {
                int index = i * m_inputImage.columns + j; // Calculate pixel index
                uint8_t& pixel = m_inputImage.pixels[index]; // Access pixel

                // Brighten pixel (increase its value)
                if (pixel < 255) {
                    pixel += 10; // Increase brightness by 10 (capped at 255)
                    ++attenuatedCount;
                }
            }
        }

        return attenuatedCount;
    }
/*int ImageBrightener::BrightenWholeImage() {
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
}*/


Image ImageBrightener::GetImage() {
	return m_inputImage;
}
