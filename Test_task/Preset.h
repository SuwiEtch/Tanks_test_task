#pragma once

#include <string>

enum class tankPreset {
	HEROTANK1,
	HEROTANK2,
	HEROTANK3,
	HEROTANK4,
	WIDTHTANK,
	ENEMYTANKEASY,
	ENEMYTANKFAST,
	ENEMYTANKPOWER,
	ENEMYTANKARMOR,
	COUNT
};

class Preset
{
public:
	Preset();
	~Preset();
	// load data
	void LoadPreset(tankPreset type);
	// returned init date
	unsigned int GetHealth() const {
		return health;
	};
	float GetBulletReload() const {
		return bullet_reload;
	};
	float GetTankVel() const {
		return tank_velocity;
	};
	float GetBulletVel() const {
		return bullet_velocity;
	};
	const char* GetTankAnimPress() const {
		return animationTankPreset.c_str();
	};
	const char* GetBulletAnimPress() const {
		return animationBulletPreset.c_str();
	};
	tankPreset GetTankType() const {
		return type;
	};
private:
	void ReadFile(const char* name);
private:
	unsigned int health{ 0 };
	float bullet_reload{ 0.0f };
	float tank_velocity{ 0.0f };
	float bullet_velocity{ 0.0f };

	std::string animationTankPreset{ 0 };
	std::string animationBulletPreset{ 0 };
	tankPreset type{tankPreset::COUNT};
};

