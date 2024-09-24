/**
 * @file Picture.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <wx/stdpaths.h>

#include "Picture.h"
#include "PictureObserver.h"
#include "Actor.h"

using namespace std;


/**
 * Constructor
*/
Picture::Picture()
{
}


/**
 * Set the current animation time
 *
 * This forces the animation of all
 * objects to the current animation location.
 * @param time The new time.
 */
void Picture::SetAnimationTime(double time)
{
    mTimeline.SetCurrentTime(time);
    UpdateObservers();

    for (auto actor : mActors)
    {
        actor->GetKeyframe();
    }
}

/**
 * Get the current animation time.
 * @return The current animation time
 */
double Picture::GetAnimationTime()
{
    return mTimeline.GetCurrentTime();
}

/**
 * Add an observer to this picture.
 * @param observer The observer to add
 */
void Picture::AddObserver(PictureObserver* observer)
{
    mObservers.push_back(observer);
}

/**
 * Remove an observer from this picture
 * @param observer The observer to remove
 */
void Picture::RemoveObserver(PictureObserver* observer)
{
    auto loc = find(std::begin(mObservers), std::end(mObservers), observer);
    if (loc != std::end(mObservers))
    {
        mObservers.erase(loc);
    }
}

/**
 * Update all observers to indicate the picture has changed.
 */
void Picture::UpdateObservers()
{
    for (auto observer : mObservers)
    {
        observer->UpdateObserver();
    }
}

/**
 * Draw this picture on a device context
 * @param graphics The device context to draw on
 */
void Picture::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto actor : mActors)
    {
        actor->Draw(graphics);
    }
}

/**
 * Add an actor to this drawable.
 * @param actor Actor to add
 */
void Picture::AddActor(std::shared_ptr<Actor> actor)
{
    mActors.push_back(actor);
    actor->SetPicture(this);
}


/**
* Save the picture animation to a file
* @param filename File to save to.
*/
void Picture::Save(const wxString& filename)
{
    wxXmlDocument xmlDoc;

    auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"anim");
    xmlDoc.SetRoot(root);

    // Save the timeline animation into the XML
    mTimeline.Save(root);

    //
    // It is possible to add attributes to the root node here
    //
    //root->AddAttribute(L"something", mSomething);
 	//root->AddAttribute(L"MachineOne",)
	 root->AddAttribute(L"MachineOneNumber",wxString::Format(wxT("%i"),mMachineOne->GetMachineNum()));
	root->AddAttribute(L"MachineTwoNumber",wxString::Format(wxT("%i"),mMachineTwo->GetMachineNum()));
	root->AddAttribute (L"MachineOneStart", wxString::Format (wxT("%i"), mMachineOne->GetStartTime()));
	root->AddAttribute (L"MachineTwoStart", wxString::Format(wxT("%i"), mMachineTwo->GetStartTime()));
	//mMachineDrawable.Save(root);

    if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
    {
        wxMessageBox(L"Write to XML failed");
        return;
    }
}



/**
* Load a picture animation from a file
* @param filename file to load from
*/
void Picture::Load(const wxString& filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Animation file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    // Load the animation from the XML
    mTimeline.Load(root);

    //
    // It is possible to load attributes from the root node here
    //
    // mSomething = root->GetAttribute(L"something", L"default");
	mMachineOne->SetMachineNum(wxAtoi(root->GetAttribute(L"machineOne",L"1")));
	mMachineTwo->SetMachineNum(wxAtoi(root->GetAttribute(L"MachineTwo", L"2")));
	mMachineOne->SetStartTime(wxAtoi(root->GetAttribute(L"MachineOneStart",L"O")));
	mMachineTwo->SetStartTime(wxAtoi(root->GetAttribute(L"MachineTwoStart", L"O")));
//	// why does this get a string
//	mLoadMachineOne = root->GetAttribute(L"MachineOne",L"Null");
//	mLoadMachineTwo = root->GetAttribute(L"MachineTwo",L"Null");

	//mMachineOne->SetMachineNum();


	//mMachineDrawable.Load(root);

    SetAnimationTime(0);
    UpdateObservers();
}

/**
 *
 * Changes the machine image
 *
 * @param parent The window that is doing the changing
 * @param number Which machine should be changed
 */
void Picture::MachineDiaglog(wxWindow *parent, int number)
{
	if(number == 1)
	{
		mMachineOne->CreatDialogBox(parent);
	}
	else
	{
		mMachineTwo->CreatDialogBox(parent);
	}

}

