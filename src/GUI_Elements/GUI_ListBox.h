/*
  Tibia CLient
  Copyright (C) 2019 Saiyans King

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef __FILE_GUI_LISTBOX_h_
#define __FILE_GUI_LISTBOX_h_

#include "GUI_Element.h"

class GUI_VScrollBar;
class GUI_ListBox : public GUI_Element
{
	public:
		GUI_ListBox(iRect boxRect, Uint32 internalID = 0);
		~GUI_ListBox();

		void setRect(iRect& NewRect);
		void setEventCallback(void(*eventHandlerFunction)(Uint32, Sint32), Uint32 mEvent);

		SDL_FORCE_INLINE Sint32 getSelect() {return m_select;}
		void setSelect(Sint32 select);

		void add(const std::string data);
		void erase(Sint32 select);

		void onKeyDown(SDL_Event event);
		void onLMouseDown(Sint32 x, Sint32 y);
		void onLMouseUp(Sint32 x, Sint32 y);
		void onMouseMove(Sint32 x, Sint32 y, bool isInsideParent);
		void onWheel(Sint32 x, Sint32 y, bool wheelUP);
		void render();

	protected:
		void (*m_eventHandlerFunction)(Uint32, Sint32);
		std::vector<std::string> m_listBox;
		GUI_VScrollBar* m_scrollBar;
		Uint32 m_evtParam;
		Uint32 m_lastClick;
		Sint32 m_maxDisplay;
		Sint32 m_select;
		bool m_doubleClicked;
};

#endif /* __FILE_GUI_LISTBOX_h_ */
