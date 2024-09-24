/**
 * @file ItemTest.cpp
 * @author Auden Garrard
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Aquarium.h>
#include <FishBeta.h>


/// Fish filename
const std::wstring FishBetaImageName = L"images/beta.png";

/**
 * Mock class for testing the class Item
 */
class ItemMock : public Item
{
public:
	ItemMock(Aquarium *aquarium) : Item(aquarium, FishBetaImageName) {}

	//void Draw(wxDC *dc) override {}

};

TEST(ItemTest, Construct)
{
	Aquarium aquarium;
	ItemMock item(&aquarium);
}

TEST(ItemTest, GettersSetters)
{
	Aquarium aquarium;
	ItemMock item(&aquarium);

	// Test initial values
	ASSERT_NEAR(0, item.GetX(), 0.0001);
	ASSERT_NEAR(0, item.GetY(), 0.0001);

	// Test SetLocation, GetX, and GetY
	item.SetLocation(10.5, 17.2);
	ASSERT_NEAR(10.5, item.GetX(), 0.0001);
	ASSERT_NEAR(17.2, item.GetY(), 0.0001);

	// Test a second with different values
	item.SetLocation(-72, -107);
	ASSERT_NEAR(-72, item.GetX(), 0.0001);
	ASSERT_NEAR(-107, item.GetY(), 0.0001);
}

TEST(ItemTest, HitTest)
{
	Aquarium aquarium;

	ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
												   L"Testing empty aquarium";

	std::shared_ptr<FishBeta> fish1 = std::make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish1);
	fish1->SetLocation(100, 200);

	ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
													 L"Testing fish at 100, 200";

	std::shared_ptr<FishBeta> fish2 = std::make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish2);
	fish2->SetLocation(100, 200);

	ASSERT_TRUE(aquarium.HitTest(100, 200) == fish2)
						<< L"Testing to make sure that it is to fish on top";

	ASSERT_EQ(aquarium.HitTest(100, 300), nullptr)
						<< L"Testing to make sure that return nullptr if no fish is clicked";

}
