/**
 * @file AquariumTest.cpp
 * @author Auden Garrard
 */


#include <pch.h>
//To test the XML
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>
#include <Castle.h>
#include <Bubbles.h>
#include <Angler.h>

using namespace std;

const unsigned int RandomSeed = 1238197374;


class AquariumTest : public ::testing::Test {
protected:
	/**
	* Create a path to a place to put temporary files
	*/
	wxString TempPath()
	{
		// Create a temporary filename we can use
		auto path = wxFileName::GetTempDir() + L"/aquarium";
		if(!wxFileName::DirExists(path))
		{
			wxFileName::Mkdir(path);
		}

		return path;
	}
	/**
	* Read a file into a wstring and return it.
	* @param filename Name of the file to read
	* @return File contents
	*/
	wstring ReadFile(const wxString &filename)
	{
		ifstream t(filename.ToStdString());
		wstring str((istreambuf_iterator<char>(t)),
					istreambuf_iterator<char>());

		return str;
	}
	/**
	 * Test to ensure an aquarium .aqua file is empty
	 * @param filename The name to the file
	 */
	void TestEmpty(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);


		ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<aqua/>")));

	}
	/**
	*  Populate an aquarium with three Beta fish
	*  @param aquarium The aquarium to populate the fish to
	*/
	void PopulateThreeBetas(Aquarium *aquarium)
	{
		//make random values
		aquarium->GetRandom().seed(RandomSeed);

		auto fish1 = make_shared<FishBeta>(aquarium);
		aquarium->Add(fish1);
		fish1->SetLocation(100, 200);

		auto fish2 = make_shared<FishBeta>(aquarium);
		aquarium->Add(fish2);
		fish2->SetLocation(400, 400);

		auto fish3 = make_shared<FishBeta>(aquarium);
		aquarium->Add(fish3);
		fish3->SetLocation(600, 100);
	}

	/**
	 * Populate an aquarium with one of Castle, Angler, Beta, and Bubbles fish
	 * @param aquarium The aquarium to populate the fish to
	 */
	void PopulateAllTypes(Aquarium *aquarium)
	{
		//Adds random values
		aquarium->GetRandom().seed(RandomSeed);
		cout << aquarium->GetRandom() << endl;

		auto anglerFish = make_shared<Angler>(aquarium);
		aquarium->Add(anglerFish);
		anglerFish->SetLocation(100,200);

		auto bubblesFish = make_shared<Bubbles>(aquarium);
		aquarium->Add(bubblesFish);
		bubblesFish->SetLocation(200,300);

		auto castle = make_shared<Castle>(aquarium);
		aquarium->Add(castle);
		castle->SetLocation(300,400);

		auto betaFish = make_shared<FishBeta>(aquarium);
		aquarium->Add(betaFish);
		betaFish->SetLocation(400,500);
	}
	/**
	 * Check to make sure that the files are being saved to the right spot
	 * @param filename The path to the file
	 */
	void TestThreeBetas(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		// Ensure three items
		ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

		// Ensure the positions are correct
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

		// This test case makes sure that the location, Type, and that thier is Speed X and Y.
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<aqua><item.* type=\"beta\"/>""<item.* type=\"beta\"/>""<item.* type=\"beta\"/></aqua>")));

		//Testing the speed of the fish and the location
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<item x=\"100\" y=\"200\" XSpeed.* YSpeed.*")));
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<item x=\"400\" y=\"400\" XSpeed.* YSpeed.*")));
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<item x=\"600\" y=\"100\" XSpeed.* YSpeed.*")));
	}
	/**
	 * Check to make sure that the files are being saved to the right spot
	 * @param filename The path to the file
	 */
	void TestAllTypes(wxString filename)
	{
		auto xml = ReadFile(filename);

		// Ensure 4 items
		ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*</aqua>")));

		// Ensure the positions are correct
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"200\" y=\"300\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"300\" y=\"400\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"500\"")));

		// Ensure the types are correct
		ASSERT_TRUE(regex_search(xml,
			 		wregex(L"<aqua><item.* type=\"angler\"/>""<item.* type=\"bubble\"/>""<item.* type=\"castle\"/><item.* type=\"beta\"/></aqua>")));

		//Testing the speed of the fish and the location
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<item x=\"100\" y=\"200\" XSpeed.* YSpeed.*")));
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<item x=\"200\" y=\"300\" XSpeed.* YSpeed.*")));
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<item x=\"400\" y=\"500\" XSpeed.* YSpeed.*")));

	}
};

