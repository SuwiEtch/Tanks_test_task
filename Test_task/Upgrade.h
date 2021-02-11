#pragma once

#include "Hero.h"
#include "Block.h"

const float powerTimer = 5.0f;

enum class powerUps {
	UPGRADE,
	EXTRALIVE,
	STELLWALL,
	MOREPOWER,
	COUNT
};

class Upgrade : public Block
{
public:
	Upgrade();
	Upgrade(
		const char* name, const float possX, const float possY,
		void (*draw)(Sprite*, int, int), const powerUps type
	);
	void Draw() override;
	// Colisium
	void PowerUpsColisium(Hero& hero);
	// Markfunction
	void ClearMark() {
		last = 0;
	};
	// work with mark
	float GetMark() const {
		return last;
	};
	void UpdateMark(const float mark) {
		last += mark;
	};
	float GetConstTime() const {
		return reloadTime;
	};
	// Get type
	powerUps GetPowerType() const {
		return powerType;
	};
private:
	void ReleasedKey() {};
	void PressKey(FRKey k) {};
private:
	powerUps powerType{};
	float last{};
	float lifeTime{ 0.50f };
	float reloadTime{ 1.0f };
};

