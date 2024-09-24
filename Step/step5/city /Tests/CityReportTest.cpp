#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <CityReport.h>
#include <MemberReport.h>

#include <TileLandscape.h>
#include <TileBuilding.h>

using namespace std;

/** Testing stub class, creates a vector from
 * the list. This is done so we can test this
 * before we create the iterator. DO NOT USE
 * THIS CODE to solve the iterator task */
class CityReportStub : public CityReport
{
public:
    CityReportStub(City* city) : CityReport(city) {}

    std::vector<std::shared_ptr<MemberReport>> GetReports()
    {
        // Result list
        std::vector<std::shared_ptr<MemberReport>> list;

        for(std::list<std::shared_ptr<ReportsBin>>::iterator bin=mReportBins.begin();
            bin!=mReportBins.end(); bin++)
        {
            for(int i=0; ; i++)
            {
                if((*bin)->mReports[i] != nullptr)
                {
                    list.push_back((*bin)->mReports[i]);
                }
                else
                {
                    // We are done with this bin
                    break;
                }
            }
        }

        return list;
    }
};

class CityReportTest : public ::testing::Test {
protected:
    static void AddTile(City* city, CityReport* report, std::shared_ptr<Tile> tile)
    {
        city->Add(tile);

        auto memberReport = make_shared<MemberReport>(tile);
        tile->Report(memberReport);
        report->Add(memberReport);
    }

    static void AddLandscape(City* city, CityReport* report, int x, int y)
    {
        auto tile = make_shared<TileLandscape>(city);
        tile->SetLocation(x, y);
        AddTile(city, report, tile);
    }

    static void AddBuilding(City* city, CityReport* report, int x, int y, std::wstring file)
    {
        auto tile = make_shared<TileBuilding>(city);
        tile->SetImage(file);
        tile->SetLocation(x, y);
        AddTile(city, report, tile);
    }
};

TEST_F(CityReportTest, Add)
{
    City city;     // We need a city

    // The report class under test
    CityReportStub report(&city);

    auto results = report.GetReports();
    ASSERT_EQ(0, (int)results.size());

    AddLandscape(&city, &report, 100, 210);

    results = report.GetReports();
    ASSERT_EQ(1, (int)results.size());
    ASSERT_EQ(wstring(L"100, 210: Landscape"), results[0]->Report());

    AddBuilding(&city, &report, 30, 109, L"market.png");

    results = report.GetReports();
    ASSERT_EQ(2, (int)results.size());
    ASSERT_EQ(wstring(L"100, 210: Landscape"), results[0]->Report());
    ASSERT_EQ(wstring(L"30, 109: Building - market.png"), results[1]->Report());

    auto str = results[1]->Report();

    for (int i = 0; i < 100; i++)
    {
        AddLandscape(&city, &report, 100+i, 210);
        AddBuilding(&city, &report, 130, 200+i, L"market.png");
    }

    results = report.GetReports();
    ASSERT_EQ(202, (int)results.size());

    for (int i = 0; i < 100; i++)
    {
        wstringstream str1, str2, str3;
        str1 << 100 + i << ", 210: Landscape";
        str2 << "130, " << 200 + i << ": Building - market.png";

        ASSERT_EQ(str1.str(), results[i * 2 + 2]->Report());
        ASSERT_EQ(str2.str(), results[i * 2 + 3]->Report());
    }

}

TEST_F(CityReportTest, Iterator)
{
	// We need a city
	City city;

	// The report class under test
	CityReportStub report(&city);

	// Test to ensure the collection is initially empty
	auto results = report.GetReports();
	ASSERT_FALSE(report.begin() != report.end());

	// Add one landscape tile
	AddLandscape(&city, &report, 100, 210);

	// Test that the iterator works with one item in the collection
	results = report.GetReports();
	// Get an iterator
	auto iter = report.begin();
	// Ensure the iterator points to the same thing as the know first
	// item in the collection.
	ASSERT_EQ(results[0]->Report(), (*iter)->Report());
	// Ensure the iterator thinks it is not at the end yet
	auto end = report.end();
	ASSERT_TRUE(iter != report.end());
	// Increment, should increment to the end
	++iter;
	ASSERT_FALSE(iter != report.end());

	// Add one building tile
	AddBuilding(&city, &report, 30, 109, L"market.png");

	// Test that the iterator works with two items in the collection
	results = report.GetReports();
	iter = report.begin();
	ASSERT_EQ(results[0]->Report(), (*iter)->Report());
	ASSERT_TRUE(iter != report.end());
	++iter;
	ASSERT_EQ(results[1]->Report(), (*iter)->Report());
	ASSERT_TRUE(iter != report.end());
	++iter;
	ASSERT_FALSE(iter != report.end());

	// Test with varying numbers of items in the collection
	for (int i = 0; i < 100; i++)
	{
		// Add two tiles
		AddLandscape(&city, &report, 100 + i, 210);
		AddBuilding(&city, &report, 130, 200 + i, L"market.png");

		// Test the iterator
		results = report.GetReports();
		size_t cnt = 0;
		for (auto memberReport : report)
		{
			ASSERT_TRUE(cnt < results.size());
			ASSERT_EQ(results[cnt]->Report(), memberReport->Report());

			cnt++;
		}

		ASSERT_EQ(results.size(), cnt);
	}
}
