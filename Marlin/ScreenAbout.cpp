#include "ScreenAbout.h"

#include "GuiBitmaps_witbox_2.h"
#include "language.h"

namespace screen
{
	ScreenAbout::ScreenAbout(const char * title, const char * text, const char * box, const unsigned char * bitmap)
		: Screen(title, MENU)
		, m_text(text)
		, m_box(box)
		, m_bitmap(bitmap)
	{ }

	ScreenAbout::~ScreenAbout()
	{ }

	void ScreenAbout::draw()
	{
		//Start painting sequence
		painter.firstPage();
		do 
		{
			painter.setColorIndex(1);
			//Paint title on top of screen
			painter.title(m_title);
			//Paint selection box on bottom of screen
			painter.box(m_box);
			//Paint bitmap on the left
			uint8_t x_init = painter.coordinateXInit();
			uint8_t y_init = painter.coordinateYInit();
			uint8_t x_end = painter.coordinateXEnd();
			uint8_t y_end = painter.coordinateYEnd();
			uint8_t x_offset = 10;
			uint8_t y_offset = (y_end - y_init - logo_height) / 2;
			painter.setColorIndex(1);
			painter.drawBitmap(x_init + x_offset, y_init + y_offset, logo_width, logo_height, bits_logo_about);
			//Paint text on the screen
			char t[64];
			strcpy(t, MACHINE_NAME);
			strcat(t, " ");
			strcat(t, FIRMWARE_VER);
			strcat(t, " ");
			strcat(t, BUILD_VER);

			painter.text(t, 5);
	
		} while( painter.nextPage() ); 

	}

	void ScreenAbout::press()
	{
		ViewManager::getInstance().activeView(m_next_screen);
	}

	void ScreenAbout::add(Screen & component)
	{
		m_next_screen = &component;
	}
}