#include "GBitmap.h"
#include "GCanvas.h"
#include "GRect.h"
#include "GColor.h"


class MyCanvas : public GCanvas {
public:

    //constructor loads initial value of bitmap (from argument)
    MyCanvas(const GBitmap& device) : fDevice(device) {}

    void clear(const GColor& color) override {
        GColor color2 = color.pinToUnit();
        //loop through all the pixels and change them all 
         for (int y = 0; y < fDevice.height(); ++y) {       
            for (int x = 0; x < fDevice.width(); ++x) {
                GPixel* row = fDevice.getAddr(x,y);
                *row = GPixel_PackARGB(
                    GRoundToInt(color2.fA*255),
                    GRoundToInt(color2.fR*255),
                    GRoundToInt(color2.fG*255),
                    GRoundToInt(color2.fB*255)
                );
            }
        }
    }
    void fillRect(const GRect& rect, const GColor& color) override {

     GIRect actualArea = rect.round();
    if(actualArea.intersect(GIRect::MakeXYWH(0,0,fDevice.width(),fDevice.height()))){               
                for(int x=actualArea.left(); x<actualArea.right(); ++x){
                    for(int y=actualArea.top(); y<actualArea.bottom(); ++y){
                            int a = (color.fA*255+.5)+((255-(int)(color.fA*255+.5))*GPixel_GetA(*(fDevice.getAddr(x,y)))+127)/255; 
                            int r = (color.fR*color.fA*255+.5)+((255-(int)(color.fA*255+.5))*GPixel_GetR(*(fDevice.getAddr(x,y)))+127)/255; 
                            int g = (color.fG*color.fA*255+.5)+((255-(int)(color.fA*255+.5))*GPixel_GetG(*(fDevice.getAddr(x,y)))+127)/255; 
                            int b = (color.fB*color.fA*255+.5)+((255-(int)(color.fA*255+.5))*GPixel_GetB(*(fDevice.getAddr(x,y)))+127)/255;

                        *fDevice.getAddr(x,y) = GPixel_PackARGB(a,r,g,b);
                }
            }

    }

    }



private:
    const GBitmap fDevice;
};

std::unique_ptr<GCanvas> GCreateCanvas(const GBitmap& device) {
    if (!device.pixels()) {
        return nullptr;
    }
    return std::unique_ptr<GCanvas>(new MyCanvas(device));
}
