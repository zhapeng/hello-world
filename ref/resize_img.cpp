#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image/stb_image_write.h>

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb_image/stb_image_resize.h>



using namespace std;


int main(int argc, char* argv[])
{
    std::cout << "Hello, STB_Image" << std::endl;

    string inputPath = "input.png";
    int iw, ih, n;

    // Loadint image, get width, height, channels
    unsigned char *idata = stbi_load(inputPath.c_str(), &iw, &ih, &n, 0);

    int ow = iw / 2;
    int oh = ih / 2;
    auto *odata = (unsigned char *)malloc(ow * oh * n);

    // resize image size
    stbi_resize(idata, iw, ih, 0, odata, ow, oh, 0, STBIR_TYPE_UINT8, n, STBIR_ALPATHA_CHANNEL_NONE, 0,
                STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP,
                STBIR_FILTER_BOX, STBIR_FILTER_BOX,
                STBIR_COLORSPACE_SRGB, nullptr
    );

    string outputPath = "out.png";
    stbi_write_png(outputPath.c_str(), ow, oh, n, odata, 0);
    
    stbi_image_free(idata):
    stbi_image_free(odata);
    return 0;
}
