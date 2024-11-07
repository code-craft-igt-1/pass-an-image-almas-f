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



Image ImageBrightener::GetImage() {
	return m_inputImage;
}
