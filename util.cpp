#include "include/util.hpp"

namespace util{
	const char* title = "SpaceGame";
	Color grey = {29, 29, 27, 255};
	Color LaserColor = {243, 216, 63, 255};
	Color BlockColor = {243, 216, 63, 255};
	std::vector<Texture2D> PNGtoAnim(Image image, int number){
		int Width = image.width / number;
		int Height = image.height;
		Rectangle CropRec;
		std::vector<Texture2D> anim;
		
		for(int i = 0; i < number; i++){
		
			CropRec = {(float)Width * i, 0.0, (float)Width, (float)Height};
			
			std::cout << CropRec.x << "\n";
			
			Image tempimage = ImageFromImage(image, CropRec);
			Texture2D temptexture = LoadTextureFromImage (tempimage);
			anim.push_back(temptexture);
			UnloadImage(tempimage);
			// UnloadTexture(temptexture);
			
		}
		
		return anim; 
		
		
	}

}
