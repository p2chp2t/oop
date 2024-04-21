#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <cstdint>
#include <cassert>
#include "SharedPtr.h"

///////////////////////////////////////////////////////////////////////////
// RGB pixel type
//    Usage:
//      - RGB<float> rgb(0.5f, 0.1f, 0.3f);
//        rgb[0] = 0.2f; // or equivalently, rgb.r = 0.2f;
template<typename ValType>
struct RGB
{
	union {
		ValType data[3];
		struct {
			ValType r, g, b;
		};
	};

	RGB() {}
	RGB(ValType r_, ValType g_, ValType b_) : r(r_), g(g_), b(b_) {}

	ValType operator[](int idx) const { return data[idx]; }
	ValType& operator[](int idx) { return data[idx]; }
};

typedef RGB<uint8_t>	RGB8b;
typedef RGB<float>		RGBf;


///////////////////////////////////////////////////////////////////////////
// Image class template
//
template<typename PixelType>
class Image
{
private:
	// ======= ADD CODE HERE IF NEEDED =========
	size_t m_width;
	size_t m_height;
	SharedArray<PixelType> m_buff;

public:
	////////////////////////////////////////////
	// constructors & destructor
	////////////////////////////////////////////

	/*default constructor*/
	Image() :m_width(0), m_height(0) {}

	/*이미지 너비와 높이 인자로 받을 때 constructor*/
	Image(size_t _width, size_t _height) :m_width(_width), m_height(_height),
		m_buff(new PixelType[_width * _height]) {}

	/*초기화할 픽셀 값이 주어졌을 때*/
	Image(size_t _width, size_t _height, const PixelType& val) :m_width(_width), m_height(_height) {
		m_buff = new PixelType[_width * _height]; //이미지 크기만큼 메모리 할당
		for (size_t i = 0;i < _height;i++) {
			for (size_t j = 0;j < _width;j++) //픽셀값 초기화
				m_buff[j + i * _width] = val;
		}
	}

	/*copy constructor*/
	Image(const Image<PixelType>& img) {
		m_width = img.m_width;
		m_height = img.m_height;
		m_buff = new PixelType[m_width * m_height];
		for (size_t i = 0;i < m_height;i++) {
			for (size_t j = 0;j < m_width;j++) //픽셀값 초기화
				m_buff[j + i * m_width] = img.m_buff[j + i * m_width];
		}
	}

	/*destructor*/
	~Image() {}

	////////////////////////////////////////////
	// assignment operator
	////////////////////////////////////////////

	/*객체를 다른 객체에 대입*/
	Image& operator=(const Image& img) {
		//assign
		m_width = img.m_width;
		m_height = img.m_height;
		m_buff = new PixelType[m_width * m_height]; 
		for (size_t i = 0;i < m_height;i++) {
			for (size_t j = 0;j < m_width;j++) //픽셀값 대입
				m_buff[j + i * m_width] = img.m_buff[j + i * m_width];
		}
		return *this;
	}

	////////////////////////////////////////////
	// element access operators
	////////////////////////////////////////////

	PixelType* operator[](int y) { return &m_buff[y * m_width]; }
	const PixelType* operator[](int y) const { return &m_buff[y * m_width]; }

	////////////////////////////////////////////
	// other methods
	////////////////////////////////////////////
	//   - width(), height()

	size_t width() const { return this->m_width; }
	size_t height() const { return this->m_height; }

};

// ======= ADD CODE HERE IF NEEDED =========


// Miscellaneous functions
void convert_pixel_type(const Image<RGB8b>& src, Image<RGBf>& dst);
void convert_pixel_type(const Image<RGBf>& src, Image<RGB8b>& dst);

bool load_bmp(const char* path, Image<RGB8b>& img);
bool save_bmp(const char* path, const Image<RGB8b>& img);

#endif
