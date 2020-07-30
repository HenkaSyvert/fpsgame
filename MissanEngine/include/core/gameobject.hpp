#pragma once

#include "missanpch.hpp"
#include "core/component.hpp"

namespace Missan {

	// Base class for all entities in Missan Scenes
	class GameObject {

	public:

		// Creates new GameObject with Transform Component already attached
		GameObject();	

		// Deletes GameObject and all attached Components
		~GameObject();	

		// Creates new instances of copy's Components and attaches them to the new GameObject
		GameObject(GameObject& copy);	

		// Adds Component of type T, attaches it, and returns pointer
		template <class T> T* AddComponent() {
			components.push_back(new T());
			components.back()->AttachToGameObject(*this);
			return (T*)components.back();
		}	

		// Returns pointer to Component of type T if found, else nullptr
		template <class T> T* GetComponent() {
			for (Component* c : components)
				if (typeid(T) == typeid(*c))
					return (T*)c;
			return nullptr;
		}

		


		// TEST ///////////////////
		// Unique identifier for this instance
		const int instanceID;

		// The name of this GameObject
		std::string name;




		// NOT PART OF PUBLIC API ///////////////////////////////////
		std::vector<class Component*> components;

	};

}