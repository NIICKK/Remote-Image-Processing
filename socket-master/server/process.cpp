#include <stdint.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include "process.h"

using namespace std;
unsigned char* out[40*40*3] = {0};

unsigned char* transform(const char* filename){
    int width, height, bpp;
    uint8_t* rgb_image;
    rgb_image = stbi_load(filename, &width, &height, &bpp, 3);
    int h = height-(height%40);
    int w = width -(width%40);
    unsigned char red[w*h] ;
    unsigned char green[w*h];
    unsigned char blue[w*h];
    //unsigned char out[w*h*3] ={0};


    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++){
            unsigned char* pixelOffset = rgb_image+(i+h*j)*3;
            red[(i+h*j)] = pixelOffset[0];
            green[i+h*j] = pixelOffset[1];
            blue[i+h*j] = pixelOffset[2];
        }
    }


    memcpy(out, red, sizeof(red));
    memcpy(out+sizeof(red), green, sizeof(green));
    memcpy(out+sizeof(red)+sizeof(green), blue, sizeof(blue));


    stbi_image_free(rgb_image);
    return out[0];

}

/*
void transform_boat(const char* file){
    int width, height, bpp;
    uint8_t* rgb_image;
    rgb_image = stbi_load(file, &width, &height, &bpp, 3);

    int h = height-(height%40);
    int w = width -(width%40);


    for(int k =0;k<50*50;k++){
        unsigned char *block = (unsigned char*)malloc(40*40*3*sizeof(unsigned char));
        int row = k/50;
        int col = k-row*50;
        for(int z=0;z<40;z++){
            for(int y=0; y<40;y++){

            }
            block[];
        }
    }


    unsigned char *red = (unsigned char*)malloc(w*h*sizeof(unsigned char));
    unsigned char *green = (unsigned char*)malloc(w*h*sizeof(unsigned char));
    unsigned char *blue = (unsigned char*)malloc(w*h*sizeof(unsigned char));


    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++){
            unsigned char* pixelOffset = rgb_image+(i+h*j)*3;
            red[(i+h*j)] = pixelOffset[0];
            green[i+h*j] = pixelOffset[1];
            blue[i+h*j] = pixelOffset[2];
        }
    }
    ofstream myfile ("boat.txt");
    if (myfile.is_open())
    {
        myfile << w<<" "<<h<<" "<<bpp<<"\n";

        for(int count = 0; count < w*h; count ++){
            myfile << (int)red[count] << " " ;
        }
        for(int count = 0; count < w*h; count ++){
            myfile << (int)green[count] << " " ;
        }
        for(int count = 0; count < w*h; count ++){
            myfile << (int)blue[count] << " " ;
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    stbi_image_free(rgb_image);
    free(red);
    free(green);
    free(blue);

}*/



void transform_image(const char* file){
    int width, height, bpp;
    uint8_t* rgb_image;
    rgb_image = stbi_load(file, &width, &height, &bpp, 3);

    unsigned char *rgb_array = (unsigned char*)malloc(width*height*sizeof(unsigned char));

    for (int k = 0; k < width * height; ++k) {
        int line = k / width;
        int col = k % height;
        int smalli = line / 40;
        int smallj = col / 40;
        int i = line % 40;
        int j = col % 40;
        rgb_array[(smalli * 50 + smallj)*40*40*3+i*40+j] = rgb_image[3 * k];
        rgb_array[(smalli * 50 + smallj)*40*40*3+i*40+j + 40 * 40] = rgb_image[3 * k + 1];
        rgb_array[(smalli * 50 + smallj)*40*40*3+i*40+j + 40 * 40 + 40 * 40] = rgb_image[3 * k + 2];
    }

    ofstream myfile ("boat.txt");
    if (myfile.is_open())
    {
        myfile << width<<" "<<height<<" "<<bpp<<"\n";

        for(int count = 0; count < width * height; ++count){
            myfile << (int)rgb_array[count] << " " ;
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    stbi_image_free(rgb_image);
    free(rgb_array);

}




void to_image(){
    int index[] = {0,1,2,3};
    int w = 80;
    int h = 40;
    int c = 3;
    uint8_t *image;
    int index_len = 4;
    int index_sqrt = 2;
    image = (uint8_t *)malloc(w*h*c*sizeof(uint8_t));

    int i =1;
    while(i<index_len) {
        int width, height, bpp;
        uint8_t *rgb_image;
         int image_num = index[i]+1;

        int image_row = (image_num-1) / index_sqrt;
        int image_col = image_num- image_row* index_sqrt-1;

        string str = "outimages/" + std::to_string(static_cast<long long>(image_num)) + ".bmp";
        const char *file_name = str.c_str();
        rgb_image = stbi_load(file_name, &width, &height, &bpp, 3);
        for (int y = 0; y < width; y++) {
            for (int x = 0; x < height; x++) {
                unsigned char *pixelOffset = rgb_image + (x + width * y) * 3;

                //int image_row = image_num / index_sqrt;
                //int image_col = image_num - image_row* index_sqrt;
                //int image_index = ((y + 40 * image_row + w * (image_col + x)))*3;
                //unsigned int image_index = (40*image_row+image_col*40*w)*3+(x + width * y) * 3;
                unsigned int image_index = (40*(image_row)+x+(image_col*40+y)*w)*3;
                image[image_index] = pixelOffset[0];
                image[image_index + 1] = pixelOffset[1];
                image[image_index + 2] = pixelOffset[2];
            }
        }
        i++;
    }

    stbi_write_png("transformed.png", w, h, c, image,w*c);
    free(image);
}


void out_put(){
    ofstream myfile ("output1.txt");
    myfile <<40<<" "<<40<<" "<<3*890<<"\n";
    for(int i =1;i<891;i++){
        if (myfile.is_open())
        {
            //myfile <<40<<" "<<40<<" "<<3*890<<"\n";
            for(int count = 0; count < 40*40*3; count ++){
                string str = "outimages/"+to_string(static_cast<long long>(i))+".bmp";
                const char * file_name  = str.c_str();
                myfile << (int)transform(file_name)[count] << " " ;
            }
            myfile<<"\n";

        }
        else cout << "Unable to open file";
    }
    myfile.close();
}



/*int main() {
    out_put();  //transform small images to txt as the building blocks.
    transform_image("received_image.jpg"); //transform image from the client to txt as CUDA as input
    //out_put();
    to_image();
    return 0;

}*/