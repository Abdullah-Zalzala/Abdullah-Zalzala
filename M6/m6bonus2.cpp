#include <iostream>
#include <fstream>

int main() {
    // Image dimensions (at least 100x100)
    const int width = 200;
    const int height = 200;

    // Output file name
    const std::string filename = "output.ppm";

    // Create and open the .ppm file using ofstream
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return 1;
    }

    // Write the PPM header
    // P3 = ASCII PPM format
    // width height
    // 255 = max color value
    ofs << "P3\n" << width << " " << height << "\n255\n";

    // Generate pixel data using nested loops
    // We'll create a simple color gradient for demonstration.
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Simple gradient:
            // Red varies with x, Green varies with y, Blue is constant
            int red   = (255 * x) / (width - 1);   // from 0 to 255 across width
            int green = (255 * y) / (height - 1);  // from 0 to 255 down height
            int blue  = 128;                       // constant mid-level blue

            // Write the RGB values to the file
            ofs << red << " " << green << " " << blue << " ";
        }
        ofs << "\n";
    }

    ofs.close();
    std::cout << "PPM image generated: " << filename << std::endl;
    return 0;
}