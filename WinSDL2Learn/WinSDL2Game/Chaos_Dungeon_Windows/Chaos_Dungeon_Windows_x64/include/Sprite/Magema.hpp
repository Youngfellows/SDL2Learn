#ifndef MAGEMA_HPP
#define MAGEMA_HPP
#include "Common/Animation.hpp"
#include "Sprite.hpp"
#include "Common/ColliSystem.hpp"
#include "WorldModel.hpp"

class Magema : public ColliableSprite
{
public:
	static Magema *Create();
	void Init() override;
	void Collied(Object *oth, BasicProp *prop, const Manifold *m) override;
	~Magema();
private:
	Magema();
	void update() override;
	void draw() override;
	Animation ani;
};

#endif
