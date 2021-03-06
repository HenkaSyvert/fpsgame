#pragma once

#include "missan.hpp"
#include "weapon.hpp"


using namespace Missan;

class Menu : public Component {

public:

	bool isPaused = false;

	// key to pause game
	Keycode pauseKey = Keycode::E;

	// to avoid multiple keypresses
	float delay = 0.5f;

	// timer for key press
	float timeStamp = 0;

	bool canPressKey = true;


	// for dispaying info about weapon
	Weapon* weapon = nullptr;



	


	void Start() {
		timeStamp = Time::unscaledTime;
		Window::SetIsCursorVisible(false);
		weapon = GetGameObject().GetComponent<Weapon>();

	}

	void Update() {

		if (!canPressKey) {
			if (Time::unscaledTime - timeStamp > delay) {
				canPressKey = true;		
			}
		}
		
		if (canPressKey && Input::GetKeyDown(pauseKey)) {
			isPaused = !isPaused;
			Window::SetIsCursorVisible(isPaused);
			canPressKey = false;
			timeStamp = Time::unscaledTime;
		}

	}

	void OnGUI() {
		ImGui::Text("press E to pause game");
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::SliderFloat("power", &weapon->force, 12.0f, 179.9f);
		char buf[60];
		auto pos = GetGameObject().GetComponent<Transform>()->position;
		sprintf_s(buf, "player xyz: (%2.1f, %2.1f, %2.1f)", pos.x, pos.y, pos.z);
		ImGui::Text(buf);
	}



	Menu* Clone() const { return new Menu(*this); }


};

