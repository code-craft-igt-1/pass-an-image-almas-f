#pragma once
#include <cstdint>
#include <memory>
struct Image {
	int rows;
	int columns;
	    std::unique_ptr<uint8_t[]> pixels; // Use unique_ptr to manage pixel data

    // Constructor that allocates memory for the pixels based on the image size
    Image(int rows, int columns)
        : rows(rows), columns(columns), pixels(std::make_unique<uint8_t[]>(rows * columns)) {}
};

class ImageBrightener {
private:
	Image m_inputImage;
public:
	ImageBrightener(Image& inputImage);
	int BrightenWholeImage();
	Image GetImage();
};