TEST_F(AquariumTest, Construct){
	Aquarium aquarium;
}

TEST_F(AquariumTest, NonoverlappingAdd1) {
	Aquarium aquarium;

	shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish1);

	ASSERT_NEAR(200, fish1->GetX(), 0.1);
	ASSERT_NEAR(200, fish1->GetY(), 0.1);

	// First fish moved to 210, 210
	fish1->SetLocation(210, 210);

	shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish2);

	// Second fish should be created at 200, 200, since there
	// is not a fish there.
	ASSERT_NEAR(200, fish2->GetX(), 0.1);
	ASSERT_NEAR(200, fish2->GetY(), 0.1);

	shared_ptr<FishBeta> fish3 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish3);

	// Since there are fish at (200, 200) and (210, 210),
	// this fish should have been created at (220, 220)
	ASSERT_NEAR(220, fish3->GetX(), 0.1);
	ASSERT_NEAR(220, fish3->GetY(), 0.1);
}

TEST_F(AquariumTest, NonoverlappingAdd2) {
	Aquarium aquarium;

	shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish1);

	ASSERT_NEAR(200, fish1->GetX(), 0.1);
	ASSERT_NEAR(200, fish1->GetY(), 0.1);

	shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish2);

	ASSERT_NEAR(210, fish2->GetX(), 0.1);
	ASSERT_NEAR(210, fish2->GetY(), 0.1);

	fish1->SetLocation(220, 220);
	// Fish are now at (220, 220), (210, 210)

	shared_ptr<FishBeta> fish3 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish3);

	// Since nothing is at (200, 200), the fish should be created there
	ASSERT_NEAR(200, fish3->GetX(), 0.1);
	ASSERT_NEAR(200, fish3->GetY(), 0.1);

	fish2->SetLocation(230, 230);
	// Fish are now at (220, 220), (230, 230), (200, 200)

	shared_ptr<FishBeta> fish4 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish4);

	// No fish at 210, 210, so should be created there.
	ASSERT_NEAR(210, fish4->GetX(), 0.1);
	ASSERT_NEAR(210, fish4->GetY(), 0.1);
}

TEST_F(AquariumTest, Save) {
	// Create a path to temporary files
	auto path = TempPath();

	// Create an aquarium
	Aquarium aquarium;

	//
	// First test, saving an empty aquarium
	//
	auto file1 = path + L"/test1.aqua";
	aquarium.Save(file1);

	TestEmpty(file1);

	//
	// Now populate the aquarium
	//

	PopulateThreeBetas(&aquarium);

	auto file2 = path + L"/test2.aqua";
	aquarium.Save(file2);

	TestThreeBetas(file2);

	//
	// Test all types
	//
	Aquarium aquarium3;
	PopulateAllTypes(&aquarium3);

	auto file3 = path + L"/test3.aqua";
	aquarium3.Save(file3);

	TestAllTypes(file3);
}

TEST_F(AquariumTest, Clear)
{
	// Create a path to temporary files
	auto path = TempPath();

	// Create an aquarium
	Aquarium aquarium;

	// Populate the Aquarium with the Beta fish
	PopulateThreeBetas(&aquarium);

	//
	auto file1 = path + L"/test1.aqua";

	// Clears the aquarium
	aquarium.Clear();

	aquarium.Save(file1);


	// test to make sur that it is empty
	TestEmpty(file1);

}

TEST_F(AquariumTest, Load) {
	// Create a path to temporary files
	auto path = TempPath();

	// Create an aquarium
	Aquarium aquarium;
	Aquarium aquarium2;

	//
	// First test, saving an empty aquarium
	//
	auto file1 = path + L"/test1.aqua";
	aquarium.Save(file1);

	TestEmpty(file1);

	aquarium2.Load(file1);
	aquarium2.Save(file1);
	TestEmpty(file1);

	//
	// Now populate the aquarium
	//

	PopulateThreeBetas(&aquarium);

	auto file2 = path + L"/test2.aqua";
	aquarium.Save(file2);

	TestThreeBetas(file2);

	aquarium2.Load(file2);
	aquarium2.Save(file2);
	TestThreeBetas(file2);

	//
	// Test all types
	//
	Aquarium aquarium3;
	PopulateAllTypes(&aquarium3);

	auto file3 = path + L"/test3.aqua";
	aquarium3.Save(file3);

	TestAllTypes(file3);

	aquarium2.Load(file3);
	aquarium2.Save(file3);
	TestAllTypes(file3);
}