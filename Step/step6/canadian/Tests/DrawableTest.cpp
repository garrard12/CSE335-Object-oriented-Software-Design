/**
 * @file DrawableTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
#include "gtest/gtest.h"

#include <Drawable.h>

using namespace std;

class DrawableMock : public Drawable
{
public:
	DrawableMock(const std::wstring &name) : Drawable(name){}

	virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}
	virtual bool HitTest(wxPoint pos) override {return false;}
};


TEST(Drawable,Constructor)
{

	DrawableMock draw(L"bob");
	ASSERT_EQ(std::wstring(L"bob"),draw.GetName());
}

TEST(Drawable,PositionGetterAndSetter)
{
	DrawableMock draw(L"bob");

	//Test the Default values
	ASSERT_NEAR(draw.GetPosition().x,0,.001);
	ASSERT_NEAR(draw.GetPosition().y,0,.001);

	// Set the new value to something else
	draw.SetPosition(wxPoint(50,75));

	// Check to make sure the new value works
	ASSERT_NEAR(draw.GetPosition().x,50,.001);
	ASSERT_NEAR(draw.GetPosition().y,75,.001);
}

TEST(Drawable,RotionGetterAndSetter)
{
	DrawableMock draw(L"bob");

	//Test the Default values
	ASSERT_NEAR(draw.GetRotation(),0,.001);

	// Set the new value to something else
	draw.SetRotation(75.4);

	// Check to make sure the new value works
	ASSERT_NEAR(draw.GetRotation(),75.4,.0001);
}

TEST(DrawableTest, Association)
{
	DrawableMock body(L"Body");
	auto arm = std::make_shared<DrawableMock>(L"Arm");
	auto leg = std::make_shared<DrawableMock>(L"Leg");

	ASSERT_EQ(nullptr, arm->GetParent());
	ASSERT_EQ(nullptr, leg->GetParent());

	body.AddChild(arm);
	body.AddChild(leg);

	ASSERT_EQ(&body, arm->GetParent());
	ASSERT_EQ(&body, leg->GetParent());
}