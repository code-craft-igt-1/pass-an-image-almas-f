#include <iostream>
#include "brightener.h"

int main() {
	auto image = std::make_unique<Image>();
    image->rows = 512;
    image->columns = 512;
	std::cout << "Brightening a 512 x 512 image\n";
    auto brightener = std::make_unique<ImageBrightener>(*image);
    int attenuatedCount = brightener->BrightenWholeImage();
    std::cout << "Attenuated " << attenuatedCount << " pixels\n";
   
}
