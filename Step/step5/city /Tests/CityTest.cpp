#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <TileLandscape.h>
#include <TileBuilding.h>
#include <TileGarden.h>
#include <TileWater.h>
#include <TileStarshipPad.h>

using namespace std;


class TestVisitor : public TileVisitor
{
public:
	virtual void VisitBuilding(TileBuilding* build) override { mNumBuildings++; }
	virtual void VisitGarden(TileGarden* Garden) override { mNumBuildings++; }
	virtual void VisitWater(TileWater* Water) override { mNumBuildings++; }
	virtual void VisitLandscape(TileLandscape* Landscape) override { mNumBuildings++; }
	virtual void VisitStatShip(TileStarshipPad* StarshipPad) override { mNumBuildings++;}

	int mNumBuildings = 0;
};

TEST(CityTest, Adjacent)
{
    City city;
    int grid = City::GridSpacing;

    // Add a center tile to test
    auto center = make_shared<TileGarden>(&city);
    center->SetLocation(grid * 10, grid * 17);
    city.Add(center);

    // Upper left
    auto ul = make_shared<TileGarden>(&city);
    ul->SetLocation(grid * 8, grid * 16);
    city.Add(ul);
    city.SortTiles();

    ASSERT_EQ(ul, city.GetAdjacent(center, -1, -1)) << L"Upper left test";
    ASSERT_EQ(nullptr,city.GetAdjacent(center, 1, -1)) << L"Upper right null test";

    // Upper right
    auto ur = make_shared<TileGarden>(&city);
    ur->SetLocation(grid * 12, grid * 16);
    city.Add(ur);

    // Lower left
    auto ll = make_shared<TileGarden>(&city);
    ll->SetLocation(grid * 8, grid * 18);
    city.Add(ll);

    // Lower right
    auto lr = make_shared<TileGarden>(&city);
    lr->SetLocation(grid * 12, grid * 18);
    city.Add(lr);

    city.SortTiles();

    ASSERT_EQ(ur, city.GetAdjacent(center, 1, -1)) << L"Upper right test";
    ASSERT_EQ(ll, city.GetAdjacent(center, -1, 1)) << L"Lower left test";
    ASSERT_EQ(lr, city.GetAdjacent(center, 1, 1)) << L"Lower right test";
}
TEST(CityTest, Iterator)
{
	// Construct a city object
	City city;

	// Add some tiles
	auto tile1 = make_shared<TileGarden>(&city);
	auto tile2 = make_shared<TileGarden>(&city);
	auto tile3 = make_shared<TileGarden>(&city);

	city.Add(tile1);
	city.Add(tile2);
	city.Add(tile3);

	// Begin points to the first item
	auto iter1 = city.begin();

	// End points after the last item
	auto iter2 = city.end();

	ASSERT_EQ(tile1, *iter1) << L"First item correct";
	++iter1;
	ASSERT_EQ(tile2, *iter1) << L"Second item correct";
	++iter1;
	ASSERT_EQ(tile3, *iter1) << L"Third item correct";
	++iter1;
	ASSERT_FALSE(iter1 != iter2);
}

TEST(CityTest, Visitor)
{
	// Construct a city object
	City city;

	//Test no vistors
	TestVisitor visitor;
	city.Accept(&visitor);
	ASSERT_EQ(0, visitor.mNumBuildings) << L"No Visitor";

	// Add some tiles of each type
	auto tile1 = make_shared<TileGarden>(&city);
	auto tile2 = make_shared<TileBuilding>(&city);
	auto tile3 = make_shared<TileLandscape>(&city);
	auto tile4 = make_shared<TileWater>(&city);
	auto tile5 = make_shared<TileStarshipPad>(&city);

	// Add the title to each city
	city.Add(tile1);
	city.Add(tile2);
	city.Add(tile3);
	city.Add(tile4);
	city.Add(tile5);

	city.Accept(&visitor);
	ASSERT_EQ(5, visitor.mNumBuildings) << L"Visitor number of buildings";
}