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

#ifndef __FILE_CONTAINER_h_
#define __FILE_CONTAINER_h_

#include "position.h"

class ItemUI;
class Container
{
	public:
		Container(Uint8 cid, ItemUI* item, std::string name, Uint8 capacity, bool hasParent, bool canUseDepotSearch, bool isUnlocked, bool hasPages, Uint16 containerSize, Uint16 firstIndex);
		~Container();
		
		SDL_FORCE_INLINE ItemUI* getItem() {return m_containerItem;}
		ItemUI* getItem(size_t index);
		SDL_FORCE_INLINE std::vector<ItemUI*>& getItems() {return m_items;}
		SDL_FORCE_INLINE std::string& getName() {return m_name;}
		SDL_FORCE_INLINE Uint16 getSize() {return m_size;}
		SDL_FORCE_INLINE Uint16 getFirstIndex() {return m_firstIndex;}
		SDL_FORCE_INLINE Uint8 getCid() {return m_id;}
		SDL_FORCE_INLINE Uint8 getCapacity() {return m_capacity;}
		SDL_FORCE_INLINE bool hasParent() {return m_hasParent;}
		SDL_FORCE_INLINE bool canUseDepotSearch() {return m_canUseDepotSearch;}
		SDL_FORCE_INLINE bool isUnlocked() {return m_isUnlocked;}
		SDL_FORCE_INLINE bool hasPages() {return m_hasPages;}

		SDL_INLINE void resetDirty() {m_dirty = false;}
		SDL_FORCE_INLINE bool isDirty() {return m_dirty;}

		void addItem(Uint16 slot, ItemUI* item);
		void setItems(std::vector<ItemUI*>& items);
		void transformItem(Uint16 slot, ItemUI* item);
		void removeItem(Uint16 slot, ItemUI* lastItem);

	protected:
		void updatePositions();

		ItemUI* m_containerItem;
		std::vector<ItemUI*> m_items;
		std::string m_name;

		Uint16 m_size;
		Uint16 m_firstIndex;
		Uint8 m_id;
		Uint8 m_capacity;

		bool m_hasParent;
		bool m_canUseDepotSearch;
		bool m_isUnlocked;
		bool m_hasPages;
		bool m_dirty;
};

#endif /* __FILE_CONTAINER_h_ */
